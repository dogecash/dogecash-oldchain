#ifndef TOGGLESWITCH_HPP
#define TOGGLESWITCH_HPP

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class ToggleSwitch : public QAbstractButton
{
    Q_OBJECT

    Q_PROPERTY(QBrush brush READ brush WRITE setBrush)
    Q_PROPERTY(bool status READ status WRITE setStatus)

    public:

        ToggleSwitch(QWidget * = Q_NULLPTR);
        ToggleSwitch(const QBrush &, QWidget * = Q_NULLPTR);

        QSize sizeHint(void) const override;

        virtual QBrush brush(void) const;
        virtual void setBrush(const QBrush &);

        virtual bool status(void) const;
        virtual void setStatus(bool);

    signals:

        void statusChanged(bool);

    protected:

        void paintEvent(QPaintEvent*) override;
        void mouseReleaseEvent(QMouseEvent *) override;

        bool m_status;
        int m_margin;

        QBrush m_bodyBrush;
        QBrush m_headBrush;
};

inline QBrush ToggleSwitch::brush(void) const
{
    return this->m_headBrush;
}

inline void ToggleSwitch::setBrush(const QBrush &brush)
{
    this->m_headBrush = brush;
}

inline bool ToggleSwitch::status(void) const
{
    return this->m_status;
}

inline void ToggleSwitch::setStatus(bool status)
{
    this->m_status = status;
}

#endif // TOGGLESWITCH_HPP
