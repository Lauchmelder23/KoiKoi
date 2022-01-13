#pragma once

#include <lol/lol.hpp>

enum class Month
{
	January, February, March, April, May, June, July, August, September, October, November, December
};

class Card : public lol::Drawable, public lol::Transformable
{
public:
	Card(lol::ObjectManager& manager, Month month, int type);

	void UpdateSuitAndType(Month month, int type);

private:
	void PreRender(const lol::CameraBase& camera) override;

private:
	std::shared_ptr<lol::Texture2D> cards;

	Month suit;
	int type;
	glm::vec2 textureOffset;
};