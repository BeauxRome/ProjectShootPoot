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
	m_font = new aie::Font("./font/consolas.ttf", 32);
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

	// Coordinates of enemies
	badiSpawnX = 1200;
	badiSpawnY = 400;

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

	//shoot one at a time

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

			//hitbox

			if (a.position->xCheck() >= standard.enemyCoor->xCheck()-45&& 
				a.position->xCheck() <= standard.enemyCoor->xCheck() + 45 &&
				a.position->yCheck()>=standard.enemyCoor->yCheck() -45&& 
				a.position->yCheck()<=standard.enemyCoor->yCheck() + 45)
			{
				Bullet& pHolder = *current;
				++current;
				bulletClub.deleteNode(pHolder);
				
				standard.setCoor();
				//increase score when I can


				continue;
			}



			a.moveBullet();
		}
	}	

	if (standard.enemyCoor->xCheck() > 190)
	{
		standard.enemyCoor->setX(standard.enemyCoor->xCheck() - 3.0f);
	}
	else
	{
		standard.setCoor();
		baseHp--;
	}


	{
		//if (input->isKeyUp(aie::INPUT_KEY_SPACE))//Juan added
		//{
		//	if (m_bulletX <= 1280 && m_bulletX != m_shipX)
		//	{
		//		m_bulletX += 25.0f;//Juan added
		//	}
		//}

		//if (m_bulletX >= 1280)
		//{
		//	m_bulletX = m_shipX; //Juan added
		//	m_bulletY = m_shipY; //Juam added

		//}
	}
	////////////

	//Enemy Stuff

	srand(time(0));
	int random = rand();
	if (m_shipX <= 1120) //Juan added
	{
		badiSpawnX -= 2.5f*SpeedModifier();//Juan added, adjusted by moi
	}

	//if (badiSpawnX <= 0)//Juan added
	//{
	//	badiSpawnX = 1280;//Juan added
	//	badiSpawnY = rand() % 550 + 150;//Juan added
	//}

	
	{
		////

		////////THIS IS HOPEFULLY GOING TO BE PUT IN WHEN THINGS ARE SET

		//while (currentBullet != nullptr)
		//{
		//	if (m_bulletX <= badiSpawn - 100 && m_bulletX >= badiSpawn + 100 &&
		//		m_bulletY <= badiSpawnY - 100 && m_bulletY <= badiSpawnY + 100)
		//	{
		//		badiSpawn == 1200;
		//	}

		//	if (currentBullet.xCheck() <= badiSpawn - 100 && currentBullet.xCheck() >= badiSpawn + 100
		//		&& currentBullet.yCheck() <= badiSpawnY - 100 && currentBullet.yCheck() <= badiSpawnY + 100)
		//	{
		//		deleteNode(currentBullet);
		//		badiSpawn = 1280;
		//		badiSpawnY = rand() % 550 + 150;//Juan added
		//		m_scoreboard += 100;
		//	}
		//	else
		//	{
		//		currentBullet = currentBullet->next;
		//	}
		//}

		////
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
					  
	renderer->setUVRect(0,0,1,1);	
	renderer->drawSprite(m_portal, 1230, 360, (720/108)*m_portal->getWidth(), 920);

	//Create a loop that will print each bullet on the screen, avoiding the nullptr


	////IT'S ALSO BROKEN AS FUCK. Shit's fucked

	if (bulletClub.length() > 0)
	{
		linkedListIterator<Bullet> current = bulletClub.begin();

		for (int i=0;i<=bulletClub.length();i++)
		{
			Bullet a = *current;
			renderer->setUVRect(0, 0, 1, 1);//Juan added
			renderer->drawSprite(m_bulletTexture, a.position->xCheck(), 
				a.position->yCheck(), 0, 0, m_rot, 2);//Juan added

			++current;
		}
	}

	////

	renderer->setUVRect(0, 0, 1, 1);
	renderer->drawSprite(m_base, -175,360,720,720,4.71239,0);

	renderer->setUVRect(0, 0, 1, 1);//Juan added
	renderer->drawSprite(m_basicEnemy, standard.enemyCoor->xCheck(), 
		standard.enemyCoor->yCheck(), 45, 45, 1.57f, 1);//Juan added

	// Button does nothing, just exists for the most part

	if (ImGui::Button("hello world"))
	{

	}	

	renderer->end();
}
