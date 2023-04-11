#pragma once
#include "Entity.hpp"

class SpriteNode :
    public Entity
{
public:
	SpriteNode(Game* game, States::ID id);

protected:
	std::string			mSprite;
	XMFLOAT3			mTiling;
	virtual void		drawCurrent() const;
	virtual void		buildCurrent();
};
