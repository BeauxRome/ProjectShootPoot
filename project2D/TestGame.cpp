#include "TestGame.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <imgui.h>
TestGame::TestGame()
{
}
TestGame::~TestGame()
{
}
bool TestGame::startup()
{
	renderer = new aie::Renderer2D();

	m_shipTexture = new aie::Texture("./textures/Galaga_Fighter.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_cameraX = 0;
	m_cameraY = 0;
	m_shipX = 600;
	m_shipY = 400;
	m_rot = 0;

	m_timer = 0;

	return true;
}

void TestGame::shutdown()
{
}

void TestGame::update(float deltaTime) 
{

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;

	//WASD will move the ship, I guess (for the time being)

	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		m_shipY += 250.0f *deltaTime;
	}


	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		m_shipX -= 250.0f *deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		m_shipY -= 250.0f *deltaTime;
	}


	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		m_shipX += 250.0f *deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_KP_7))
	{
		m_rot += 1.0f *deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_KP_9))
	{
		m_rot -= 1.0f *deltaTime;
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void TestGame::draw()
{
	this->clearScreen();
	renderer->setCameraPos(m_cameraX, m_cameraY);
	renderer->begin();

	renderer->setUVRect(0, 0, 1, 1);
	renderer->drawSprite(m_shipTexture, m_shipX, m_shipY, 0, 0, m_rot, 1);

	if (ImGui::Button("hello world"))
	{

	}	

	renderer->end();
}
