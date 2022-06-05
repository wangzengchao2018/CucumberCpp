# Foreword

When I was working a few years ago, I was fortunate to join the project team led by Mr. Quan (bzquan), contacted, learned and practiced the BDD agile development method in the direction of C++.

Customers, testers, and developers continuously communicate and communicate, so that software product functions are gradually instantiated. The instantiated documents (feature files written in Gherkin language) also take into account the characteristics of requirements documents, test documents, and development documents.

The project-customized test framework based on GoogleTest and GoogleMock provides a guarantee for the continuous improvement and refactoring of the project code.

The BDD agile development method makes coding no longer boring and makes the development process very interesting.

In the near future, we plan to introduce this BDD development process into Linux project development.

At present, the adaptation, compilation and operation of CucumberCpp have been successfully completed on the host of the Ubuntu20.04 system.
Development environment configuration:
1. Ubuntu 20.04
2. gcc/g++ version 9.4.0
3. QT5.62

Considering the versatility of the Linux platform, the original project has been modified as follows:
1. Cancel the use of #define to define multilingual texts, and fall back to the first version of Unicode transcoding to ensure that only English characters are in the generated .h/.cpp files.
2. In order to compile successfully under Linux system, several QT project files (.pro) and source files (.h/.cpp) have been modified.
3. The feature files in all example projects are regenerated with the latest tools, compiled and run through.

# Cucumber/C++
Cucumber/C++ is an editor of Cucumber/Gherkin, a language of specification by example in the BDD world.
C++ step implementation is simple and straight forward.

# Screen shot
![sceen shot](https://github.com/bzquan/CucumberCpp/blob/master/CucumberC%2B%2B.jpg)

# Features
1. Keywords highlight
2. Pretty formatting
3. Generation of C++ Gherkin implementation skeleton.

# Building Cucumber/C++
1. Install Qt5.6
2. Setup C++14 compiler, eg. Visual Studio 2015, gcc5.2.
3. Optional: Bison is needed if you want to change Gherkin parser grammer, gherkin.y.
3. Configure Qt projects, CucumberCpp.pro and GherkinParser.pro.
4. CucumberCpp is GUI projects which depends on GherkinParser.

# Examples
[Simple string calculator](https://github.com/bzquan/CucumberCpp/blob/master/Example/SimpleStringCalculator.md)  
[How to use mock object](https://github.com/bzquan/CucumberCpp/blob/master/Example/SimpleStringCalculatorMock.md)
 
# Limitations
It only supports English Keywords of Gherkin. However you can use any languages to write specification by example in Gherkin.


# Memo
[Markdown help from stackoverflow](http://stackoverflow.com/editing-help)

#--------------------------------------------------------------------------------------------------
