#pragma once

class LightsOutBoard;

void Toggle(LightsOutBoard* board, int x, int y);
void LightsOutLevelMaker(LightsOutBoard* board, int steps, int seed = -1);
bool IsGameOver(LightsOutBoard* b);