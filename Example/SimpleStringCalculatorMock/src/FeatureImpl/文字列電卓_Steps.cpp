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

#include "文字列電卓_Steps.h"

// List of steps that match this function:
// <数字文字列>がある
// void 文字列電卓_Steps::数字文字列がある(GherkinRow& row)
void u25991uuu23383uuu21015uuu38651uuu21331uu_Steps::u25968uuu23383uuu25991uuu23383uuu21015uuu12364uuu12354uuu12427uu(GherkinRow& row)
{
    model.Input(row[L"数字文字列"].strValue());
}

// List of steps that match this function:
// 数字を合計する
// void 文字列電卓_Steps::数字を合計する()
void u25991uuu23383uuu21015uuu38651uuu21331uu_Steps::u25968uuu23383uuu12434uuu21512uuu35336uuu12377uuu12427uu()
{
    model.CalculateSum();
}

// List of steps that match this function:
// 期待結果は<合計>であること
// void 文字列電卓_Steps::期待結果は合計であること(GherkinRow& row)
void u25991uuu23383uuu21015uuu38651uuu21331uu_Steps::u26399uuu24453uuu32080uuu26524uuu12399uuu21512uuu35336uuu12391uuu12354uuu12427uuu12371uuu12392uu(GherkinRow& row)
{
    model.ExpectedSum(row[L"合計"].intValue());
}


