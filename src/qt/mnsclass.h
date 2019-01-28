#ifndef MNSCLASS_H
#define MNSCLASS_H

#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>
#include <QFont>
#include <QLabel>

namespace Ui {
class MnsClass;
}

class MnsClass : public QWidget
{
    Q_OBJECT

public:
    explicit MnsClass(QWidget *parent = nullptr);
    ~MnsClass();

    void loadTable_mns();
    void loadTableHeader_mns();
    void loadTableBody_mns();
    void setfont_mns();


private:
    Ui::MnsClass *ui;
    QWidget *widget_table;
    QScrollArea *scrollArea;
    QGridLayout *loGrid;
    QFont *font_label_mns, *font_button_mns;
    QLabel *label_alias_header, *label_address_header, *label_protocal_header, *label_status_header, *label_seen_header, *label_pubkey_header, *label_active_header;
    QLabel **label_alias, **label_address, **label_protocal, **label_status, **label_seen, **label_pubkey, **label_active;
};

#endif // MNSCLASS_H
