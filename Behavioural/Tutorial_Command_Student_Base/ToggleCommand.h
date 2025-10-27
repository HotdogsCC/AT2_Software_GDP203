#pragma once
#include "ICommand.h"

struct LightsOutState;
class LightsOutBoard;

class ToggleCommand : public ICommand
{
public:
	ToggleCommand(LightsOutBoard* inBoard, LightsOutState* inState, int inX, int inY) :
		board(inBoard), state(inState), x(inX), y(inY) {}

	virtual void Do() override;
	virtual void Undo() override;

private:
	LightsOutBoard* const board;
	LightsOutState* const state;
	const int x, y;
};
