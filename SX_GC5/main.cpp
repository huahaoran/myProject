#include "mainwindow.h"
#include <QApplication>
#include<QWidget>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<Qpainter>
#include<QWidget>
#include<QPoint>
#include<QPolygon>
#include<QLabel>
#include<QVector>
#include<QPen>
#include<qmath.h>
#include<complex>
#include<QPixmap>
#include<QBasicTimer>

const  int ecgWave_2[]={
    0x21, 0x21, 0x22, 0x22, 0x23, 0x22, 0x22, 0x21, 0x21,
        0x20, 0x20, 0x1f, 0x1e, 0x1d, 0x1c, 0x1b, 0x1b, 0x1a,
        0x19, 0x18, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12,
        0x11, 0x11, 0x10, 0x10, 0x0f, 0x0f, 0x0e, 0x0d, 0x0c,
        0x0c, 0x0b, 0x0a, 0x09, 0x09, 0x08, 0x07, 0x06, 0x06,
        0x05, 0x05, 0x04, 0x04, 0x03, 0x03, 0x02, 0x02, 0x01,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x03, 0x06, 0x0a, 0x0e, 0x13, 0x18, 0x1d,
        0x23, 0x28, 0x2d, 0x32, 0x37, 0x3b, 0x40, 0x44, 0x49,
        0x4d, 0x51, 0x54, 0x57, 0x58, 0x5a, 0x5a, 0x5a, 0x59,
        0x59, 0x57, 0x55, 0x52, 0x50, 0x4c, 0x49, 0x45, 0x42,
        0x3e, 0x3b, 0x37, 0x34, 0x31, 0x2f, 0x2c, 0x29, 0x26,
        0x24, 0x22, 0x20, 0x1f, 0x1f, 0x1e, 0x1e, 0x1d, 0x1d,
        0x1e, 0x1f, 0x20, 0x21, 0x21, 0x22, 0x22, 0x23, 0x22,
        0x22, 0x21, 0x21, 0x20, 0x20, 0x1f, 0x1e, 0x1d, 0x1c,
        0x1b, 0x1b, 0x1a, 0x19, 0x18, 0x18, 0x17, 0x16, 0x15,
        0x14, 0x13, 0x12, 0x11, 0x11, 0x10, 0x10, 0x0f, 0x0f,
        0x0e, 0x0d, 0x0c, 0x0c, 0x0b, 0x0a, 0x09, 0x09, 0x08,
        0x07, 0x06, 0x06, 0x05, 0x05, 0x04, 0x04, 0x03, 0x03,
        0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x0a, 0x0e,
        0x13, 0x18, 0x1d, 0x23, 0x28, 0x2d, 0x32, 0x37, 0x3b,
        0x40, 0x44, 0x49, 0x4d, 0x51, 0x54, 0x57, 0x58, 0x5a,
        0x5a, 0x5a, 0x59, 0x59, 0x57, 0x55, 0x52, 0x50, 0x4c,
        0x49, 0x45, 0x42, 0x3e, 0x3b, 0x37, 0x34, 0x31, 0x2f,
        0x2c, 0x29, 0x26, 0x24, 0x22, 0x20, 0x1f, 0x1f, 0x1e,
        0x1e, 0x1d, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x21, 0x22,
        0x22, 0x23, 0x22, 0x22, 0x21,

};

