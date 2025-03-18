#pragma once

struct Condition;
class ITargetable 
{
public: 
	virtual bool TakeDamage(float amount) = 0;
	virtual void Heal(float amount) = 0;
	virtual void InflictCondition(Condition* condition) = 0;
	virtual void UpdateConditions() = 0;
};