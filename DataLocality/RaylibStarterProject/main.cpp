#include <raylib.h>

#include "TransformComponent.h"
#include "AIComponent.h"
#include "SpriteComponent.h"

int main(int argv, char* argc[]) {

    InitWindow(800, 450, "vibing");
    SetTargetFPS(60);

    const int MAX_ENTITIES = 10;
    const int NUM_ENTITIES = 3;

    TransformComponent* transformComponents = new TransformComponent[MAX_ENTITIES];
    AIComponent* aiComponents = new AIComponent[MAX_ENTITIES];
    SpriteComponent* spriteComponents = new SpriteComponent[MAX_ENTITIES];

    transformComponents[0] = TransformComponent(Vector2{ 400.0f, 350.0f });
    transformComponents[1] = TransformComponent(Vector2{ 400.0f, 50.0f });
    transformComponents[2] = TransformComponent(Vector2{ 700.0f, 200.0f });

    aiComponents[0] = AIComponent(200.0, 1.0f);
    aiComponents[1] = AIComponent(200.0, 1.0f);
    aiComponents[2] = AIComponent(200.0f, 1.0f, false);

    spriteComponents[0] = spriteComponents[1] = spriteComponents[2] = SpriteComponent("SmartFella.png");


    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        for (int i = 0; i < NUM_ENTITIES; i++)
        {
            aiComponents[i].Update(transformComponents[i], deltaTime);
        }


        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("We out here", 300, 4, 20, LIGHTGRAY);

        for (int i = 0; i < NUM_ENTITIES; i++)
        {
            spriteComponents[i].Draw(transformComponents[i]);
        }

        EndDrawing();
    }

    delete[] aiComponents;
    delete[] transformComponents;
    delete[] spriteComponents;

    CloseWindow();

    return 0;
}