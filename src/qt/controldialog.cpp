#include "controldialog.h"
#include "ui_controldialog.h"
#include <QGraphicsBlurEffect>
#include <QScrollArea>
#include <QDebug>


ControlDialog::ControlDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlDialog)
{
    ui->setupUi(this);
    ui->widget_table->setMinimumWidth(this->geometry().width());
    ui->widget_table->setMaximumWidth(this->geometry().width());

    this->loadToggleTreeMode();
    this->setFont_control_dialog();
    this->setFontTable_control_dialog();
    this->loadTable_control_dialog();

}

void ControlDialog::resizeEvent(QResizeEvent *event){
    ui->widget_table->setMinimumWidth(this->geometry().width());
    ui->widget_table->setMaximumWidth(this->geometry().width());
}

ControlDialog::~ControlDialog()
{
    delete ui;
}

void ControlDialog::loadToggleTreeMode() {
    toggle_tree_mode = new ToggleSwitch();
    ui->layout_tree_mode_toggle->addWidget(toggle_tree_mode);
    toggle_tree_mode->setParent(this);
    toggle_tree_mode->setGeometry(10,10,68,28);
    toggle_tree_mode->show();
    toggle_tree_mode->setStatus(true);

    connect(toggle_tree_mode, SIGNAL(statusChanged(bool)), SLOT(change_table_mode(bool)));
}

