#ifndef RECT_H
#define RECT_H
//Autor                 Alex Krieg
//Datum                 01.10.2018
#define RECT_VERSION   "00.00.00"


#include "rect_global.h"
#include <geometry.h>

class RECTSHARED_EXPORT Rect : private QObject
{
    Q_OBJECT
    public:
        Rect(QPainter *p);
        ~Rect();

        void        color(QColor col);
        QColor      color();
        void        frameColor(QColor col);
        QColor      frameColor();
        void        frameSize(unsigned int size);
        unsigned int frameSize();
        void        begin(QPoint pos);
        QPoint      begin();
        void        end(QPoint pos);
        QPoint      end();
        void        angle(geometry::Angle angle);
        void        angle(float degree);
        float       angle();
        void        rotate(float deltaDegree);
        void        drawPos(QPoint pos);
        QPoint      drawPos();

        void        frame(bool enable);
        bool        frame();
        void        infill(bool enable);
        bool        infill();

    signals:

    public slots:
        void draw();
    private slots:

    private:
        QRect       _rect;
        QPainter   *painter;
        QPoint      _posA;
        QPoint      _posB;
        QPoint      _drawPos;
        unsigned int _frameSize;
        geometry::Angle _angle;
        QColor      _color;
        QColor      _frameColor;
        bool        _frameEnable;
        bool        _infillEnable;
};

#endif // RECT_H
