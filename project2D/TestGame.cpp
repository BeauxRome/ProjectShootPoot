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

	m_bulletTexture = new aie::Texture("./textures/bullet.png");//Juan added

	m_font = new aie::Font("./font/consolas.ttf", 32);

	// Coordinates of camera
	m_cameraX = 0;
	m_cameraY = 0;
	
	// Coordinates of the ship
	m_shipX = 600;
	m_shipY = 400;
	m_bulletX = 600;
	m_bulletY = 400;
	m_bullet = m_shipX;//Juan added;

	// Rotation of ship
	m_rot = 0;

	m_timer = 0;

	return true;
}

void TestGame::shutdown()
{
	delete m_font;
	delete m_shipTexture;
	delete m_bulletTexture;//Juan added
	delete renderer;
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

	// WASD will move the ship, I guess (for the time being)

	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		m_shipY += 250.0f *deltaTime;
		m_bulletY += 250.0f *deltaTime;
	}

	

	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		m_shipX -= 250.0f *deltaTime;
		m_bulletX -= 250.0f *deltaTime;
	}



	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		m_shipY -= 250.0f *deltaTime;
		m_bulletY -= 250.0f *deltaTime;
	}


	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		m_shipX += 250.0f *deltaTime;
		m_bulletX += 250.0f *deltaTime;
	}

	// These keys rotate the ship

	if (input->isKeyDown(aie::INPUT_KEY_KP_7))
	{
		m_rot += 1.0f *deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_KP_9))
	{
		m_rot -= 1.0f *deltaTime;
	}

	////////////

	//This will be for the firng of the projectile

	/*if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		m_bullet -= 0.0f*deltaTime; //Juan added
	}*/

	////////////

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void TestGame::draw()
{
	this->clearScreen();
	renderer->setCameraPos(m_cameraX, m_cameraY);
	renderer->begin();

	// Draws the player ship

	renderer->setUVRect(0, 0, 1, 1);
	renderer->drawSprite(m_shipTexture, m_shipX, m_shipY, 0, 0, m_rot, 1);

	// Draws bollit // Juan added
	
	//renderer->setUVRect(0, 0, 1, 1); // Juan added
	//renderer->drawSprite(m_bulletTexture, m_bullet, 0); // Juan added
	// Button does nothing, just exists for the most part

	if (ImGui::Button("hello world"))
	{
	
	}	

	// Spawns bollit
	aie::Input* input = aie::Input::getInstance(); //Juan added
	
	if (input->isKeyDown(aie::INPUT_KEY_SPACE))//Juan added
	{
		renderer->setUVRect(0, 0, 1, 1);//Juan added
		//renderer->drawSprite(m_bulletTexture, m_bullet, 0, 0);//Juan added
		renderer->drawSprite(m_bulletTexture, m_bulletX, m_bulletY, 0, 0, m_rot, 1);//Juan added
		m_bulletX += 25.0f;//Juan added
		
	} //fun fact, making this a while loop causes the program to freeze
		//fun fact, while loops in general causes the program to freeze

	if (input->isKeyUp(aie::INPUT_KEY_SPACE))//Juan added
	{

		m_bulletX = m_shipX;//Juan added
		m_bulletY = m_shipY;
		//m_bullet = m_shipX;//Juan added
	}
	
	
	renderer->end();
}  
