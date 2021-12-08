#include "Enemy.h"

AIMovement Enemy::addMovement(AIMovement())
{
	return AIMovement();
}

bool Enemy::removeMovement(AIMovement())
{
	return false;
}

bool Enemy::removeMovement(const char)
{
	return false;
}

AIMovement Enemy::getMovement(const char*)
{
	return AIMovement();
}

bool Enemy::GetTargetInSight()
{
	return false;
}
