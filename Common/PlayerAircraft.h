#pragma once
#include "Aircraft.hpp"
#include <string>

class PlayerAircraft :
    public Aircraft
{
public:
    PlayerAircraft(Game* game);
private:
    void		updateCurrent(const GameTimer& gt) override;
    void		drawCurrent() const;
};
