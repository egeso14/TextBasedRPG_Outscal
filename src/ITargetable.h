#pragma once

class ITargetable 
{
public: 
	virtual bool TakeDamage(float amount) = 0;
	virtual void Heal(float amount) = 0;
};