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

#include "文字列電卓Mock_Steps.h"

// List of steps that match this function:
// <数字文字列>を入力する
// void 文字列電卓Mock_Steps::数字文字列を入力する(GherkinRow& row)
void u25991uuu23383uuu21015uuu38651uuu21331uuMock_Steps::u25968uuu23383uuu25991uuu23383uuu21015uuu12434uuu20837uuu21147uuu12377uuu12427uu(GherkinRow& row)
{
    model.Input(row[L"数字文字列"].strValue());
}

// List of steps that match this function:
// <合計>が通知されること[[mock]]
// void 文字列電卓Mock_Steps::合計が通知されることmock(GherkinRow& row)
void u25991uuu23383uuu21015uuu38651uuu21331uuMock_Steps::u21512uuu35336uuu12364uuu36890uuu30693uuu12373uuu12428uuu12427uuu12371uuu12392uumock(GherkinRow& row)
{
    model.ExpectedSum(row[L"合計"].intValue());
}


