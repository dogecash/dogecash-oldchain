#include "widget.h"
#include "ui_widget.h"
#include "QPainter"
#include "QPainterPath"
#include "QFont"
#include "QImage"
#include "QPoint"
#include "QLabel"
#include "QBrush"
#include "QGradient"
#include "QRect"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setButtonIcons();
    this->setFonts();
    item_v_layout = new QVBoxLayout(this);
    item_h_layout = new QHBoxLayout(this);
    item_v_layout->addLayout(item_h_layout);

    this->preparePages();
    this->prepareBlur();
    this->prepareOpacity();

    this->loadFirstPage();
//
    this->unsetBlur();

    this->unsetOpacity();

}
void Widget::resizeEvent(QResizeEvent *event){

    homePage->setGeometry(0,143,this->geometry().width(),this->geometry().height()-310);

    sendPage->setGeometry(0,143,this->geometry().width(),this->geometry().height()-310);

    controlDialogPage->setGeometry(0,143,this->geometry().width(),this->geometry().height()-193);

    receivePage->setGeometry(0, 143, this->geometry().width(), this->geometry().height()-310);

    receiveDialogPage->setGeometry(0,143, this->geometry().width(), this->geometry().height() - 193);

    mnsPage->setGeometry(0,143, this->geometry().width(), this->geometry().height()-310);

    historyPage->setGeometry(0,143, this->geometry().width(), this->geometry().height() - 310);

    linelabel->setGeometry(0,68, this->geometry().width(), 411);
}

virtual void Widget::~Widget()
{
    delete ui;
}

void Widget::loadFirstPage()
{
    this->unsetBlur();
    this->unsetOpacity();

    item_h_layout->addWidget(homePage);
    this->hidePages();
    ui->label_line->show();
    homePage->show();
//    choosePayment->show();
    homePage->setGeometry(0,143,this->geometry().width(),this->geometry().height()-310);
    this->setButtonIcons();
    this->unsetBlur();
    pixmap_home = new QPixmap(":/icon/home_active.png");
    homeIcon = new QIcon(*pixmap_home);
    ui->button_home->setIconSize(QSize(60,112));
    ui->button_home->setIcon(*homeIcon);
    ui->label_status->show();
}

void Widget::loadSendPage(){

    this->unsetBlur();
    this->unsetOpacity();
    sendPage->unset_opacity_page2();
    item_h_layout->addWidget(sendPage);
    this->hidePages();
    ui->label_line->show();
    sendPage->show();
    ui->label_balance->show();
    ui->label_balance_value->show();
    ui->frame_control->show();

    this->setButtonIcons();
    pixmap_send = new QPixmap(":/icon/send_active.png");
    sendIcon = new QIcon(*pixmap_send);
    ui->button_send->setIcon(*sendIcon);
    ui->button_send->setIconSize(QSize(60,112));
    ui->label_status->show();
    ui->button_control->setEnabled(true);
    connect(sendPage, SIGNAL(Click_search()), SLOT(show_choose_alias_dialog()));


}

void Widget::loadReceivePage() {
    this->unsetBlur();
    this->unsetOpacity();
    item_h_layout->addWidget(receivePage);
    this->hidePages();
    linelabel->show();
    linelabel->lower();
    receivePage->show();
    receivePage->raise();
    ui->label_line->hide();

    this->setButtonIcons();
    pixmap_receive = new QPixmap(":/icon/receive_active.png");
    receiveIcon = new QIcon(*pixmap_receive);
    ui->button_receive->setIcon(*receiveIcon);
    ui->button_receive->setIconSize(QSize(60, 112));

    connect(receivePage, SIGNAL(SelectItem(int)), SLOT(loadReceiveDialogPage(int)));

}

