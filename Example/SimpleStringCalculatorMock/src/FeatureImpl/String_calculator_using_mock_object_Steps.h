/* The MIT License (MIT)
 * 
 * Copyright (c) 2022 Zengchao Wang
 * Copyright (c) 2016 Bingzhe Quan
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "FeatureStepModel.h"
#include "String_calculator_using_mock_object_TestModel.h"

using namespace bdd;
#ifdef WIN32
#if (_MSC_VER < 1900)   // _MSC_VER == 1900 (Visual Studio 2015, MSVC++ 14.0)
using namespace boost;
#endif
#endif

class String_calculator_using_mock_object_Steps : public AbstractStepModel
{
public:
    void SetUp()
    {
        RegisterSteps();
        model.SetUp();
    }

    void TearDown()
    {
        model.TearDown();
    }

    void ExecuteTest()
    {
        model.Execute();
    }

public:
    void Input_Numbers(GherkinRow&);
    void The_result_Sum_shall_be_informedmock(GherkinRow&);

public:
    void RegisterSteps() override
    {
        Step(
            L"Input <Numbers>",
            function < void(GherkinRow&) >
            (bind(&String_calculator_using_mock_object_Steps::Input_Numbers, this, _1)));
        Step(
            L"The result <Sum> shall be informed\\[\\[mock\\]\\]",
            function < void(GherkinRow&) >
            (bind(&String_calculator_using_mock_object_Steps::The_result_Sum_shall_be_informedmock, this, _1)));
    }

private:
    String_calculator_using_mock_object_TestModel model;
};

