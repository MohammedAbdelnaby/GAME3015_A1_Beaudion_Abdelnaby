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