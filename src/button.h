#pragma once

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Button:public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Button(QString name, QGraphicsItem* parent=NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

signals:
    void clicked();

private:
    QGraphicsTextItem* text;
};
