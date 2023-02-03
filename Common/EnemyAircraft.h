#pragma once
#include "Aircraft.hpp"
#include <string>

class EnemyAircraft :
    public Aircraft
{
public:
    EnemyAircraft(Game* game);
private:
    void		updateCurrent(const GameTimer& gt) override;
    void		drawCurrent() const;

    float mEnemySpeed;
};