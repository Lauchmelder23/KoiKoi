#pragma once

#include <lol/lol.hpp>

class CardStackSprite : public lol::Transformable, public lol::Drawable
{
public:
	CardStackSprite(lol::ObjectManager& manager);
	~CardStackSprite();

	glm::vec3 GetSize() { return glm::vec3(0.61035f, 1.0f, 0.0f) * GetScale(); }

private:
	void PreRender(const lol::CameraBase& camera) override;

private:
	std::shared_ptr<lol::Texture2D> texture;
};