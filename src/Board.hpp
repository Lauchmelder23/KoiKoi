#pragma once

#include <lol/lol.hpp>
#include "Card.hpp"

class Board : public lol::Layer
{
public:
	Board(lol::ObjectManager& manager);
	~Board();

	void OnUpdate() override;
	void OnRender(lol::CameraBase& camera) override;

private:
	std::vector<std::shared_ptr<Card>> openCards;
};