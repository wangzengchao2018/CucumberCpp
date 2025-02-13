/*
 * Copyright (C) 2009  Lorenzo Bettini <http://www.lorenzobettini.it>
 * See COPYING file that comes with this distribution
 */

#include <QPlainTextEdit>
#include "FindDialog.h"
#include "ui_findreplacedialog.h"

FindDialog::FindDialog(QPlainTextEdit *pTextEdit) :
    FindReplaceDialog(pTextEdit)
{
    ui->findReplaceForm->hideReplaceWidgets();
    setWindowTitle(tr("Find"));
    ui->findReplaceForm->setTextEdit(pTextEdit);

    setModal(false);
}

FindDialog::~FindDialog()
{
}

void FindDialog::writeSettings(QSettings &settings, const QString &prefix) {
    FindReplaceDialog::writeSettings(settings, prefix);
}

void FindDialog::readSettings(QSettings &settings, const QString &prefix) {
    FindReplaceDialog::readSettings(settings, prefix);
}
