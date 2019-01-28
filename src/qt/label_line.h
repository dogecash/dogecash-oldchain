#ifndef LABEL_LINE_H
#define LABEL_LINE_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPixmap>

class Label_line : public QWidget
{
    Q_OBJECT
public:
    explicit Label_line(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event);

private:
    QLabel *line_label;
    QWidget *widget;
    QHBoxLayout *layout;
    QSpacerItem *left_item, *right_item;

signals:

public slots:
};

#endif // LABEL_LINE_H
