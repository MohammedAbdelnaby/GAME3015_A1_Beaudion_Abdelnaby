/*
* Names: Mohammed , Sam
* Date: 2023-01-30
* Last Modified: 2023-01-30
*/
#pragma once
#include "SceneNode.hpp"
#include "Aircraft.hpp"
#include "SpriteNode.h"

class World 
{
public:
	explicit							World(Game* window);
	void								update(const GameTimer& gt);
	void								draw();
	void								HandleInputUpdate();
	void								ScrollBackground();
	void								UpdateEnemies();

	//void								loadTextures();
	void								buildScene();


private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};


private:
	Game*								mGame;

	SceneNode*							mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;

	XMFLOAT4							mWorldBounds;
	XMFLOAT2		    				mSpawnPosition;
	float								mScrollSpeed;
	float								mEnemySpeed;
	Aircraft*							mPlayerAircraft;
	SpriteNode*							mBackground,*mWorld;
	std::list<Aircraft*>				mEnemies;
};
