/*
* Names: Mohammed , Sam
* Date: 2023-01-30
* Last Modified: 2023-01-30
*/
#pragma once
#include "Entity.hpp"
#include <string>

class Aircraft :
    public Entity
{
public:
	enum Type
	{
		Player,
		Enemy,
	};


public:
	Aircraft(Type type, Game* game);


private:
	void				updateCurrent(const GameTimer& gt) override;
	virtual void		drawCurrent() const;
	virtual void		buildCurrent();


private:
	Type				mType;
	std::string			mSprite;
};
