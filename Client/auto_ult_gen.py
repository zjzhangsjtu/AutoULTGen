import os
from xml_generator import *
import mock_generator
import re

BASIC_TYPE = {'int', 'bool', 'dword', 'uint8_t', 'uint16_t', 'uint32_t', 'uint64_t', 'char', 'unsigned'}


def filename_add_mock2(filename):
    filename_spl = filename.strip().split('_')
    filename_new = ''
    if len(filename_spl) > 2:
        for idx in range(len(filename_spl) - 2):
            filename_new += filename_spl[idx] + '_'
        filename_new += 'mock_' + filename_spl[-2] + '_' + filename_spl[-1]
        return filename_new
    else:
        return filename + '_mock'


def filename_add_mock(filename):
    return 'test_' + filename


def filename_add_test(filename):
    filename_spl = filename.strip().split('_')
    filename_new = ''
    if len(filename_spl) > 1:
        for idx in range(len(filename_spl) - 1):
            filename_new += filename_spl[idx] + '_'
        filename_new += 'test_case_' + filename_spl[-1]
        return filename_new
    else:
        return filename + '_test_case'


# def class_name_add_mock_2(class_name):
#     idx = class_name.find('Pkt')
#     return class_name[0:idx] + 'Mock' + class_name[idx:]

def class_name_add_mock(class_name):
    return 'Test' + class_name


def class_name_add_test(test_name):
    ss = test_name.split('_')
    test_class_name = ''
    for s in ss:
        test_class_name += s.capitalize()
    return test_class_name


def get_namespace(line):
    namespace = line[10:]
    if namespace[-1] == '{':
        namespace = namespace[:-1]
    return namespace


def get_class(line):
    idx1 = 6
    idx2 = line.find(':')
    super_class = ''
    class_name = ''
    if idx2 == -1:
        class_name = line[idx1:].strip()
    else:
        class_name = line[idx1:idx2 - 1].strip()
        idx2 = line.find('public') + 7
        super_class = line[idx2:].strip()
    return class_name, super_class


def split_by_upper(s):
    spl = []
    for i in s:
        if i.isupper():
            spl.append(i)
        else:
            spl[-1] += i
    return spl


def find_super_directory(super_class, namespace):
    spl = split_by_upper(super_class)
    workspace_dir = 'C:\\Users\\qichenma\\workspace-new\\gfx\\gfx-driver\\Source\\media\\media_embargo\\media_driver_next\\agnostic\\common\\codec\\hal'
    for idx in range(len(spl)):
        spl[idx] = spl[idx].lower()
        if spl[idx] == 'pkt':
            spl[idx] = 'packet'
    target_file = namespace
    for i in spl:
        target_file += '_' + i
    target_file += '.h'
    cur_dir = os.getcwd()
    os.system('cd ' + workspace_dir)
    print(target_file)
    file_path = os.system('dir /s /b |find ' + '\"' + target_file + '\" > ' + cur_dir + '\\temp.txt')
    os.system('cd ' + cur_dir)
    with open('temp.txt', 'r') as f_tmp:
        file_path = f_tmp.readline()
    print(file_path)
    return file_path


def analyze_method_info(lines):
    method_info = {
        'return_type': '',
        'method_name': '',
        'method_test_name': '',
        'parameters': [],
        'virtual': False
    }
    s = lines[0].strip()

    if len(lines) > 1:
        for i in lines[1:]:
            s = s + ' ' + i.strip()
    print(s)
    if s.startswith('virtual'):
        method_info['virtual'] = True
        s = s[8:].strip()

    # if s.startswith('void'):
    #     method_info['return_type'] = 'void'
    # elif s.startswith('MOS_STATUS'):
    #     method_info['return_type'] = 'MOS_STATUS'

    idx0 = s.find(' ')
    method_info['return_type'] = s[:idx0].strip()
    idx1 = s.find('(')
    idx2 = s.find(')')
    method_info['method_name'] = s[idx0+1:idx1].strip()
    s_para = s[idx1+1:idx2]
    paras = s_para.split(',')
    for i in paras:
        tmp = i.strip().split(' ')
        tmp = [i for i in tmp if i != '']
        if len(tmp) > 2 and tmp[0] == 'const':
            tmp = tmp[1:]
        if len(tmp) == 2:
            if tmp[0][-1] == '&':
                tmp[0] = tmp[0][:-1]
                tmp[1] = '&' + tmp[1]
            para = {'type': tmp[0].strip(), 'name': tmp[1].strip()}
            method_info['parameters'].append(para)
    method_info['method_test_name'] = method_info['method_name'] + 'Test'

    print(method_info)
    return method_info


