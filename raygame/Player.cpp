#include "Player.h"
#include "inputComponent.h"
#include "MoveComponent.h"
#include "Sprite.h"
void Player::start()
{
	Actor::start();

	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*> (addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(10);
	m_spriteComponent = dynamic_cast<Sprite*> (addComponent(new Sprite("Images/player.png")));
	//Set spawn point
	//Set move speed
	//Set position clamps
}

void Player::update(float deltaTime)
{
	Actor::update(deltaTime);

	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	m_moveComponent->setVelocity(moveDirection * 10);
}
