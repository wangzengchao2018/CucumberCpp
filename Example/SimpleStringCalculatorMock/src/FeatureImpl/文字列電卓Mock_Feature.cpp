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
#include "文字列電卓Mock_Steps.h"

// class 文字列電卓Mock_Feature : public FeatureTestModel
class u25991uuu23383uuu21015uuu38651uuu21331uuMock_Feature : public FeatureTestModel
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
    // 文字列電卓Mock_Steps steps;
    u25991uuu23383uuu21015uuu38651uuu21331uuMock_Steps steps;
};

// class 文字列電卓Mock_Feature_数字文字列の合計 :
class u25991uuu23383uuu21015uuu38651uuu21331uuMock_Feature_u25968uuu23383uuu25991uuu23383uuu21015uuu12398uuu21512uuu35336uu :
    // public 文字列電卓Mock_Feature,
    public u25991uuu23383uuu21015uuu38651uuu21331uuMock_Feature,
    public WithParamInterface<GherkinRow>
{
public:
    void SetUp() override
    {
        // 文字列電卓Mock_Feature::SetUp();
        u25991uuu23383uuu21015uuu38651uuu21331uuMock_Feature::SetUp();
        Spec("@guid-05692578-2ff0-d490-487b-473121d9acfa");
    }
};

// TEST_P(文字列電卓Mock_Feature_数字文字列の合計, ScenarioOutline)
TEST_P(u25991uuu23383uuu21015uuu38651uuu21331uuMock_Feature_u25968uuu23383uuu25991uuu23383uuu21015uuu12398uuu21512uuu35336uu, ScenarioOutline)
{
    GherkinRow param = GetParam();

    Then(L"<合計>が通知されること[[mock]]", param);
    When(L"<数字文字列>を入力する", param);
    ExecuteTest();
}

// GherkinTable 文字列電卓Mock_Feature_数字文字列の合計_1_ExampleTable(
GherkinTable u25991uuu23383uuu21015uuu38651uuu21331uuMock_Feature_u25968uuu23383uuu25991uuu23383uuu21015uuu12398uuu21512uuu35336uu_1_ExampleTable(
        L"|数字文字列  |合計|\n"
        L"|            |0   |\n"
        L"|18          |18  |\n"
        L"|1 + 2 + 3   |6   |\n"
        L"|4, 5, 6     |15  |\n"
        L"|7; 8; 9     |24  |\n"
        L"|1, 2; 3     |0   |\n"
        L"|a1 + a2 + a3|0   |");

INSTANTIATE_TEST_CASE_P(
        // 文字列電卓Mock_Feature_0,
        u25991uuu23383uuu21015uuu38651uuu21331uuMock_Feature_0,
        // 文字列電卓Mock_Feature_数字文字列の合計,
        u25991uuu23383uuu21015uuu38651uuu21331uuMock_Feature_u25968uuu23383uuu25991uuu23383uuu21015uuu12398uuu21512uuu35336uu,
        // testing::ValuesIn(文字列電卓Mock_Feature_数字文字列の合計_1_ExampleTable.Rows()));
        testing::ValuesIn(u25991uuu23383uuu21015uuu38651uuu21331uuMock_Feature_u25968uuu23383uuu25991uuu23383uuu21015uuu12398uuu21512uuu35336uu_1_ExampleTable.Rows()));


