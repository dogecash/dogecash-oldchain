#ifndef CONTROLDIALOG_H
#define CONTROLDIALOG_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <toggleswitch.hpp>
#include <QCheckBox>
#include <QPixmap>
#include <QIcon>
#include <QScrollArea>



namespace Ui {
class ControlDialog;
}

class ControlDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ControlDialog(QWidget *parent = nullptr);
    ~ControlDialog();

    void setFont_control_dialog();
    void loadToggleTreeMode();
    void loadTable_control_dialog();
    void setFontTable_control_dialog();
    void resizeEvent(QResizeEvent *event);

    ToggleSwitch *toggle_tree_mode;
protected:
    QFont *font_label_summary, *font_label_table;
    QLabel **label_locks_table,**label_table_tree, **label_table_amount, **label_table_label, **label_table_address, **label_table_personal, **label_table_date, **label_table_confirmation;
    QCheckBox **check_table_control_dailog;
    QPixmap *pixmap_lock_control_dialog, *pixmap_tree_control_dailog;
    QIcon *lockIcon_control_dialog;
    QWidget *widget_table_data;
    QScrollArea *scrollArea;
    QGridLayout *loGrid;

    QLabel *label_amount_header, *label_space_header3, *label_label_header, *label_address_header, *label_personal_header, *label_date_header, *label_confirmation_header, *label_space_header1, *label_space_header2;

    int count;

signals:
    void button_ok_click();

private slots:
    void on_button_ok_control_dialog_clicked();
    void change_table_mode(bool);

private:
    Ui::ControlDialog *ui;
};

#endif // CONTROLDIALOG_H
