#ifndef RECEIVE_H
#define RECEIVE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QPixelFormat>
#include <QIcon>
#include <QFont>
#include <QScrollArea>
#include <QLabel>
#include <QGridLayout>
#include <QGraphicsOpacityEffect>
#include <labelbutton.h>



namespace Ui {
class receive;
}

class receive : public QWidget
{
    Q_OBJECT

public:
    explicit receive(QWidget *parent = nullptr);
    ~receive();

    void load_Label_input();
    void set_main_font();
    void load_table_receive();
    void load_table_header();
    void load_table_body();
    void prepareOpacity_receive();
    void setOpacity_receive();
    void unsetOpacity_receive();
    void remove_receive_address(int i);
    void reload_table_body();

private:
    Ui::receive *ui;

    QLineEdit *edit_label_receive;
    QPushButton *button_search_label_receive;
    QPixmap *pixmap_button_search_receive;
    QIcon *icon_buttonsearch_receive;
    QFont *font_main_receive, *font_table_receive;
    QWidget *widget_table_data;
    QScrollArea *scrollArea;
    QLabel *label_table_date_header, *label_table_label_header, *label_table_message_header, *label_table_amount_header;
    QGridLayout *loGrid;
    QLabel **label_table_date, **label_table_label, **label_table_message, **label_table_amount;
    QGraphicsOpacityEffect *opacity_widget_table_receive, *opacity_label_label_receive, *opacity_label_amount_receive, *opacity_label_message_receive, *opacity_widget_label_receive, *opacity_edit_amount_receive, *opacity_edit_message_receive, *opacity_button_request_receive, *opacity_check_reuse_address, *opacity_label_reuse_address, *opacity_label_table_title_receive;

    int count;

signals:
    void SelectItem(int i);

private slots:
    void select_item(int i);
    void hoverd_row(int i);
    void leaved_row(int i);
};

#endif // RECEIVE_H
