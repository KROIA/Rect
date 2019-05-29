#ifndef RECT_H
#define RECT_H
//Autor                 Alex Krieg
//Datum                 28.05.2019
#define RECT_VERSION   "00.01.00"


#include "rect_global.h"
#include <geometry.h>

enum RotationPos{
    middle = 0,
    cornerUL = 1,
    cornerUR = 2,
    cornerDL = 3,
    cornerDR = 4
};

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
        void        frameSize(int size);
        int         frameSize();
        void        begin(QPoint pos);
        QPoint      begin();
        void        end(QPoint pos);
        QPoint      end();
        void        angle(geometry::Angle angle);
        void        angle(float degree);
        float       angle();
        void        rotate(float deltaDegree);
        void        rotatePos(int rotPos);
        void        rotationPoint(QPoint rotationPoint);
        QPoint      rotationPoint();
        void        drawPos(QPoint pos);
        QPoint      drawPos();

        void        frame(bool enable);
        bool        frame();
        void        infill(bool enable);
        bool        infill();

        void        middlePoint(QPointF middlePoint);
        QPointF     middlePoint();

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
        int         _frameSize;
        geometry::Angle _angle;
        QColor      _color;
        QColor      _frameColor;
        bool        _frameEnable;
        bool        _infillEnable;
        int         _rotationPos;

        QPointF     _middlePoint;
        QPoint      _middlePointOffset;
        QPoint      _rotationPoint;
};

#endif // RECT_H
