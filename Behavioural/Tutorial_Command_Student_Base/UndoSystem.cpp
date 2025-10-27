#include "UndoSystem.h"

#include "ICommand.h"

void UndoSystem::Undo()
{
	//check we have an action to undo
	if (undo.empty())
	{
		return;
	}

	//grab the last command
	std::shared_ptr<ICommand> lastCommand = undo.top();

	//undo it
	lastCommand->Undo();

	//remove it from the undo stack
	undo.pop();

	//add it to the redo stack
	redo.push(lastCommand);

}

void UndoSystem::Redo()
{
	//check we have an action to redo
	if (redo.empty())
	{
		return;
	}

	//grab the last command
	std::shared_ptr<ICommand> lastCommand = redo.top();

	//redo it
	lastCommand->Do();

	//remove it from redo stack
	redo.pop();

	//yoink it back on the undo
	undo.push(lastCommand);
}

void UndoSystem::Add(ICommand* cmd)
{
	//emplace the command into the undo stack
	undo.emplace(cmd);

	//clear the redo stack
	redo = {};
}

