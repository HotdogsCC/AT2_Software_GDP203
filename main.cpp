#include <raylib.h>

#include "tinyxml2.h"
#include <vector>

#include "SingletonTutorial.h"
#include "EnemyFactory.h"


void DemonstratingNoneSingleton()
{
    ErrorLogger* errorLogger = new ErrorLogger();
    errorLogger->LogError("First error");
}

void DemonstratingSingletonPt2()
{
    SingletonErrorLogger::GetInstance().LogError("Second Error");
}

void DemonstratingSingleton()
{
    SingletonErrorLogger::GetInstance().LogError("First Error");
    DemonstratingSingletonPt2();
}

void DemonstratingTemplatedSingleton()
{
    ErrorLoggerTemplatedSingleton::GetInstance().LogError("Templated error logged");
}


int main (int argv, char* argc[]){

    InitWindow(800,600, "Raylib Starter");
    SetTargetFPS(60);

    //singletons
    //DemonstratingNoneSingleton();
    //DemonstratingSingleton();
    DemonstratingTemplatedSingleton();

    //enemy factory
    EnemyFactory* eFactory = new EnemyFactory();
     
    //old instantiation
    //Enemy* e1 = eFactory->CreateEnemy("Melee", Vector2{ 200.0f, 250.0f });
    //Enemy* e2 = eFactory->CreateEnemy("Heavy", Vector2{ 300.0f, 250.0f });

    //using xml parser
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError eResult = doc.LoadFile("EnemyCollection.xml");

    //check it worked
    if (eResult != tinyxml2::XML_SUCCESS)
    {
        std::cerr << "Error loading file: " << eResult << '\n';
        return eResult;
    }

    //get the enemies
    tinyxml2::XMLElement* root = doc.RootElement();
    tinyxml2::XMLElement* enemy = root->FirstChildElement("Enemy");

    //where the enemies will be stored from the xml
    std::vector<Enemy*> enemies;

    //spawn the enemies
    while (enemy)
    {
        const char* type;
        float xpos, ypos;

        type = enemy->Attribute("type");
        enemy->QueryFloatAttribute("xpos", &xpos);
        enemy->QueryFloatAttribute("ypos", &ypos);

        Enemy* e = eFactory->CreateEnemy(type, Vector2{ xpos, ypos });
        enemies.push_back(e);

        enemy = enemy->NextSiblingElement("Enemy");
    }

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(BLACK);
        DrawText("Raylib Starter", 10, 10, 20, WHITE);

        //old draw enemies
        //e1->draw();
        //e2->draw();

        for (Enemy* e : enemies)
        {
            e->draw();
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}