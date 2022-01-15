#include "CardSprite.hpp"

#include <spdlog/spdlog.h>
#include "ObjectIDs.hpp"

CardSprite::CardSprite(lol::ObjectManager& manager, std::shared_ptr<Card> card) :
	card(card)
{
	try
	{
		vao = manager.Get<lol::VertexArray>(VAO_CARD);
	}
	catch (const lol::ObjectNotFoundException& err)
	{
		std::shared_ptr<lol::VertexBuffer> vbo = std::make_shared<lol::VertexBuffer>(std::vector<float>{
			0.0f, 0.0f, 0.0f, 1.0f / 4.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.61035f, 1.0f, 1.0f / 12.0f, 0.0f,
			0.61035f, 0.0f, 1.0f / 12.0f, 1.0f / 4.0f
		});

		lol::BufferLayout layout({
			lol::VertexAttribute(lol::Type::Float, 2, false),
			lol::VertexAttribute(lol::Type::Float, 2, false)
			});
		vbo->SetLayout(layout);

		std::shared_ptr<lol::ElementBuffer> ebo = std::make_shared<lol::ElementBuffer>(std::vector<unsigned int>{ 0, 1, 2, 0, 2, 3 });

		vao = manager.Create<lol::VertexArray>(VAO_CARD, vbo, ebo);
	}
	catch (const std::exception& err)
	{
		spdlog::critical("Unknown error in constructor of CardStack");
		throw err;
	}

	shader = manager.Get<lol::Shader>(SHADER_CARD);
	cards = manager.Get<lol::Texture2D>(TEXTURE_CARD_ATLAS);
	
	textureOffset = glm::vec2(
		static_cast<int>(card->GetSuit()) / 12.0f,
		card->GetType() / 4.0f
	);
}

void CardSprite::PreRender(const lol::CameraBase& camera)
{
	cards->Bind();
	shader->SetUniform("offset", textureOffset);

	shader->SetUniform("model", transformation);
	shader->SetUniform("view", camera.GetView());
	shader->SetUniform("projection", camera.GetProjection());
}
