#ifndef HISTPAGE_H
#define HISTPAGE_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QScrollArea>
#include <QFont>
#include <QPixmap>
#include <QHBoxLayout>
#include <QSpacerItem>

class HistPage : public QWidget
{
    Q_OBJECT
public:
    explicit HistPage(QWidget *parent = nullptr);

    void loadpage();
    void resizeEvent(QResizeEvent *event);
    void setTable_history();
    void loadTableHeader_history();
    void setFontTable_history();
    void setTableBody_history();
    void loadTableFooter_history();


private:
    QWidget *main_widget, *widget_table;
    QPushButton *button;
    QVBoxLayout *main_layout;
    QGridLayout *loGrid;
    QLabel *label_space_header, *label_date_header, *label_label_header, *label_message_header, *label_amount_header, *label_footer;
    QLabel **label_icon_check, **label_date, **label_label, **label_message, **label_amount;
    QFont *font_history;
    QScrollArea *scrollArea;
    QSpacerItem *verticalSpacer1;
    QPixmap *pixmap_checked_icon, *pixmap_loading_icon;




signals:

public slots:
};

#endif // HISTPAGE_H
