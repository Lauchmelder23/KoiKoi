#include "BoardLayer.hpp"

BoardLayer::BoardLayer(lol::ObjectManager& manager, const Board& board) :
	lol::Layer("Board"), manager(manager), board(board)
{
}

void BoardLayer::OnUpdate()
{
}

void BoardLayer::OnRender(lol::CameraBase& camera)
{
	for (CardSprite& sprite : sprites)
		camera.Draw(sprite);
}

void BoardLayer::OnRevealCard(std::shared_ptr<Card> card)
{
	sprites.push_back(CardSprite(manager, card));
	CardSprite& newCard = sprites.back();
	newCard.SetScale(glm::vec3(0.2f));
	
	// If this is the first card to be put on the board, place it in the top left slot
	if (sprites.size() == 1)
	{
		newCard.SetPosition(glm::vec3(
			0.25f + 0.05f,
			0.5f + 0.025f,
			0.0f
		));
	}
	else
	{
		// If an even number of cards has been drawn, placce the last one below the previous one
		if (sprites.size() % 2 == 0)
		{
			CardSprite& spriteBeforeLast = sprites[sprites.size() - 2];
			newCard.SetPosition(glm::vec3(
				spriteBeforeLast.GetPosition().x,
				spriteBeforeLast.GetPosition().y - newCard.GetSize().y - 0.05f,
				0.0f
			));
		}
		else // Else, place it in the next row
		{
			CardSprite& secondSpriteBeforeLast = sprites[sprites.size() - 3];
			newCard.SetPosition(glm::vec3(
				secondSpriteBeforeLast.GetPosition().x + newCard.GetSize().x + 0.05f,
				secondSpriteBeforeLast.GetPosition().y,
				0.0f
			));
		}
	}
}
