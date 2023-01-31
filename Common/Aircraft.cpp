/*
* Names: Mohammed , Sam
* Date: 2023-01-30
* Last Modified: 2023-01-30
*/
#include "Aircraft.hpp"
#include "Game.hpp"

Aircraft::Aircraft(Type type, Game* game) : Entity(game)
	, mType(type)
{
	switch (type)
	{
	case (Player):
		mSprite = "Player";
		break;
	case (Enemy):
		mSprite = "Enemy";
		break;
	default:
		mSprite = "Enemy";
		break;
	}
}

void Aircraft::drawCurrent() const
{	
	
}

void Aircraft::updateCurrent(const GameTimer& gt)
{
	Entity::updateCurrent(gt);

	// Enemy Update
	if (mType == Type::Enemy)
	{
		if (getWorldPosition().x <= -4.0)
		{
			setPosition(rand() % 10 + 6, 0.1, 1.7 - (rand() % 34) / 10);
		}
	}

	// Player Update
	if (mType == Type::Player)
	{
		setVelocity(0.0f, 0.0f, 0.0f);

		if (GetAsyncKeyState('W') & 0x8000)
		{
			setVelocity(0.0f, 0.0f, 1.0f);
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			setVelocity(0.0f, 0.0f, -1.0f);
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			setVelocity(1.0f, 0.0f, 0.0f);
		}
		if (GetAsyncKeyState('A') & 0x8000)
		{
			setVelocity(-1.0f, 0.0f, 0.0f);
		}
	}
}

void Aircraft::buildCurrent()
{
	auto render = std::make_unique<RenderItem>();
	renderer = render.get();
	renderer->World = getTransform();
	renderer->ObjCBIndex = game->getRenderItems().size();
	renderer->Mat = game->getMaterials()[mSprite].get();
	renderer->Geo = game->getGeometries()["boxGeo"].get();
	renderer->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	renderer->IndexCount = renderer->Geo->DrawArgs["box"].IndexCount;
	renderer->StartIndexLocation = renderer->Geo->DrawArgs["box"].StartIndexLocation;
	renderer->BaseVertexLocation = renderer->Geo->DrawArgs["box"].BaseVertexLocation;

	game->getRenderItems().push_back(std::move(render));

}
