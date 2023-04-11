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
	if (GetAsyncKeyState(' ') & 0x8000)
	{
		mGame->PopCurrentRenderState();
		mGame->PushCurrentRenderState(States::Menu);
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
	mBackground->setPosition(5.0, 0, 0.0);
	mBackground->setScale(20.0, 1.0, 20.0);
	mSceneGraph->attachChild(std::move(backgroundSprite));

	std::unique_ptr<Label> label(new Label(mGame, "TitleScreen", States::Title));
	mLabel = label.get();
	mLabel->setPosition(0.0, 1, 0.0);
	mLabel->setScale(4.0, 1.0, 2.0);
	mSceneGraph->attachChild(std::move(label));
#pragma endregion

	mSceneGraph->build();

}
#pragma endregion