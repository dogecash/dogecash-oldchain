#ifndef CHOOSEPAYMENT_H
#define CHOOSEPAYMENT_H

#include <QWidget>
#include <QScrollArea>
#include <QFont>
#include <QGridLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

namespace Ui {
class ChoosePayment;
}

class ChoosePayment : public QWidget
{
    Q_OBJECT

public:
    explicit ChoosePayment(QWidget *parent = nullptr);
    ~ChoosePayment();
    void loadPage();
    void loadTable();



private:
    Ui::ChoosePayment *ui;

    QWidget *widget_table;
    QScrollArea *scrollArea;
    QGridLayout *loGrid;
    QHBoxLayout *h_layout;
    QVBoxLayout *main_layout;
    QLabel *label_label_header, *label_alias_header, **label_label_body, **label_alias_body;
    QFont *font_choose_alias, *font_dialog;
    QSpacerItem *verticalSpacer1;
    int count;
signals:
    void Selected_alias(QString);
    void Close_dialog();
private slots:
    void select_item(int);
    void hoverd_row(int);
    void leaved_row(int);
    void on_button_choose_clicked();
    void on_button_new_clicked();
    void on_button_copy_clicked();
    void on_button_delete_clicked();

};

#endif // CHOOSEPAYMENT_H
