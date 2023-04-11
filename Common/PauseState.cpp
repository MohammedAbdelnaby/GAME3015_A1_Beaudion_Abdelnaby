#include "PauseState.h"
#include "Game.hpp"


PauseState::PauseState(StateStack& stack, Context context)
	: State(stack, context),
	mState(States::Pause)
	, mSceneGraph(new SceneNode(context.mGame, mState))
	, mGame(context.mGame)
{
}

void PauseState::draw()
{
	mSceneGraph->draw();
}

bool PauseState::update(const GameTimer& dt)
{
	if (!IsSatesPlaying())
	{
		return true;
	}
	mSceneGraph->update(dt);
	if (GetAsyncKeyState(' ') & 0x8000)
	{
		mGame->PopCurrentRenderState();
		mGame->PushCurrentRenderState(States::Menu);
	}
	return true;
}

bool PauseState::handleEvent(Command& event)
{
	// If any key is pressed, trigger the next screen


	return true;
}
bool PauseState::IsSatesPlaying()
{
	for (int i = 0; i < mGame->GetCurrentState().size(); i++)
	{
		if (mGame->GetCurrentState()[i] == mState)
		{
			return true;
		}
	}
	return false;
}
void PauseState::buildState()
{
#pragma region Scenery

	std::unique_ptr<Label> label(new Label(mGame, "Pause", mState));
	mLabel = label.get();
	mLabel->setPosition(0.0, 1, 0.0);
	mLabel->setScale(4.0, 1.0, 2.0);
	mSceneGraph->attachChild(std::move(label));
#pragma endregion

	mSceneGraph->build();

}
#pragma endregion