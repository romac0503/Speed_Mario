#include "RunningState.h"

RunningState::~RunningState()
{

}

void RunningState::init(GameStateManager* manager)
{
	this->manager = manager;
	m_frameDelta = 0;
	m_currentFrame = 0;
}

void RunningState::update(float deltaTime)
{
	manager->update(deltaTime);
}

void RunningState::keyDown(ci::app::KeyEvent event)
{
	draw();
}

void RunningState::keyUp(ci::app::KeyEvent event)
{
	if (event.getCode() == app::KeyEvent::KEY_LEFT)
	{
		manager->setState("Standing");
	}

	if (event.getCode() == app::KeyEvent::KEY_RIGHT)
	{
		manager->setState("Standing");
	}
	
}

void RunningState::draw()
{
	manager->m_player->draw();
}



