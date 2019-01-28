#ifndef PAGE2_H
#define PAGE2_H

#include <QWidget>
#include <toggleswitch.hpp>
#include <QFont>
#include <QPushButton>
#include <QLineEdit>
#include <QPixmap>
#include <QIcon>
#include <QGraphicsOpacityEffect>
//#include <labelbutton.h>

namespace Ui {
class Page2;
}

class Page2 : public QWidget
{
    Q_OBJECT

public:
    explicit Page2(QWidget *parent = nullptr);
    ~Page2();

    void load_toogle_button();
    void setFont_page2();
    void prepare_opacity_page2();
    void unset_opacity_page2();
    void set_opacity_page2();
    void setAlias(QString a);

    ToggleSwitch *swiftx_toggle;
protected:
    QFont *font_label_main2, *font_little2;
    QGraphicsOpacityEffect *opacity_label_pay, *opacity_widget_pay, *opacity_label_label, *opacity_edit_label_value, *opacity_label_amount, *opacity_edit_amount_value, *opacity_button_send, *opacity_label_swiftx, *opacity_label_advance, *opacity_swiftx_toggle;
    QLabel *label_advance;

signals:
    void Click_search();

private slots:
    void label_clicked();
    void on_button_search_icon_clicked();

private:
    Ui::Page2 *ui;
};

#endif // PAGE2_H
