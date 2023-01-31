#include "SpriteNode.h"
#include "Game.hpp"

SpriteNode::SpriteNode(Type type, Game* game) : Entity(game)
, mType(type)
{
	switch (type)
	{
	case (Background):
		mSprite = "Desert";
		mTiling = XMFLOAT3(10.0f, 10.0f, 10.0f);
		break;
	case (Planet):
		mSprite = "Planet";
		mTiling = XMFLOAT3(1.0f, 1.0f, 1.0f);
		break;
	}
}

void SpriteNode::drawCurrent() const
{
	renderer->World = getTransform();
	renderer->NumFramesDirty++;
}

void SpriteNode::buildCurrent()
{
	auto render = std::make_unique<RenderItem>();
	renderer = render.get();
	renderer->World = getTransform();
	XMStoreFloat4x4(&renderer->TexTransform, XMMatrixScaling(mTiling.x, mTiling.y, mTiling.z));
	renderer->ObjCBIndex = game->getRenderItems().size();
	renderer->Mat = game->getMaterials()[mSprite].get();
	renderer->Geo = game->getGeometries()["boxGeo"].get();
	renderer->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	renderer->IndexCount = renderer->Geo->DrawArgs["box"].IndexCount;
	renderer->StartIndexLocation = renderer->Geo->DrawArgs["box"].StartIndexLocation;
	renderer->BaseVertexLocation = renderer->Geo->DrawArgs["box"].BaseVertexLocation;

	game->getRenderItems().push_back(std::move(render));
}
