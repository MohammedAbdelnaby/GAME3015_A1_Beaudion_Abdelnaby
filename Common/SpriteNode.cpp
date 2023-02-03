/*
* Names: Mohammed , Sam
* Date: 2023-01-30
* Last Modified: 2023-01-30
*/
#include "SpriteNode.h"
#include "Game.hpp"

SpriteNode::SpriteNode(Game* game) : Entity(game)
{

}

void SpriteNode::drawCurrent() const
{
	renderer->Mat = game->getMaterials()[mSprite].get();
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
