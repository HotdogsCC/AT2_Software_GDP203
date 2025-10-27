#pragma once
#include <memory>
#include <stack>

class ICommand;

class UndoSystem
{
public:
	//undoes the last action
	void Undo();
	//redoes the last action
	void Redo();

	//add a command into the redo stack
	void Add(ICommand* cmd);

private:
	std::stack<std::shared_ptr<ICommand>> undo;
	std::stack<std::shared_ptr<ICommand>> redo;
};
