#pragma once

#include <lol/lol.hpp>
#include "Board.hpp"
#include "../CardSprite.hpp"

class BoardLayer : public lol::Layer
{
public:
	BoardLayer(lol::ObjectManager& manager, const Board& board);

	void OnUpdate() override;
	void OnRender(lol::CameraBase& camera) override;

	void OnRevealCard(std::shared_ptr<Card> card);
	void OnCleanup();

private:
	void OnCleanupAnimationEnd(CardSprite* sprite);

private:
	const Board& board;

	lol::ObjectManager& manager;
	std::vector<CardSprite*> sprites;
	std::vector<CardSprite*> oldSprites;
};