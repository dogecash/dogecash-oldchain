#include "label_line.h"

Label_line::Label_line(QWidget *parent) : QWidget(parent)
{
    QPixmap pixmap(":/img/main-back.png");

    line_label = new QLabel();
    line_label->setPixmap(pixmap);
    line_label->setGeometry(0,0,417, 433);
    line_label->setMinimumSize(417,433);
    line_label->setMaximumSize(417, 433);
    line_label->setStyleSheet("background-color: transparent;");

    widget = new QWidget();
    widget->setParent(this);
    widget->setStyleSheet("background-color: transparent");

    layout = new QHBoxLayout();
    widget->setLayout(layout);
    widget->setGeometry(0,0,this->geometry().width(), this->geometry().height());
    left_item = new QSpacerItem(10,10,QSizePolicy::Expanding, QSizePolicy::Fixed);
    right_item = new QSpacerItem(10,10,QSizePolicy::Expanding, QSizePolicy::Fixed);
    layout->addItem(left_item);
    layout->addWidget(line_label);
    layout->addItem(right_item);
    widget->show();
}

void Label_line::resizeEvent(QResizeEvent *event)
{
    widget->setGeometry(0,0,this->geometry().width(), this->geometry().height());
}
