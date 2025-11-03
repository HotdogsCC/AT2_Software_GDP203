#pragma once

#include <functional>

template <typename T>
class DoubleBuffer
{
public:
	DoubleBuffer(T* ft, T* bk) :
		front{ ft }, back{ bk } {
	}

	const T& ReadBuffer() const
	{
		return *back;
	}

	T& WriteBuffer()
	{
		return *front;
	}

	void Swap()
	{
		std::swap(back, front);
	}
private:
	T* front;
	T* back;


};

