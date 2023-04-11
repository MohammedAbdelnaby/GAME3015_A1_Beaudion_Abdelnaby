#pragma once
#include "State.h"
#include "StateStack.h"
#include "Background.h"
#include "SceneNode.hpp"
#include "SpriteNode.h"
#include "Background.h"
#include "CommandQueue.h"


class TitleState : public State
{
public:
	TitleState(StateStack& stack, Context context);
	
	void		buildState();
	void		draw();
	bool		update(const GameTimer& dt);
	bool		handleEvent(Command& event);


private:
	enum Layer
	{
		BACKGROUND,
		AIR,
		LAYER_COUNT
	};
	Game* mGame;

	SceneNode* mSceneGraph;
	std::array<SceneNode*, LAYER_COUNT>	mSceneLayers;
	CommandQueue						mCommandQueue;

	XMFLOAT4							mWorldBounds;
	Background* mBackground;

	// Inherited via State
};