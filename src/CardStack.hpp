#pragma once

#include <lol/lol.hpp>
#include "Card.hpp"

class CardStack : public lol::Transformable, public lol::Drawable
{
public:
	CardStack(lol::ObjectManager& manager);
	~CardStack();

	std::shared_ptr<Card> DrawCard();
	inline bool Empty() { return stack.empty(); }
	glm::vec3 GetSize() { return glm::vec3(0.61035f, 1.0f, 0.0f) * GetScale(); }

private:
	void PreRender(const lol::CameraBase& camera) override;

private:
	std::shared_ptr<lol::Texture2D> backside;
	std::vector<std::shared_ptr<Card>> stack;
};