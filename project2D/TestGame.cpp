#include "TestGame.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Node.h"
#include <imgui.h>
#include <iostream>
#include <ctime>

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
	m_base = new aie::Texture("./textures/metriodoBlock.png");
	m_portal = new aie::Texture("./textures/Eldritch.png");
	m_bulletTexture = new aie::Texture("./textures/bullet.png");//Juan added
	m_basicEnemy = new aie::Texture("./textures/enemy.png");//Juan added
	m_font = new aie::Font("./font/consolas.ttf", 26);
	m_subtlety = new aie::Font("./font/consolas.ttf", 18);
	m_gameOver = new aie::Texture("./textures/GameOver.png");// Juamn added
	bulletClub = UnorderedLinkedList<Bullet>();
	// Coordinates of camera
	m_cameraX = 0;
	m_cameraY = 0;
	
	// Coordinates of the ship
	m_shipX = 600;
	m_shipY = 400;
	m_bulletX = 600; //Juan added
	m_bulletY = 400; //Juan added
	baseHp = 5;
	shipHp = 3;

	// Coordinates of enemies
	//badiSpawnX = 1200;
	//badiSpawnY = 400;

	Enemy();

	standard.setCoor();

	m_scoreboard = 0;
	m_timer = 0;

	return true;
}

int TestGame::SpeedModifier()
{
	return (m_scoreboard < 1000) ? 1 : m_scoreboard / 1000;
}

void TestGame::shutdown()
{
	delete m_font;
	delete m_shipTexture;
	delete m_base;
	delete m_bulletTexture;//Juan added
	delete m_basicEnemy; //Juan added
	delete m_gameOver;//Juan added
	delete renderer;
}

void TestGame::update(float deltaTime)
{

	m_timer += deltaTime;


	
	aie::Input* input = aie::Input::getInstance();

	
	// WASD will move the ship, I guess (for the time being)
	if (m_shipY <= 695)
	{
		if (input->isKeyDown(aie::INPUT_KEY_W))
		{
			m_shipY += 250.0f *deltaTime;
			//m_bulletY += 250.0f *deltaTime;//Juan added
		}
	}

	if (m_shipX >= 220)
	{
		if (input->isKeyDown(aie::INPUT_KEY_A))
		{
			m_shipX -= 250.0f *deltaTime;
			//m_bulletX -= 250.0f *deltaTime;//Juan added
		}
	}

	if (m_shipY >=25)
	{
		if (input->isKeyDown(aie::INPUT_KEY_S))
		{
			m_shipY -= 250.0f *deltaTime;
			//m_bulletY -= 250.0f *deltaTime;//Juan added
		}
	}

	if (m_shipX <= 1115)
	{
		if (input->isKeyDown(aie::INPUT_KEY_D))
		{
			m_shipX += 250.0f *deltaTime;
			//m_bulletX += 250.0f *deltaTime;//Juan added
		}

	}
	


	////////////

	//This will be for the firng of the projectile
	
	if (bulletClub.length()<1)
	{
		if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))//Juan added
		{
			Bullet* newBullet = new Bullet;

			newBullet->position->setX(m_shipX);
			newBullet->position->setY(m_shipY);
			bulletClub.insertFirst(*newBullet);


		}
	}

	//This is the process of the bullets

	if (bulletClub.length() > 0)
	{
		linkedListIterator<Bullet> current = bulletClub.begin();

		//goes through each active bullet
		for (int i = 0; i <= bulletClub.length(); i++)
		{
			Bullet a = *current;
			if (a.position->xCheck() > 1280)
			{
				Bullet& pHolder = *current;
				++current;
				bulletClub.deleteNode(pHolder);
				
				continue;
			}			

			//Ghetto hitbox for enemy and bullet

			if (a.position->xCheck() >= standard.enemyCoor->xCheck()-45&& 
				a.position->xCheck() <= standard.enemyCoor->xCheck() + 45 &&
				a.position->yCheck()>=standard.enemyCoor->yCheck() -45&& 
				a.position->yCheck()<=standard.enemyCoor->yCheck() + 45)
			{
				Bullet& pHolder = *current;
				++current;
				bulletClub.deleteNode(pHolder);
				
				standard.setCoor();
				m_scoreboard += 100;


				continue;
			}



			a.moveBullet();
		}
	}	

	//If the Enemy goes too far, Base takes damage

	if (standard.enemyCoor->xCheck() > 190)
	{
		standard.enemyCoor->setX(standard.enemyCoor->xCheck() - 3.0f*SpeedModifier());
	}
	else
	{
		standard.setCoor();
		baseHp--;
	}

	// If the 2 ships crash into each other

	if (m_shipX >= standard.enemyCoor->xCheck() - 45 &&
		m_shipX <= standard.enemyCoor->xCheck() + 45 &&
		m_shipY >= standard.enemyCoor->yCheck() - 45 &&
		m_shipY <= standard.enemyCoor->yCheck() + 45)
	{
		standard.setCoor();
		shipHp--;
	}


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		quit();
	}
}
void TestGame::draw()
{
	this->clearScreen();
 	renderer->setCameraPos(m_cameraX, m_cameraY);
	renderer->begin();

	// Draws the player ship

	renderer->setUVRect(0, 0, 1, 1);
	renderer->drawSprite(m_shipTexture, m_shipX, m_shipY, 50, 50, 4.71239, 1);
					  
	// Indicates portal location	
	renderer->drawSprite(m_portal, 1230, 360, (720/108)*m_portal->getWidth(), 920);

	//Create a loop that will print each bullet on the screen, avoiding the nullptr

	if (bulletClub.length() > 0)
	{
		linkedListIterator<Bullet> current = bulletClub.begin();

		for (int i=0;i<=bulletClub.length();i++)
		{
			Bullet a = *current;
			renderer->drawSprite(m_bulletTexture, a.position->xCheck(), 
				a.position->yCheck(), 0, 0, m_rot, 2);//Juan added

			++current;
		}
	}

	//// Base indicator

	renderer->drawSprite(m_base, -175,360,720,720,4.71239,0);

	//// Enemy Sprite
	renderer->drawSprite(m_basicEnemy, standard.enemyCoor->xCheck(), 
		standard.enemyCoor->yCheck(), 45, 45, 1.57f, 0);//Juan added

	//Lives Display


	if (shipHp > 0)
	{
		renderer->drawSprite(m_shipTexture, 200, 695, 25, 25, 0, 0);
	}
	if (shipHp > 1)
	{
		renderer->drawSprite(m_shipTexture, 250, 695, 25, 25, 0, 0);
	}
	if (shipHp > 2)
	{
		renderer->drawSprite(m_shipTexture, 300, 695, 25, 25, 0, 0);
	}

	//Base HP Display

	if (baseHp == 5)
	{
		renderer->drawText(m_font, "Base: 5", 1000, 700, 0);
	}
	
	if (baseHp == 4)
	{
		renderer->drawText(m_font, "Base: 4", 1000, 700, 0);
	}

	if (baseHp == 3)
	{
		renderer->drawText(m_font, "Base: 3", 1000, 700, 0);
	}

	if (baseHp == 2)
	{
		renderer->drawText(m_font, "Base: 2", 1000, 700, 0);
	}

	if (baseHp == 1)
	{
		renderer->drawText(m_font, "Base: 1", 1000, 700, 0);
	}

	//GAME OVER
	if (shipHp <= 0 || baseHp <= 0)
	{
		renderer->drawSprite(m_gameOver, 630, 360, 1300, 720, 0, 0);
		renderer->drawText(m_subtlety, "(Press ESC to exit the game)", 480, 50, 0);
	}


	renderer->end();
}