const int ecgWave[] = {2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2008, 2016, 2016, 2016, 2024, 2032, 2048,
                       2064, 2064, 2064, 2072, 2080, 2080, 2080, 2088, 2096, 2104,
                       2112, 2112, 2112, 2112, 2112, 2112, 2104, 2096, 2088,
                       2080, 2080, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2032,
                       2032, 2016, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 1992, 1984, 1976,
                       1968, 1960, 1952, 1944, 1936, 1944, 1952, 2016, 2080, 2136,
                       2192, 2256, 2320, 2376, 2432, 2488, 2544, 2568, 2592, 2536,
                       2480, 2424, 2368, 2304, 2240, 2184, 2128, 2072, 2016, 1968,
                       1920, 1928, 1936, 1944, 1952, 1960, 1968, 1984, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2008, 2016, 2024, 2032, 2032,
                       2032, 2048, 2064, 2064, 2064, 2072, 2080, 2088, 2096, 2104,
                       2112, 2112, 2112, 2120, 2128, 2136, 2144, 2152, 2160, 2160,
                       2160, 2160, 2160, 2168, 2176, 2176, 2176, 2184, 2192,
                       2192, 2192, 2192, 2200, 2208, 2208, 2208, 2208, 2208, 2208,
                       2208, 2200, 2192, 2192, 2192, 2184, 2176, 2176, 2176, 2168,
                       2160, 2160, 2160, 2144, 2128, 2128, 2128, 2128, 2128, 2112,
                       2096, 2088, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2024,
                       2016, 2016, 2016, 2008, 2000, 2000, 2000, 2000, 2000,
                       2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000};
const  int ecgWave_3[]={
    0x0f, 0x10, 0x10, 0x11, 0x12, 0x12, 0x12, 0x13, 0x13,
      0x14, 0x14, 0x14, 0x14, 0x15, 0x17, 0x17, 0x17, 0x18,
      0x18, 0x19, 0x19, 0x19, 0x19, 0x1a, 0x19, 0x1a, 0x1a,
      0x1b, 0x1b, 0x1b, 0x1c, 0x1c, 0x1b, 0x1b, 0x1a, 0x1a,
      0x1a, 0x19, 0x19, 0x18, 0x18, 0x18, 0x17, 0x17, 0x15,
      0x15, 0x15, 0x14, 0x15, 0x14, 0x14, 0x14, 0x15, 0x15,
      0x14, 0x14, 0x15, 0x14, 0x14, 0x14, 0x15, 0x17, 0x17,
      0x17, 0x17, 0x18, 0x18, 0x19, 0x19, 0x19, 0x1a, 0x1b,
      0x1c, 0x1d, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x24,
      0x24, 0x26, 0x26, 0x26, 0x26, 0x24, 0x23, 0x23, 0x23,
      0x23, 0x22, 0x21, 0x20, 0x1d, 0x1d, 0x1c, 0x1c, 0x1c,
      0x1c, 0x1c, 0x1c, 0x1c, 0x1b, 0x1c, 0x1b, 0x1a, 0x1a,
      0x19, 0x18, 0x17, 0x15, 0x14, 0x12, 0x12, 0x11, 0x10,
      0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f

};

class QWidgetDraw: public QWidget
{
public:
    int ecgdata;
    qreal index;
    qreal range;
    QPixmap*pixmap;
  QWidgetDraw(QWidget* parent=0):QWidget(parent){
                                                            QBasicTimer*timer=new QBasicTimer();
                                                            timer->start(5,this);

        pixmap= new QPixmap(this->width(),this->height());
        pixmap->fill(Qt::black);//将背景调整成黑色
       //变量定义
        index=0;//当前水平方向数据更新位置
        range=0;//圆周角度
        ecgdata=0;
    }

virtual void timerEvent(QTimerEvent*event)
{
     drawWaveToPixmap();
    this->update();
}
  drawWaveToPixmap()
  {
      QPainter pixPainter;
      pixPainter.begin(this->pixmap);
      drawecgwave(&pixPainter);
      pixPainter.end();
  }
  drawecgwave(QPainter*painter)
  {
                                                      QPen pen;
                                                      pen.setWidth(2);
                                                      pen.setColor(QColor("red"));
                                                      painter->setPen(pen);
                                                     //擦除当前列
                                                      painter->save();//保持当前配置
                                                      pen.setColor(Qt::black);
                                                      painter->setPen(pen);

                                                      index=index+1;
                                                      if(index>width())
                                                          index=0;

                                                      painter->drawLine(index,0,index,height());
                                                      painter->restore();

                                                      //绘图
                                                      qreal height=this->height();
                                                      QPoint linestart;
                                                      QPoint lineend;
                                                      linestart.setX(index-1);
                                                      lineend.setX(index);



                                                      qreal value=ecgWave_2[ecgdata];
                                                      int y= round(height/2-((value-0)/100)*height/2);
                                                      linestart.setY(y);
                                                      ecgdata=ecgdata+5;
                                                      if(ecgdata>=sizeof(ecgWave_2)/sizeof(int))
                                                          ecgdata=0;
                                                      value=ecgWave_2[ecgdata];
                                                      y= round(height/2-((value-0)/100)*height/2);
                                                      lineend.setY(y);
                                                      painter->drawLine(linestart,lineend);
  }
    virtual void paintEvent(QPaintEvent*event)
    {
        QPainter*painter=new QPainter();
        painter->begin(this);
        painter->resetTransform();//坐标系复位
        painter->drawPixmap(0,0,*pixmap);
        painter->resetTransform();//坐标系复位
        painter->end();
    }
    drawTriangle(QPainter*painter)
    {

    }

};