def get_file_info(lines, file_name):
    info = {
        'file_name': file_name,
        'mock_name': '',
        'mock_name2': '',
        'test_name': '',
        'class_name': '',
        'mock_class_name': '',
        'test_class_name': '',
        'super_class': '',
        'namespace': '',
        'public_methods': [],
        'private_methods': [],
        'protected_methods': [],
        'methods_info': [],
        'var': [],
        'class_var': [],
        'includes': {}
    }
    info['mock_name'] = filename_add_mock(info['file_name'])
    info['test_name'] = filename_add_test(info['file_name'])
    info['mock_name2'] = filename_add_mock2(info['file_name'])

    f_methods = 'public_methods'
    f_continue = False
    f_ignore = False
    f_struct = False
    for line in lines:
        line_clr = line.strip()
        if f_ignore:
            idx = line_clr.find('*/')
            if idx == -1:
                continue
            else:
                f_ignore = False
                line_clr = line_clr[idx+2:]
        if line_clr == '':
            continue
        if line_clr.startswith('/*'):
            f_ignore = True
            continue
        if line_clr.startswith('//'):
            continue
        if line_clr.startswith('struct'):
            f_struct = True
        if line_clr.find('}') != -1:
            f_struct = False
        if f_struct:
            continue
        if f_continue:
            info[f_methods][-1].append(line)
            if line_clr[-1] == ';':
                f_continue = False
            else:
                f_continue = True
        else:
            if line_clr.startswith('#') or line_clr.startswith('*'):
                continue
            if line_clr.startswith('namespace '):
                info['namespace'] = get_namespace(line_clr)
                continue
            if line_clr.startswith('class'):
                info['class_name'], info['super_class'] = get_class(line_clr)
                info['mock_class_name'] = class_name_add_mock(info['class_name'])
                info['test_class_name'] = class_name_add_test(info['test_name'])
                continue
            if line_clr.startswith('public:'):
                f_methods = 'public_methods'
                continue
            if line_clr.startswith('protected:'):
                f_methods = 'protected_methods'
                continue
            if line_clr.startswith('private:'):
                f_methods = 'private_methods'
                continue
            if line_clr.startswith('MOS_STATUS') or line_clr.startswith('void') or line_clr.startswith('virtual'):
                info[f_methods].append([line])
                if line_clr[-1] == ';' or line_clr[-1] == '}':
                    f_continue = False
                else:
                    f_continue = True
                continue

            if line_clr.find('(') != -1:
                continue
            tmp0 = line_clr.split(' ')
            tmp = []
            filter_keywords = ['static', 'constexpr', 'const']
            for t in tmp0:
                if t and t not in filter_keywords:
                    tmp.append(t)
            if len(tmp) > 2:
                if tmp[0] == 'struct':
                    continue
                if tmp[1][-1] == ';':
                    tmp[1] = tmp[1][:-1]
                if tmp[0] in BASIC_TYPE:
                    info['var'].append({'type': tmp[0], 'name': tmp[1]})
                else:
                    info['class_var'].append({'type': tmp[0], 'name': tmp[1]})
    print(info['var'])
    for i in info['public_methods']:
        info['methods_info'].append(analyze_method_info(i))
    for i in info['private_methods']:
        info['methods_info'].append(analyze_method_info(i))
    for i in info['protected_methods']:
        info['methods_info'].append(analyze_method_info(i))
    super_class_header = find_super_directory(info['super_class'], info['namespace'])
    if super_class_header != '':
        sup_lines = []
        sup_info = get_file_info(sup_lines, super_class_header)
        info['public_methods'] += sup_info['public_methods']
        info['protected_methods'] += sup_info['protected_methods']
        info['private_methods'] += sup_info['private_methods']
        info['methods_info'] += sup_info['methods_info']

    return info


