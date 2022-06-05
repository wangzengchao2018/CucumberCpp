QT += core
QT -= gui

CONFIG += c++11

TARGET = SimpleStringCalculatorMock
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

# enable under Windows
#DEFINES += WIN32

# enable under Linux
DEFINES += QT

SOURCES += \
    src/main.cpp \
    src/TestCaseModel/AbstractTestModel.cpp \
    src/TestCaseModel/GherkinTable.cpp \
    src/TestCaseModel/IndirectFunctionCaller.cpp \
    src/TestCaseModel/NotificationTrace.cpp \
    src/TestCaseModel/StringUtility.cpp \
    src/FeatureImpl/文字列電卓_Feature.cpp \
    src/FeatureImpl/文字列電卓_Steps.cpp \
    src/FeatureImpl/文字列電卓_TestModel.cpp \
    src/FeatureImpl/文字列電卓Mock_Feature.cpp \
    src/FeatureImpl/文字列電卓Mock_Steps.cpp \
    src/FeatureImpl/文字列電卓Mock_TestModel.cpp \
    src/FeatureImpl/String_calculator_Feature.cpp \
    src/FeatureImpl/String_calculator_Steps.cpp \
    src/FeatureImpl/String_calculator_TestModel.cpp \
    src/FeatureImpl/String_calculator_using_mock_object_Feature.cpp \
    src/FeatureImpl/String_calculator_using_mock_object_Steps.cpp \
    src/FeatureImpl/String_calculator_using_mock_object_TestModel.cpp \
    src/SUT/StringCalculator.cpp \
    src/Unit/StringCalculatorTest.cpp

HEADERS += \
    src/TestCaseModel/AbstractNotificationTrace.h \
    src/TestCaseModel/AbstractTestModel.h \
    src/TestCaseModel/FeatureStepArg.h \
    src/TestCaseModel/FeatureStepFunction.h \
    src/TestCaseModel/FeatureStepModel.h \
    src/TestCaseModel/FeatureTestModel.h \
    src/TestCaseModel/GeneralMacro.h \
    src/TestCaseModel/GherkinTable.h \
    src/TestCaseModel/IndirectFunctionCaller.h \
    src/TestCaseModel/IndirectFunctionCallRequest.h \
    src/TestCaseModel/NotificationTrace.h \
    src/TestCaseModel/StringUtility.h \
    src/FeatureImpl/文字列電卓_Steps.h \
    src/FeatureImpl/文字列電卓_TestModel.h \
    src/FeatureImpl/文字列電卓Mock_Steps.h \
    src/FeatureImpl/文字列電卓Mock_TestModel.h \
    src/FeatureImpl/String_calculator_Steps.h \
    src/FeatureImpl/String_calculator_TestModel.h \
    src/FeatureImpl/String_calculator_using_mock_object_Steps.h \
    src/FeatureImpl/String_calculator_using_mock_object_TestModel.h \
    src/Mock/MockDisplay.h \
    src/SUT/StringCalculator.h \
    src/SUT/IDisplay.h

INCLUDEPATH += $$PWD/gmock-1.7.0-lib/include
LIBS += -L$$PWD/gmock-1.7.0-lib/lib/ -lgmock

INCLUDEPATH += $$PWD/src
INCLUDEPATH += $$PWD/src/TestCaseModel
INCLUDEPATH += $$PWD/src/FeatureImpl
INCLUDEPATH += $$PWD/src/Mock
INCLUDEPATH += $$PWD/src/SUT
