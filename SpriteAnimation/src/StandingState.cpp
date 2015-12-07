#include "StandingState.h"

StandingState::~StandingState()
{

}

void StandingState::init(GameStateManager* manager)
{

}

void StandingState::update(double deltaTime)
{

}

void StandingState::draw()
{
	manager->m_player->draw();
}

void StandingState::keyDown(ci::app::KeyEvent event)
{
	if (event.getCode() == app::KeyEvent::KEY_LEFT)
	{
		manager->setState("Running");
	}

	if (event.getCode() == app::KeyEvent::KEY_RIGHT)
	{
		manager->setState("Running");
	}
}

void StandingState::keyUp(ci::app::KeyEvent event)
{

}