#include "BootStrapTestApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <imgui.h>
#include "Player.h"
#include "Bullet.h"

BootStrapTestApp::BootStrapTestApp() {

}

BootStrapTestApp::~BootStrapTestApp() {

}

bool BootStrapTestApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	//m_ship = new aie::Texture("../bin/textures/ship.png");
	//m_bullet = new aie::Texture("../bin/textures/bullet.png");
	/*m_shipPos = new glm::vec2(100, 200);
	m_bulletPos = new glm::vec2(100, 200);*/
	m_player = new Player(new glm::vec2 (100, 200));
	//b_isFired = false;
	m_timer = 0;
	return true;
}

void BootStrapTestApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void BootStrapTestApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_player->Update(deltaTime, input);

	m_timer += deltaTime;

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	/*if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_shipPos->y += 5;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_shipPos->y -= 5;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_shipPos->x -= 5;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_shipPos->x += 5;*/


	//if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	//{
	//	b_isFired = true;
	//}

	//if (b_isFired)
	//{
	//	m_bulletPos->y += 5;
	//}
} 

void BootStrapTestApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	
	
	ImGui::Begin("Sample Window");
	ImGui::Text("Timer: (%1.0f)", 0);
	ImGui::SliderFloat("Test Slide", &m_timer, 0, 10000000.0f);
	ImGui::End();

	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	/*m_2dRenderer->drawSprite(m_ship, m_shipPos->x, m_shipPos->y, 0, 0, 0, 0, 0);
	m_2dRenderer->drawSprite(m_bullet, m_bulletPos->x, m_bulletPos->y, 0, 0, 0, 0, 0, 0);*/

	m_player->Draw(m_2dRenderer);
	// done drawing sprites
	m_2dRenderer->end();
}