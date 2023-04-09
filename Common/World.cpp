///*
//* Names: Mohammed , Sam
//* Date: 2023-01-30
//* Last Modified: 2023-01-30
//*/
//#include "World.hpp"
//#include <time.h> 
//#include <iostream>
//
//World::World(Game* game)
//	: mSceneGraph(new SceneNode(game))
//	, mGame(game)
//	, mPlayerAircraft(nullptr)
//	, mBackground(nullptr)
//	, mWorldBounds(-1.5f, 1.5f, 200.0f, 0.0f) //Left, Right, Down, Up
//	, mSpawnPosition(0.f, 0.f)
//{
//}
//
//void World::update(const GameTimer& gt)
//{
//	mPlayerAircraft->setVelocity(0.f, 0.f, 0.f);
//	processInput();
//	// Forward commands to the scene graph
//	while (!mCommandQueue.isEmpty())
//		mSceneGraph->onCommand(mCommandQueue.pop(), gt);
//	// Regular update step
//	mSceneGraph->update(gt);
//}
//
//void World::draw()
//{
//	mSceneGraph->draw();
//}
//
//
//void World::buildScene()
//{
//#pragma region Player
//
//	srand(time(NULL));
//	std::unique_ptr<PlayerAircraft> player(new PlayerAircraft(mGame));
//	mPlayerAircraft = player.get();
//	mPlayerAircraft->setPosition(-2, 0.1, 0.0);
//	mPlayerAircraft->setScale(1.0, 1.0, 1.0);
//	mSceneGraph->attachChild(std::move(player));
//
//#pragma endregion
//
//#pragma region Enemies
//
//	std::unique_ptr<EnemyAircraft> enemy1(new EnemyAircraft(mGame));
//	auto raptor = enemy1.get();
//	raptor->setPosition(rand() % 10 + 6, 0.05, 1.7 - rand() % 3);
//	raptor->setScale(1.0, 1.0, 1.0);
//	raptor->setWorldRotation(0, XM_PI * 2, 0);
//	mSceneGraph->attachChild(std::move(enemy1));
//	mEnemies.push_back(raptor);
//
//	std::unique_ptr<EnemyAircraft> enemy2(new EnemyAircraft(mGame));
//	auto raptor2 = enemy2.get();
//	raptor2->setPosition(rand() % 10 + 6, 0.05, 1.7 - rand() % 3);
//	raptor2->setScale(1.0, 1.0, 1.0);
//	raptor2->setWorldRotation(0, XM_PI * 2, 0);
//	mSceneGraph->attachChild(std::move(enemy2));
//	mEnemies.push_back(raptor2);
//
//#pragma endregion
//
//#pragma region Scenery
//
//	std::unique_ptr<Background> backgroundSprite(new Background(mGame));
//	mBackground = backgroundSprite.get();
//	//mBackground->setPosition(mWorldBounds.x, mWorldBounds.z);
//	mBackground->setPosition(5.0, 0, 0.0);
//	mBackground->setScale(20.0, 1.0, 20.0);
//	mSceneGraph->attachChild(std::move(backgroundSprite));
//
//	std::unique_ptr<Planets> planetsSprite1(new Planets(mGame));
//	auto Planet1 = planetsSprite1.get();
//	//mBackground->setPosition(mWorldBounds.x, mWorldBounds.z);
//	Planet1->setPosition(rand() % 10 + 6, 0.05, 1.7 - rand() % 3);
//	Planet1->setScale(1.0, 1.0, 1.0);
//	mSceneGraph->attachChild(std::move(planetsSprite1));
//	mPlanets.push_back(Planet1);
//
//	std::unique_ptr<Planets> planetsSprite2(new Planets(mGame));
//	auto Planet2 = planetsSprite2.get();
//	//mBackground->setPosition(mWorldBounds.x, mWorldBounds.z);
//	Planet2->setPosition(rand() % 10 + 6, 0.05, 1.7 - rand() % 3);
//	Planet2->setScale(1.0, 1.0, 1.0);
//	mSceneGraph->attachChild(std::move(planetsSprite2));
//	mPlanets.push_back(Planet2);
//#pragma endregion
//
//	mSceneGraph->build();
//}
//
//CommandQueue& World::getCommandQueue()
//{
//	return mCommandQueue;
//}
//
//void World::processInput()
//{
//	CommandQueue& commands = getCommandQueue();
//	mPlayerAircraft->handleEvent(commands);
//	mPlayerAircraft->handleRealtimeInput(commands);
//}