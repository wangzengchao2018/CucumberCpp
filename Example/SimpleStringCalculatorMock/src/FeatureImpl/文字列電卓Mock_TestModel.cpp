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

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "文字列電卓Mock_TestModel.h"

using namespace ::testing;

// void 文字列電卓Mock_TestModel::SetUp()
void u25991uuu23383uuu21015uuu38651uuu21331uuMock_TestModel::SetUp()
{
}

// void 文字列電卓Mock_TestModel::TearDown()
void u25991uuu23383uuu21015uuu38651uuu21331uuMock_TestModel::TearDown()
{
}

// void 文字列電卓Mock_TestModel::VerifyExpectations()
void u25991uuu23383uuu21015uuu38651uuu21331uuMock_TestModel::VerifyExpectations()
{
}

// void 文字列電卓Mock_TestModel::Input(string input)
void u25991uuu23383uuu21015uuu38651uuu21331uuMock_TestModel::Input(string input)
{
    m_Calculator.Input(input);
    m_Calculator.CalculateSum();
}

// void 文字列電卓Mock_TestModel::ExpectedSum(int sum)
void u25991uuu23383uuu21015uuu38651uuu21331uuMock_TestModel::ExpectedSum(int sum)
{
    m_MockDisplay.ExpectSum(sum);
}
