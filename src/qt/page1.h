#ifndef PAGE1_H
#define PAGE1_H

#include <QWidget>
#include <QFont>

namespace Ui {
class page1;
}

class page1 : public QWidget
{
    Q_OBJECT

public:
    explicit page1(QWidget *parent = nullptr);
    ~page1();

protected:
    QFont *font_label_main, *font_label_total_value;

private:
    Ui::page1 *ui;
    void setFont();
};

#endif // PAGE1_H
