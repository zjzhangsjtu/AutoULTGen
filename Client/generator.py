class Generator(object):
    """

    """

    def __init__(self):
        """

        """
        self.file_header = 'sample_header.txt'

    @staticmethod
    def write_file(filename, lines):
        with open(filename, 'w') as fout:
            fout.writelines(lines)

    def add_file_header(self, lines):
        """

        :param lines:
        :return:
        """
        with open(self.file_header, 'r') as f_header:
            for line in f_header:
                lines.append(line)
        lines.append('\n')

    @staticmethod
    def add_brief_intro_h(lines, file_name, class_name):
        lines.append('//!\n')
        lines.append('//! \\file     ' + file_name + '\n')
        lines.append('//! \\brief    header file of ' + class_name + ' class\n')
        lines.append('//! \\details\n')
        lines.append('//!\n')
        lines.append('\n')

    @staticmethod
    def add_brief_intro_cpp(lines, file_name, class_name):
        lines.append('//!\n')
        lines.append('//! \\file     ' + file_name + '\n')
        lines.append('//! \\brief    implementation file of ' + class_name + ' class\n')
        lines.append('//! \\a mock derived from ' + file_name[:-4] + ' and used for ult test\n')
        lines.append('//!\n')
        lines.append('\n')

    @staticmethod
    def add_includes_h(lines, filename, includes):
        name_ifd = filename.upper()
        name_ifd = '__' + name_ifd + '_H__'
        lines.append('#ifndef ' + name_ifd + '\n')
        lines.append('#define ' + name_ifd + '\n')
        lines.append('\n')
        for h_file in includes:
            lines.append('#include \"' + h_file + '\"\n')
        lines.append('\n')

    @staticmethod
    def add_includes_cpp(lines, includes):
        for h_file in includes:
            lines.append('#include \"' + h_file + '\"\n')
        lines.append('\n')

    def add_body_h(self, lines, info):
        """

        :return:
        """
        pass

    def generate_h(self):
        """

        :return:
        """
        pass

    def generate_cpp(self):
        """

        :return:
        """
        pass

    def generate(self):
        """

        :return:
        """
        self.generate_h()
        self.generate_cpp()