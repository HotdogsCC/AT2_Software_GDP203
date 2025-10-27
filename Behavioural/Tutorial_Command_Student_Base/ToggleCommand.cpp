#include "ToggleCommand.h"
#include "LightsOutBoard.h"
#include "LightsOutState.h"
#include "Utility.h"

void ToggleCommand::Do()
{
    Toggle(board, x, y);
    state->num_steps--;
}

void ToggleCommand::Undo()
{
    Toggle(board, x, y);
    state->num_steps++;
}
