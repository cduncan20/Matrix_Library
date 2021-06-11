<h1>Matrix Multiplication / Transpose Library </h1>

**Authors:** Casey Duncan <br />
**Date:** 6/10/2021 <br />
**Description:** Matrix multiplication and transpose library that can be used in C++ 11. <br />

<h2>OVERVIEW</h2>

The objective of this project was the design a library within C++ 11 that was able to perform multiplication and transposition functions on user-defined matrices. Additionally, a test script was required to ensure the library functions were performing as intended.

<h2>Requirements</h2>

In order to build this project, you must be using CMake version 3.14.

<h2>How to Use</h2>

In order to use this library, each matrix needs to be initialized as a vector of vectors. This includes both input and output matrices, where the output matrices are initialized as empty. Once a matrix has been initialized as vector of vectors, it is then initialized as an object of the class *Matrix*. After this the matrix can be multiplied by another matrix object of the same class by using the asterisk(*) operator and it can be transposed by using the class function *transpose()*. More detail with examples is shown within the *demo.cpp* file. The location of this file is provided within the *File Location* section below. To see the results of the demonstration within the terminal, follow these steps:
1. Perform all steps within the *Building Project* section below.
2. Navigate into the location titled *build* by entering the following: <br />
`cd build`<br />
3. Execute the executable file called *matrix_library_demo* by entering the following: <br />
`src/matrix_library_demo`<br />

After performing the steps above, the results of the demo should appear within the terminal.

<h2>File Directory</h2>

The requirements for this project included a library that was able to perform multiplication and transposition functions and a test framework. In addition to these two requirements, I build a demonstration script for how to use the library. The locations for these files are provided below:
1. Library: `matrix_library/include/matlib.h`<br />
2. Test Framework: `matrix_library/test/test.cpp`<br />
3. Demonstration: `matrix_library/src/demo.cpp`<br />

<h2>Building Project</h2>

To build this project on your own system, you must following the steps below:
1. Download the project onto your machine.
2. Open terminal on your machine and navigate into the to the location of the downloaded project by entering the following: <br />
`cd ~/<path to save location>`<br />
3. Navigate into the location titled *matrix_library* by entering the following: <br />
`cd matrix_library`<br />
4. Write the build files for the project into a new folder called *build* using CMake by entering the following:<br />
`cmake -S . -B build`<br />
5. Build the project using CMake by entering the following:<br />
`cmake --build build`<br />

<h2>Testing Library</h2>

The Test Framework for this project was built using [GoogleTest](https://google.github.io/googletest/). To test this project on your own system, you must following the steps below:
1. Perform steps 1 - 3 within the *Building Project* section above.
2. Navigate into the location titled *build/test* by entering the following: <br />
`cd build/test`<br />
3. Execute the test for the library by entering the following: <br />
`ctest`<br />

There are six tests that will execute to verify that the library is working correctly. The results for each test will be displayed in the terminal.