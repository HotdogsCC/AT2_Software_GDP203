#include "DrawLightsOutBoard.h"
#include "LightsOutBoard.h"
#include "UserInterface.h"
#include <raylib.h>


int DrawLightsOutBoard::SquareSize() const {
    return size / board->GetDim();
}

DrawLightsOutBoard::DrawLightsOutBoard(LightsOutBoard* brd, UserInterface* i, int size, Color b, Color e, Color o) : board{ brd }, size{ size },
bd{ b }, interface{ i }, edges{ e }, on{ o }
{
    rect = Rectangle{ 0,0,(float)size,(float)size };
}


void DrawLightsOutBoard::Draw() {
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, bd);
    for (int y = 0; y < board->GetDim(); ++y) {
        for (int x = 0; x < board->GetDim(); ++x) {
            if (auto p = board->Get(x, y)) {
                DrawRectangle((x * SquareSize()) + rect.x, (y * SquareSize()) + rect.y, SquareSize(), SquareSize(), on);
            }
        }
    }

    for (int y = 0; y < board->GetDim(); ++y) {
        DrawLine(rect.x, rect.y + y * SquareSize(), rect.x + size, rect.y + y * SquareSize(), edges);

    }
    for (int x = 0; x < board->GetDim(); ++x) {
        DrawLine(rect.x + x * SquareSize(), rect.y, rect.x + x * SquareSize(), rect.y + size, edges);
    }
    auto mp = interface->GetMousePosition();
    int x = (int)(mp.x / (rect.width / board->GetDim()));
    int y = (int)(mp.y / (rect.height / board->GetDim()));

    if (x >= 0 && x < board->GetDim() && y >= 0 && y < board->GetDim()) {
        DrawRectangle(x * SquareSize() + rect.x, y * SquareSize() + rect.y, SquareSize(), SquareSize(), Color{ 128,255,96,255 });
    }
}
