#ifndef __ITEM_TYPE_H
#define __ITEM_TYPE_H
#include<QApplication>
#include<QMouseEvent>
#include<QRect>
class ItemType:public QObject
{
    Q_OBJECT
private:
    QRect _rect;
protected:
    bool iEmit;//每个item只能发送一次信号
public:
    ItemType(QRect irect):_rect(irect){iEmit = false;}
    virtual void show(QWidget *pwidget)=0;
    virtual void __mousePressEvent(QMouseEvent *evt);
    virtual void emitSignal()=0;
    virtual ~ItemType(){};
    QRect rect();
};
class NumItem:public ItemType
{
   Q_OBJECT
signals:
    void pressNumItem();
private:
    int num;
public:
    NumItem(QRect irect,int num);
    virtual void emitSignal();
    virtual void show(QWidget *pwidget);
    ~NumItem(){}
};
class MineItem:public ItemType
{
    Q_OBJECT
signals:
    void pressMineItem();
public:
    using ItemType::ItemType;
    virtual void emitSignal();
    virtual void show(QWidget *pwidget);
    ~MineItem(){};
};
#endif