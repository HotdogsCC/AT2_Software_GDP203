#pragma once

class ICommand
{
public:
	virtual void Do() = 0;
	virtual void Undo(){}
};