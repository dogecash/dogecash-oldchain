#include "receive.h"
#include "ui_receive.h"
#include <QDebug>

receive::receive(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::receive)
{
    ui->setupUi(this);

    this->load_Label_input();

    this->set_main_font();

    this->load_table_receive();

    this->prepareOpacity_receive();

    this->unsetOpacity_receive();

}

receive::~receive()
{
    delete ui;
}
void receive::load_Label_input() {
   ui->widget_label->setLayout(new QHBoxLayout());
   edit_label_receive = new QLineEdit();
   button_search_label_receive = new QPushButton();
   ui->widget_label->layout()->setMargin(0);
   ui->widget_label->layout()->setSpacing(0);
   ui->widget_label->layout()->addWidget(edit_label_receive);
   ui->widget_label->layout()->addWidget(button_search_label_receive);
   edit_label_receive->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
   edit_label_receive->setMinimumHeight(49);
   edit_label_receive->setMaximumHeight(49);
   edit_label_receive->setFrame(false);
   edit_label_receive->setStyleSheet("background-color: transparent; color: #ffdfb5");

   button_search_label_receive->setMinimumSize(49, 49);
   button_search_label_receive->setMaximumSize(49, 49);
   button_search_label_receive->setStyleSheet("background-color: transparent; color: #ffdfb5;");


   pixmap_button_search_receive = new QPixmap(":/icon/search.svg");
   icon_buttonsearch_receive = new QIcon(*pixmap_button_search_receive);
   button_search_label_receive->setIcon(*icon_buttonsearch_receive);
   button_search_label_receive->setIconSize(QSize(24,24));

}
void receive::set_main_font(){
    font_main_receive = new QFont();
    font_main_receive->setFamily("Chivo");
    font_main_receive->setPixelSize(15);
    font_main_receive->setLetterSpacing(QFont::AbsoluteSpacing, 1.4);
    font_main_receive->setBold(true);

    edit_label_receive->setFont(*font_main_receive);
    ui->label_label->setFont(*font_main_receive);
    ui->label_amount->setFont(*font_main_receive);
    ui->label_message->setFont(*font_main_receive);
    ui->edit_amount_value->setFont(*font_main_receive);
    ui->edit_message_value->setFont(*font_main_receive);
    ui->button_request->setFont(*font_main_receive);
    ui->label_table_title->setFont(*font_main_receive);

    font_table_receive = new QFont();
    font_table_receive->setFamily("Chivo");
    font_table_receive->setLetterSpacing(QFont::AbsoluteSpacing, 1.2);
    font_table_receive->setPixelSize(13);

    ui->label_reuse_address->setFont(*font_table_receive);

}
void receive:: load_table_receive() {
    widget_table_data = new QWidget();
    widget_table_data->setStyleSheet("background-color: transparent");
    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setWidget(widget_table_data);
    scrollArea->setStyleSheet("background-color:transparent;");
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setGeometry(0,0, 10,10);
    loGrid = new QGridLayout();
    widget_table_data->setLayout(loGrid);
    loGrid->setMargin(0);
    loGrid->setHorizontalSpacing(0);
    loGrid->setVerticalSpacing(0);



    ui->widget_table->setLayout(new QVBoxLayout());
    ui->widget_table->setStyleSheet("background-color: transparent");
    ui->widget_table->layout()->addWidget(scrollArea);
//    ui->widget_table->layout()->setSpacerItem();
    ui->widget_table->layout()->setMargin(0);
    ui->widget_table->layout()->setSpacing(0);
    ui->widget_table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui->widget_table->setMinimumHeight(0);



    this->load_table_header();
    this->load_table_body();


}

