#pragma once
#include <raylib.h>

class IGraphic
{
protected:
    Rectangle rect;
public:
    void SetRectangle(Rectangle r);
    const Rectangle& GetRectangle() const;

    virtual void Draw() = 0;
    virtual ~IGraphic();
};