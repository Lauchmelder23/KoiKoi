#include "Board.hpp"

#include "CardStack.hpp"
#include "ObjectIDs.hpp"

Board::Board(lol::ObjectManager& manager) :
	Layer("Board"), stack(manager)
{
	stack.SetScale(glm::vec3(0.2f));
	stack.SetPosition(glm::vec3(
		0.25f - (stack.GetSize().x + 0.05f),
		0.5f - (stack.GetSize().y * 0.5f),
		0.0f
	));

	// Draw 8 cards from stack
	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			std::shared_ptr<Card> card = stack.DrawCard();
			card->SetScale(glm::vec3(0.2f));

			glm::vec3 cardSize = card->GetSize();
			card->SetPosition(glm::vec3(
				0.25f + (cardSize.x + 0.05f) * x, 
				0.5f - cardSize.y - 0.025f + (cardSize.y + 0.05f) * y,
				0.0f
			));

			openCards.push_back(card);
		}
	}
}

Board::~Board()
{
}

void Board::OnUpdate()
{
}

void Board::OnRender(lol::CameraBase& camera)
{
	stack.Draw(camera);

	for (std::shared_ptr<Card> card : openCards)
		card->Draw(camera);
}
