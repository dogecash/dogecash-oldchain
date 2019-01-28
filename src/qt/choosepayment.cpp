#include "choosepayment.h"
#include "ui_choosepayment.h"
#include <labelbutton.h>
#include <QDebug>

ChoosePayment::ChoosePayment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChoosePayment)
{
    ui->setupUi(this);
    loadPage();

    font_choose_alias = new QFont();
    font_choose_alias->setFamily("Chivo");
    font_choose_alias->setPixelSize(13);
    font_choose_alias->setLetterSpacing(QFont::AbsoluteSpacing, 1.2);
//    ui->label_notify->setFont(*font_choose_alias);
    ui->label_notify->setStyleSheet("background-color: transparent; color: white");
    font_dialog = new QFont();
    font_dialog->setFamily("Chivo");
    font_dialog->setPixelSize(15);
    font_dialog->setLetterSpacing(QFont::AbsoluteSpacing, 1.4);
    font_dialog->setBold(true);
    ui->label_notify->setFont(*font_dialog);
    ui->button_new->setFont(*font_dialog);
    ui->button_copy-> setFont(*font_dialog);
    ui->button_delete->setFont(*font_dialog);
    ui->button_choose-> setFont(*font_dialog);

    loadTable();
}

ChoosePayment::~ChoosePayment()
{
    delete ui;
}

void ChoosePayment::loadPage()
{
    widget_table = new QWidget();
    widget_table->setStyleSheet("background-color: blue");
    widget_table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    scrollArea = new QScrollArea();
    scrollArea->setWidget(widget_table);
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet("background-color: transparent; ");
    scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setGeometry(0,0,10,10);

    h_layout = new QHBoxLayout();

    loGrid = new QGridLayout();
    loGrid->setMargin(0);
    loGrid->setContentsMargins(0,0,0,0);
    loGrid->setVerticalSpacing(0);
    loGrid->setHorizontalSpacing(0);
    widget_table->setLayout(loGrid);
    ui->widget_main->setLayout(new QHBoxLayout());
    ui->widget_main->layout()->addWidget(scrollArea);
    ui->widget_main->layout()->setMargin(0);
    ui->widget_main->layout()->setContentsMargins(0,0,0,0);
    ui->widget_main->layout()->setSpacing(0);
    ui->widget_main->setStyleSheet("background-color: transparent");
}

void ChoosePayment::loadTable()
{
    label_label_header = new QLabel();
    label_label_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 11px");
    label_label_header->setMinimumHeight(41);
    label_label_header->setMaximumHeight(41);
    label_label_header->setMaximumWidth(150);
    label_label_header->setMinimumWidth(150);
    label_alias_header = new QLabel();
    label_alias_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 11px");
    label_alias_header->setMinimumHeight(41);
    label_alias_header->setMaximumHeight(41);
    label_label_header->setText("LABEL");
    label_alias_header->setText("ALIAS");
    label_label_header->setFont(*font_choose_alias);
    label_alias_header->setFont(*font_choose_alias);

    loGrid->addWidget(label_label_header, 0, 0);
    loGrid->addWidget(label_alias_header, 0, 1);

    count = 5;
    label_label_body = new QLabel*[count];
    label_alias_body = new QLabel*[count];
    for (int i = 0; i < count; i++) {
        label_label_body[i] = new LabelButton(this, i);
        label_label_body[i]->setText("(No Label)" + QString::number(i));
        label_label_body[i]->setMaximumHeight(29);
        label_label_body[i]->setMinimumHeight(29);
        label_alias_body[i] = new LabelButton(this, i);
        label_alias_body[i]->setMaximumHeight(29);
        label_alias_body[i]->setText("DQ68xWwN8mkU8cJDLvP6HK434qUptCH68v  : " + QString::number(i) );
        label_alias_body[i]->setMinimumHeight(29);
        label_label_body[i]->setFont(*font_choose_alias);
        label_alias_body[i]->setFont(*font_choose_alias);
        if (i % 2 == 0) {
            label_label_body[i]->setStyleSheet("background-color: #2a3036; color: white; padding-top: 8px; padding-bottom-8px;");
            label_alias_body[i]->setStyleSheet("background-color: #2a3036; color: white;  padding-top: 8px; padding-bottom-8px;");
        } else {
            label_label_body[i]->setStyleSheet("background-color: #1f272e; color: white; padding-top: 8px; padding-bottom-8px;");
            label_alias_body[i]->setStyleSheet("background-color: #1f272e; color: white; padding-top: 8px; padding-bottom-8px;");
        }
        loGrid->addWidget(label_alias_body[i], i+1, 1);
        loGrid->addWidget(label_label_body[i], i+1, 0);
        connect(label_label_body[i], SIGNAL(Clicked(int)), SLOT(select_item(int )));
        connect(label_label_body[i], SIGNAL(Entered(int)), SLOT(hoverd_row(int)));
        connect(label_label_body[i], SIGNAL(Leaved(int)), SLOT(leaved_row(int)));
        connect(label_alias_body[i], SIGNAL(Clicked(int)), SLOT(select_item(int )));
        connect(label_alias_body[i], SIGNAL(Entered(int)), SLOT(hoverd_row(int)));
        connect(label_alias_body[i], SIGNAL(Leaved(int)), SLOT(leaved_row(int)));
    }
}

