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

public:
	Aircraft(Game* game, States::ID id);


public:
	virtual void		buildCurrent();

protected:
};
