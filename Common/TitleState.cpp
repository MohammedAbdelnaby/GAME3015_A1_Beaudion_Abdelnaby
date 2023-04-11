#include "TitleState.h"
#include "Game.hpp"


TitleState::TitleState(StateStack& stack, Context context)
	: State(stack, context),
	mSceneGraph(new SceneNode(context.mGame, States::Title))
	, mGame(context.mGame)
	, mBackground(nullptr)
	, mWorldBounds(-1.5f, 1.5f, 200.0f, 0.0f) //Left, Right, Down, Up
{
}

void TitleState::draw()
{
	mSceneGraph->draw();
}

bool TitleState::update(const GameTimer& dt)
{
	mSceneGraph->update(dt);
	if (GetAsyncKeyState('S') & 0x8000)
	{
		mGame->SetCurrentState(States::Game);
	}
	return true;
}

bool TitleState::handleEvent(Command& event)
{
	// If any key is pressed, trigger the next screen


	return true;
}
void TitleState::buildState()
{
#pragma region Scenery

	std::unique_ptr<Background> backgroundSprite(new Background(mGame, States::Title));
	mBackground = backgroundSprite.get();
	//mBackground->setPosition(mWorldBounds.x, mWorldBounds.z);
	mBackground->setPosition(5.0, 0, 0.0);
	mBackground->setScale(20.0, 1.0, 20.0);
	mSceneGraph->attachChild(std::move(backgroundSprite));
#pragma endregion

	mSceneGraph->build();

}
#pragma endregion