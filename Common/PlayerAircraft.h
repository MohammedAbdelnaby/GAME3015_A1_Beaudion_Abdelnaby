#pragma once
#include "Aircraft.hpp"
#include <string>
#include "CommandQueue.h"

class PlayerAircraft :
    public Aircraft
{
public:
    PlayerAircraft(Game* game);
private:
    void		 updateCurrent(const GameTimer& gt) override;
    void		 drawCurrent() const;
    unsigned int getCategory() override;

public:
    void handleEvent(CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);
};

struct AircraftMover
{
    AircraftMover(float vx, float vy, float vz) :
        velocity(vx, vy, vz)
    {
    }
    void operator() (SceneNode& node, const GameTimer& gt) const
    {
        PlayerAircraft& aircraft = static_cast<PlayerAircraft&>(node);
        aircraft.setVelocity(velocity);
    }
    XMFLOAT3 velocity;
};