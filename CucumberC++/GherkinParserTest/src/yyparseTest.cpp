﻿/* The MIT License (MIT)
 * 
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

#include <sstream>
#include <regex>
#include "IVisitable.h"
#include "Language.h"
#include "Tag.h"
#include "StepArgument.h"
#include "DocString.h"
#include "TableCell.h"
#include "TableRow.h"
#include "DataTable.h"
#include "ScenarioDefinition.h"
#include "ScenarioOutline.h"
#include "Example.h"
#include "GherkinParser.h"

using namespace std;
using namespace testing;
using namespace GherkinAst;

class yyparseTest : public testing::Test {
public:
    virtual void SetUp(){}
    virtual void TearDown(){}

    Feature& CurrentFeature(GherkinParser& parser)
    {
        return *(parser.astBuilder().Feature());
    }

protected:
    Language    actualLanguage;
    vector<Tag> actualTags;
    GherkinParser parser;
};

TEST_F(yyparseTest, Language_Parsing)
{
    // Given
    wistringstream is{
        L"# language: en\n"
        L"Feature: title"
    };

    // When
    bool res = parser.parse(is);

    // Then
    ASSERT_FALSE(res);
    Language* language = CurrentFeature(parser).Language();
    ASSERT_EQ(wstring(L"en"), language->Value());
}

TEST_F(yyparseTest, Tag_Parsing)
{
    // Given
    wistringstream is{
        L"# language: en\n"
        L"@testTag\n"
        L"Feature: title"
    };

    // When
    parser.parse(is);

    // Then
    Feature& feature = CurrentFeature(parser);
    ASSERT_EQ(1, feature.Tags().size());
    ASSERT_EQ(wstring(L"@testTag"), feature.Tags()[0].Name());
}

TEST_F(yyparseTest, Tags_2_lines)
{
    // Given
    wistringstream is{
        L"@testTag1\n"
        L"@testTag2\n"
        L"Feature: title"
    };

    // When
    parser.parse(is);

    // Then
    Feature& feature = CurrentFeature(parser);
    ASSERT_EQ(2, feature.Tags().size());
    ASSERT_EQ(wstring(L"@testTag1"), feature.Tags()[0].Name());
    ASSERT_EQ(wstring(L"@testTag2"), feature.Tags()[1].Name());
}

TEST_F(yyparseTest, FeatureTitle)
{
    // Given
    wistringstream is{
        L"@testTag\n"
        L"Feature: 機能概要"
    };

    // When
    parser.parse(is);

    // Then
    Feature& feature = CurrentFeature(parser);
    ASSERT_EQ(wstring(L"機能概要"), feature.Title());
    ASSERT_EQ(2, feature.Location().Line());
}

TEST_F(yyparseTest, FeatureDescription)
{
    // Given
    wistringstream is{
        L"@testTag\n"
        L"Feature: 機能概要\n"
        L"Featureの機能説明1\n"
        L"Featureの機能説明2"
    };

    // When
    parser.parse(is);

    // Then
    Feature& feature = CurrentFeature(parser);
    wstring desc{
        L"Featureの機能説明1\n"
        L"Featureの機能説明2"
    };
    ASSERT_EQ(desc, feature.Description());
}

TEST_F(yyparseTest, FeatureEmptyDescription)
{
    // Given
    wistringstream is{
        L"@testTag\n"
        L"Feature: 機能概要"
    };

    // When
    parser.parse(is);

    // Then
    Feature& feature = CurrentFeature(parser);
    ASSERT_EQ(wstring(), feature.Description());
}

TEST_F(yyparseTest, Background_no_title)
{
    // Given
    wistringstream is{
        L"Feature: 機能概要\n"
        L"機能説明\n"
        L"Background :\n"
        L"  Given 前提条件"
    };

    // When
    parser.parse(is);

    // Then
    Background* background = CurrentFeature(parser).Background();
    ASSERT_EQ(wstring(), background->Title());
    ASSERT_EQ(3, background->Location().Line());
}

TEST_F(yyparseTest, Background_have_title)
{
    // Given
    wistringstream is{
        L"Feature: 機能概要\n"
        L"機能説明\n"
        L"Background : title\n"
        L"  Given 前提条件"
    };

    // When
    parser.parse(is);

    // Then
    Background* background = CurrentFeature(parser).Background();
    ASSERT_EQ(wstring(L"title"), background->Title());
}

TEST_F(yyparseTest, Scenario_with_background)
{
    // Given
    wistringstream is{
        L"Feature: 機能概要\n"
        L"機能説明\n"
        L"Background : title\n"
        L" 前提条件説明\n"
        L"  Given 前提条件\n"
        L"@guid-xxxxx\n"
        L"Scenario: s1\n"
        L"  When 動作\n"
    };

    // When
    bool success = parser.parse(is);

    // Then
    ASSERT_TRUE(success);
}

TEST_F(yyparseTest, Feature_with_empty_line)
{
    // Given
    wistringstream is{
        L"Feature: feature title\n\n"
        L"Background : background title\n"
        L"Description of background\n"
        L"Given precondition\n\n"
        L"@guid-xxxxx\n"
        L"Scenario : title\n"
        L"When action\n"
    };

    // When
    bool success = parser.parse(is);

    // Then
    ASSERT_TRUE(success);
}

TEST_F(yyparseTest, Step)
{
    // Given
    wistringstream is{
        L"Feature: 機能概要\n"
        L"Background : title\n"
        L"  Given 前提条件"
    };

    // When
    parser.parse(is);

    // Then
    Background* background = CurrentFeature(parser).Background();
    std::vector<GherkinAst::Step>& steps = background->Steps();

    ASSERT_EQ(1, steps.size());
    ASSERT_EQ(wstring(L"Given"), steps[0].Keyword());
    ASSERT_EQ(wstring(L"前提条件"), steps[0].Text());
}

TEST_F(yyparseTest, MultiSteps)
{
    // Given
    wistringstream is{
        L"Feature: 機能概要\n"
        L"Background : title\n"
        L"  Given 前提条件\n"
        L"  When 動作"
    };

    // When
    parser.parse(is);

    // Then
    Background* background = CurrentFeature(parser).Background();
    std::vector<GherkinAst::Step>& steps = background->Steps();

    ASSERT_EQ(2, steps.size());
    ASSERT_EQ(wstring(L"Given"), steps[0].Keyword());
    ASSERT_EQ(wstring(L"前提条件"), steps[0].Text());
    ASSERT_EQ(wstring(L"When"), steps[1].Keyword());
    ASSERT_EQ(wstring(L"動作"), steps[1].Text());
}

TEST_F(yyparseTest, StepDocString)
{
    // Given
    wistringstream is{
        L"Feature: 機能概要\n"
        L"Background : title\n"
        L"  Given 前提条件\n"
        L"\"\"\" jason\n"
        L"  1st line\n"
        L"  2nd line\n"
        L"\"\"\"\n"
    };

    // When
    parser.parse(is);

    // Then
    Background* background = CurrentFeature(parser).Background();
    std::vector<GherkinAst::Step>& steps = background->Steps();
    ASSERT_EQ(1, steps.size());

    GherkinAst::StepArgument* pArg = steps[0].StepArgument();
    GherkinAst::DocString* pDocStr = dynamic_cast<GherkinAst::DocString*>(pArg);
    ASSERT_TRUE(pDocStr != nullptr);
    wstring doc_str {
        L"  1st line\n"
        L"  2nd line"
    };

    ASSERT_EQ(doc_str, pDocStr->Content());
    ASSERT_EQ(wstring(L"jason"), pDocStr->ContentType());
}

TEST_F(yyparseTest, StepDataTable)
{
    // Given
    wistringstream is{
        L"Feature: 機能概要\n"
        L"Background : title\n"
        L"  Given 前提条件\n"
        L"|col1|col2|\n"
        L"|v1  |v2  |"
    };

    // When
    parser.parse(is);

    // Then
    Background* background = CurrentFeature(parser).Background();
    std::vector<GherkinAst::Step>& steps = background->Steps();
    ASSERT_EQ(1, steps.size());

    GherkinAst::StepArgument* pArg = steps[0].StepArgument();
    GherkinAst::DataTable* pDataTable = dynamic_cast<GherkinAst::DataTable*>(pArg);
    ASSERT_TRUE(pDataTable != nullptr);
    std::vector<TableRow>& rows = pDataTable->Rows();
    ASSERT_EQ(2, rows.size());
    ASSERT_EQ(wstring(L"col1"), rows[0][0].Value());
    ASSERT_EQ(wstring(L"v2"), rows[1][1].Value());
}

TEST_F(yyparseTest, StepDataTable_inconsistent_col)
{
    // Given
    wistringstream is{
        L"Feature: 機能概要\n"
        L"Background : title\n"
        L"  Given 前提条件\n"
        L"|col1|col2|\n"
        L"|v1  |"
    };

    // When
    parser.parse(is);

    // Then
    ASSERT_TRUE(true);  // TableColumnsInconsistent exception should not be thrown
}

TEST_F(yyparseTest, Scenario)
{
    // Given
    wistringstream is{
        L"Feature: 機能概要\n"
        L"Scenario : title\n"
        L"説明文1\n"
        L"説明文2\n"
        L"  Given 前提条件"
    };

    // When
    parser.parse(is);

    // Then
    Feature& feature = CurrentFeature(parser);
    std::vector<ScenarioDefinition*>& scenarios = feature.ScenarioDefinitions();
    ASSERT_EQ(1, scenarios.size());
    ASSERT_EQ(wstring(L"Scenario"), scenarios[0]->Keyword());
    ASSERT_EQ(wstring(L"title"), scenarios[0]->Title());
    ASSERT_EQ(wstring(L"説明文1\n説明文2"), scenarios[0]->Description());
}

TEST_F(yyparseTest, ScenarioOutline)
{
    // Given
    wistringstream is{
        L"Feature: 機能概要\n"
        L"Scenario Outline: title\n"
        L"説明文1\n"
        L"説明文2\n"
        L"  Given 前提条件\n"
        L"Examples :\n"
        L"|col1|col2|\n"
        L"|v1  |v2  |"
    };

    // When
    parser.parse(is);

    // Then
    Feature& feature = CurrentFeature(parser);
    std::vector<ScenarioDefinition*>& scenarios = feature.ScenarioDefinitions();
    ASSERT_EQ(1, scenarios.size());

    ScenarioOutline* scenario_outline = dynamic_cast<ScenarioOutline*>(scenarios[0]);
    ASSERT_EQ(wstring(L"Scenario Outline"), scenario_outline->Keyword());
    ASSERT_EQ(wstring(L"title"), scenario_outline->Title());
    ASSERT_EQ(wstring(L"説明文1\n説明文2"), scenario_outline->Description());
}

TEST_F(yyparseTest, ScenarioOutline_Examples)
{
    // Given
    wistringstream is{
        L"Feature: 機能概要\n"
        L"Scenario Outline: title\n"
        L"説明文1\n"
        L"説明文2\n"
        L"  Given 前提条件\n"
        L"Examples :\n"
        L"|col1|col2|\n"
        L"|v1  |v2  |"
    };

    // When
    parser.parse(is);

    // Then
    Feature& feature = CurrentFeature(parser);
    std::vector<ScenarioDefinition*>& scenarios = feature.ScenarioDefinitions();
    ASSERT_EQ(1, scenarios.size());
    ScenarioOutline* scenario_outline = dynamic_cast<ScenarioOutline*>(scenarios[0]);
    std::vector<GherkinAst::Example*>& examples = scenario_outline->Examples();
    ASSERT_EQ(1, examples.size());
    ASSERT_EQ(wstring(L"Examples"), examples[0]->Keyword());
    DataTable& dataTable = examples[0]->ExampleTable();
    std::vector<TableRow>& rows = dataTable.Rows();
    ASSERT_EQ(2, rows.size());
    ASSERT_EQ(wstring(L"col1"), rows[0][0].Value());
    ASSERT_EQ(wstring(L"v2"), rows[1][1].Value());
}

TEST_F(yyparseTest, ScenarioOutline_MultiExamples)
{
    // Given
    wistringstream is{
        L"Feature: 機能概要\n"
        L"Scenario Outline: title\n"
        L"説明文1\n"
        L"説明文2\n"
        L"  Given 前提条件\n"
        L"Examples :\n"
        L"|col1|col2|\n"
        L"|v1  |v2  |\n"
        L"Examples :サンプルデータ\n"
        L"|col1|col2|\n"
        L"|v1  |v2  |\n"
    };

    // When
    parser.parse(is);

    // Then
    Feature& feature = CurrentFeature(parser);
    std::vector<ScenarioDefinition*>& scenarios = feature.ScenarioDefinitions();
    ScenarioOutline* scenario_outline = dynamic_cast<ScenarioOutline*>(scenarios[0]);
    std::vector<GherkinAst::Example*>& examples = scenario_outline->Examples();
    ASSERT_EQ(2, examples.size());
    ASSERT_EQ(wstring(), examples[0]->Title());
    ASSERT_EQ(wstring(L"サンプルデータ"), examples[1]->Title());
}

TEST_F(yyparseTest, ScenarioOutline_Examples_inconsistent_col)
{
    // Given
    wistringstream is{
        L"Feature: 機能概要\n"
        L"Scenario Outline: title\n"
        L"説明文1\n"
        L"説明文2\n"
        L"  Given 前提条件\n"
        L"Examples :\n"
        L"|col1|\n"
        L"|v1  |v2  |"
    };

    // When
    parser.parse(is);

    // Then
    ASSERT_TRUE(true);  // TableColumnsInconsistent exception should not be thrown
}
