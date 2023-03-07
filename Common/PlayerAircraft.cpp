#include "PlayerAircraft.h"

PlayerAircraft::PlayerAircraft(Game* game) : Aircraft(game)
{
	mSprite = "Player";
}

void PlayerAircraft::updateCurrent(const GameTimer& gt)
{
	setVelocity(0.0f, 0.0f, 0.0f);
	if (GetAsyncKeyState('W') & 0x8000)
	{
		setVelocity(0.0f, 0.0f, 1.0f);
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		setVelocity(0.0f, 0.0f, -1.0f);
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		setVelocity(1.0f, 0.0f, 0.0f);
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		setVelocity(-1.0f, 0.0f, 0.0f);
	}
	
	Entity::updateCurrent(gt);
}

void PlayerAircraft::drawCurrent() const
{
}

unsigned int PlayerAircraft::getCategory()
{
	return Category::PlayerAircraft;
}

void PlayerAircraft::handleEvent(CommandQueue& commands)
{
}

void PlayerAircraft::handleRealtimeInput(CommandQueue& commands)
{
	const float playerSpeed = 1.f;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		Command moveLeft;
		moveLeft.category = Category::PlayerAircraft;
		moveLeft.action = derivedAction<PlayerAircraft>(
			AircraftMover(-playerSpeed, 0.f, 0.f));
		commands.push(moveLeft);
	}
}