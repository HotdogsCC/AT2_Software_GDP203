#pragma once
#include "IGraphic.h"

class LightsOutBoard;
class UserInterface;

class DrawLightsOutBoard : public IGraphic
{
    LightsOutBoard* board;
    UserInterface* interface;
    Color bd, edges, on;
    int size;

    int SquareSize() const;

public:
    DrawLightsOutBoard(LightsOutBoard* brd, UserInterface* i, int size, Color b, Color e, Color o);
    void Draw();
};