void Widget::setButtonIcons(){
    pixmap_home = new QPixmap(":/icon/home.png");
    homeIcon = new QIcon(*pixmap_home);
    ui->button_home->setIcon(*homeIcon);
    ui->button_home->setIconSize(QSize(60,112));
    pixmap_send = new QPixmap(":/icon/send.png");
    sendIcon = new QIcon(*pixmap_send);
    ui->button_send->setIcon(*sendIcon);
    ui->button_send->setIconSize(QSize(60,112));
    pixmap_receive = new QPixmap(":/icon/receive.png");
    receiveIcon = new QIcon(*pixmap_receive);
    ui->button_receive->setIcon(*receiveIcon);
    ui->button_receive->setIconSize(QSize(60,112));
    pixmap_mns = new QPixmap(":/icon/mns.png");
    mnsIcon = new QIcon(*pixmap_mns);
    ui->button_mns->setIcon(*mnsIcon);
    ui->button_mns->setIconSize(QSize(60,112));
    pixmap_history = new QPixmap(":/icon/history.png");
    historyIcon = new QIcon(*pixmap_history);
    ui->button_history->setIcon(*historyIcon);
    ui->button_history->setIconSize(QSize(60,112));
}
void Widget::setFonts() {

    font_label_header = new QFont();
    font_label_header->setFamily("Chivo");
    font_label_header->setPixelSize(21);
//    ui->label_header->setFont(*font_label_header);


    font_label_balance = new QFont();
    font_label_balance->setLetterSpacing(QFont::AbsoluteSpacing, 1.4);
    font_label_balance->setFamily("Chivo");
    font_label_balance->setPixelSize(14);
    font_label_balance->setBold(true);
    ui->label_balance->setStyleSheet("background-color: transparent; color: white;");
    ui->label_balance->setFont(*font_label_balance);

    font_button_control = new QFont();
    font_button_control->setLetterSpacing(QFont::AbsoluteSpacing, 1.4);
    font_button_control->setFamily("Chivo");
    font_button_control->setBold(true);
    font_button_control->setPixelSize(14);
    ui->button_control->setFont(*font_button_control);
    ui->button_control->setStyleSheet("color: #f2f2f2; background-color: #b6a27e");

    font_label_balance_value = new QFont();
    font_label_balance_value->setLetterSpacing(QFont::AbsoluteSpacing, 1.5);
    font_label_balance_value->setFamily("Chapaza");
    font_label_balance_value->setPixelSize(44);
    ui->label_balance_value->setFont(*font_label_balance_value);

    font_label_status = new QFont();
    font_label_status->setPixelSize(14);
    font_label_status->setFamily("Chivo");
    ui->label_status->setFont(*font_label_status);
    ui->label_status->setStyleSheet("background-color:transparent; color: #5e6972;");
}


//void draw(){
//    QImage image(417,417, QImage::Format_ARGB32);
//    image.fill(Qt::transparent);
//    QPoint p(0, 30);

//    QLinearGradient grad1(10, 10, 400, 400);
//    grad1.setColorAt(0.0, Qt::white);
//    grad1.setColorAt(0.3, Qt::green);
//    grad1.setColorAt(0.6, Qt::red);
//    grad1.setColorAt(0.8, Qt::blue);
//    grad1.setColorAt(1.0, Qt::black);

//    QString text = "12,412.5326";
//    QFont font;
//    font.setFamily("Chapaza");
//    font.setPixelSize(44);
//    font.setBold(true);
//    QPainterPath path1;
//    path1.addText(p, font, text);
//    QPainterPath path2;
//    path2.addRect(10, 10, 200, 200);
//    QPainterPath strike = (path1 & path2);
//    QPainter painter(&image);

//    painter.fillPath(path1, grad1);
//    painter.end();

//    ui->label_lines->setPixmap(QPixmap::fromImage(image));
//}

void Widget::on_button_send_clicked()
{
    this->loadSendPage();
}

void Widget::on_button_home_clicked()
{
    this->loadFirstPage();
}

void Widget::unsetBlur(){
    blur_sendPage->setEnabled(false);
    blur_receivePage->setEnabled(false);
    blur_button_control->setEnabled(false);
    blur_label_line->setEnabled(false);
    blur_button_home->setEnabled(false);
    blur_button_send->setEnabled(false);
    blur_button_receive->setEnabled(false);
    blur_button_mns->setEnabled(false);
    blur_button_history->setEnabled(false);
}

void Widget::setBlur() {
    blur_sendPage->setEnabled(true);
    blur_receivePage->setEnabled(true);
    blur_button_control->setEnabled(true);
    blur_label_line->setEnabled(true);
    blur_button_home->setEnabled(true);
    blur_button_send->setEnabled(true);
    blur_button_receive->setEnabled(true);
    blur_button_mns->setEnabled(true);
    blur_button_history->setEnabled(true);
}

