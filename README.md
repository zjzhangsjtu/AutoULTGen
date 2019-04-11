# ULT Auto Generator

## Description

Unit level test has been widely recognized as an important approach to improve software quality, as it can expose bugs earlier in the development phase. However, manual unit level test development is often tedious and insufficient. Also, it is hard for developers to precisely identify the most error prone code block deserving the best test coverage by themselves. So we developed the automatic Unit level test framework which can help us identify the most critical code block, provide the test coverage recommendation, and automatically generate >80% ULT test codes (~280K Lines) as well as >70% test cases (~110K cases) for intel media driver.

The Auto Unit Level Test Framework for Intel Media driver is composed of the Server-side and the client-side facilities. The server-side of Auto ULT Framework is in charge of automatic error Prone logic detection and the per component test coverage recommendation generation. While the client-side will automatically generate the test code and test cases based on the recommendation from server side.

## User Guide

### Client-side

#### 1. Generation Test Class and Test Case Class

1. Enter the directory

```bash
cd AutoULTGen/Client/
```

2. Then write the paths and names of header files we need to parse in the input.txt one line per file like below.

   ```
   ./encode_hevc_vdenc_packet_g12.h
   ./encode_scalability_singlepipe.h
   ./encode_scalability_option.h
   ./media_scalability_factory.h
   ```

   

3. Write the specific header files we need in the *_header.xml.

   ```xml
   <?xml version="1.0" encoding="utf8"?>
   <encode_hevc_vdenc_packet_g12.h>
     <test_encode_hevc_vdenc_packet_g12.h>
       <Header file="encode_hevc_vdenc_mock_pipeline_g12.h"/>
       <Source file="mhw_utilities.h"/>
     </test_encode_hevc_vdenc_packet_g12.h>
     <encode_hevc_vdenc_packet_g12_test_case.h>
       <Header file="memory_leak_detector.h"/>
       <Header file="mock_platform.h"/>
       <Header file="encode_test_fixture.h"/>
       <Source file="codechal_debug_ext.h"/>
       <Source file="media_cmd_task.h"/>
       <Source file="encode_hevc_vdenc_ult_test_data.h"/>
       <Source file="codechal_setting_ext.h"/>
       <Source file="codec_test_environment.h"/>
     </encode_hevc_vdenc_packet_g12_test_case.h>
     <mock_encode_hevc_vdenc_packet_g12.h>
       <Header file=""/>
       <Source file=""/>
     </mock_encode_hevc_vdenc_packet_g12.h>
   </encode_hevc_vdenc_packet_g12.h>
   ```

   Tags with name 'Header' means the includes in the .h file we generate, others with name 'Source' means the includes in the .cpp file.

4. Run the script

   ```bash
   python3 main.py
   ```

​     The files we need will be generated in this directory.