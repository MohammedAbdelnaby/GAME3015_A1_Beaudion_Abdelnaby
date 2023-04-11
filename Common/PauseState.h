#pragma once
#include "State.h"
#include "StateStack.h"
#include "Background.h"
#include "SceneNode.hpp"
#include "SpriteNode.h"
#include "Label.h"


class PauseState : public State
{
public:
	PauseState(StateStack& stack, Context context);

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
	States::ID mState;
	SceneNode* mSceneGraph;
	std::array<SceneNode*, LAYER_COUNT>	mSceneLayers;
	Label* mLabel;

	// Inherited via State
};