void Widget::on_button_control_clicked()
{

    item_h_layout->addWidget(controlDialogPage);

    controlDialogPage->show();
    this->setBlur();
    this->set_Opacity(0.2);
    sendPage->set_opacity_page2();
    ui->label_status->hide();
    ui->button_control->setEnabled(false);

    connect(controlDialogPage, SIGNAL(button_ok_click()), SLOT(close_control_dialog()));
}

void Widget:: close_control_dialog() {
    controlDialogPage->hide();
    this->unsetBlur();
    this->unsetOpacity();
    sendPage->unset_opacity_page2();
    ui->label_status->show();
    ui->button_control->setEnabled(true);
}

void Widget::preparePages(){
    homePage = new page1();
    homePage->setParent(this);
    homePage->setGeometry(0,143,this->geometry().width(),this->geometry().height()-310);

    sendPage = new Page2();
    sendPage->setParent(this);
    sendPage->setGeometry(0,143,this->geometry().width(),this->geometry().height()-310);

    controlDialogPage = new ControlDialog();
    controlDialogPage->setParent(this);
    controlDialogPage->setGeometry(0,143,this->geometry().width(),this->geometry().height()-193);

    receivePage = new receive();
    receivePage->setParent(this);
    receivePage->setGeometry(0,143, this->geometry().width(), this->geometry().height()-310);

    receiveDialogPage = new ReceiveDailog();
    receiveDialogPage->setParent(this);
    receiveDialogPage->setGeometry(0,143, this->geometry().width(), this->geometry().height()-193);

    mnsPage = new MnsClass();
    mnsPage->setParent(this);
    mnsPage->setGeometry(0,143, this->geometry().width(), this->geometry().height()-310);

    historyPage = new HistPage();
    historyPage->setParent(this);
    historyPage->setGeometry(0,143, this->geometry().width(), this->geometry().height()-310);

    linelabel = new Label_line();
    linelabel->setParent(this);
    linelabel->setGeometry(0,68, this->geometry().width(), 411);

    choosePayment = new ChoosePayment();
    choosePayment->setParent(this);
    choosePayment->setGeometry(0,143, this->geometry().width(), this->geometry().height()-310);

}
void Widget::hidePages() {
    homePage->hide();

    sendPage->hide();

    receivePage->hide();
    ui->label_balance->hide();
    ui->label_balance_value->hide();
    ui->frame_control->hide();

    controlDialogPage->hide();

    receiveDialogPage->hide();

    mnsPage->hide();

    historyPage->hide();

    linelabel->hide();

    choosePayment->hide();

    ui->label_line->hide();
}
void Widget::prepareBlur(){
    blur_sendPage = new QGraphicsBlurEffect(this);
    blur_sendPage->setBlurRadius(2);
    sendPage->setGraphicsEffect(blur_sendPage);
    blur_receivePage = new QGraphicsBlurEffect(this);
    blur_receivePage->setBlurRadius(4);
    receivePage->setGraphicsEffect(blur_receivePage);

    blur_button_control = new QGraphicsBlurEffect(this);
    blur_button_control->setBlurRadius(2);
    ui->button_control->setGraphicsEffect(blur_button_control);
    blur_label_line = new QGraphicsBlurEffect(this);
    blur_label_line->setBlurRadius(2);
    ui->label_line->setGraphicsEffect(blur_label_line);
    blur_button_home = new QGraphicsBlurEffect(this);
    blur_button_home->setBlurRadius(2);
    ui->button_home->setGraphicsEffect(blur_button_home);
    blur_button_send = new QGraphicsBlurEffect(this);
    blur_button_send->setBlurRadius(2);
    ui->button_send->setGraphicsEffect(blur_button_send);
    blur_button_receive = new QGraphicsBlurEffect(this);
    blur_button_receive->setBlurRadius(2);
    ui->button_receive->setGraphicsEffect(blur_button_receive);
    blur_button_mns = new QGraphicsBlurEffect(this);
    blur_button_mns->setBlurRadius(2);
    ui->button_mns->setGraphicsEffect(blur_button_mns);
    blur_button_history = new QGraphicsBlurEffect(this);
    blur_button_history->setBlurRadius(2);
    ui->button_history->setGraphicsEffect(blur_button_history);
}
void Widget::prepareOpacity() {
    opacity_frame_control = new QGraphicsOpacityEffect(this);
//    opacity_frame_control->setOpacity(0.1);
    ui->frame_control->setGraphicsEffect(opacity_frame_control);
    opacity_frame_line = new QGraphicsOpacityEffect(this);
//    opacity_frame_line->setOpacity(0.1);
    ui->frame_line->setGraphicsEffect(opacity_frame_line);
    opacity_frame_button_icon = new QGraphicsOpacityEffect(this);
//    opacity_frame_button_icon->setOpacity(0.1);
    ui->frame_button_icon->setGraphicsEffect(opacity_frame_button_icon);
}
void Widget::unsetOpacity() {
    opacity_frame_line->setEnabled(false);
    opacity_frame_control->setEnabled(false);
    opacity_frame_button_icon->setEnabled(false);
    receivePage->unsetOpacity_receive();
}
void Widget::set_Opacity(double value)
{
    opacity_frame_line->setEnabled(true);
    opacity_frame_line->setOpacity(value);
    opacity_frame_control->setEnabled(true);
    opacity_frame_control->setOpacity(value);
    opacity_frame_button_icon->setEnabled(true);
    opacity_frame_button_icon->setOpacity(value);
    receivePage->setOpacity_receive();

}

