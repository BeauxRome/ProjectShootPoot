#pragma once
#include "Application.h"
#include "Renderer2D.h"

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

	aie::Renderer2D* renderer;

protected:
	
	aie::Font*			m_font;
	aie::Texture*		m_shipTexture;
	aie::Texture*		m_base;
	aie::Texture*		m_bulletTexture;// Juan added
	aie::Texture*		m_portal;

	float m_cameraX, m_cameraY;
	float m_shipX, m_shipY;
	float m_rot;
	float m_timer;
	float m_bullet;// Juan added
};