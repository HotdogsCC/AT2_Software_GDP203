#include "ButtonManager.h"

Button::Button(int i, Rectangle z, std::function<void(int id, int x, int y)> c) : id{ i }, zone{ z }, cmd{ c } {}
void Button::Press(int x, int y) {
    x = x - zone.x;
    y = y - zone.y;
    if (x > 0 && x < zone.width &&
        y > 0 && y < zone.height)
        cmd(id, x, y);
}
Button::~Button() {}



TextButton::TextButton(const char* name, int i, Rectangle z, std::function<void(int id, int x, int y)> c) : Button{ i,z,c }, n{ name } {}
void TextButton::Draw() {
    DrawRectangle(zone.x, zone.y, zone.width, zone.height, Color{ 64,128,255,255 });
    auto m = MeasureText(n, 14);
    DrawText(n, zone.x + zone.width / 2 - m / 2, zone.y + zone.height / 2 - 14 / 2, 14, Color{ 0,0,0,255 });
}

void ButtonManager::AddButton(Button* b) {
    buttons.emplace_back(b);
}
void ButtonManager::ButtonHit(int x, int y, int key) {
    for (auto b : buttons)
    {
        b->Press(x, y);
    }
}
