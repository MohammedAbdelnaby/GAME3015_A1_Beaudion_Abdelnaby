/*
* Names: Mohammed , Sam
* Date: 2023-01-30
* Last Modified: 2023-01-30
*/
#pragma once
#include "SceneNode.hpp"
#include "Aircraft.hpp"
#include "PlayerAircraft.h"
#include "EnemyAircraft.h"
#include "SpriteNode.h"
#include "Background.h"
#include "Planets.h"

class World 
{
public:
	explicit							World(Game* window);
	void								update(const GameTimer& gt);
	void								draw();

	//void								loadTextures();
	void								buildScene();


private:
	enum Layer
	{
		BACKGROUND,
		AIR,
		LAYER_COUNT
	};


private:
	Game*								mGame;

	SceneNode*							mSceneGraph;
	std::array<SceneNode*, LAYER_COUNT>	mSceneLayers;

	XMFLOAT4							mWorldBounds;
	XMFLOAT2		    				mSpawnPosition;
	float								mEnemySpeed;
	PlayerAircraft*						mPlayerAircraft;
	Background*							mBackground;
	std::list<Planets*>					mPlanets;
	std::list<EnemyAircraft*>			mEnemies;
};
