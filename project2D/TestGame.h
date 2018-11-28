#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include <vector>



class TestGame : public aie::Application
{
public:
	TestGame();
	virtual ~TestGame();
	// Inherited via Application
	virtual bool startup() override;
	virtual void shutdown() override;
	virtual void update(float deltaTime) override;
	void draw(float deltaTime);
	virtual void draw() override;

	aie::Renderer2D* renderer;

protected:
	
	aie::Font*			m_font;
	aie::Texture*		m_shipTexture;
	aie::Texture*		m_bulletTexture;// Juan added
	aie::Texture*		m_meteorTexture;// Juan added
	aie::Texture*		m_basicEnemy;// Juan added
	aie::Texture*		m_fastEnemy;// Juan added
	aie::Texture*		m_bigEnemy;// Juan added
	aie::Texture*		m_livesTexture;//Juan added
	aie::Texture*		m_livesTexture2;//Juan added
	aie::Texture*		m_livesTexture3;//Juan added



	float m_cameraX, m_cameraY;
	float m_shipX, m_shipY;
	float m_rot;
	float m_timer;
	float m_bulletX; //Juan added
	float m_bulletY; //Juan added
	float meteoSpawn;//Juan added
	float meteoSpawnX;//Jua added
	float badiSpawn; //Juan added
	float badiSpawnY;//Juan added
	float speedyboi; //Juan added
	float speedyboiY;//Juan added
	float beefyboi;  //Juan added
	float beefyboiY; //Juan added
	float somelives; //Juan added
	float somelivesY;//Juan added
	float somelives2; //Jua added
	float somelivesY2;//Jua added
	float somelives3; //Jua added
	float somelivesY3;//Jua added



};