class Ecg2: public  QWidget
{
public:
    Ecg2(QWidget*parent=0):QWidget(parent)
    {
        this->setWindowFlags (Qt::FramelessWindowHint);
        this->setStyleSheet("background-color:black");
        QLabel*title=new QLabel("SPO2");
        title->setStyleSheet(("color:white"));
        QWidgetDraw*wavewin2=new QWidgetDraw();
        QVBoxLayout*layout2=new QVBoxLayout();

        layout2->addWidget(title);
        layout2->addWidget(wavewin2);
        layout2->setStretch(0,1);
        layout2->setStretch(1,5);
        this->setLayout(layout2);
    }
};//心跳图

class QWidgetDraw1: public QWidget
{
public:

    qreal index;
    qreal range;
    int ecgdata=0;
    QPixmap*pixmap;
  QWidgetDraw1(QWidget* parent=0):QWidget(parent){
                                                                QBasicTimer*timer=new QBasicTimer();
                                                                timer->start(10,this);

        pixmap= new QPixmap(this->width(),this->height());
        pixmap->fill(Qt::black);//将背景调整成黑色
       //变量定义
        index=0;//当前水平方向数据更新位置
        range=0;//圆周角度
    }

virtual void timerEvent(QTimerEvent*event)
{

     drawWaveToPixmap();
    this->update();
}
  drawWaveToPixmap()
  {
      QPainter pixPainter;
      pixPainter.begin(this->pixmap);
      drawsinewave(&pixPainter);
      pixPainter.end();
  }
    virtual void paintEvent(QPaintEvent*event)
    {
      QPainter*painter=new QPainter();
      painter->begin(this);
      painter->resetTransform();//坐标系复位
      painter->drawPixmap(0,0,*pixmap);
      painter->resetTransform();//坐标系复位
      painter->end();
    }
    drawTriangle(QPainter*painter)
    {
        QPen pen;
        pen.setWidth(2);
        pen.setColor(QColor("red"));
        painter->setPen(pen);
       //擦除当前列
        painter->save();//保持当前配置
        pen.setColor(Qt::black);
        painter->setPen(pen);

        index=index+1;
        if(index>width())
            index=0;

        painter->drawLine(index,0,index,height());
        painter->restore();

        //绘图
        qreal height=this->height();
        QPoint linestart;
        QPoint lineend;
        linestart.setX(index-1);
        lineend.setX(index);



        qreal value=ecgWave[ecgdata];
        int y= round(height/2-((value-2048)/600)*height/2);
        linestart.setY(y);
        ecgdata=ecgdata+5;
        if(ecgdata>=sizeof(ecgWave)/sizeof(int))
            ecgdata=0;
        value=ecgWave[ecgdata];
        y= round(height/2-((value-2048)/600)*height/2);
        lineend.setY(y);
        painter->drawLine(linestart,lineend);

    }

