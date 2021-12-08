#pragma once
#include "AIMovement.h"
class Enemy :
	public Actor
{
public:
	AIMovement addMovement(AIMovement());
	bool removeMovement(AIMovement());
	bool removeMovement(const char);
	AIMovement getMovement(const char*);
	bool GetTargetInSight();

private:
	AIMovement** m_owner;
};

