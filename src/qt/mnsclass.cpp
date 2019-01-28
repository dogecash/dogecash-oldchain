#include "mnsclass.h"
#include "ui_mnsclass.h"

MnsClass::MnsClass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MnsClass)
{
    ui->setupUi(this);
    this->setfont_mns();
    this->loadTable_mns();
    this->loadTableHeader_mns();
    this->loadTableBody_mns();

}

MnsClass::~MnsClass()
{
    delete ui;
}

void MnsClass::loadTable_mns()
{
    widget_table = new QWidget();
    widget_table->setStyleSheet("background-color: transparent");
    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(widget_table);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setStyleSheet("background-color:transparent;");
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setGeometry(0,0, 10,10);
    loGrid = new QGridLayout();
    widget_table->setLayout(loGrid);
    loGrid->setMargin(0);
    loGrid->setHorizontalSpacing(0);
    loGrid->setVerticalSpacing(0);



    ui->widget->setLayout(new QVBoxLayout());
    ui->widget->setStyleSheet("background-color: transparent");
    ui->widget->layout()->addWidget(scrollArea);
    ui->widget->layout()->setMargin(0);
    ui->widget->layout()->setSpacing(0);
    ui->widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui->widget->setMinimumHeight(0);
}

void MnsClass::loadTableHeader_mns()
{
    label_alias_header = new QLabel("ALIAS");
    label_address_header = new QLabel("ADDRESS");
    label_protocal_header = new QLabel("PROTOCAL");
    label_status_header = new QLabel("STATUS");
    label_active_header = new QLabel("ACTIVE");
    label_seen_header = new QLabel("LAST SEEN(UTC)");
    label_pubkey_header = new QLabel("PUBKEY");

    label_alias_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 57px; padding-right: 9px;");
    label_alias_header->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label_alias_header->setMinimumHeight(41);
    label_alias_header->setMaximumHeight(41);
    label_alias_header->setFont(*font_label_mns);
    loGrid->addWidget(label_alias_header, 0, 0);

    label_address_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 17px; padding-right: 9px;");
    label_address_header->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label_address_header->setMinimumHeight(41);
    label_address_header->setMaximumHeight(41);
    label_address_header->setFont(*font_label_mns);
    loGrid->addWidget(label_address_header, 0, 1);

    label_protocal_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 17px; padding-right: 9px;");
    label_protocal_header->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label_protocal_header->setMinimumHeight(41);
    label_protocal_header->setMaximumHeight(41);
    label_protocal_header->setFont(*font_label_mns);
    loGrid->addWidget(label_protocal_header, 0, 2);

    label_status_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 17px; padding-right: 9px;");
    label_status_header->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label_status_header->setMinimumHeight(41);
    label_status_header->setMaximumHeight(41);
    label_status_header->setFont(*font_label_mns);
    loGrid->addWidget(label_status_header, 0, 3);

    label_active_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 17px; padding-right: 9px;");
    label_active_header->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label_active_header->setMinimumHeight(41);
    label_active_header->setMaximumHeight(41);
    label_active_header->setFont(*font_label_mns);
    loGrid->addWidget(label_active_header, 0, 4);

    label_seen_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 17px; padding-right: 9px;");
    label_seen_header->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label_seen_header->setMinimumHeight(41);
    label_seen_header->setMaximumHeight(41);
    label_seen_header->setFont(*font_label_mns);
    loGrid->addWidget(label_seen_header, 0, 5);

    label_pubkey_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 17px; padding-right: 36px;");
    label_pubkey_header->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    label_pubkey_header->setMinimumHeight(41);
    label_pubkey_header->setMaximumHeight(41);
    label_pubkey_header->setFont(*font_label_mns);
    loGrid->addWidget(label_pubkey_header, 0, 6);
}

