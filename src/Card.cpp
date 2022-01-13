#include "Card.hpp"

Card::Card(lol::ObjectManager& manager, Month month, int type)
{
	try
	{
		vao = manager.Get<lol::VertexArray>(2);
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

		vao = manager.Create<lol::VertexArray>(2, vbo, ebo);
	}

	shader = manager.Get<lol::Shader>(1);
	cards = manager.Get<lol::Texture2D>(0);

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

	shader->SetUniform("view", camera.GetView());
	shader->SetUniform("projection", camera.GetProjection());
}
