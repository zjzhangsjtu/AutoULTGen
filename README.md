Description

Unit level test has been widely recognized as an important approach to improve software quality, as it can expose bugs earlier in the development phase. However, manual unit level test development is often tedious and insufficient. Also, it is hard for developers to precisely identify the most error prone code block deserving the best test coverage by themselves.  So we developed the automatic Unit level test framework which can help us identify the most critical code block, provide the test coverage recommendation, and automatically generate >80% ULT test codes (~280K Lines) as well as >70% test cases (~110K cases) for intel media driver.

The Auto Unit Level Test Framework for Intel Media driver is composed of the Server-side and the client-side facilities. The server-side of Auto ULT Framework is in charge of automatic error Prone logic detection and the per component test coverage recommendation generation. While the client-side will automatically generate the test code and test cases based on the recommendation from server side. 