void Widget::loadMNSPage()
{
    this->unsetBlur();
    this->unsetOpacity();
    item_h_layout->addWidget(mnsPage);
    this->hidePages();
    linelabel->show();
    linelabel->lower();
    mnsPage->show();
    mnsPage->raise();
    mnsPage->setGeometry(0,143,this->geometry().width(),this->geometry().height()-310);
    this->setButtonIcons();
    pixmap_mns = new QPixmap(":/icon/mns_active.png");
    mnsIcon = new QIcon(*pixmap_mns);
    ui->button_mns->setIconSize(QSize(60,112));
    ui->button_mns->setIcon(*mnsIcon);
    ui->label_status->show();
}

void Widget::loadHistoryPage()
{
    this->unsetBlur();
    this->unsetOpacity();
    item_h_layout->addWidget(historyPage);
    this->hidePages();
    linelabel->show();
    linelabel->lower();
    historyPage->show();
    historyPage->raise();
    historyPage->setGeometry(0,143, this->geometry().width(), this->geometry().height()-310);
//    ui->label_status->setNum(historyPage->geometry().width());
    this->setButtonIcons();
    pixmap_history = new QPixmap(":/icon/history_active.png");
    historyIcon = new QIcon(*pixmap_history);
    ui->button_history->setIconSize(QSize(60, 112));
    ui->button_history->setIcon(*historyIcon);
    ui->label_status->show();
}

void Widget::on_button_receive_clicked()
{
    this->loadReceivePage();
}

void Widget::loadReceiveDialogPage(int j)
{
    this->setBlur();
    this->set_Opacity(0.1);
    item_h_layout->addWidget(receiveDialogPage);
    receiveDialogPage->setIndex(j);

    receiveDialogPage->show();
    receiveDialogPage->raise();

    linelabel->hide();

    connect(receiveDialogPage, SIGNAL(Close_Dialog()), SLOT(close_receive_dialog()));
    connect(receiveDialogPage, SIGNAL(Select_remove(int)), SLOT(remove_receive_address(int)));

}

void Widget::close_receive_dialog()
{
    receiveDialogPage->hide();
    this->unsetBlur();
    this->unsetOpacity();
    linelabel->show();
}

void Widget::on_button_mns_clicked()
{
    this->loadMNSPage();
}

void Widget::on_button_history_clicked()
{
    this->loadHistoryPage();
}

void Widget::remove_receive_address(int i)
{
    receivePage->remove_receive_address(i);
    close_receive_dialog();
}

void Widget::show_choose_alias_dialog()
{
    choosePayment->show();
    choosePayment->setGeometry(0,143,this->geometry().width(),this->geometry().height()-310);
    this->setBlur();
    this->set_Opacity(0.2);
    sendPage->set_opacity_page2();
    connect(choosePayment, SIGNAL(Selected_alias(QString)), SLOT(close_choose_alias_dialog(QString)));
    connect(choosePayment, SIGNAL(Close_dialog()), SLOT(close_choose_alias_dialog()));
}

void Widget::close_choose_alias_dialog(QString a)
{
    this->unsetBlur();
    this->unsetOpacity();
    sendPage->unset_opacity_page2();
    sendPage->setAlias(a);
    choosePayment->hide();
}

void Widget::close_alias_dialog()
{
    this->unsetBlur();
    this->unsetOpacity();
    sendPage->unset_opacity_page2();
    choosePayment->hide();
}
