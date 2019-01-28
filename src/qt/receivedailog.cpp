#include "receivedailog.h"
#include "ui_receivedailog.h"

ReceiveDailog::ReceiveDailog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReceiveDailog)
{
    ui->setupUi(this);

    font_receive_dialog = new QFont();
    font_receive_dialog->setFamily("Chivo");
    font_receive_dialog->setBold(true);
    font_receive_dialog->setLetterSpacing(QFont::AbsoluteSpacing, 1.4);
    font_receive_dialog->setPixelSize(15);

    ui->label_uri->setFont(*font_receive_dialog);
    ui->label_address->setFont(*font_receive_dialog);
    ui->label_uri_value->setFont(*font_receive_dialog);
    ui->label_information->setFont(*font_receive_dialog);
    ui->label_address_value->setFont(*font_receive_dialog);
    ui->button_uri->setFont(*font_receive_dialog);
    ui->button_address->setFont(*font_receive_dialog);
    ui->button_remove->setFont(*font_receive_dialog);
}

ReceiveDailog::~ReceiveDailog()
{
    delete ui;
}

void ReceiveDailog::setIndex(int i)
{
    this->index = i;
}

void ReceiveDailog::on_button_uri_clicked()
{
    emit this->Close_Dialog();
}

void ReceiveDailog::on_button_address_clicked()
{
    emit this->Close_Dialog();
}

void ReceiveDailog::on_button_remove_clicked()
{
    emit this->Select_remove(this->index);

}
