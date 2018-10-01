// Autor    Alex Krieg
// Version  00.00.00
// Datum    01.10.2018

#include "rect.h"

Rect::Rect(QPainter *p)
{
    painter = p;
    color(QColor(0,255,0));
    frameColor(color());
    frameSize(3);
    begin(QPoint(0,0));
    end(QPoint(100,100));
    angle(0);
    drawPos(QPoint(0,0));
    frame(true);
    infill(true);
}
Rect::~Rect()
{

}

void Rect::color(QColor col)
{
    _color = col;
}
QColor Rect::color()
{
    return _color;
}
void Rect::frameColor(QColor col)
{
    _frameColor = col;
}
QColor Rect::frameColor()
{
    return _frameColor;
}
void Rect::frameSize(unsigned int size)
{
    _frameSize = size;
}
unsigned int Rect::frameSize()
{
    return _frameSize;
}
void Rect::begin(QPoint pos)
{
    _posA = pos;
}
QPoint Rect::begin()
{
    return _posA;
}
void Rect::end(QPoint pos)
{
    _posB = pos;
}
QPoint Rect::end()
{
    return _posB;
}
void   Rect::angle(geometry::Angle angle)
{
    _angle = angle;
}
void   Rect::angle(float degree)
{
    _angle.degree(degree);
}
float  Rect::angle()
{
    return _angle.degree();
}
void   Rect::rotate(float deltaDegree)
{
    _angle+deltaDegree;
}
void   Rect::drawPos(QPoint pos)
{
    _drawPos = pos;
}
QPoint Rect::drawPos()
{
    return _drawPos;
}
void Rect::frame(bool enable)
{
    _frameEnable = enable;
}
bool Rect::frame()
{
    return _frameEnable;
}
void Rect::infill(bool enable)
{
    _infillEnable = enable;
}
bool Rect::infill()
{
    return _infillEnable;
}

void Rect::draw()
{
      QRect rect(_posA,_posB);

      if(_infillEnable)
      {
          QBrush brush(_color);
          painter->setBrush(brush);
      }
      if(_frameEnable)
      {
          QPen linepen(_frameColor);
          linepen.setWidth(_frameSize);
          painter->setPen(linepen);
      }

      painter->translate(_drawPos);
      painter->rotate(_angle.degree());

      painter->drawRect(rect);

      painter->rotate(-_angle.degree());
      painter->translate(QPoint(-_drawPos.x(),-_drawPos.y()));
}
