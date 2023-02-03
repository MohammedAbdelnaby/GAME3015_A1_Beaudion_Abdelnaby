#pragma once
#include "SpriteNode.h"
#include <string>

class Background :
    public SpriteNode
{
public:
    Background(Game* game);
private:
    void		updateCurrent(const GameTimer& gt) override;
    void		drawCurrent() const;
    float		mScrollSpeed;
};