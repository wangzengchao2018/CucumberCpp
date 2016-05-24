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

#pragma once

#include <string>
#include <vector>
#include "IVisitable.h"

namespace CucumberCpp
{
    class BDDFeatureBuilder;
    class BDDStepImplBuilderManager;

    class BDDASTVisitor : public GherkinAst::IVisitable
    {
    public:
        BDDASTVisitor(BDDFeatureBuilder& featureBuilder, BDDStepImplBuilderManager& stepImplBuilderManager);

        void Accept(GherkinAst::Feature& feature) override;
        void Accept(GherkinAst::Background& background) override;
        void Accept(GherkinAst::ScenarioOutline& scenarioOutline) override;
        void Accept(GherkinAst::Example& example) override;
        void Accept(GherkinAst::DataTable& dataTable) override;
        void Accept(GherkinAst::DocString& docString) override;
        void Accept(GherkinAst::Step& step) override;
        void Accept(GherkinAst::Scenario& scenario) override;
        void AcceptSenarioTags(std::vector<GherkinAst::Tag>& tags) override;

        /////// Not relevant functions of IVisitable //////

        void Accept(GherkinAst::Language& /*language*/)  override { }
        void Accept(std::vector<GherkinAst::Tag>& /*tags*/)  override { }

    private:
        BDDFeatureBuilder& m_FeatureBuilder;
        BDDStepImplBuilderManager& m_StepImplBuilderManager;
    };
}
