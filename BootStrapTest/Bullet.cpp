#include "Bullet.h"
#include <Texture.h>
#include <Renderer2D.h>


Bullet::Bullet()
{
	bullPosX = 0.0f;
	bullPosY = 0.0f;
	m_bulletTex = new aie::Texture("../bin/textures/bullet.png");
	
}


Bullet::~Bullet()
{
	delete m_bulletTex;
}

void Bullet::draw(aie::Renderer2D* m_2dRenderer)
{

}

void Bullet::update(float deltaTime)
{
	bullPosY += 500.0f * deltaTime;
}
