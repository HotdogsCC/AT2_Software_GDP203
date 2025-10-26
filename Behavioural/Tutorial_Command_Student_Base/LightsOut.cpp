#include "LightsOutState.h"
#include "UserInterface.h"
#include "LightsOutBoard.h"
#include "DrawLightsOutBoard.h"
#include "ButtonManager.h"
#include "Utility.h"

#include <memory>
#include <vector>
#include <functional>
#include <random>
#include <thread>

#include <raylib.h>
#include <raymath.h>
#include <stdexcept>
#include <chrono>

using namespace std::chrono_literals;

int main() {

    SetConfigFlags(FLAG_MSAA_4X_HINT);

    //Game state objects
    LightsOutState state;

    //Loop until QUIT
    while (!state.quit) {

        state.game_over = false;
        state.num_steps = state.level;
        
        //Set up the component and their relationships via pointers
        LightsOutBoard board{ (int)state.size };
        ButtonManager bm;
        UserInterface ui{ &bm };
        DrawLightsOutBoard drawboard{&board,&ui,(int)state.size * 32,state.off_light,state.lines,state.on_light};

        //Set up 'buttons' on each tile
        //Maps mouse position to a tile position and then toggles the cross around that tile
        auto board_fn = [&](int id, int xp, int yp) {
            int x = xp / 32;
            int y = yp / 32;
            Toggle(&board, x, y);
            state.num_steps--;
            };

        auto board_button = new Button{ 0, Rectangle{0,0,(float)state.size * 32,(float)state.size * 32}, board_fn };
        bm.AddButton(board_button);

       
        //Make the level but toggle 'level' number of times as a form of difficulty
        LightsOutLevelMaker(&board, state.level, state.level);

        //Make a new window
        InitWindow(state.size * 32 + 256, state.size * 32, "Lights Out");

        //Individual game loop
        while (!state.game_over) {

            //Quit if close button pushed
            if (WindowShouldClose()) {
                state.quit = true;
                break;
            }

            //Update the UI and get mouse/keyboard events
            ui.Update();

            //Draw
            BeginDrawing();
            ClearBackground(BLACK);
            drawboard.Draw();

            //Draw UI on the side
            char steps[256];
            sprintf_s(steps, 256, "%i steps to complete", state.num_steps);
            DrawText(steps, 32*7 + 14, 14, 14, Color{ 255,255,255,255 });

            //Check gameover condition
            if (IsGameOver(&board)) {
                state.game_over = true;
                //Make the game harder!
                state.level++;
                //Output win message
                DrawText("Winner Winner!\nChicken Dinner!", 6, 6, 14, Color{ 0,128,255,255 });
            }

            EndDrawing();
        }

        //If game over but NOT quitting, just wait 2 seconds.
        if(!state.quit)
            std::this_thread::sleep_for(2s);

        CloseWindow();
    }
    return 0;
}