#pragma once
#include "SpriteNode.h"
#include <string>

class Label :
    public SceneNode
{
public:
    Label(Game* game, std::string labelName, States::ID id);
    virtual void		buildCurrent();
private:
    void		updateCurrent(const GameTimer& gt) override;
    void		drawCurrent() const;
    float		mScrollSpeed;
};