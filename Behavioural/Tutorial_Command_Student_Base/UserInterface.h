#pragma once

#include <unordered_map>
#include <raylib.h>
#include <functional>

enum State {
    PRESSED,
    RELEASED
};

using KeyFunction = std::function<void(int key, State state)>;

class ButtonManager;

class UserInterface
{
    std::unordered_map<int, KeyFunction> keymap;
    ButtonManager* bm;

    Vector2 mouse_position;
    bool left_mouse_down;

    void UpdateMouse();
    void UpdateKeyboard();

public:
    UserInterface(ButtonManager* b);
    void Update();
    Vector2 GetMousePosition() const;
    bool GetMouseDown() const;
};