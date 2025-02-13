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

#include "Definitions.h"
#include "PrettyTableRow.h"
#include "PrettyTableCell.h"
#include "PrettyGherkinDef.h"
#include "PrettyTableRowFormatter.h"

using namespace std;
using namespace GherkinAst;

wstring PrettyTableRowFormatter::Format(std::vector<int> preferedCellsWidth)
{
    wstring formattingText{ GetIndent() };
    formattingText.append(FormatRow(preferedCellsWidth));

    return formattingText;
}

wstring PrettyTableRowFormatter::FormatRow(std::vector<int> preferedCellsWidth)
{
    wstring rowBuilder;
    int index = 0;
    for (PrettyTableCell& tableCell : m_Context.Cells())
    {
        rowBuilder
            .append(CELLL_SEPARATOR)
            .append(GetCellValue(tableCell, preferedCellsWidth[index]));
        index++;
    }
    rowBuilder.append(CELLL_SEPARATOR);

    return rowBuilder;
}

wstring PrettyTableRowFormatter4GoogleTest::GetCellValue(PrettyTableCell& cell, int preferedWidth)
{
    return cell.TrimmedValue(preferedWidth);
}

wstring PrettyTableRowFormatter4Feature::GetIndent()
{
    return STEPARG_INDENT;
}

wstring PrettyTableRowFormatter4Feature::GetCellValue(PrettyTableCell& cell, int preferedWidth)
{
    return cell.OriginalValue(preferedWidth);
}
