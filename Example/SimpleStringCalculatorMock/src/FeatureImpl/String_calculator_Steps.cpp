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

#include "String_calculator_Steps.h"

// List of steps that match this function:
// Enter <Numbers> with separator
void String_calculator_Steps::Enter_Numbers_with_separator(GherkinRow& row)
{
    model.Input(row[L"Numbers"].strValue());
}

// List of steps that match this function:
// Sum all the numbers
void String_calculator_Steps::Sum_all_the_numbers()
{
    model.Sum();
}

// List of steps that match this function:
// The result should be <Sum>
void String_calculator_Steps::The_result_should_be_Sum(GherkinRow& row)
{
    model.ExpectedSum(row[L"Sum"].intValue());
}


