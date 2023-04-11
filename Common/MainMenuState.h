#pragma once
#include "State.h"
#include "StateStack.h"
#include "Background.h"
#include "SceneNode.hpp"
#include "SpriteNode.h"
#include "Background.h"
#include "Label.h"


class MainMenuState : public State
{
public:
	MainMenuState(StateStack& stack, Context context);

	void		buildState();
	void		draw();
	bool		update(const GameTimer& dt);
	bool		handleEvent(Command& event);


private:
	bool IsSatesPlaying();
	enum Layer
	{
		BACKGROUND,
		AIR,
		LAYER_COUNT
	};
	Game* mGame;

	SceneNode* mSceneGraph;
	std::array<SceneNode*, LAYER_COUNT>	mSceneLayers;
	States::ID mState;
	XMFLOAT4							mWorldBounds;
	Background* mBackground;
	Label* mLogoLabel;
	Label* mPlayLabel;
	Label* mExitLabel;

	// Inherited via State
};