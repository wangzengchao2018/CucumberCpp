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

#include "MockDisplay.h"
#include "StringCalculator.h"

using namespace testing;

class StringCalculatorTest : public testing::Test
{
public:
    StringCalculator calculator;
};

//TEST_F(StringCalculatorTest, 初期状態)
TEST_F(StringCalculatorTest, initial_state)
{
    // Given
    
	// When
    int result = calculator.CalculateSum();

	// Then
    ASSERT_EQ(0, result);
}

//TEST_F(StringCalculatorTest, 数字一個)
TEST_F(StringCalculatorTest, one_number)
{
    // Given
    calculator.Input("18");

    // When
    int result = calculator.CalculateSum();

    // Then
    ASSERT_EQ(18, result);
}

//TEST_F(StringCalculatorTest, 区切り文字がプラス記号)
TEST_F(StringCalculatorTest, the_delimiter_is_a_plus_sign)
{
    // Given
    calculator.Input("1 + 2 + 3");

    // When
    int result = calculator.CalculateSum();

    // Then
    ASSERT_EQ(6, result);
}

//TEST_F(StringCalculatorTest, MockObjectの使用)
TEST_F(StringCalculatorTest, using_MockObject)
{
    // Given
    MockDisplay mock;
    StringCalculator calc{ &mock };
    calc.Input("1 + 2 + 3");

    // When
//    EXPECT_CALL(mock, Sum(6));
    mock.ExpectSum(6);   // ここが簡略されました

    calc.CalculateSum();

    // Then
}
