#include "EnemyAircraft.h"

EnemyAircraft::EnemyAircraft(Game* game) : Aircraft(game),
 mEnemySpeed(5)
{
	mSprite = "Enemy";
	setVelocity(-mEnemySpeed, 0.0f, 0.0f);
}

void EnemyAircraft::updateCurrent(const GameTimer& gt)
{
	if (getWorldPosition().x <= -4.0f)
	{
		setPosition(rand() % 10 + 6, 0.1, 1.7 - (rand() % 34) / 10);
	}
	Entity::updateCurrent(gt);
}

void EnemyAircraft::drawCurrent() const
{
}