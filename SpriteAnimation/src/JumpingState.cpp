#include "JumpingState.h"
#include "StateManager.h"

JumpingState::~JumpingState()
{
}

void JumpingState::init(StateManager* manager)
{
	this->manager = manager;
}

void JumpingState::exit()
{
	this->manager = nullptr;
}

void JumpingState::update(float deltaTime)
{
}

void JumpingState::draw(Sprite& sprite, Vec2f& pos, int framesPerSec, bool isFlipped)
{
	sprite.animate(pos, isFlipped, 2, framesPerSec);
}

void JumpingState::keyDown(ci::app::KeyEvent event, ci::Vec2f& pos, ci::Vec2f& velocity)
{
	if (event.getCode() == cinder::app::KeyEvent::KEY_LEFT)
	{
		manager->setState("running");
	}

	else if (event.getCode() == cinder::app::KeyEvent::KEY_RIGHT)
	{
		manager->setState("running");
	}
}

void JumpingState::keyUp(ci::app::KeyEvent event)
{
	if (event.getCode() == cinder::app::KeyEvent::KEY_LEFT)
	{
		manager->setState("standing");
	}

	if (event.getCode() == cinder::app::KeyEvent::KEY_RIGHT)
	{
		manager->setState("standing");
	}
}