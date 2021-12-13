#include "MainScene.h"
#include "Sprite.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
void MainScene::start()
{
	Player* player = new Player(50, 50, "player");
	player->getTransform()->setScale({ 50,50 });

	addActor(player);
};
