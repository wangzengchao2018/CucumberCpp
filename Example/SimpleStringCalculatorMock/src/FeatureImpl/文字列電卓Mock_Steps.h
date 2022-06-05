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
#include "文字列電卓Mock_TestModel.h"

using namespace bdd;
#ifdef WIN32
#if (_MSC_VER < 1900)   // _MSC_VER == 1900 (Visual Studio 2015, MSVC++ 14.0)
using namespace boost;
#endif
#endif

// class 文字列電卓Mock_Steps : public AbstractStepModel
class u25991uuu23383uuu21015uuu38651uuu21331uuMock_Steps : public AbstractStepModel
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
    // void 数字文字列を入力する(GherkinRow&);
    void u25968uuu23383uuu25991uuu23383uuu21015uuu12434uuu20837uuu21147uuu12377uuu12427uu(GherkinRow&);
    // void 合計が通知されることmock(GherkinRow&);
    void u21512uuu35336uuu12364uuu36890uuu30693uuu12373uuu12428uuu12427uuu12371uuu12392uumock(GherkinRow&);

public:
    void RegisterSteps() override
    {
        Step(
            L"<数字文字列>を入力する",
            function < void(GherkinRow&) >
            (bind(&u25991uuu23383uuu21015uuu38651uuu21331uuMock_Steps::u25968uuu23383uuu25991uuu23383uuu21015uuu12434uuu20837uuu21147uuu12377uuu12427uu, this, _1)));
        Step(
            L"<合計>が通知されること\\[\\[mock\\]\\]",
            function < void(GherkinRow&) >
            (bind(&u25991uuu23383uuu21015uuu38651uuu21331uuMock_Steps::u21512uuu35336uuu12364uuu36890uuu30693uuu12373uuu12428uuu12427uuu12371uuu12392uumock, this, _1)));
    }

private:
    // 文字列電卓Mock_TestModel model;
    u25991uuu23383uuu21015uuu38651uuu21331uuMock_TestModel model;
};

