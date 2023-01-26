#include "World.hpp"
#include <time.h> 
#include <iostream>

World::World(Game* game)
	: mSceneGraph(new SceneNode(game))
	, mGame(game)
	, mPlayerAircraft(nullptr)
	, mBackground(nullptr)
	, mWorldBounds(-1.5f, 1.5f, 200.0f, 0.0f) //Left, Right, Down, Up
	, mSpawnPosition(0.f, 0.f)
	, mScrollSpeed(1.0f)
	, mEnemySpeed(7)
{
}

void World::update(const GameTimer& gt)
{
	HandleInputUpdate();
	ScrollBackground();
	UpdateEnemies();
	mSceneGraph->update(gt);
}



void World::draw()
{
	mSceneGraph->draw();
}

void World::HandleInputUpdate()
{
	mPlayerAircraft->setVelocity(0.0f, 0.0f, 0.0f);

	if (GetAsyncKeyState('W') & 0x8000)
	{
		mPlayerAircraft->setVelocity(0.0f, 0.0f, 1.0f);
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		mPlayerAircraft->setVelocity(0.0f, 0.0f, -1.0f);
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		mPlayerAircraft->setVelocity(1.0f, 0.0f, 0.0f);
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		mPlayerAircraft->setVelocity(-1.0f, 0.0f,0.0f);
	}
}

void World::ScrollBackground()
{
	if (mBackground->getWorldPosition().x <= -5.0)
	{
		mBackground->setPosition(5.0, 0, 0.0);
	}
}

void World::UpdateEnemies()
{
	for each (Aircraft* enemy in mEnemies)
	{
		if (enemy->getWorldPosition().x <= -4.0)
		{
			enemy->setPosition(rand() % 10 + 6, 0.1, 1.7 - (rand() % 34)/10);
		}
	}
}

void World::buildScene()
{
	srand(time(NULL));
	std::unique_ptr<Aircraft> player(new Aircraft(Aircraft::Eagle, mGame));
	mPlayerAircraft = player.get();
	mPlayerAircraft->setPosition(-2, 0.1, 0.0);
	mPlayerAircraft->setScale(1.0, 1.0, 1.0);
	mSceneGraph->attachChild(std::move(player));

	std::unique_ptr<Aircraft> enemy1(new Aircraft(Aircraft::Raptor, mGame));
	auto raptor = enemy1.get();
	raptor->setPosition(rand() % 10 + 6, 0.1, 1.7 - rand() % 3);
	raptor->setScale(1.0, 1.0, 1.0);
	raptor->setVelocity(-mEnemySpeed, 0.0f, 0.0f);
	raptor->setWorldRotation(0, XM_PI * 2, 0);
	mSceneGraph->attachChild(std::move(enemy1));
	mEnemies.push_back(raptor);

	std::unique_ptr<Aircraft> enemy2(new Aircraft(Aircraft::Raptor, mGame));
	auto raptor2 = enemy2.get();
	raptor2->setPosition(rand() % 10 + 6, 0.1, 1.7 - rand() % 3);
	raptor2->setScale(1.0, 1.0, 1.0);
	raptor2->setVelocity(-mEnemySpeed, 0.0f, 0.0f);
	raptor2->setWorldRotation(0, XM_PI * 2, 0);
	mSceneGraph->attachChild(std::move(enemy2));
	mEnemies.push_back(raptor2);

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(mGame));
	mBackground = backgroundSprite.get();
	//mBackground->setPosition(mWorldBounds.x, mWorldBounds.z);
	mBackground->setPosition(5.0, 0, 0.0);
	mBackground->setScale(20.0, 1.0, 20.0);
	mBackground->setVelocity(-mScrollSpeed, 0, 0.0);
	mSceneGraph->attachChild(std::move(backgroundSprite));

	mSceneGraph->build();
}
