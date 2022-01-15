#pragma once

#include <lol/lol.hpp>
#include "CardStack.hpp"

#include "../CardStackSprite.hpp"

class CardStackLayer : public lol::Layer
{
public:
	CardStackLayer(lol::ObjectManager& manager, const CardStack& stack);

	void OnUpdate() override;
	void OnRender(lol::CameraBase& camera) override;

private:
	const CardStack& stack;
	CardStackSprite sprite;
};