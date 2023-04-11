#pragma once
#include "GameState.h"
#include "Game.hpp"


GameState::GameState(StateStack& stack, Context context)
	: State(stack, context),
	mSceneGraph(new SceneNode(context.mGame, States::Title))
	, mGame(context.mGame)
	, mBackground(nullptr)
	, mWorldBounds(-1.5f, 1.5f, 200.0f, 0.0f) //Left, Right, Down, Up
{
}

void GameState::draw()
{
	mSceneGraph->draw();
}

bool GameState::update(const GameTimer& dt)
{
	mSceneGraph->update(dt);
	if (GetAsyncKeyState('S') & 0x8000)
	{
		mGame->PopCurrentRenderState();
		mGame->PushCurrentRenderState(States::Title);
	}
	return true;
}

bool GameState::handleEvent(Command& event)
{
	// If any key is pressed, trigger the next screen


	return true;
}
void GameState::buildState()
{
#pragma region Player
	std::unique_ptr<PlayerAircraft> player(new PlayerAircraft(mGame, States::Game));
	mPlayerAircraft = player.get();
	mPlayerAircraft->setPosition(-2, 0.1, 0.0);
	mPlayerAircraft->setScale(1.0, 1.0, 1.0);
	mSceneGraph->attachChild(std::move(player));
#pragma endregion
#pragma region Enemies
	std::unique_ptr<EnemyAircraft> enemy1(new EnemyAircraft(mGame, States::Game));
	auto raptor = enemy1.get();
	raptor->setPosition(rand() % 10 + 6, 0.05, 1.7 - rand() % 3);
	raptor->setScale(1.0, 1.0, 1.0);
	raptor->setWorldRotation(0, XM_PI * 2, 0);
	mSceneGraph->attachChild(std::move(enemy1));
	mEnemies.push_back(raptor);
	std::unique_ptr<EnemyAircraft> enemy2(new EnemyAircraft(mGame, States::Game));
	auto raptor2 = enemy2.get();
	raptor2->setPosition(rand() % 10 + 6, 0.05, 1.7 - rand() % 3);
	raptor2->setScale(1.0, 1.0, 1.0);
	raptor2->setWorldRotation(0, XM_PI * 2, 0);
	mSceneGraph->attachChild(std::move(enemy2));
	mEnemies.push_back(raptor2);
#pragma endregion
#pragma region Scenery
	std::unique_ptr<Background> backgroundSprite(new Background(mGame, States::Game));
	mBackground = backgroundSprite.get();
	//mBackground->setPosition(mWorldBounds.x, mWorldBounds.z);
	mBackground->setPosition(5.0, 0, 0.0);
	mBackground->setScale(20.0, 1.0, 20.0);
	mSceneGraph->attachChild(std::move(backgroundSprite));
	std::unique_ptr<Planets> planetsSprite1(new Planets(mGame, States::Game));
	auto Planet1 = planetsSprite1.get();
	//mBackground->setPosition(mWorldBounds.x, mWorldBounds.z);
	Planet1->setPosition(rand() % 10 + 6, 0.05, 1.7 - rand() % 3);
	Planet1->setScale(1.0, 1.0, 1.0);
	mSceneGraph->attachChild(std::move(planetsSprite1));
	mPlanets.push_back(Planet1);
	std::unique_ptr<Planets> planetsSprite2(new Planets(mGame, States::Game));
	auto Planet2 = planetsSprite2.get();
	//mBackground->setPosition(mWorldBounds.x, mWorldBounds.z);
	Planet2->setPosition(rand() % 10 + 6, 0.05, 1.7 - rand() % 3);
	Planet2->setScale(1.0, 1.0, 1.0);
	mSceneGraph->attachChild(std::move(planetsSprite2));
	mPlanets.push_back(Planet2);
#pragma endregion
	mSceneGraph->build();

}
#pragma endregion