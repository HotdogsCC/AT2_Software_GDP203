#include <raylib.h>

int main (int argv, char* argc[]){

    InitWindow(800,600, "Raylib Starter");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(BLACK);
        DrawText("Raylib Starter", 10, 10, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}