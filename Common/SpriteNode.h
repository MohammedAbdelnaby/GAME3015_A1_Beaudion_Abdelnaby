#pragma once
#include "Entity.hpp"

class SpriteNode :
    public Entity
{
public:
	enum Type
	{
		Background,
		Planet,
	};

	SpriteNode(Type type, Game* game);

private:
	Type				mType;
	std::string			mSprite;
	XMFLOAT3			mTiling;
	virtual void		drawCurrent() const;
	virtual void		buildCurrent();
};