void ChoosePayment::select_item(int i)
{
    for (int i = 0; i < count; i++ ){
        if (i % 2 == 0) {
            label_label_body[i]->setStyleSheet("background-color: #2a3036; color: white; padding-top: 8px; padding-bottom-8px;");
            label_alias_body[i]->setStyleSheet("background-color: #2a3036; color: white;  padding-top: 8px; padding-bottom-8px;");
        } else {
            label_label_body[i]->setStyleSheet("background-color: #1f272e; color: white; padding-top: 8px; padding-bottom-8px;");
            label_alias_body[i]->setStyleSheet("background-color: #1f272e; color: white; padding-top: 8px; padding-bottom-8px;");
        }
    }
    label_alias_body[i]->setStyleSheet("background-color: #b99d7c; color: #1f272e; padding-top: 8px; padding-bottom: 8px; padding-left: 20px");
    label_label_body[i]->setStyleSheet("background-color: #b99d7c; color: #1f272e; padding-top: 8px; padding-bottom: 8px; padding-left: 20px");
}

void ChoosePayment::hoverd_row(int i)
{
    if (label_alias_body[i]->styleSheet() == "background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 20px" or
            label_alias_body[i]->styleSheet() == "background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 20px" ) {
        label_alias_body[i]->setStyleSheet("background-color: #b99d7c; color: #1f272e; padding-top: 8px; padding-bottom: 8px; padding-left: 20px");
        label_label_body[i]->setStyleSheet("background-color: #b99d7c; color: #1f272e; padding-top: 8px; padding-bottom: 8px; padding-left: 20px");
        qDebug()<<"Ello"<<endl;
    } else {
        label_alias_body[i]->setStyleSheet("background-color: #b99d7c; color: #1f272e; padding-top: 8px; padding-bottom: 8px;");
        label_label_body[i]->setStyleSheet("background-color: #b99d7c; color: #1f272e; padding-top: 8px; padding-bottom: 8px;");
        qDebug()<<"Send"<<endl;
    }
}

void ChoosePayment::leaved_row(int i)
{
    if (i % 2 == 0){
        if (label_alias_body[i]->styleSheet() == "background-color: #b99d7c; color: #1f272e; padding-top: 8px; padding-bottom: 8px; padding-left: 20px"){
            label_alias_body[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 20px");
            label_label_body[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 20px");
            qDebug()<<"2 and padding"<<endl;
        } else {
            label_alias_body[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px;");
            label_label_body[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px;");
            qDebug() << "2 nopadding"<<endl;
        }
    } else {
        if (label_alias_body[i]->styleSheet() == "background-color: #b99d7c; color: #1f272e; padding-top: 8px; padding-bottom: 8px; padding-left: 20px"){
            label_alias_body[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 20px");
            label_label_body[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 20px");
            qDebug()<< "padding"<<endl;
        } else {
            label_alias_body[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; ");
            label_label_body[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; ");
            qDebug()<<"nopadding"<<endl;
        }
    }

}

void ChoosePayment::on_button_choose_clicked()
{
    for (int i = 0; i< count; i++) {
        if (label_alias_body[i]->styleSheet().indexOf("padding-left: 20px") >=0) {
            emit Selected_alias(label_alias_body[i]->text());
        }
    }
}

void ChoosePayment::on_button_new_clicked()
{
    emit Close_dialog();
}

void ChoosePayment::on_button_copy_clicked()
{
    emit Close_dialog();
}

void ChoosePayment::on_button_delete_clicked()
{
    emit Close_dialog();
}
