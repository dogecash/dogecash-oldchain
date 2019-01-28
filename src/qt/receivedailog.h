#ifndef RECEIVEDAILOG_H
#define RECEIVEDAILOG_H

#include <QWidget>
#include <QFont>

namespace Ui {
class ReceiveDailog;
}

class ReceiveDailog : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiveDailog(QWidget *parent = nullptr);
    ~ReceiveDailog();
    void setIndex(int);

signals:
    void Close_Dialog();
    void Select_remove(int);

private slots:
    void on_button_uri_clicked();

    void on_button_address_clicked();

    void on_button_remove_clicked();

private:
    Ui::ReceiveDailog *ui;

    QFont *font_receive_dialog;

    int index;
};

#endif // RECEIVEDAILOG_H
