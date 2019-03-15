// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "transactiondescdialog.h"
#include "guiutil.h"
#include "ui_transactiondescdialog.h"

#include "transactiontablemodel.h"

#include <QModelIndex>
#include <QSettings>
#include <QString>
#include <QPushButton>

TransactionDescDialog::TransactionDescDialog(const QModelIndex& idx, QWidget* parent) : QDialog(parent),
                                                                                        ui(new Ui::TransactionDescDialog)
{
    ui->setupUi(this);

    /* Open CSS when configured */
    this->setStyleSheet(GUIUtil::loadStyleSheet());

    QString desc = idx.data(TransactionTableModel::LongDescriptionRole).toString();
    ui->detailText->setHtml(desc);

   // QPushButton * cancelButton = ui->buttonBox->button(QDialogButtonBox::Cancel);
   // cancelButton->setIcon(QIcon());
}

TransactionDescDialog::~TransactionDescDialog()
{
    delete ui;
}