def add_file_header(lines):
    with open('sample_header.txt', 'r') as f_header:
        for line in f_header:
            lines.append(line)
    lines.append('\n')


def add_brief_intro_h(lines, file_name, class_name):
    lines.append('//!\n')
    lines.append('//! \\file     ' + file_name + '.h\n')
    lines.append('//! \\brief    header file of ' + class_name + ' class\n')
    lines.append('//! \\details\n')
    lines.append('//!\n')
    lines.append('\n')


def add_brief_intro_cpp(lines, file_name, class_name):
    lines.append('//!\n')
    lines.append('//! \\file     ' + file_name + '.cpp\n')
    lines.append('//! \\brief    implementation file of ' + class_name + ' class\n')
    lines.append('//! \\a mock derived from ' + file_name[:-4] + ' and used for ult test\n')
    lines.append('//!\n')
    lines.append('\n')


def add_brief_intro_cpp_test(lines, file_name, class_name):
    lines.append('//!\n')
    lines.append('//! \\file     ' + file_name + '.cpp\n')
    lines.append('//! \\brief    implementation file of ' + class_name + ' class\n')
    lines.append('//! \\details  ULT of ' + file_name + '\n')
    lines.append('//!\n')
    lines.append('\n')


def add_include_h(lines, filename, includes):
    name_ifd = filename.upper()
    name_ifd = '__' + name_ifd + '_H__'
    lines.append('#ifndef ' + name_ifd + '\n')
    lines.append('#define ' + name_ifd + '\n')
    lines.append('\n')
    for h_file in includes:
        lines.append('#include \"' + h_file + '\"\n')
        #lines.append('#include \"' + info['file_name'] + '.h\"\n')
    lines.append('\n')


def add_include_cpp(lines, info, includes):
    lines.append('\n')
    lines.append('#include \"' + info['mock_name'] + '.h\"\n')
    lines.append('#include \"gtest/gtest.h\"\n')
    for h_file in includes:
        lines.append('#include \"' + h_file + '\"\n')
    lines.append('\n')


def add_include_cpp_test(lines, info, includes):
    lines.append('\n')
    lines.append('#include \"' + info['test_name'] + '.h\"\n')
    lines.append('#include \"gtest/gtest.h\"\n')
    for h_file in includes:
        lines.append('#include \"' + h_file + '\"\n')
    lines.append('\n')


def add_method_annotation(lines, method_name):
    lines.append('        //!\n')
    lines.append('        //! \\brief     Test  ' + method_name + '\n')
    lines.append('        //!\n')
    lines.append('        //! \\return    MOS_STATUS\n')
    lines.append('        //!            MOS_STATUS_SUCCESS if success, else fail reason\n')
    lines.append('        //!\n')


def remove_override(method):
    method[-1] = method[-1].replace('override', '')


def replace_void(method):
    method[0] = method[0].replace('void', 'MOS_STATUS')


def add_test(method):
    idx = method[0].find('(')
    method[0] = method[0][:idx] + 'Test' + method[0][idx:]


def new_method_name_h(method):
    add_test(method)
    replace_void(method)
    remove_override(method)


def new_method_name_cpp(method, mock_class_name):
    idx = method[0].find('MOS_STATUS')
    method[0] = method[0][:idx + 11] + mock_class_name + '::' + method[0][idx + 11:]
    method[-1] = method[-1].replace(';', '')
    method.append('        {\n')
    method.append('\n')
    method.append('        return MOS_STATUS_SUCCESS;\n')
    method.append('        }\n')


def get_method_name(method):
    idx0 = method[0].find('MOS_STATUS') + 11
    idx1 = method[0].find('Test')
    return method[0][idx0:idx1]


