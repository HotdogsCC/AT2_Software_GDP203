#include "SpecialAttack.h"
#include <chrono>
#include <thread>
#include <iostream>

void SpecialAttack::PlaySound(const char* soundName, double volume)
{
	std::cout << "Play Sound: " << soundName << ", " << volume << std::endl;
}

void SpecialAttack::SpawnParticles(const char* particleEffectName, float duration)
{
	std::cout << "Particle: " << particleEffectName << ", " << duration << std::endl;
}

void SpecialAttack::Move(Vector2 position, Player& player)
{
	//player.move(position);
	std::cout << "Move: " << position.x << ", " << position.y << '\n';
}

void SpecialAttack::WaitNSeconds(double seconds)
{
	std::cout << "Wait: " << seconds << '\n';
	long long lSeconds = seconds;
	std::this_thread::sleep_for(std::chrono::seconds(lSeconds));
}

void SpecialAttack::DealDamage(Player& targetedEnemy, float damageAmount)
{
	//std::cout << "Dealing Damage: " << targetedEnemy.getName() << ", " << damageAmount << '\n';
}



