#include <raylib.h>
#include "GameObject.h"

int main (int argv, char* argc[]){

    InitWindow(800,450, "vibing");
    SetTargetFPS(60);

    GameObject* player = new GameObject(new TransformComponent(Vector2{ 200.0f, 300.0f }),
        new MoveableComponent(5.0f),
        new SpriteComponent("SmartFella.png"));

    while (!WindowShouldClose()) {

        player->Update();

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("We out here", 300, 4, 20, LIGHTGRAY);

        player->Draw();

        EndDrawing();
    }

    delete player;

    CloseWindow();

    return 0;
}