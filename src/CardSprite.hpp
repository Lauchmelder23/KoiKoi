#pragma once

#include <lol/lol.hpp>
#include "Card.hpp"

struct Animation
{
	glm::vec3 from;
	glm::vec3 to;
	double alpha;
	double duration;
};

class CardSprite : public lol::Drawable, public lol::Transformable
{
public:
	CardSprite(lol::ObjectManager& manager, std::shared_ptr<Card> card);

	glm::vec3 GetSize() { return glm::vec3(0.61035f, 1.0f, 0.0f) * GetScale(); }

	void CreateAnimation(Animation animation);
	inline const Animation& GetAnimation() { return animation; }
	void Update(double dt);

private:
	void PreRender(const lol::CameraBase& camera) override;

private:
	std::shared_ptr<lol::Texture2D> cards;
	glm::vec2 textureOffset;

	// TODO: Create Animation handler?
	Animation animation;
	double t;
	bool animationRunning;

	std::shared_ptr<Card> card;
};