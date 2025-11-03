#pragma once
#include <cassert>
#include <raylib.h>

class Ticker
{
public:
	Ticker(float time) : timeUntilNextTick{ time }, tickRate{ time } {}
	void SetNewTickTime(float tm) {
		assert(tm > 0);
		tickRate = tm; timeUntilNextTick = tickRate;
	}
	bool CanTick() {
		if (tickRate <= 0)
			return true;
		timeUntilNextTick -= GetFrameTime();
		bool can_tick = false;
		while (timeUntilNextTick < 0) {
			can_tick = true;
			timeUntilNextTick += tickRate;
		}
		return can_tick;
	}
private:
	float timeUntilNextTick;
	float tickRate;
};