def add_body_h(lines, info):
    for i in info['public_methods']:
        new_method_name_h(i)

    for i in info['protected_methods']:
        new_method_name_h(i)

    for i in info['private_methods']:
        new_method_name_h(i)

    lines.append('namespace ' + info['namespace'] + '\n')
    lines.append('{\n')
    lines.append('    class ' + info['mock_class_name'] + ' : public ' + info['class_name'] + '\n')
    lines.append('    {\n\n')
    lines.append('    public:\n\n')
    lines.append('\n')
    lines.append('        virtual ~' + info['mock_class_name'] + '() {};\n')
    lines.append('\n')

    for i in info['methods_info']:
        if i['method_name'] == '':
            continue
        add_method_annotation(lines, i['method_name'])
        # line = '        ' + i['return_type'] + ' ' + i['method_name'] + 'Test('
        line = '        MOS_STATUS ' + i['method_name'] + 'Test('
        # for p in i['parameters']:
        #     line = line + p['type'] + ' ' + p['name'] + ', '
        # if line[-2:] == ', ':
        #     line = line[0:-2]
        line += ');\n'
        lines.append(line)
        lines.append('\n')

    # for i in info['public_methods']:
    #     method_name = get_method_name(i)
    #     add_method_annotation(lines, method_name)
    #     lines += i
    #     lines.append('\n')
    # lines.append('\n')
    #
    # for i in info['protected_methods']:
    #     method_name = get_method_name(i)
    #     add_method_annotation(lines, method_name)
    #     lines += i
    #     lines.append('\n')
    # lines.append('\n')
    #
    # for i in info['private_methods']:
    #     method_name = get_method_name(i)
    #     add_method_annotation(lines, method_name)
    #     lines += i
    #     lines.append('\n')

    lines.append('    private:\n')
    with open('dependency_class.txt' ,'r') as fin:
        for line in fin:
            class_name = line.strip().split(' ')[0]
            pattern = "[A-Z]"
            #variable_name = re.sub(pattern, lambda x: "_" + x.group(0), class_name).lower()
            variable_name = class_name[0].lower() + class_name[1:]
            lines.append('        ' + class_name + ' *m_' + variable_name + ';\n')
    lines.append('\n')
    lines.append('    };\n')
    lines.append('}\n')
    lines.append('#endif\n')


def add_arg_init(lines, name, type):
    if type in BASIC_TYPE:
        lines.append('            ' + type + ' ' + name + ' = 0;\n')
    else:
        lines.append('            ' + type + ' ' + name + ';\n')
        lines.append('            memset(&' + name + ', 0, sizeof(' + name + '));\n')
    return lines


def add_function_body(lines, method_info, class_name, info):
    if method_info['method_name'] == '':
        return
    lines.append('        MOS_STATUS ' + class_name + '::' + method_info['method_name'] + 'Test()\n')
    lines.append('        {\n')
    for p in method_info['parameters']:
        name = p['name']
        type = p['type']
        if name.startswith('&'):
            name = name[1:]
        add_arg_init(lines, name, type)
        # lines.append('            ' + p['type'] + ' ' + name + ';\n')
        # lines.append('            memset(&' + name + ', 0, sizeof(' + name + '));\n')
        lines.append('\n')

    s = '            EXPECT_EQ(' + info['class_name'] + '::' + method_info['method_name'] + '('
    for p in method_info['parameters']:
        name = p['name']
        if name.startswith('&'):
            name = name[1:]
        #s = s + ' &' + name + ', '
        s = s + name + ', '
    if s[-2:] == ', ':
        s = s[0:-2]
    if method_info['return_type'] != 'void':
        if method_info['return_type'] == 'MOS_STATUS':
            expect_return_type = 'MOS_STATUS_SUCCESS'
        else:
            expect_return_type = '0'
        s = s + '), ' + expect_return_type + ');\n'
        lines.append(s)
    lines.append('\n')
    lines.append('            return MOS_STATUS_SUCCESS;\n')
    lines.append('        }\n')
    lines.append('\n')


