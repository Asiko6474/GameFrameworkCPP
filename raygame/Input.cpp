#include "Input.h"
#include "raylib.h"

Input::Input()
{
}

Input::Input(Actor*, const char*)
{
}

Input::~Input()
{
}

const char* Input::getName()
{
	return nullptr;
}

void Input::getOwner(Actor*)
{
}

void Input::Start()
{
}

void Input::Update()
{
	int xDirection;
	int yDirection;
	if (IsKeyDown(KEY_W))
	{
		 yDirection = -1;
	}
	else if (IsKeyDown(KEY_S))
	{
		yDirection = 1;
	}
	else if (IsKeyDown(KEY_A))
	{
		xDirection = -1;
	}
	else if (IsKeyDown(KEY_D))
	{
		xDirection = 1;
	}
}

void Input::Draw()
{
}

void Input::end()
{
}

void Input::onCollision()
{
}