   drawsinewave(QPainter*painter)
   {
       QPen pen;
       pen.setWidth(2);
       pen.setColor(QColor("green"));
       painter->setPen(pen);
      //擦除当前列
       painter->save();//保持当前配置
       pen.setColor(Qt::black);
       painter->setPen(pen);

       index=index+1;
       if(index>width())
           index=0;

       painter->drawLine(index,0,index,height());
       painter->restore();

       //绘图
       qreal height=this->height();
       QPoint linestart;
       QPoint lineend;
       linestart.setX(index-1);
       lineend.setX(index);



       qreal value=ecgWave[ecgdata];
       int y= round(height/2-((value-2048)/600)*height/2);
       linestart.setY(y);
       ecgdata=ecgdata+5;
       if(ecgdata>=sizeof(ecgWave)/sizeof(int))
           ecgdata=0;
       value=ecgWave[ecgdata];
       y= round(height/2-((value-2048)/600)*height/2);
       lineend.setY(y);
       painter->drawLine(linestart,lineend);




   }

};

class Ecg: public  QWidget
{
public:
    Ecg(QWidget*parent=0):QWidget(parent)
    {
        this->setWindowFlags (Qt::FramelessWindowHint);
        this->setStyleSheet("background-color:black");
        QLabel*title=new QLabel("ECGⅡ      x1");
        title->setStyleSheet(("color:white"));
        QWidgetDraw1*wavewin=new QWidgetDraw1();
        QVBoxLayout*layout=new QVBoxLayout();

        layout->addWidget(title);
        layout->addWidget(wavewin);
        layout->setStretch(0,1);
        layout->setStretch(1,5);
        this->setLayout(layout);
    }
};//正弦图1

class QWidgetDraw2: public QWidget
{
public:
    int ecgdata=0;
    qreal index;
    qreal range;
    QPixmap*pixmap;
  QWidgetDraw2(QWidget* parent=0):QWidget(parent){
                                                                        QBasicTimer*timer=new QBasicTimer();
                                                                        timer->start(10,this);

        pixmap= new QPixmap(this->width(),this->height());
        pixmap->fill(Qt::black);//将背景调整成黑色
       //变量定义
        index=0;//当前水平方向数据更新位置
        range=0;//圆周角度
    }

virtual void timerEvent(QTimerEvent*event)
{
     drawWaveToPixmap();
    this->update();
}
  drawWaveToPixmap()
  {
      QPainter pixPainter;
      pixPainter.begin(this->pixmap);
      drawsinewave(&pixPainter);
      pixPainter.end();
  }
    virtual void paintEvent(QPaintEvent*event)
    {
        QPainter*painter=new QPainter();
        painter->begin(this);
        painter->resetTransform();//坐标系复位
        drawsinewave(painter);
        painter->drawPixmap(0,0,*pixmap);
        painter->resetTransform();//坐标系复位
        painter->end();
    }
    drawTriangle(QPainter*painter)
    {
        QPen*pen = new QPen();
        pen->setWidth(1);
        pen->setColor(QColor("#F40002"));
        painter->setPen(*pen);
        //
        int height =this->height();
        int width = this->width();
        int y;
//        int dir=0;
        qreal R=M_PI/100;
        qreal A=height/3;
        for(int x=0;x<width;x++)
            painter->drawPoint(x,height/2+A*qSin(R*x));


    }

                          drawsinewave(QPainter*painter)
   {
                              QPen pen;
                              pen.setWidth(2);
                              pen.setColor(QColor("yellow"));
                              painter->setPen(pen);
                             //擦除当前列
                              painter->save();//保持当前配置
                              pen.setColor(Qt::black);
                              painter->setPen(pen);

                              index=index+1;
                              if(index>width())
                                  index=0;

                              painter->drawLine(index,0,index,height());
                              painter->restore();

                              //绘图
                              qreal height=this->height();
                              QPoint linestart;
                              QPoint lineend;
                              linestart.setX(index-1);
                              lineend.setX(index);



                              qreal value=ecgWave_3[ecgdata];
                              int y= round(height/2-((value-0)/100)*height/2);
                              linestart.setY(y);
                              ecgdata=ecgdata+5;
                              if(ecgdata>=sizeof(ecgWave_3)/sizeof(int))
                                  ecgdata=0;
                              value=ecgWave_3[ecgdata];
                              y= round(height/2-((value-0)/100)*height/2);
                              lineend.setY(y);
                              painter->drawLine(linestart,lineend);





   }

};

