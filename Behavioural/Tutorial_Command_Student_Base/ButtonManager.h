#pragma once
#include "IGraphic.h"
#include <vector>
#include <raylib.h>
#include <functional>
#include <memory>

class Button
{
protected:
    Rectangle zone;
    int id;
    std::function<void(int id, int x, int y)> cmd;
public:
    Button(int i, Rectangle z, std::function<void(int id, int x, int y)> c);
    void Press(int x, int y);
    virtual ~Button();
};

class TextButton : public Button, public IGraphic
{
    const char* n;
public:
    TextButton(const char* name, int i, Rectangle z, std::function<void(int id, int x, int y)> c);
    virtual void Draw() override;
};

class ButtonManager
{
    std::vector<std::shared_ptr<Button>> buttons;
public:
    void AddButton(Button* b);
    void ButtonHit(int x, int y, int key);
};