def add_body_cpp(lines, info):
    lines.append('namespace ' + info['namespace'] + '\n')
    lines.append('{\n')
    for i in info['methods_info']:
        add_function_body(lines, i, info['mock_class_name'], info)
        # if i['method_name'] == '':
        #     continue
        # line = '        MOS_STATUS ' + info['mock_class_name'] + '::' + i['method_name'] + '('
        # # for p in i['parameters']:
        # #     line = line + p['type'] + ' ' + p['name'] + ', '
        # # if line[-2:] == ', ':
        # #     line = line[0:-2]
        # line += ')\n'
        #
        # lines.append(line)
        # lines.append('        {\n')
        # lines.append('            MOS_COMMAND_BUFFER cmdBuffer;\n')
        # lines.append('            memset(&cmdBuffer, 0, sizeof(cmdBuffer));\n')
        # s = '            EXPECT_EQ(' + info['class_name'] + '::' + i['method_name'] + '('
        # for p in i['parameters']:
        #     s = s + p['type'] + ' ' + p['name'] + ', '
        # if s[-2:] == ', ':
        #     s = s[0:-2]
        # s = s + '), MOS_STATUS_SUCCESS);\n'
        # lines.append(s)
        # #lines.append('            EXPECT_EQ(' + info['class_name'] + '::' + i['method_name'] + '(), MOS_STATUS_SUCCESS);\n')
        # lines.append('\n')
        # lines.append('        }\n')
        # lines.append('\n')


    # for i in info['public_methods']:
    #     #idx = i[0].find('MOS_STATUS')
    #     #i[0] = i[0][:idx + 11] + info['mock_class_name'] + '::' + i[0][idx + 11:]
    #     new_method_name_cpp(i, info['mock_class_name'])
    #     lines += i
    #     lines.append('\n')
    # lines.append('\n')
    #
    # # lines.append('    protected:\n')
    # for i in info['protected_methods']:
    #     #idx = i[0].find('MOS_STATUS')
    #     #i[0] = i[0][:idx + 11] + info['mock_class_name'] + '::' + i[0][idx + 11:]
    #     new_method_name_cpp(i, info['mock_class_name'])
    #     lines += i
    #     lines.append('\n')
    # lines.append('\n')
    #
    # for i in info['private_methods']:
    #     new_method_name_cpp(i, info['mock_class_name'])
    #     lines += i
    #     lines.append('\n')

    lines.append('}\n')


def generate_h_file(info):
    mock_file_h = []
    add_file_header(mock_file_h)
    add_brief_intro_h(mock_file_h, info['mock_name'], info['class_name'])
    includes = list(info['includes']['test']['h'])
    includes.append(info['file_name'] + '.h')
    add_include_h(mock_file_h, info['mock_name'], includes)
    add_body_h(mock_file_h, info)
    with open(info['mock_name'] + '.h', 'w') as fout:
        fout.writelines(mock_file_h)


def generate_cpp_file(info):
    mock_file_cpp = []
    add_file_header(mock_file_cpp)
    add_brief_intro_cpp(mock_file_cpp, info['mock_name'], info['class_name'])
    includes = list(info['includes']['test']['cpp'])
    add_include_cpp(mock_file_cpp, info, includes)
    add_body_cpp(mock_file_cpp, info)
    with open(info['mock_name'] + '.cpp', 'w') as fout:
        fout.writelines(mock_file_cpp)


def add_test_h_body(lines, info):
    lines.append('namespace ' + info['namespace'] + '\n')
    lines.append('{\n')
    lines.append('    class ' + info['test_class_name'] + ' : public ' + 'EncodeTestFixture' + '\n')
    lines.append('    {\n\n')
    lines.append('    protected:\n\n')
    lines.append('\n')
    lines.append('        //!\n')
    lines.append('        //! \\brief   Initialization work before executing a unit test\n')
    lines.append('        //!\n')
    lines.append('        virtual void SetUp();\n')
    lines.append('\n')
    lines.append('        //!\n')
    lines.append('        //! \\brief   Uninitializaiton and exception handling after the unit test done\n')
    lines.append('        //!\n')
    lines.append('        virtual void TearDown();\n')
    lines.append('\n')
    lines.append('        //!\n')
    lines.append('        //! \\brief   Get Platform\n')
    lines.append('        //! \\param   [in] platform\n')
    lines.append('        //! \\        Reference to PLATFORM\n')
    lines.append('        //!\n')
    lines.append('        void GetPlatformByName(PLATFORM &platform);\n')
    lines.append('\n')
    lines.append('        //!\n')
    lines.append('        //! \\brief   Prepare Encode Params\n')
    lines.append('        //! \\param   [in] encodeParams\n')
    lines.append('        //! \\        Reference to EncodeParams\n')
    lines.append('        //!\n')
    lines.append('        void PrepareEncodeParams(EncoderParams &encodeParams);\n')
    lines.append('\n')
    lines.append('        ' + info['mock_class_name'] + '        *m_packet = nullptr;\n')
    lines.append('\n')
    lines.append('    };\n')
    lines.append('}\n')
    lines.append('\n')
    lines.append('#endif\n')


