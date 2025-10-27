#pragma once

struct Vector2
{
    float x;
    float y;
};

class Player; 

class SpecialAttack
{
public:
    virtual ~SpecialAttack() {}
    virtual void Activate(Player& player) = 0;

protected:
    void PlaySound(const char* soundName, double volume);
    void SpawnParticles(const char* particleEffectName, float duration);
    void Move(Vector2 position, Player& player);
    void WaitNSeconds(double seconds);
    void DealDamage(Player& targetedEnemy, float damageAmount);
};


