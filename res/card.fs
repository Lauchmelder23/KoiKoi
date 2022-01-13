#version 440 core

in vec2 uvCoord;
out vec4 FragColor;

uniform vec2 offset;
uniform sampler2D motive;

void main()
{
	FragColor = texture(motive, uvCoord + offset);
}