class Ecg3: public  QWidget
{
public:
    Ecg3(QWidget*parent=0):QWidget(parent)
    {
        this->setWindowFlags (Qt::FramelessWindowHint);
        this->setStyleSheet("background-color:black");
        QLabel*title=new QLabel("RESP      x1");
        title->setStyleSheet(("color:white"));
        QWidgetDraw2*wavewin=new QWidgetDraw2();
        QVBoxLayout*layout=new QVBoxLayout();

        layout->addWidget(title);
        layout->addWidget(wavewin);
        layout->setStretch(0,1);
        layout->setStretch(1,5);
        this->setLayout(layout);
    }
};//正弦图2


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
     MainWindow w;
     w.setWindowTitle(QString("L6_zy_HuYiDong"));
    //标题
    QWidget*title =new QWidget();
    title->setStyleSheet("background-color:rgb(100,100,100)");
    //左边框
    Ecg*wave=new Ecg();
    wave->setStyleSheet("background-color:black");
    Ecg2*wave2= new Ecg2();
    wave2->setStyleSheet("background-color:black");
    Ecg3*wave3=new Ecg3();
    wave3->setStyleSheet("background-color:black");
    //
    QVBoxLayout*layout = new QVBoxLayout();
   layout->addWidget(wave);
    layout->addWidget(wave2);
    layout->addWidget(wave3);
    //右边框定义
    QWidget*A1=new QWidget();
    A1->setStyleSheet("background-color:rgb(100,100,100)");
    QWidget*A2=new QWidget();
    A2->setStyleSheet("background-color:rgb(100,100,200)");
    QWidget*B1=new QWidget();
    B1->setStyleSheet("background-color:rgb(200,100,100)");
    QWidget*C1=new QWidget();
    C1->setStyleSheet("background-color:rgb(200,100,50)");
    QWidget*C2=new QWidget();
    C2->setStyleSheet("background-color:rgb(50,100,150)");
    QWidget*D1=new QWidget();
    D1->setStyleSheet("background-color:rgb(100,50,100)");
    QWidget*D2=new QWidget();
    D2->setStyleSheet("background-color:rgb(50,200,150)");
    //右边相应水平框的组合
    QHBoxLayout*layout1 = new QHBoxLayout();
    layout1->addWidget(A1);
    layout1->addWidget(A2);
    QHBoxLayout*layout2 = new QHBoxLayout();
    layout2->addWidget(B1);
    QHBoxLayout*layout3 = new QHBoxLayout();
    layout3->addWidget(C1);
    layout3->addWidget(C2);
    QHBoxLayout*layout4 = new QHBoxLayout();
    layout4->addWidget(D1);
    layout4->addWidget(D2);

    //右边框垂直布局
     QVBoxLayout*right = new QVBoxLayout();
     right->addLayout(layout1);
     right->addLayout(layout2);
     right->addLayout(layout3);
     right->addLayout(layout4);
    //整体布局的比例
    QHBoxLayout*down=new QHBoxLayout();
    down->addLayout(layout);
    down->addLayout(right);
    down->setStretch(0,2);
    down->setStretch(1,1);
    //
    QVBoxLayout*Main=new QVBoxLayout();
    Main->addWidget(title);
    Main->addLayout(down);
    Main->setStretch(0,1);
    Main->setStretch(1,10);
   //主界面创建
    QWidget*window= new QWidget();
    window->resize(800,480);
    window->setLayout(Main);
//    window->setLayout(layout);


    window->setParent(&w);
    w.resize(800,480);
    w.show();

    return a.exec();
}
