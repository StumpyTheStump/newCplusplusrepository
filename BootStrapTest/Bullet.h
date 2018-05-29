#pragma once
namespace aie {
	class Renderer2D;
	class Texture;
}

class Bullet
{
public:
	Bullet();
	~Bullet();

	void draw(aie::Renderer2D* m_2dRenderer);

	void update(float deltaTime);

	float			bullPosX; // x position
	float			bullPosY; // y position
	aie::Texture*	m_bulletTex;
	
	
};

