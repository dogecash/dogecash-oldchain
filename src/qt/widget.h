#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QIcon>
#include <QFont>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsBlurEffect>
#include <QGraphicsOpacityEffect>

#include <page1.h>
#include <toggleswitch.hpp>
#include <page2.h>
#include <controldialog.h>
#include <receive.h>
#include <receivedailog.h>
#include <mnsclass.h>
#include <histpage.h>
#include <label_line.h>
#include <choosepayment.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    virtual ~Widget();

    QPixmap *pixmap_home, *pixmap_send, *pixmap_receive, *pixmap_mns, *pixmap_history;
    QIcon *homeIcon, *sendIcon, *receiveIcon, *mnsIcon, *historyIcon ;
    QFont *font_label_header, *font_label_balance, *font_label_balance_value, *font_button_control, *font_label_status;

    QHBoxLayout *item_h_layout;
    QVBoxLayout *item_v_layout;

    QGraphicsBlurEffect *blur_sendPage, *blur_receivePage, *blur_button_control, *blur_label_line, *blur_button_home, *blur_button_send, *blur_button_receive, *blur_button_mns, *blur_button_history;
    QGraphicsOpacityEffect *opacity_sendPage, *opacity_receivePage, *opacity_frame_control, *opacity_frame_line, *opacity_frame_button_icon;


    page1 *homePage;
    Page2 *sendPage;
    receive *receivePage;
    ControlDialog *controlDialogPage;
    ReceiveDailog *receiveDialogPage;
    MnsClass *mnsPage;
    HistPage *historyPage;
    Label_line *linelabel;
    ChoosePayment *choosePayment;


protected:


private slots:

    void on_button_send_clicked();

    void on_button_home_clicked();

    void on_button_control_clicked();

    void resizeEvent(QResizeEvent *event);

    void close_control_dialog();

    void on_button_receive_clicked();

    void loadReceiveDialogPage(int);

    void close_receive_dialog();

    void on_button_mns_clicked();

    void on_button_history_clicked();

    void remove_receive_address(int);

    void show_choose_alias_dialog();

    void close_choose_alias_dialog(QString);

    void close_alias_dialog();

private:
    Ui::Widget *ui;
    void setButtonIcons();
    void setFonts();
    void loadFirstPage();
    void loadSendPage();
    void loadReceivePage();
    void unsetBlur();
    void setBlur();
    void preparePages();
    void prepareBlur();
    void hidePages();
    void prepareOpacity();
    void unsetOpacity();
    void set_Opacity(double value);
    void loadMNSPage();
    void loadHistoryPage();

};

#endif // WIDGET_H
