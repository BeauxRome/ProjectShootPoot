#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "UnorderedLinkList.h"
#include "Bullet.h"
#include "LinkedList.h"
#include "Enemy.h"

class TestGame : public aie::Application
{
public:
	TestGame();
	virtual ~TestGame();
	// Inherited via Application
	virtual bool startup() override;
	virtual void shutdown() override;
	virtual void update(float deltaTime) override;
	virtual void draw() override;



	int SpeedModifier();

	aie::Renderer2D* renderer;

protected:
	
	aie::Font*			m_font;
	aie::Font*			m_subtlety;
	aie::Texture*		m_shipTexture;
	aie::Texture*		m_base;
	aie::Texture*		m_bulletTexture;// Juan added
	aie::Texture*		m_basicEnemy;
	aie::Texture*		m_portal;
	aie::Texture*		m_gameOver;

	float m_cameraX, m_cameraY;
	float m_shipX, m_shipY;
	float m_rot;
	int m_scoreboard;
	float m_timer;
	float m_bulletX; //Juan added
	float m_bulletY; //Juan added
	int baseHp;
	int shipHp;
	UnorderedLinkedList<Bullet> bulletClub;
	Enemy standard;
};    