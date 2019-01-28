/*
LabelButton: used to accept input on QLabels
 */
#include <QLabel>
#include <QMouseEvent>
#include <QEnterEvent>
class LabelButton : public QLabel
{
    Q_OBJECT

public:
    LabelButton(QWidget *parent);
    LabelButton(QWidget *parent, QRect geo, QString imageString);
    LabelButton(QWidget *parent, int i);

    int getIndex();
public:
    int index;
private:
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    virtual void enterEvent(QEvent * event);
    virtual void leaveEvent(QEvent * event);
//    void mouseMoveEvent(QMouseEvent *event);

signals:
    void Clicked(int i);
    void Entered(int i);
    void Leaved(int i);
    void Pressed(LabelButton *label);
    void Selected();
};