def add_test_cpp_body(lines, info):
    lines.append('namespace ' + info['namespace'] + '\n')
    lines.append('{\n')
    lines.append('\n')
    lines.append('    void ' + info['test_class_name'] + '::SetUp()\n')
    lines.append('    {\n')
    lines.append('\n\n')
    lines.append('    }\n')
    lines.append('\n')
    lines.append('    void ' + info['test_class_name'] + '::TearDown()\n')
    lines.append('    {\n')
    lines.append('\n\n')
    lines.append('    }\n')
    lines.append('    void ' + info['test_class_name'] + '::GetPlatformByName(PLATFORM &platform)\n')
    lines.append('    {\n')
    lines.append('\n\n')
    lines.append('    }\n')
    lines.append('    void ' + info['test_class_name'] + '::PrepareEncodeParams(EncoderParams &encodeParams)\n')
    lines.append('    {\n')
    lines.append('\n\n')
    lines.append('    }\n')
    lines.append('\n\n')
    for method in info['methods_info']:
        if method['method_name'] == '' or method['virtual']:
            continue
        lines.append('    TEST_F(' + info['test_class_name'] + ', ' + method['method_name'] + ')\n')
        lines.append('    {\n')
        lines.append('        EXPECT_EQ(m_packet->' + method['method_test_name'] + '(), MOS_STATUS_SUCCESS);\n')
        lines.append('    }\n')
    lines.append('}\n')


def generate_test_h_file(info):
    test_file_h = []
    add_file_header(test_file_h)
    add_brief_intro_h(test_file_h, info['test_name'], info['test_class_name'])

    includes = list(info['includes']['test_case']['h'])
    includes.append('memory_leak_detector.h')
    includes.append('mock_platform.h')
    includes.append(info['mock_name'] + '.h')
    includes.append('encode_test_fixture.h')
    add_include_h(test_file_h, info['test_name'], includes)

    add_test_h_body(test_file_h, info)

    with open(info['test_name'] + '.h', 'w') as fout:
        fout.writelines(test_file_h)


def generate_test_cpp_file(info):
    test_file_cpp = []
    add_file_header(test_file_cpp)
    add_brief_intro_cpp_test(test_file_cpp, info['file_name'], info['test_class_name'])
    includes = list(info['includes']['test_case']['cpp'])
    add_include_cpp_test(test_file_cpp, info, includes)
    add_test_cpp_body(test_file_cpp, info)

    with open(info['test_name'] + '.cpp', 'w') as fout:
        fout.writelines(test_file_cpp)


def main():
    file_list = []
    with open('file_list.txt', 'r') as fin:
        for line in fin:
            file_list.append(line.strip())

    for file_name in file_list:
        with open(file_name + '.h', 'r') as fin:
            lines = fin.readlines()

        info = get_file_info(lines, file_name)
        print(info['var'])
        generate_header_xml(info)
        info['includes'] = read_header_xml(info)
        generate_h_file(info)
        generate_cpp_file(info)
        generate_test_h_file(info)
        generate_test_cpp_file(info)
        generate_mock_xml(info)

    with open('dependency_class.txt') as fin:
        for line in fin:
            tmp = line.strip().split(' ')
            dependency_class = tmp[0]
            with open(tmp[1], 'r') as fin:
                lines = fin.readlines()
            info = get_file_info(lines, 'hevc_vdenc_pipeline_g12')
            mock_class = mock_generator.MockGenerator(info)
            mock_class.generate()


if __name__ == '__main__':
    main()
