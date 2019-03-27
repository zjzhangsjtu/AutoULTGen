from ult_generator.generator import Generator
from ult_generator.header_parser import HeaderParser


class TestGenerator(Generator):
    """

    """

    def __init__(self, head_parser):
        """

        :param info:
        """
        Generator.__init__(self)
        if isinstance(head_parser, HeaderParser):
            self.info = head_parser
            self.test_filename_h = 'test_' + self.info.name
            self.test_filename_cpp = 'test_' + self.info.name[:-2] + '.cpp'
            self.test_class_name = 'Test' + self.info.class_name
            self.lines_h = [self.info.name]
            self.lines_cpp = [self.test_filename_h]
            self.includes_h = []
            self.includes_cpp = []
        else:
            print('Use HeadParser Class to initialize!')

    @staticmethod
    def add_method_annotation(lines, method_name):
        lines.append('        //!\n')
        lines.append('        //! \\brief     Test  ' + method_name + '\n')
        lines.append('        //!\n')
        lines.append('        //! \\return    MOS_STATUS\n')
        lines.append('        //!            MOS_STATUS_SUCCESS if success, else fail reason\n')
        lines.append('        //!\n')

    def add_body_h(self, lines, info):
        """

        :param lines:
        :param info:
        :return:
        """
        lines.append('namespace ' + info.namespace + '\n')
        lines.append('{\n')
        lines.append('    class ' + self.test_class_name + ' : public ' + info.class_name + '\n')
        lines.append('    {\n\n')
        lines.append('    public:\n\n')
        lines.append('\n')
        lines.append('        virtual ~' + self.test_class_name + '() {};\n')
        lines.append('\n')

        for i in info.methods_info:
            if i['method_name']:
                self.add_method_annotation(lines, i['method_name'])
                line = '        MOS_STATUS ' + i['method_name'] + 'Test();\n'
                lines.append(line)
                lines.append('\n')

        lines.append('    private:\n')
        with open('dependency_class.txt', 'r') as fin:
            for line in fin:
                class_name = line.strip().split(' ')[0]
                # pattern = "[A-Z]"
                # variable_name = re.sub(pattern, lambda x: "_" + x.group(0), class_name).lower()
                variable_name = class_name[0].lower() + class_name[1:]
                lines.append('        ' + class_name + ' *m_' + variable_name + ';\n')
        lines.append('\n')
        lines.append('    };\n')
        lines.append('}\n')
        lines.append('#endif\n')

    def generate_h(self):
        """

        :return:
        """
        self.add_file_header(self.lines_h)
        self.add_brief_intro_h(self.lines_h, self.test_filename_h, self.test_class_name)
        print(self.includes_h)
        self.add_includes_h(self.lines_h, self.test_filename_h[:-2], self.includes_h)
        self.add_body_h(self.lines_h, self.info)
        self.write_file(self.test_filename_h, self.lines_h)

    def add_arg_init(self, lines, name, p_type):
        """

        :param lines:
        :param name:
        :param p_type:
        :return:
        """
        if p_type in self.basic_type:
            lines.append('            ' + p_type + ' ' + name + ' = 0;\n')
        else:
            lines.append('            ' + p_type + ' ' + name + ';\n')
            lines.append('            memset(&' + name + ', 0, sizeof(' + name + '));\n')
        return lines

    def add_function_body(self, lines, method_info, class_name, info):
        """

        :param lines:
        :param method_info:
        :param class_name:
        :param info:
        :return:
        """
        if method_info['method_name'] == '':
            return
        lines.append('        MOS_STATUS ' + class_name + '::' + method_info['method_name'] + 'Test()\n')
        lines.append('        {\n')
        for p in method_info['parameters']:
            name = p['name']
            type = p['type']
            if name.startswith('&'):
                name = name[1:]
            self.add_arg_init(lines, name, type)
            lines.append('\n')

        s = '            EXPECT_EQ(' + class_name + '::' + method_info['method_name'] + '('
        for p in method_info['parameters']:
            name = p['name']
            if name.startswith('&'):
                name = name[1:]
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

    def add_body_cpp(self, lines, info):
        """

        :param lines:
        :param info:
        :return:
        """
        lines.append('namespace ' + info.namespace + '\n')
        lines.append('{\n')
        for i in info.methods_info:
            self.add_function_body(lines, i, self.test_class_name, info)
        lines.append('}\n')

    def generate_cpp(self):
        """

        :return:
        """
        self.add_file_header(self.lines_cpp)
        self.add_brief_intro_cpp(self.lines_cpp, self.test_filename_cpp, self.test_class_name)
        print(self.includes_cpp)
        self.add_includes_cpp(self.lines_cpp, self.includes_cpp)
        self.add_body_cpp(self.lines_cpp, self.info)
        self.write_file(self.test_filename_cpp, self.lines_cpp)
