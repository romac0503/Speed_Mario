#include "StandingState.h"
#include "StateManager.h"

StandingState::~StandingState()
{
}

void StandingState::init(StateManager* manager)
{
	this->manager = manager;
}

void StandingState::exit()
{
	this->manager = nullptr;
}

void StandingState::update(float deltaTime)
{
}

void StandingState::draw(Sprite& sprite, Vec2f& pos, int framesPerSec, bool isFlipped)
{
	sprite.animate(pos, isFlipped, 0, framesPerSec);
}

void StandingState::keyDown(ci::app::KeyEvent event, cinder::Vec2f& pos, cinder::Vec2f& velocity)
{
	if (event.getCode() == cinder::app::KeyEvent::KEY_LEFT)
	{
		manager->setState("running");
	}

	else if (event.getCode() == cinder::app::KeyEvent::KEY_RIGHT)
	{
		manager->setState("running");
	}

	else if (event.getCode() == cinder::app::KeyEvent::KEY_SPACE)
	{
		manager->setState("jumping");
	}
}

void StandingState::keyUp(ci::app::KeyEvent event)
{
	
}