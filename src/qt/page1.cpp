#include "page1.h"
#include "ui_page1.h"

page1::page1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page1)
{
    ui->setupUi(this);
    this->setFont();
}

page1::~page1()
{
    delete ui;
}
void page1::setFont() {
    font_label_main = new QFont();
    font_label_total_value = new QFont();

    font_label_main->setPixelSize(15);
    font_label_main->setLetterSpacing(QFont::AbsoluteSpacing, 1.4);
    font_label_main->setFamily("Chivo");
    font_label_main->setBold(true);

    ui->label_total->setFont(*font_label_main);
    ui->label_immature->setFont(*font_label_main);
    ui->label_available->setFont(*font_label_main);
    ui->label_immature_value->setFont(*font_label_main);
    ui->label_available_value->setFont(*font_label_main);

    font_label_total_value->setPixelSize(114);
    font_label_total_value->setLetterSpacing(QFont::AbsoluteSpacing, 3.8);
    font_label_total_value->setFamily("Chapaza");

    ui->label_total_value->setFont(*font_label_total_value);

}
