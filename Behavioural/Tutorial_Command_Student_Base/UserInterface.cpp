#include "UserInterface.h"
#include "ButtonManager.h"

void UserInterface::UpdateMouse() {
    mouse_position = ::GetMousePosition();

    int mc = IsMouseButtonPressed(MouseButton::MOUSE_BUTTON_RIGHT);

    //LMB to make/confirm a move
    left_mouse_down = IsMouseButtonPressed(MouseButton::MOUSE_BUTTON_LEFT) ? 1 : 0;
    if (left_mouse_down)
        bm->ButtonHit(mouse_position.x, mouse_position.y, State::PRESSED);
}

void UserInterface::UpdateKeyboard() {

    for (auto& k : keymap) {
        if (IsKeyDown(k.first)) {
            k.second(k.first, State::PRESSED);
        }
    }

    //if (IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)) {
        //if (IsKeyPressed(KEY_Z))
            //undos->Undo();
        //if (IsKeyPressed(KEY_Y))
            //undos->Redo();
    //}
}

UserInterface::UserInterface(ButtonManager* b)
    : bm{ b }
    , left_mouse_down{ false }
    , mouse_position{ 0,0 } {
}

void UserInterface::Update() {
    UpdateMouse();
    UpdateKeyboard();
}

Vector2 UserInterface::GetMousePosition() const { return mouse_position; }
bool UserInterface::GetMouseDown() const { return left_mouse_down; }
