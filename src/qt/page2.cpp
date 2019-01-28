#include "page2.h"
#include "ui_page2.h"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <labelbutton.h>

Page2::Page2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page2)
{
    ui->setupUi(this);

    swiftx_toggle = new ToggleSwitch();
    label_advance = new LabelButton(this);
    label_advance->setText("ADVANCED");
    label_advance->setStyleSheet("background-color: transparent; color: white");
    ui->widget_advance->setLayout(new QHBoxLayout());
    ui->widget_advance->layout()->setMargin(0);
    ui->widget_advance->layout()->setContentsMargins(0,0,0,0);
    ui->widget_advance->layout()->addWidget(label_advance);
    ui->widget_advance->setStyleSheet("background-color: transparent");
    connect(label_advance, SIGNAL(Selected()), SLOT(label_clicked()));


    this->load_toogle_button();
    this->setFont_page2();
    this->prepare_opacity_page2();
    this->unset_opacity_page2();
//    this->set_opacity_page2();

}

Page2::~Page2()
{
    delete ui;
}

void Page2::load_toogle_button(){

        swiftx_toggle->setParent(this);
        ui->swiftx_toogle_layout->addWidget(swiftx_toggle);
        swiftx_toggle->setGeometry(30,30,68,28);
        swiftx_toggle->show();

}
void Page2::setFont_page2(){
    font_label_main2 = new QFont();
    font_label_main2->setFamily("Chivo");
    font_label_main2->setBold(true);
    font_label_main2->setLetterSpacing(QFont::AbsoluteSpacing, 1.4);
    font_label_main2->setPixelSize(15);
    ui->label_pay->setFont(*font_label_main2);

    ui->edit_pay_value->setFont(*font_label_main2);
    ui->label_amount->setFont(*font_label_main2);
    ui->edit_amount_value->setFont(*font_label_main2);
    ui->label_label->setFont(*font_label_main2);
    ui->edit_label_value->setFont(*font_label_main2);
    ui->button_send->setFont(*font_label_main2);

    font_little2 = new QFont();
    font_little2->setFamily("Chivo");
    font_little2->setLetterSpacing(QFont::AbsoluteSpacing, 1.2);
    font_little2->setPixelSize(13);
//    ui->label_advance->setFont(*font_little2);
    ui->label_swiftx->setFont(*font_little2);
    label_advance->setFont(*font_little2);
}

void Page2::prepare_opacity_page2() {
    opacity_label_pay = new QGraphicsOpacityEffect(this);
    opacity_label_pay->setOpacity(0.2);
    ui->label_pay->setGraphicsEffect(opacity_label_pay);
    opacity_widget_pay = new QGraphicsOpacityEffect(this);
    opacity_widget_pay->setOpacity(0.2);
    ui->widget_pay->setGraphicsEffect(opacity_widget_pay);
    opacity_label_label = new QGraphicsOpacityEffect(this);
    opacity_label_label->setOpacity(0.2);
    ui->label_label->setGraphicsEffect(opacity_label_label);
    opacity_edit_label_value = new QGraphicsOpacityEffect(this);
    opacity_edit_label_value->setOpacity(0.2);
    ui->edit_label_value->setGraphicsEffect(opacity_edit_label_value);
    opacity_label_amount = new QGraphicsOpacityEffect(this);
    opacity_label_amount->setOpacity(0.2);
    ui->label_amount->setGraphicsEffect(opacity_label_amount);
    opacity_edit_amount_value = new QGraphicsOpacityEffect(this);
    opacity_edit_amount_value->setOpacity(0.2);
    ui->edit_amount_value->setGraphicsEffect(opacity_edit_amount_value);
    opacity_button_send = new QGraphicsOpacityEffect(this);
    opacity_button_send->setOpacity(0.2);
    ui->button_send->setGraphicsEffect(opacity_button_send);
    opacity_label_swiftx = new QGraphicsOpacityEffect(this);
    opacity_label_swiftx->setOpacity(0.2);
    ui->label_swiftx->setGraphicsEffect(opacity_label_swiftx);
    opacity_label_advance = new QGraphicsOpacityEffect(this);
    opacity_label_advance->setOpacity(0.2);
//    ui->label_advance->setGraphicsEffect(opacity_label_advance);
    label_advance->setGraphicsEffect(opacity_label_advance);
    opacity_swiftx_toggle = new QGraphicsOpacityEffect(this);
    opacity_swiftx_toggle->setOpacity(0.2);
    swiftx_toggle->setGraphicsEffect(opacity_swiftx_toggle);
}

void Page2::unset_opacity_page2()
{
    opacity_label_pay->setEnabled(false);
    opacity_widget_pay->setEnabled(false);
    opacity_label_label->setEnabled(false);
    opacity_edit_label_value->setEnabled(false);
    opacity_label_amount->setEnabled(false);
    opacity_edit_amount_value->setEnabled(false);
    opacity_button_send->setEnabled(false);
    opacity_label_swiftx->setEnabled(false);
    opacity_label_advance->setEnabled(false);
    opacity_swiftx_toggle->setEnabled(false);
}

void Page2::set_opacity_page2()
{
    opacity_label_pay->setEnabled(true);
    opacity_widget_pay->setEnabled(true);
    opacity_label_label->setEnabled(true);
    opacity_edit_label_value->setEnabled(true);
    opacity_label_amount->setEnabled(true);
    opacity_edit_amount_value->setEnabled(true);
    opacity_button_send->setEnabled(true);
    opacity_label_swiftx->setEnabled(true);
    opacity_label_advance->setEnabled(true);
    opacity_swiftx_toggle->setEnabled(true);
}

void Page2::setAlias(QString a)
{
    ui->edit_pay_value->setText(a);
}

void Page2::label_clicked()
{
    label_advance->setText("HELLO");

}

void Page2::on_button_search_icon_clicked()
{
    emit Click_search();
}
