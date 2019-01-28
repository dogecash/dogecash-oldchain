#include <toggleswitch.hpp>
#include <QFont>

ToggleSwitch::ToggleSwitch(QWidget *parent) :
    QAbstractButton(parent),
    m_status(false),
    m_margin(0),
    m_bodyBrush(Qt::lightGray)
{
    this->setBrush(QColor(Qt::darkGreen));
}

ToggleSwitch::ToggleSwitch(const QBrush &brush, QWidget *parent) :
    QAbstractButton(parent),
    m_status(false),
    m_margin(0),
    m_bodyBrush(Qt::lightGray)
{

    this->setBrush(brush);
}

void ToggleSwitch::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::NoPen);

    if(true == this->isEnabled())
    {
//QColor("#29333d")
        this->brush().setColor(QColor("#b6a27e"));
        painter.setBrush(this->m_status ? QColor("#b6a27e") : QColor("#29333d"));
        painter.setOpacity(1);
        painter.setRenderHint(QPainter::Antialiasing, true);

        painter.drawRoundedRect(QRect(0, 0, this->width(),
            this->height()), 14, 14);

        painter.setBrush(this->m_bodyBrush);
        painter.setOpacity(1);
        QFont *font = new QFont();
        font->setFamily("Chivo");
        font->setPixelSize(13);
        font->setLetterSpacing(QFont::AbsoluteSpacing, 1.2);
        painter.setBrush(Qt::white);
        if(true == this->m_status)
        {
            painter.setPen(QColor("#f2f2f2"));
            painter.drawEllipse(this->width() - this->height()+1 , (this->height() / 2) - (this->height() / 2) + 2,
                this->height()-4, this->height()-4);
            painter.setFont(*font);
            painter.drawText(8,19,"YES");

        }
        else
        {
            painter.setPen(QColor("#526475"));
            painter.drawEllipse(QRectF(2, (this->height() / 2) - (this->height() / 2) + 2, this->height()-4, this->height()-4));
            painter.setFont(*font);
            painter.drawText(37,19, "NO");
        }
    }
    else
    {
        painter.setBrush(Qt::black);
        painter.setOpacity(0.12);

        painter.drawRoundedRect(QRect(0, 0, this->width(),
                                      this->height()), 16, 16);

        painter.setOpacity(1.0);
//        painter.setBrush(QColor("#BDBDBD"));
        painter.setBrush(Qt::blue);


        painter.drawEllipse(QRectF((this->width() / 2), (this->height() / 2) - (this->height() / 2),
            this->height(), this->height()));
    }
}

void ToggleSwitch::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton)
    {
        this->m_status = !this->m_status;
        emit ToggleSwitch::statusChanged(this->m_status);
    }

    QAbstractButton::mouseReleaseEvent(event);
}

QSize ToggleSwitch::sizeHint(void) const
{
    return QSize(this->width() + (2 * this->m_margin), this->height() + (2 * this->m_margin));
}
