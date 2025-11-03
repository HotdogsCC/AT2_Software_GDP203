#include <chrono>
#include <raylib.h>

int main (int argv, char* argc[]){

    constexpr int screenWidth = 1024;
    constexpr int screenHeight = 768;

    constexpr float groundHeight = 100;

    constexpr float playerSize = 20;
    Vector2 playerPosition = { 300, screenHeight - (groundHeight + playerSize) };

    InitWindow(screenWidth, screenHeight, "Raylib Starter");
    SetTargetFPS(60);

    static auto previousTime = std::chrono::high_resolution_clock::now();

    while (!WindowShouldClose()) {
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = now - previousTime;
        previousTime = now;

        float deltaTime = duration.count();

        //update the player
        constexpr float walkVelocity = 100.0f;
        if (IsKeyDown(KEY_LEFT))
        {
            playerPosition.x -= walkVelocity * deltaTime;
        }
        else if (IsKeyDown(KEY_RIGHT))
        {
            playerPosition.x += walkVelocity * deltaTime;
        }


        BeginDrawing();

        ClearBackground(WHITE);
        DrawRectangle(0, screenHeight - groundHeight, 2000, 20, BLACK);
        DrawCircleV(playerPosition, playerSize, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}