void receive:: load_table_header() {
    label_table_date_header = new QLabel("DATE");
    label_table_date_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 97px; padding-right: 10px;");
    label_table_date_header->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label_table_date_header->setMinimumHeight(41);
    label_table_date_header->setMaximumHeight(41);
    label_table_date_header->setFont(*font_table_receive);
    loGrid->addWidget(label_table_date_header, 0, 0);

    label_table_date_header->show();

    label_table_label_header = new QLabel("LABEL");
    label_table_label_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 57px; padding-right: 10px;");
    label_table_label_header->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label_table_label_header->setMinimumHeight(41);
    label_table_label_header->setMaximumHeight(41);
    label_table_label_header->setFont(*font_table_receive);
    loGrid->addWidget(label_table_label_header, 0, 1);

    label_table_message_header = new QLabel("MESSAGE");
    label_table_message_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 57px; padding-right: 10px;");
    label_table_message_header->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label_table_message_header->setMinimumHeight(41);
    label_table_message_header->setMaximumHeight(41);
    label_table_message_header->setFont(*font_table_receive);
    loGrid->addWidget(label_table_message_header, 0, 2);

    label_table_amount_header = new QLabel("AMOUNT (DOGEC)");
    label_table_amount_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 57px; padding-right: 10px;");
    label_table_amount_header->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label_table_amount_header->setMinimumHeight(41);
    label_table_amount_header->setMaximumHeight(41);
    label_table_amount_header->setFont(*font_table_receive);
    loGrid->addWidget(label_table_amount_header, 0, 3);
}
void receive::load_table_body() {
    count = 15;
    label_table_label = new QLabel*[count];
    label_table_amount = new QLabel*[count];
    label_table_message = new QLabel*[count];
    label_table_date = new QLabel*[count];

    for (int i = 0; i<count; i++){

        label_table_date[i] = new LabelButton(this, i);
        label_table_date[i]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        label_table_date[i]->setMinimumSize(290, 29);
        label_table_date[i]->setMaximumSize(290, 29);
        label_table_date[i]->setText(QString::number(i) + ": 02/29/2018 03:55AM");
        loGrid->addWidget(label_table_date[i], i+1, 0);
        label_table_date[i]->show();
        label_table_date[i]->setFont(*font_table_receive);
        if (i % 2 == 0) {
            label_table_date[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 97px; padding-right: 10px");
        } else {
            label_table_date[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 97px; padding-right: 10px");
        }
        connect(label_table_date[i], SIGNAL(Clicked(int)), SLOT(select_item(int )));
        connect(label_table_date[i], SIGNAL(Entered(int)), SLOT(hoverd_row(int)));
        connect(label_table_date[i], SIGNAL(Leaved(int)), SLOT(leaved_row(int)));


        label_table_label[i] = new LabelButton(this, i);
        label_table_label[i]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        label_table_label[i]->setMinimumSize(160, 29);
        label_table_label[i]->setMaximumSize(160, 29);
        label_table_label[i]->setText("(No label) " + QString::number(i));
        loGrid->addWidget(label_table_label[i], i+1, 1);
        label_table_label[i]->show();
        label_table_label[i]->setFont(*font_table_receive);

        if (i % 2 == 0) {
            label_table_label[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
        } else {
            label_table_label[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
        }

        connect(label_table_label[i], SIGNAL(Clicked(int)), SLOT(select_item(int )));
        connect(label_table_label[i], SIGNAL(Entered(int)), SLOT(hoverd_row(int)));
        connect(label_table_label[i], SIGNAL(Leaved(int)), SLOT(leaved_row(int)));

        label_table_message[i] = new LabelButton(this, i);
        label_table_message[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        label_table_message[i]->setMinimumHeight(29);
        label_table_message[i]->setMaximumHeight(29);
        label_table_message[i]->setText("SHARED MASTERNODE WITH PEDRO" + QString::number(i));
        loGrid->addWidget(label_table_message[i], i+1, 2);
        label_table_message[i]->show();
        label_table_message[i]->setFont(*font_table_receive);

        if (i % 2 == 0) {
            label_table_message[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
        } else {
            label_table_message[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
        }
        connect(label_table_message[i], SIGNAL(Clicked(int)), SLOT(select_item(int )));
        connect(label_table_message[i], SIGNAL(Entered(int)), SLOT(hoverd_row(int)));
        connect(label_table_message[i], SIGNAL(Leaved(int)), SLOT(leaved_row(int)));

        label_table_amount[i] = new LabelButton(this, i);
        label_table_amount[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        label_table_amount[i]->setMinimumHeight(29);
        label_table_amount[i]->setMaximumHeight(29);
        label_table_amount[i]->setText(QString::number(i) + ": 1,324.55231");
        loGrid->addWidget(label_table_amount[i], i+1, 3);
        label_table_amount[i]->show();
        label_table_amount[i]->setFont(*font_table_receive);
        if (i % 2 == 0) {
            label_table_amount[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
        } else {
            label_table_amount[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
        }
        connect(label_table_amount[i], SIGNAL(Clicked(int)), SLOT(select_item(int)));
        connect(label_table_amount[i], SIGNAL(Entered(int)), SLOT(hoverd_row(int)));
        connect(label_table_amount[i], SIGNAL(Leaved(int)), SLOT(leaved_row(int)));
    }

}

void receive::select_item(int i)
{
//    label_table_date[i]->setText("OK");
    emit SelectItem(i);

}

void receive::prepareOpacity_receive() {
    opacity_widget_table_receive = new QGraphicsOpacityEffect(this);
    opacity_widget_table_receive->setOpacity(0.1);
    ui->widget_table->setGraphicsEffect(opacity_widget_table_receive);

    opacity_label_label_receive = new QGraphicsOpacityEffect(this);
    opacity_label_label_receive->setOpacity(0.1);
    ui->label_label->setGraphicsEffect(opacity_label_label_receive);

    opacity_label_amount_receive = new QGraphicsOpacityEffect(this);
    opacity_label_amount_receive->setOpacity(0.1);
    ui->label_amount->setGraphicsEffect(opacity_label_amount_receive);

    opacity_label_message_receive = new QGraphicsOpacityEffect(this);
    opacity_label_message_receive->setOpacity(0.1);
    ui->label_message->setGraphicsEffect(opacity_label_message_receive);

    opacity_widget_label_receive = new QGraphicsOpacityEffect(this);
    opacity_widget_label_receive->setOpacity(0.1);
    ui->widget_label->setGraphicsEffect(opacity_widget_label_receive);

    opacity_edit_amount_receive = new QGraphicsOpacityEffect(this);
    opacity_edit_amount_receive->setOpacity(0.1);
    ui->edit_amount_value->setGraphicsEffect(opacity_edit_amount_receive);

    opacity_edit_message_receive = new QGraphicsOpacityEffect(this);
    opacity_edit_message_receive->setOpacity(0.1);
    ui->edit_message_value->setGraphicsEffect(opacity_edit_message_receive);

    opacity_button_request_receive = new QGraphicsOpacityEffect(this);
    opacity_button_request_receive->setOpacity(0.1);
    ui->button_request->setGraphicsEffect(opacity_button_request_receive);

    opacity_check_reuse_address = new QGraphicsOpacityEffect(this);
    opacity_check_reuse_address->setOpacity(0.1);
    ui->check_resuse_address->setGraphicsEffect(opacity_check_reuse_address);

    opacity_label_reuse_address = new QGraphicsOpacityEffect(this);
    opacity_label_reuse_address->setOpacity(0.1);
    ui->label_reuse_address->setGraphicsEffect(opacity_label_reuse_address);

    opacity_label_table_title_receive = new QGraphicsOpacityEffect(this);
    opacity_label_table_title_receive->setOpacity(0.1);
    ui->label_table_title->setGraphicsEffect(opacity_label_table_title_receive);
}

void receive::setOpacity_receive(){
    opacity_widget_table_receive->setEnabled(true);

    opacity_label_label_receive->setEnabled(true);

    opacity_label_amount_receive->setEnabled(true);

    opacity_label_message_receive->setEnabled(true);

    opacity_widget_label_receive->setEnabled(true);

    opacity_edit_amount_receive->setEnabled(true);

    opacity_edit_message_receive->setEnabled(true);

    opacity_button_request_receive->setEnabled(true);

    opacity_check_reuse_address->setEnabled(true);

    opacity_label_reuse_address->setEnabled(true);

    opacity_label_table_title_receive->setEnabled(true);

}

void receive::unsetOpacity_receive(){
    opacity_widget_table_receive->setEnabled(false);

    opacity_label_label_receive->setEnabled(false);

    opacity_label_amount_receive->setEnabled(false);

    opacity_label_message_receive->setEnabled(false);

    opacity_widget_label_receive->setEnabled(false);

    opacity_edit_amount_receive->setEnabled(false);

    opacity_edit_message_receive->setEnabled(false);

    opacity_button_request_receive->setEnabled(false);

    opacity_check_reuse_address->setEnabled(false);

    opacity_label_reuse_address->setEnabled(false);

    opacity_label_table_title_receive->setEnabled(false);
}

void receive::remove_receive_address(int i)
{
//    std::move(label_table_date + i+1, // copy everything starting here
//              label_table_date + count, // and ending here, not including it,
//              label_table_date + i);

    loGrid->removeWidget(label_table_date[i]);
    loGrid->removeWidget(label_table_label[i]);
    loGrid->removeWidget(label_table_message[i]);
    loGrid->removeWidget(label_table_amount[i]);
}

void receive::reload_table_body(){
    for (int i = 0; i < count; i++){
        loGrid->addWidget(label_table_date[i], i+1, 0);
        loGrid->addWidget(label_table_label[i], i+1, 1);
        loGrid->addWidget(label_table_message[i], i+1, 2);
        loGrid->addWidget(label_table_amount[i], i+1, 3);
    }
}


void receive::hoverd_row(int i)
{
    label_table_date[i]->setStyleSheet("background-color: #b99d7c; color: #1f272e; padding-top: 8px; padding-bottom: 8px; padding-left: 97px; padding-right: 10px");
    label_table_label[i]->setStyleSheet("background-color: #b99d7c; color: #1f272e; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
    label_table_amount[i]->setStyleSheet("background-color: #b99d7c; color: #1f272e; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
    label_table_message[i]->setStyleSheet("background-color: #b99d7c; color: #1f272e; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
}

void receive::leaved_row(int i)
{
    if (i % 2 == 0){
        label_table_date[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 97px; padding-right: 10px");
        label_table_label[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
        label_table_amount[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
        label_table_message[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
    } else {
        label_table_date[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 97px; padding-right: 10px");
        label_table_label[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
        label_table_amount[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
        label_table_message[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 10px");
    }
}
