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

	float m_cameraX, m_cameraY;
	float m_shipX, m_shipY;
	float m_rot;
	float m_timer;
	float m_bulletX; //Juan added
	float m_bulletY; //Juan added
	//float m_bullet;// Juan added
	//float x;//Juan added
	//std::vector<float> bulletV; //Juan added
};