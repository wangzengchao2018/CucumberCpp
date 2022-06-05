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
#include "String_calculator_using_mock_object_Steps.h"

class String_calculator_using_mock_object_Feature : public FeatureTestModel
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
    String_calculator_using_mock_object_Steps steps;
};

class String_calculator_using_mock_object_Feature_A_separator_can_be__comma_or_semicolon :
    public String_calculator_using_mock_object_Feature,
    public WithParamInterface<GherkinRow>
{
public:
    void SetUp() override
    {
        String_calculator_using_mock_object_Feature::SetUp();
        Spec("@guid-08173785-8ecc-3427-5807-f4d184e28ae8");
    }
};

TEST_P(String_calculator_using_mock_object_Feature_A_separator_can_be__comma_or_semicolon, ScenarioOutline)
{
    GherkinRow param = GetParam();

    Then(L"The result <Sum> shall be informed[[mock]]", param);
    When(L"Input <Numbers>", param);
    ExecuteTest();
}

GherkinTable String_calculator_using_mock_object_Feature_A_separator_can_be__comma_or_semicolon_1_ExampleTable(
        L"|Numbers  |Sum|\n"
        L"|1 + 2 + 3|6  |\n"
        L"|4, 5, 6  |15 |\n"
        L"|7; 8; 9  |24 |\n"
        L"|1, 2; 3  |0  |");

INSTANTIATE_TEST_CASE_P(
        String_calculator_using_mock_object_Feature_0,
        String_calculator_using_mock_object_Feature_A_separator_can_be__comma_or_semicolon,
        testing::ValuesIn(String_calculator_using_mock_object_Feature_A_separator_can_be__comma_or_semicolon_1_ExampleTable.Rows()));


