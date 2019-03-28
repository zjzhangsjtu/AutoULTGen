from ult_generator import header_parser
from ult_generator import test_generator
from ult_generator import test_case_generator
from ult_generator import xml_generator
import re
import os


# PLATFORMS = {'G12': 'gen12', 'common':'common'}
# COMPONENTS = {'encode'}
#
#
# def find_class_file(class_name, start_path='../../Source/media/media_embargo/media_driver_next/agnostic'):
#     pattern = "[A-Z]"
#     class_name = re.sub(pattern, lambda x: " " + x.group(0), class_name)
#     name_split = class_name.strip().split(' ')
#     platform = 'common'
#     for word in name_split:
#         if word in PLATFORMS:
#             platform = word
#             break

def finddir(startdir, target, root_path):
    try:
        # startdir = startdir.replace('/', '\\')
        os.chdir(startdir)
    except:
        # print('startdir err')
        # print(startdir)
        return None
    for new_dir in os.listdir(os.curdir):
        #print(new_dir)
        if new_dir == target:
            result = os.getcwd() + os.sep + new_dir
            print(result)
            #os.chdir(root_path)
            return result
        if os.path.isdir(new_dir):
            result = finddir(new_dir, target, root_path)
            if result:
                return result
            os.chdir(os.pardir)
    return None


def find_super_class_file(class_name, includes, media_path):
    print(includes)
    t1 = class_name.lower()
    t1 = t1.replace('pkt', 'packet')
    file_name = ''
    for i in includes:
        t2 = i[:-2].replace('_', '')
        # print(t1)
        # print(t2)
        if t2.find(t1) != -1:
            file_name = i
            break
    if file_name:
        print(file_name)
        return finddir(media_path, file_name, os.getcwd())
    else:
        return None


def main(input_file='input.txt', media_path='../../../Source/media/media_embargo/media_driver_next/'):
    """

    :param input_file:
    :param media_path:
    :return:
    """
    with open(input_file, 'r') as fin:
        for line in fin:
            line = line.strip()
            idx = line.rfind('/')
            file_name = line[idx+1:]
            file_path = line[:idx+1]
            parser_list = [header_parser.HeaderParser(file_name, file_path)]
            print(os.getcwd())
            parser_list[0].read_file()
            parser_list[0].parse_file_info()
            # parser_list[0].print_info()
            while True:
                root_path = os.getcwd()
                s = find_super_class_file(parser_list[-1].super_class, parser_list[-1].includes, media_path)
                os.chdir(root_path)
                if s:
                    idx = s.rfind('/')
                    file_name = s[idx + 1:]
                    file_path = s[:idx + 1]
                    parser_list.append(header_parser.HeaderParser(file_name, file_path))
                    parser_list[-1].read_file()
                    parser_list[-1].parse_file_info()
                else:
                    break
            for i in parser_list[1:]:
                parser_list[0].methods_info.extend(i.methods_info)
            test = test_generator.TestGenerator(parser_list[0])
            test_case = test_case_generator.TestCaseGenerator(parser_list[0])
            xml_filename = parser_list[0].name[:-2] + '_header.xml'

            if os.path.exists(xml_filename):
                includes = xml_generator.read_header_xml(parser_list[0])
                test.includes_h = includes['test_h']
                test.includes_cpp = includes['test_cpp']
                test_case.includes_h = includes['test_case_h']
                test_case.includes_cpp = includes['test_case_cpp']
            else:
                includes = {'test_h': test.includes_h, 'test_cpp': test.includes_cpp,
                            'test_case_h': test_case.includes_h, 'test_case_cpp': test_case.includes_cpp}
                xml_generator.generate_header_xml(parser_list[0], includes)

            test.generate()
            test_case.generate()


if __name__ == '__main__':
    main()
