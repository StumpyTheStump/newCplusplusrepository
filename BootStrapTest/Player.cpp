#include "Player.h"
#include <Renderer2D.h>
#include <Texture.h>
#include <Input.h>
#include "Bullet.h"
#include <exception>
#include <iostream>

Player::Player()
{
}

Player::Player(glm::vec2 * pos)
{
	m_texture = new aie::Texture("../bin/textures/ship.png");
	m_pos = pos;

	for (int i = 0; i < 20; ++i)
	{
		m_bullet = new Bullet();
		m_inActiveBullets.push_back(m_bullet);
	}
}


Player::~Player()
{
	delete m_texture;
	delete m_bullet;
}

void Player::Update(float deltaTime, aie::Input* input)
{
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		m_pos->y += 300.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		m_pos->y -= 300.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		m_pos->x -= 300.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		m_pos->x += 300.0f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		Bullet* newBullet = nullptr;
		if (m_inActiveBullets.size() > 0)
			newBullet = m_inActiveBullets.at(m_inActiveBullets.size() - 1);
		try
		{
			if (newBullet != nullptr) {
				newBullet->bullPosX = m_pos->x;
				newBullet->bullPosY = m_pos->y;
				m_activeBullets.push_back(newBullet);
				m_inActiveBullets.pop_back();
			}
			else
				throw std::exception();
		}
		catch(std::exception e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	if (m_activeBullets.size() >= 20)
	{
		for (auto it = m_activeBullets.begin(); it != m_activeBullets.end(); ++it)
		{
			Bullet* usedBullet;
			if ((*it)->bullPosY >= 720)
			{
				usedBullet = m_activeBullets.at(m_activeBullets.size() - 1);
				usedBullet->bullPosX = m_pos->x;
				usedBullet->bullPosY = m_pos->y;
				m_inActiveBullets.push_back(usedBullet);
				m_activeBullets.pop_back();
			}
		}
	}

	
}

void Player::Draw(aie::Renderer2D * spriteBatch)
{
	spriteBatch->drawSprite(m_texture, m_pos->x, m_pos->y);

	for (auto it = m_activeBullets.begin(); it != m_activeBullets.end(); ++it)
	{
		(*it)->draw(spriteBatch);
	}
}