void ControlDialog:: loadTable_control_dialog(){

    widget_table_data = new QWidget();
    widget_table_data->setStyleSheet("background-color: transparent");
    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setWidget(widget_table_data);
    scrollArea->setStyleSheet("background-color:transparent;");
    loGrid = new QGridLayout();
    widget_table_data->setLayout(loGrid);

    ui->widget_table->setLayout(new QVBoxLayout());
    ui->widget_table->layout()->addWidget(scrollArea);
    ui->widget_table->layout()->setMargin(0);
    ui->widget_table->layout()->setSpacing(0);

    loGrid->setMargin(0);
    loGrid->setHorizontalSpacing(0);
    loGrid->setVerticalSpacing(0);


    label_space_header1 = new QLabel();
    label_space_header1->setStyleSheet("background-color: #1f272e; color: #b99d7c");
    label_space_header1->setMinimumSize(41,49);
    label_space_header1->setMaximumSize(41, 49);
    loGrid->addWidget(label_space_header1, 0, 0);
    label_space_header1->show();

    label_space_header2 = new QLabel();
    label_space_header2->setStyleSheet("background-color: #1f272e");
    label_space_header2->setMinimumSize(34,49);
    label_space_header2->setMaximumSize(34, 49);
    loGrid->addWidget(label_space_header2, 0, 1);
    label_space_header2->show();

    label_space_header3 = new QLabel();
    label_space_header3->setStyleSheet("background-color: #1f272e");
    label_space_header3->setMinimumSize(34,49);
    label_space_header3->setMaximumSize(34, 49);
    loGrid->addWidget(label_space_header3, 0, 2);

    label_amount_header = new QLabel("AMOUNT");
    label_amount_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 11px; padding-right: 10px;");
    label_amount_header->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    label_amount_header->setMinimumHeight(49);
    label_amount_header->setMaximumHeight(49);
    label_amount_header->setFont(*font_label_table);
    loGrid->addWidget(label_amount_header, 0, 3);
    label_amount_header->show();

    label_label_header = new QLabel("LABEL");
    label_label_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 11px; padding-right: 10px;");
    label_label_header->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    label_label_header->setMinimumHeight(49);
    label_label_header->setMaximumHeight(49);
    label_label_header->setFont(*font_label_table);
    loGrid->addWidget(label_label_header, 0, 4);
    label_label_header->show();

    label_address_header = new QLabel("ADDRESS");
    label_address_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 11px; padding-right: 10px;");
    label_address_header->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    label_address_header->setMinimumHeight(49);
    label_address_header->setMaximumHeight(49);
    label_address_header->setFont(*font_label_table);
    loGrid->addWidget(label_address_header, 0, 5);
    label_address_header->show();

    label_personal_header = new QLabel("PERSONAL");
    label_personal_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 11px; padding-right: 10px;");
    label_personal_header->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    label_personal_header->setMinimumHeight(49);
    label_personal_header->setMaximumHeight(49);
    label_personal_header->setFont(*font_label_table);
    loGrid->addWidget(label_personal_header, 0, 6);
    label_personal_header->show();

    label_date_header = new QLabel("DATE");
    label_date_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 11px; padding-right: 10px;");
    label_date_header->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    label_date_header->setMinimumHeight(49);
    label_date_header->setMaximumHeight(49);
    label_date_header->setFont(*font_label_table);
    loGrid->addWidget(label_date_header, 0, 7);
    label_date_header->show();

    label_confirmation_header = new QLabel("CONFIRMATION");
    label_confirmation_header->setStyleSheet("background-color: #1f272e; color: #b99d7c; padding-top: 17px; padding-bottom: 10px; padding-left: 11px; padding-right: 10px;");
    label_confirmation_header->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    label_confirmation_header->setMinimumHeight(49);
    label_confirmation_header->setMaximumHeight(49);
    label_confirmation_header->setFont(*font_label_table);
    loGrid->addWidget(label_confirmation_header, 0,8);
    label_confirmation_header->show();


//    scrollArea->setWidget(ui->widget_table);
//    ui->widget_table->setLayout(ui->layout_table);



    pixmap_lock_control_dialog = new QPixmap(":/icon/lock_table.svg");
    pixmap_tree_control_dailog = new QPixmap(":/icon/tree_table.png");
    count = 15;
    label_locks_table = new QLabel*[count];
    label_table_amount = new QLabel*[count];
    label_table_label = new QLabel*[count];
    label_table_address = new QLabel*[count];
    label_table_personal = new QLabel*[count];
    label_table_date = new QLabel*[count];
    label_table_confirmation = new QLabel*[count];
    check_table_control_dailog = new QCheckBox*[count];
    label_table_tree = new QLabel*[count];


    for (int i = 0; i< count; i++){
        label_locks_table[i] = new QLabel();
        if (i % 2 == 0) {
            label_locks_table[i]->setStyleSheet("background-color: #2a3036; padding-left: 21px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        } else {
            label_locks_table[i]->setStyleSheet("background-color: #1f272e; padding-left: 21px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        }

        label_locks_table[i]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        label_locks_table[i]->setMinimumSize(41, 29);
        label_locks_table[i]->setMaximumSize(41, 29);
        label_locks_table[i]->setPixmap(*pixmap_lock_control_dialog);
        label_locks_table[i]->setMargin(-2);

        label_table_tree[i] = new QLabel();
        if (i % 2 == 0) {
            label_table_tree[i]->setStyleSheet("background-color: #2a3036; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        } else {
            label_table_tree[i]->setStyleSheet("background-color: #1f272e; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        }

        label_table_tree[i]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        label_table_tree[i]->setMinimumSize(34, 29);
        label_table_tree[i]->setMaximumSize(34, 29);
        label_table_tree[i]->setPixmap(*pixmap_tree_control_dailog);
        label_table_tree[i]->setMargin(-2);


        check_table_control_dailog[i] = new QCheckBox();
        if (i % 2 == 0) {
            check_table_control_dailog[i]->setStyleSheet("background-color: #2a3036; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        } else {
            check_table_control_dailog[i]->setStyleSheet("background-color: #1f272e; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        }
        check_table_control_dailog[i]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        check_table_control_dailog[i]->setMinimumSize(34, 29);
        check_table_control_dailog[i]->setMaximumSize(34, 29);

        label_table_amount[i] = new QLabel("1,324.55231");
        if (i % 2 == 0) {
            label_table_amount[i]->setStyleSheet("background-color: #2a3036; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        } else {
            label_table_amount[i]->setStyleSheet("background-color: #1f272e; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        }
        label_table_amount[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        label_table_amount[i]->setMinimumHeight(29);
        label_table_amount[i]->setMaximumHeight(29);
        label_table_amount[i]->setFont(*font_label_table);

        label_table_label[i] = new QLabel("(No label)");
        if (i % 2 == 0) {
            label_table_label[i]->setStyleSheet("background-color: #2a3036; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        } else {
            label_table_label[i]->setStyleSheet("background-color: #1f272e; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        }
        label_table_label[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        label_table_label[i]->setMinimumHeight(29);
        label_table_label[i]->setMaximumHeight(29);
        label_table_label[i]->setFont(*font_label_table);
//        label_table_label[i]->text().toUpper();

        label_table_address[i] = new QLabel("DQ68xWwN8mkU8cJDLvP6HK434qUptCH68v");
        if (i % 2 == 0) {
            label_table_address[i]->setStyleSheet("background-color: #2a3036; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        } else {
            label_table_address[i]->setStyleSheet("background-color: #1f272e; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        }
        label_table_address[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        label_table_address[i]->setMinimumHeight(29);
        label_table_address[i]->setMaximumHeight(29);
        label_table_address[i]->setFont(*font_label_table);
//        label_table_address[i]->text().toUpper();

        label_table_personal[i] = new QLabel("Personal");
        if (i % 2 == 0) {
            label_table_personal[i]->setStyleSheet("background-color: #2a3036; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        } else {
            label_table_personal[i]->setStyleSheet("background-color: #1f272e; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        }
        label_table_personal[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        label_table_personal[i]->setMinimumHeight(29);
        label_table_personal[i]->setMaximumHeight(29);
        label_table_personal[i]->setFont(*font_label_table);
//        label_table_personal[i]->text().toUpper();

        label_table_date[i] = new QLabel("02/29/2018");
        if (i % 2 == 0) {
            label_table_date[i]->setStyleSheet("background-color: #2a3036; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        } else {
            label_table_date[i]->setStyleSheet("background-color: #1f272e; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        }
        label_table_date[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        label_table_date[i]->setMinimumHeight(29);
        label_table_date[i]->setMaximumHeight(29);
        label_table_date[i]->setFont(*font_label_table);

        label_table_confirmation[i] = new QLabel("77,423");
        if (i % 2 == 0) {
            label_table_confirmation[i]->setStyleSheet("background-color: #2a3036; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        } else {
            label_table_confirmation[i]->setStyleSheet("background-color: #1f272e; padding-left: 11px; padding-right: 10px;  padding-top: 8px;  padding-bottom: 8px;  color: #f2f2f2;");
        }
        label_table_confirmation[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        label_table_confirmation[i]->setMinimumHeight(29);
        label_table_confirmation[i]->setMaximumHeight(29);
        label_table_confirmation[i]->setFont(*font_label_table);


        loGrid->addWidget(label_locks_table[i], i+1,0);
        loGrid->addWidget(label_table_tree[i], i+1, 1);
        loGrid->addWidget(check_table_control_dailog[i], i+1, 2);
        loGrid->addWidget(label_table_amount[i], i+1, 3);
        loGrid->addWidget(label_table_label[i], i+1, 4);
        loGrid->addWidget(label_table_address[i], i+1, 5);
        loGrid->addWidget(label_table_personal[i], i+1, 6);
        loGrid->addWidget(label_table_date[i], i+1, 7);
        loGrid->addWidget(label_table_confirmation[i], i+1, 8);
//        loGrid->setRowMinimumHeight(i, 29);



//        label_locks_table[i]->show();
//        check_table_control_dailog[i]->show();
//        label_table_amount[i]->show();
//        label_table_label[i]->show();
//        label_table_address[i]->show();
//        label_table_date[i]->show();
//        label_table_personal[i]->show();
//        label_table_confirmation[i]->show();
    }
}

void ControlDialog:: setFont_control_dialog(){
    font_label_summary = new QFont();
    font_label_summary->setBold(true);
    font_label_summary->setFamily("Chivo");
    font_label_summary->setPixelSize(15);
    font_label_summary->setLetterSpacing(QFont::AbsoluteSpacing, 1.4);

    ui->label_fee->setFont(*font_label_summary);
    ui->label_dust->setFont(*font_label_summary);
    ui->label_bytes->setFont(*font_label_summary);
    ui->label_amount->setFont(*font_label_summary);
    ui->label_change->setFont(*font_label_summary);
    ui->label_priority->setFont(*font_label_summary);
    ui->label_quantity->setFont(*font_label_summary);
    ui->label_after_fee->setFont(*font_label_summary);

    ui->label_fee_value->setFont(*font_label_summary);
    ui->label_dust_value->setFont(*font_label_summary);
    ui->label_bytes_value->setFont(*font_label_summary);
    ui->label_amount_value->setFont(*font_label_summary);
    ui->label_change_value->setFont(*font_label_summary);
    ui->label_priority_value->setFont(*font_label_summary);
    ui->label_quantity_value->setFont(*font_label_summary);
    ui->label_after_fee_value->setFont(*font_label_summary);
    ui->label_request_payments_history->setFont(*font_label_summary);

    ui->button_select_all->setFont(*font_label_summary);
    ui->button_toggle_lock_state->setFont(*font_label_summary);
    ui->label_tree_mode->setFont(*font_label_summary);
    ui->label_list_mode->setFont(*font_label_summary);
    ui->label_list_mode_value->setFont(*font_label_summary);
    ui->button_ok_control_dialog->setFont(*font_label_summary);
}
void ControlDialog::setFontTable_control_dialog()
{
    font_label_table = new QFont();
    font_label_table->setFamily("Chivo");
    font_label_table->setPixelSize(13);
    font_label_table->setLetterSpacing(QFont::AbsoluteSpacing, 1.2);

}

void ControlDialog::on_button_ok_control_dialog_clicked()
{
    emit button_ok_click();
}

void ControlDialog::change_table_mode(bool state)
{
    if (state) {
        qDebug()<<"True"<<endl;

        loGrid->addWidget(label_space_header2, 0, 1);
        for (int i = 0; i < count; i++) {
            loGrid->addWidget(label_table_tree[i], i+1, 1);
        }
    } else {
        qDebug()<<"False"<<endl;

        loGrid->removeWidget(label_space_header3);
        for (int i = 0; i < count; i++){
            loGrid->removeWidget(label_table_tree[i]);
        }
        loGrid->removeItem(loGrid->itemAtPosition(0,1));
    }
//    if (!state) {

//    }
}
