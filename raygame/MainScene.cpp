#include "MainScene.h"
#include "Actor.h"
#include "Sprite.h"
#include "MoveComponent.h"
#include "Transform2D.h"

void MainScene::start()
{
	Actor* player = new Actor(50, 50, "player");
	player->addComponent(new Sprite("images/player.png"));
	player->addComponent(new MoveComponent());
	player->getTransform()->setScale({ 50,50 });
	addActor(player);
};
