#include "histpage.h"

HistPage::HistPage(QWidget *parent) : QWidget(parent)
{
    loadpage();
    setFontTable_history();
    setTable_history();
    loadTableHeader_history();
    setTableBody_history();
}

void HistPage::loadpage()
{
    main_widget = new QWidget();
    main_widget->setParent(this);
    main_widget->setGeometry(0,35, this->geometry().width(), this->geometry().height()-55);
    main_widget->setStyleSheet("background-color: yellow");
    main_widget->show();
    main_layout = new QVBoxLayout();
    main_layout->setMargin(0);
    main_layout->setContentsMargins(0,0,0,0);
    main_layout->setAlignment(Qt::AlignTop);
    main_widget->setLayout(main_layout);
}

void HistPage::resizeEvent(QResizeEvent *event)
{
    main_widget->setGeometry(0,35, this->geometry().width(), this->geometry().height()-55);

}

void HistPage::setTable_history()
{
    widget_table = new QWidget();
    widget_table->setStyleSheet("Background-color: blue");
    widget_table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    scrollArea = new QScrollArea();
//    scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    scrollArea->setWidgetResizable(true);

    scrollArea->setWidget(widget_table);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    loGrid = new QGridLayout();
    loGrid->setSpacing(0);
    loGrid->setHorizontalSpacing(0);
    loGrid->setVerticalSpacing(0);
    loGrid->setMargin(0);
    widget_table->setLayout(loGrid);
    main_layout->addWidget(scrollArea);
    verticalSpacer1 = new QSpacerItem(20,0,QSizePolicy::Fixed, QSizePolicy::Preferred);
    main_layout->addSpacerItem(verticalSpacer1);

}

void HistPage::loadTableHeader_history()
{
    label_space_header = new QLabel();
    label_space_header->setStyleSheet("background-color: #1f272e;");
    label_space_header->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    label_space_header->setMinimumSize(90,41);
    label_space_header->setMaximumSize(90,41);
    label_space_header->setFont(*font_history);
    loGrid->addWidget(label_space_header, 0, 0);

    label_date_header = new QLabel("DATE");
    label_date_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 7px; padding-right: 7px;");
    label_date_header->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    label_date_header->setMinimumSize(225,41);
    label_date_header->setMaximumSize(225,41);
    label_date_header->setFont(*font_history);
    loGrid->addWidget(label_date_header, 0, 1);

    label_label_header = new QLabel("LABEL");
    label_label_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 7px; padding-right: 7px;");
    label_label_header->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    label_label_header->setMinimumSize(177,41);
    label_label_header->setMaximumSize(177,41);
    label_label_header->setFont(*font_history);
    loGrid->addWidget(label_label_header, 0, 2);

    label_message_header = new QLabel("MESSAGE");
    label_message_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 7px; padding-right: 7px;");
    label_message_header->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    label_message_header->setMinimumHeight(41);
    label_message_header->setMaximumHeight(41);
    label_message_header->setFont(*font_history);
    loGrid->addWidget(label_message_header, 0, 3);

    label_amount_header = new QLabel("Amount (DOGEC)");
    label_amount_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 7px; padding-right: 149px;");
    label_amount_header->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label_amount_header->setMinimumHeight(41);
    label_amount_header->setMaximumHeight(41);
    label_amount_header->setFont(*font_history);
    loGrid->addWidget(label_amount_header, 0, 4);
}

void HistPage::setFontTable_history()
{
    font_history = new QFont();
    font_history->setFamily("Chivo");
    font_history->setPixelSize(13);
    font_history->setLetterSpacing(QFont::AbsoluteSpacing, 1.2);
}

