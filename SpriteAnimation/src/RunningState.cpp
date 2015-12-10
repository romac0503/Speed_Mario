#include "RunningState.h"
#include "StateManager.h"

RunningState::~RunningState()
{
	std::cout << "RunningState exited" << std::endl;
}

void RunningState::init(StateManager* manager)
{
	this->manager = manager;
}

void RunningState::exit()
{
	delete this;
}

void RunningState::update(float deltaTime)
{
	_deltaTime = deltaTime;
}

void RunningState::keyDown(ci::app::KeyEvent event, Vec2f& pos, Vec2f& velocity)
{
	if (event.getCode() == app::KeyEvent::KEY_LEFT)
	{
		pos.x -= (_deltaTime + velocity.x);
	}

	if (event.getCode() == app::KeyEvent::KEY_RIGHT)
	{
		pos.x += (_deltaTime + velocity.x);
	}
}

void RunningState::keyUp(ci::app::KeyEvent event)
{
	if (event.getCode() == app::KeyEvent::KEY_LEFT)
	{
		manager->setState("standing");
	}

	if (event.getCode() == app::KeyEvent::KEY_RIGHT)
	{
		manager->setState("standing");
	}
}

void RunningState::draw(Sprite& sprite, Vec2f& pos, int framesPerSec, bool isFlipped)
{
	sprite.animate(pos, isFlipped, 1, framesPerSec);
}



