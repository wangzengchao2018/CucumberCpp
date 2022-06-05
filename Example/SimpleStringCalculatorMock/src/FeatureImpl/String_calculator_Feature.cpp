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

#ifdef WIN32
// Disable warning C4819: The file contains a character that cannot be represented in the current code page
#pragma warning(disable : 4819)
// Disable warning C4800: 'int' : forcing value to bool 'true' or 'false'(performance warning)
#pragma warning(disable : 4800)
#endif

#include "FeatureTestModel.h"
#include "String_calculator_Steps.h"

class String_calculator_Feature : public FeatureTestModel
{
public:
    void SetUp() override
    {
        steps.SetUp();
        FeatureBackground();
    }
    void TearDown() override
    {
        steps.TearDown();
    }

protected:
    AbstractStepModel* GetStepModel() override
    {
        return &steps;
    }

    void FeatureBackground()
    {
    }

    void ExecuteTest()
    {
        steps.ExecuteTest();
    }

private:
    String_calculator_Steps steps;
};

class String_calculator_Feature_A_separator_can_be__comma_or_semicolon :
    public String_calculator_Feature,
    public WithParamInterface<GherkinRow>
{
public:
    void SetUp() override
    {
        String_calculator_Feature::SetUp();
        Spec("@guid-084139ff-dda8-440c-9941-f20a18464473");
    }
};

TEST_P(String_calculator_Feature_A_separator_can_be__comma_or_semicolon, ScenarioOutline)
{
    GherkinRow param = GetParam();

    Given(L"Enter <Numbers> with separator", param);
    When(L"Sum all the numbers");
    Then(L"The result should be <Sum>", param);
    ExecuteTest();
}

GherkinTable String_calculator_Feature_A_separator_can_be__comma_or_semicolon_1_ExampleTable(
        L"|Numbers  |Sum|\n"
        L"|1 + 2 + 3|6  |\n"
        L"|4, 5, 6  |15 |\n"
        L"|7; 8; 9  |24 |\n"
        L"|1, 2; 3  |0  |");

INSTANTIATE_TEST_CASE_P(
        String_calculator_Feature_0,
        String_calculator_Feature_A_separator_can_be__comma_or_semicolon,
        testing::ValuesIn(String_calculator_Feature_A_separator_can_be__comma_or_semicolon_1_ExampleTable.Rows()));