void HistPage::setTableBody_history()
{
    int count = 51;
    label_date = new QLabel*[count];
    label_icon_check = new QLabel*[count];
    label_label = new QLabel*[count];
    label_message = new QLabel*[count];
    label_amount = new QLabel*[count];
    pixmap_checked_icon = new QPixmap(":/icon/check_table.png");
    pixmap_loading_icon = new QPixmap(":/icon/refresh_table.png");
    for (int i = 0; i < count; i++) {
        label_icon_check[i] = new QLabel();
        if (i == 0) {
            label_icon_check[i]->setPixmap(*pixmap_loading_icon);
        } else {
            label_icon_check[i]->setPixmap(*pixmap_checked_icon);
        }
        if (i % 2 == 0) {
            label_icon_check[i]->setStyleSheet("background-color: #2a3036; padding-left: 70px; padding-right: 7px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        } else {
            label_icon_check[i]->setStyleSheet("background-color: #1f272e; padding-left: 70px; padding-right: 7px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        }
        label_icon_check[i]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        label_icon_check[i]->setMinimumSize(90, 29);
        label_icon_check[i]->setMaximumSize(90, 29);
        label_icon_check[i]->setScaledContents(true);
        label_icon_check[i]->setFont(*font_history);
        loGrid->addWidget(label_icon_check[i], 1+i, 0);

        label_date[i] = new QLabel();
        label_date[i]->setText("02/29/2018 03:55AM");
        label_date[i]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        label_date[i]->setMinimumSize(225,29);
        label_date[i]->setMaximumSize(225,29);
        if (i % 2 == 0) {
            label_date[i]->setStyleSheet("background-color: #2a3036; padding-left: 7px; padding-right: 7px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        } else {
            label_date[i]->setStyleSheet("background-color: #1f272e; padding-left: 7px; padding-right: 7px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        }
        loGrid->addWidget(label_date[i], 1+i, 1);
        label_date[i]->setFont(*font_history);

        label_label[i] = new QLabel();
        label_label[i]->setText("(No label)");
        label_label[i]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        label_label[i]->setMinimumSize(177,29);
        label_label[i]->setMaximumSize(177,29);
        if (i % 2 == 0) {
            label_label[i]->setStyleSheet("background-color: #2a3036; padding-left: 7px; padding-right: 7px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        } else {
            label_label[i]->setStyleSheet("background-color: #1f272e; padding-left: 7px; padding-right: 7px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        }
        loGrid->addWidget(label_label[i], 1+i, 2);
        label_label[i]->setFont(*font_history);

        label_message[i] = new QLabel();
        label_message[i]->setText("(No label)");
        label_message[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        label_message[i]->setMinimumHeight(29);
        label_message[i]->setMaximumHeight(29);
        if (i % 2 == 0) {
            label_message[i]->setStyleSheet("background-color: #2a3036; padding-left: 7px; padding-right: 7px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        } else {
            label_message[i]->setStyleSheet("background-color: #1f272e; padding-left: 7px; padding-right: 7px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        }
        label_message[i]->setFont(*font_history);
        loGrid->addWidget(label_message[i], 1+i, 3);

        label_amount[i] = new QLabel();
        label_amount[i]->setText("(No label)");
        label_amount[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        label_amount[i]->setMinimumHeight(29);
        label_amount[i]->setMaximumHeight(29);
        if (i % 2 == 0) {
            label_amount[i]->setStyleSheet("background-color: #2a3036; padding-left: 7px; padding-right: 7px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        } else {
            label_amount[i]->setStyleSheet("background-color: #1f272e; padding-left: 7px; padding-right: 7px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        }
        label_amount[i]->setFont(*font_history);
        loGrid->addWidget(label_amount[i], 1+i, 4);

    }

    label_footer = new QLabel();
    if (count % 2 == 0) {
        label_footer->setStyleSheet("background-color: #2a3036;");
    } else {
        label_footer->setStyleSheet("background-color: #1f272e;");
    }

    label_footer->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label_footer->setMinimumHeight(40);
    label_footer->setMaximumHeight(40);
    loGrid->addWidget(label_footer, count+1, 0, 1, 5);
}

void HistPage::loadTableFooter_history()
{



}