void MnsClass::loadTableBody_mns()
{
    int count = 12;
    label_alias = new QLabel*[count];
    label_address = new QLabel*[count];
    label_protocal = new QLabel*[count];
    label_status = new QLabel*[count];
    label_active = new QLabel*[count];
    label_seen = new QLabel*[count];
    label_pubkey = new QLabel*[count];

    for (int i = 0; i < count; i++){
        label_alias[i] = new QLabel();
        label_alias[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        label_alias[i]->setMinimumHeight(29);
        label_alias[i]->setMaximumHeight(29);
        label_alias[i]->setText("MN" + QString::number(i));
        loGrid->addWidget(label_alias[i], i+1, 0);
        label_alias[i]->setFont(*font_label_mns);
        if (i % 2 == 0) {
            label_alias[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 9px");
        } else {
            label_alias[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 57px; padding-right: 9px");
        }

        label_address[i] = new QLabel();
        label_address[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        label_address[i]->setMinimumHeight(29);
        label_address[i]->setMaximumHeight(29);
        label_address[i]->setText("45.31.45.135:6740");
        loGrid->addWidget(label_address[i], i+1, 1);
        label_address[i]->setFont(*font_label_mns);
        if (i % 2 == 0) {
            label_address[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 17px; padding-right: 9px");
        } else {
            label_address[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 17px; padding-right: 9px");
        }

        label_protocal[i] = new QLabel();
        label_protocal[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        label_protocal[i]->setMinimumHeight(29);
        label_protocal[i]->setMaximumHeight(29);
        label_protocal[i]->setText("72018");
        loGrid->addWidget(label_protocal[i], i+1, 2);
        label_protocal[i]->setFont(*font_label_mns);
        if (i % 2 == 0) {
            label_protocal[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 17px; padding-right: 9px");
        } else {
            label_protocal[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 17px; padding-right: 9px");
        }

        label_status[i] = new QLabel();
        label_status[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        label_status[i]->setMinimumHeight(29);
        label_status[i]->setMaximumHeight(29);
        label_status[i]->setText("Enabled");
        loGrid->addWidget(label_status[i], i+1, 3);
        label_status[i]->setFont(*font_label_mns);
        if (i % 2 == 0) {
            label_status[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 17px; padding-right: 9px");
        } else {
            label_status[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 17px; padding-right: 9px");
        }

        label_active[i] = new QLabel();
        label_active[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        label_active[i]->setMinimumHeight(29);
        label_active[i]->setMaximumHeight(29);
        label_active[i]->setText("48d 12h:31m:06s");
        loGrid->addWidget(label_active[i], i+1, 4);
        label_active[i]->setFont(*font_label_mns);
        if (i % 2 == 0) {
            label_active[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 17px; padding-right: 9px");
        } else {
            label_active[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 17px; padding-right: 9px");
        }

        label_seen[i] = new QLabel();
        label_seen[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        label_seen[i]->setMinimumHeight(29);
        label_seen[i]->setMaximumHeight(29);
        label_seen[i]->setText("2018-11-27 04:50");
        loGrid->addWidget(label_seen[i], i+1, 5);
        label_seen[i]->setFont(*font_label_mns);
        if (i % 2 == 0) {
            label_seen[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 17px; padding-right: 9px");
        } else {
            label_seen[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 17px; padding-right: 9px");
        }

        label_pubkey[i] = new QLabel();
        label_pubkey[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        label_pubkey[i]->setMinimumHeight(29);
        label_pubkey[i]->setMaximumHeight(29);
        label_pubkey[i]->setText("SDfgw4egAV5dsRVsd4gSD4gERb5seDBS%E");
        loGrid->addWidget(label_pubkey[i], i+1, 6);
        label_pubkey[i]->setFont(*font_label_mns);
        if (i % 2 == 0) {
            label_pubkey[i]->setStyleSheet("background-color: #2a3036; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 17px; padding-right: 36px");
        } else {
            label_pubkey[i]->setStyleSheet("background-color: #1f272e; color: #f2f2f2; padding-top: 8px; padding-bottom: 8px; padding-left: 17px; padding-right: 36px");
        }
    }
}

void MnsClass::setfont_mns()
{
    font_label_mns = new QFont();
    font_label_mns->setFamily("Chivo");
    font_label_mns->setPixelSize(13);
    font_label_mns->setLetterSpacing(QFont::AbsoluteSpacing, 1.2);

    font_button_mns = new QFont();
    font_button_mns->setFamily("Chivo");
    font_button_mns->setBold(true);
    font_button_mns->setLetterSpacing(QFont::AbsoluteSpacing, 1.4);
    font_button_mns->setPixelSize(15);

    ui->button_all->setFont(*font_button_mns);
    ui->button_alias->setFont(*font_button_mns);
    ui->button_update->setFont(*font_button_mns);
    ui->button_missing->setFont(*font_button_mns);
    ui->label_notify1->setFont(*font_label_mns);
    ui->label_notify2->setFont(*font_label_mns);
    ui->label_notify3->setFont(*font_label_mns);

}
