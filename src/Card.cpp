#include "Card.hpp"

#include <spdlog/spdlog.h>
#include "ObjectIDs.hpp"

Card::Card(lol::ObjectManager& manager, Month month, int type)
{
	try
	{
		vao = manager.Get<lol::VertexArray>(VAO_CARD);
	} 
	catch (const lol::ObjectNotFoundException& err)
	{
		std::shared_ptr<lol::VertexBuffer> vbo = std::make_shared<lol::VertexBuffer>(std::vector<float>{
			0.0f, 0.0f,			0.0f, 1.0f / 4.0f,
			0.0f, 1.0f,			0.0f, 0.0f,
			0.61035f, 1.0f,		1.0f / 12.0f, 0.0f,
			0.61035f, 0.0f,		1.0f / 12.0f, 1.0f / 4.0f
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
		spdlog::critical("Unknown error in constructor of Card");
		throw err;
	}

	shader = manager.Get<lol::Shader>(SHADER_CARD);
	cards = manager.Get<lol::Texture2D>(TEXTURE_CARD_ATLAS);

	UpdateSuitAndType(month, type);
}

void Card::UpdateSuitAndType(Month month, int type)
{
	this->suit = month;
	this->type = type;

	textureOffset = glm::vec2(
		static_cast<int>(this->suit) / 12.0f,
		this->type / 4.0f
	);
}

void Card::PreRender(const lol::CameraBase& camera)
{
	cards->Bind();
	shader->SetUniform("offset", textureOffset);

	shader->SetUniform("model", transformation);
	shader->SetUniform("view", camera.GetView());
	shader->SetUniform("projection", camera.GetProjection());
}
