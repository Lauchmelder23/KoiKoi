#include "CardStackLayer.hpp"

CardStackLayer::CardStackLayer(lol::ObjectManager& manager, const CardStack& stack) :
	lol::Layer("Stack"), stack(stack), sprite(manager)
{
	sprite.SetScale(glm::vec3(0.2f));
	sprite.SetPosition(glm::vec3(
		0.25f - sprite.GetSize().x - 0.05f,
		0.5f - 0.5f* sprite.GetSize().y,
		0.0f
	));
}

void CardStackLayer::OnUpdate()
{
	if (stack.Empty())
		sprite.SetScale(glm::vec3(0.0f));
	else
		sprite.SetScale(glm::vec3(0.2f));
}

void CardStackLayer::OnRender(lol::CameraBase& camera)
{
	camera.Draw(sprite);
}
