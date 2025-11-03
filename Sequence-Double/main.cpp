#include <raylib.h>
#include "raymath.h"

#include "Board.h"
#include "DoubleBuffer.h"
#include "Game.h"
#include "Ticker.h"

int main (int argv, char* argc[]){

    int dimx = 25;
    int dimy = 25;
    int px = 16;

    InitWindow(dimx * px,dimy * px, "Conway's Game of Life");
    SetTargetFPS(60);

    Board gameboard1(dimx, dimy);
    Board gameboard2(dimx, dimy);
    DoubleBuffer bufferedboard(&gameboard1, &gameboard2);

    bool tick = false;
    float tickTime = 1.0f;
    Ticker ticker{ 1.0f };

    while (!WindowShouldClose()) {

        Vector2 mousePos = GetMousePosition();
        int mpx = mousePos.x / px;
        int mpy = mousePos.y / px;

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            bufferedboard.Swap();
            bufferedboard.WriteBuffer().At(mpx, mpy) = !bufferedboard.WriteBuffer().At(mpx, mpy);
            bufferedboard.Swap();
        }

        if (IsKeyPressed(KEY_LEFT))
        {
            tickTime += 0.1f;
            tickTime = Clamp(tickTime, 0.01f, 1.0f);
            ticker.SetNewTickTime(tickTime);
        }

        if (IsKeyPressed(KEY_RIGHT))
        {
            tickTime -= 0.1f;
            tickTime = Clamp(tickTime, 0.01f, 1.0f);
            ticker.SetNewTickTime(tickTime);
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            tick = !tick;
        }

        if (IsKeyPressed(KEY_ENTER) || tick && ticker.CanTick())
        {
	        for (int y = 0; y < dimy; y++)
	        {
		        for (int x = 0; x < dimx; x++)
		        {
                    bufferedboard.WriteBuffer().At(x, y) = Game::NewValue(&bufferedboard.ReadBuffer(), x, y);
		        }
	        }

            bufferedboard.Swap();
        }



        BeginDrawing();
        bufferedboard.ReadBuffer().Draw(px);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
