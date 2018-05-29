#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <glm\vec2.hpp>

class Player;

class BootStrapTestApp : public aie::Application {
public:

	BootStrapTestApp();
	virtual ~BootStrapTestApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*		m_ship;
	aie::Texture*		m_bullet;
	glm::vec2*			m_shipPos;
	glm::vec2*			m_bulletPos;
	Player*				m_player;


public:
	float				m_timer;
	bool				b_isFired;
	
};