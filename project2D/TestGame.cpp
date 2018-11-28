#include "TestGame.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <imgui.h>
#include <iostream>
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

	m_livesTexture = new aie::Texture("./textures/Lives.png");//Juan added

	m_livesTexture2 = new aie::Texture("./textures/Lives.png");//Juan added

	m_livesTexture3 = new aie::Texture("./textures/Lives.png");//Juan added

	m_bulletTexture = new aie::Texture("./textures/bullet.png");//Juan added

	m_meteorTexture = new aie::Texture("./textures/rock_small.png");//Juan added

	m_basicEnemy = new aie::Texture("./textures/enemy.png");//Juan added

	m_fastEnemy = new aie::Texture("./textures/fast_enemy.png");//Juan added

	m_bigEnemy = new aie::Texture("./textures/big_enemy.png");//Juan added

	m_gameOver = new aie::Texture("./textures/GameOver.png");// Juamn added

	m_font = new aie::Font("./font/consolas.ttf", 32);

	// Coordinates of camera
	m_cameraX = 0;
	m_cameraY = 0;
	
	// Coordinates of the ship
	m_shipX = 600;
	m_shipY = 400;
	m_bulletX = 600; //Juan added
	m_bulletY = 400; //Juam added

	//Coordinates of meteors

	meteoSpawn = 700; //Juan added
	meteoSpawnX = 800;//Juan added

	// Coordinates of speedybois
	//speedyboi = 1200; //Juan added
	speedyboi = -1200; //Juan added
	speedyboi = 400; //Juan added

	//Coordinates of beefybois

	beefyboi = -1200;
	beefyboiY = 400;

	// Rotation of ship
	m_rot = 0;

	m_timer = 0;

	// Hit Boxy 


	// life boxy

	somelives = 0;
	somelivesY = 800;

	somelives2 = 30;
	somelivesY2 = 800;

	somelives3 = 60;
	somelivesY3 = 800;

	// dead boxy

	deadboi = 600;
	return true;
}

void TestGame::shutdown()
{
	delete m_font;
	delete m_shipTexture;
	delete m_bulletTexture;//Juan added
	delete m_meteorTexture; //Juan added
	delete m_fastEnemy; //Juan added
	delete m_bigEnemy; //Juan added
	delete m_livesTexture;//Juan added
	delete m_livesTexture2;//Juan added
	delete m_livesTexture3;//Juan added
	delete m_gameOver;//Juan added
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
		m_bulletY += 250.0f *deltaTime;//Juan added
	}

	

	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		m_shipX -= 250.0f *deltaTime;
		m_bulletX -= 250.0f *deltaTime;//Juan added
	}



	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		m_shipY -= 250.0f *deltaTime;
		m_bulletY -= 250.0f *deltaTime;//Juan added
	}


	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		m_shipX += 250.0f *deltaTime;
		m_bulletX += 250.0f *deltaTime;//Juan added
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


	//These keys shoots bollit

	if (input->isKeyDown(aie::INPUT_KEY_SPACE))//Juan added
	{
		if (m_bulletX <= 1280)
		{
			m_bulletX += 25.0f;//Juan added
		}
	}

	if (input->isKeyUp(aie::INPUT_KEY_SPACE))//Juan added
	{
		if (m_bulletX <= 1280 && m_bulletX != m_shipX)
		{
			m_bulletX += 25.0f;//Juan added
		}
	}

	if (m_bulletX >= 1280)
	{
		m_bulletX = m_shipX; //Juan added
		m_bulletY = m_shipY; //Juam added
		
	}

	//Meteor stuff

	if (m_shipX <= 1120)//Juan added
	{
		meteoSpawn -= 3.0f;//Juan added
	}

	if (meteoSpawn <= -200)//Juan added
	{
		meteoSpawn = 700;//Juan added
		meteoSpawnX = rand() % 893 + 250;//Juan added
		std::cout << meteoSpawnX << std::endl;
	}

	//speedyboi stuff

	if (m_shipX <= 1120)//Juan added
	{
		speedyboi -= 25.0f;//Juan added
	}

	if (speedyboi <= -30000)//Juan added
	{
		speedyboi = 1200; //Juan added
		speedyboiY = rand() % 550 + 150;//Juan added
	}

	//beefyboi stuff

	if (m_shipX <= 1120)//Juan added
	{
		beefyboi -= 1.0f;//Juan added
	}

	if (beefyboi <= -3000)//Juan added
	{
		beefyboi = 1200; //Juan added
		beefyboiY = rand() % 550 + 150;//Juan added
	}

	// healthyboi stuff

	

	
	
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

	// Draws the player bollit
	renderer->setUVRect(0, 0, 1, 1);//Juan added
	renderer->drawSprite(m_bulletTexture, m_bulletX, m_bulletY, 0, 0, m_rot, 2);//Juan added

	renderer->setUVRect(0, 0, 1, 1);//Juan added
	renderer->drawSprite(m_meteorTexture, meteoSpawnX, meteoSpawn, 0, 0, 0, 1);//Juan added

	renderer->setUVRect(0, 0, 1, 1);//Juan added
	renderer->drawSprite(m_fastEnemy, speedyboi, speedyboiY, 0, 0, 1.57f, 1);//Juan added

	renderer->setUVRect(0, 0, 1, 1);//Juan added
	renderer->drawSprite(m_bigEnemy, beefyboi, beefyboiY, 1200, 1200, 1.57f, 1);//Juan added

	//Draws the health

	renderer->setUVRect(0, 0, 1, 1);
	renderer->drawSprite(m_livesTexture, somelives, somelivesY, 25, 25, m_rot, 1);

	renderer->setUVRect(0, 0, 1, 1);
	renderer->drawSprite(m_livesTexture2, somelives2, somelivesY2, 25, 25, m_rot, 1);

	renderer->setUVRect(0, 0, 1, 1);
	renderer->drawSprite(m_livesTexture3, somelives3, somelivesY3, 25, 25, m_rot, 1);
	

	// myeetrra

	//renderer->setUVRect(0, 0, 1, 1);
	//renderer->drawSprite(m_gameOver, deadboi, 400, 1500, 1200, m_rot, 0);

	

	if (ImGui::Button("hello world"))
	{
	
	}	
	
	renderer->end();
}  
