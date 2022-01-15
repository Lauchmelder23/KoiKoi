#pragma once

#include <lol/lol.hpp>
#include "Card.hpp"

class CardSprite : public lol::Drawable, public lol::Transformable
{
public:
	CardSprite(lol::ObjectManager& manager, std::shared_ptr<Card> card);

	glm::vec3 GetSize() { return glm::vec3(0.61035f, 1.0f, 0.0f) * GetScale(); }

private:
	void PreRender(const lol::CameraBase& camera) override;

private:
	std::shared_ptr<lol::Texture2D> cards;
	glm::vec2 textureOffset;

	std::shared_ptr<Card> card;
};