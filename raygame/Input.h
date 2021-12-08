#pragma once
#include "Actor.h"

class Input
{
public:
	Input();
	Input(Actor*, const char*);
	virtual ~Input();
	const char* getName();
	void getOwner(Actor*);
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void end();
	virtual void onCollision();

private:
	Actor* m_owner;
	const char* m_name;
};

