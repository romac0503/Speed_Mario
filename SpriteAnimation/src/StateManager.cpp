#include "StateManager.h"
#include "State.h"
#include "StandingState.h"
#include "RunningState.h"
#include "JumpingState.h"

StateManager::StateManager():currState(nullptr)
{
	isFlipped = false;
	jumpPressed = false;
	grounded = true;
	jumpVelocity = JUMP_VELOCITY;
	gravity = GRAVITY;
}

StateManager::~StateManager()
{
	delete currState;
}

void StateManager::setState(std::string stateName)
{
	State* state = states[stateName];

	if (state != currState)
	{
		if (currState != nullptr)
		{
			currState->exit();
		}
		currState = state;
		currState->init(this);
	}
}

void StateManager::registerState(std::string name, State* state)
{
	states[name] = state;
}

void StateManager::update(float delta)
{
	if (grounded && !jumpPressed)
	{
		jumpVelocity = JUMP_VELOCITY;
		jumpPressed = false;
	}

	if (!grounded)
	{
		pos.y -= jumpVelocity;
		jumpVelocity -= gravity;
	}

	if (pos.y >= getWindowHeight() / 2)
	{
		pos.y = getWindowHeight() / 2;
		grounded = true;
	}

	if (leftDown)
	{
		pos.x -= (velocity.x + delta);
	}

	if (rightDown)
	{
		pos.x += (velocity.x + delta);
	}

	currState->update(delta);
}

void StateManager::draw(Sprite& sprite, Vec2f& pos, int framesPerSec)
{
	currState->draw(sprite, pos, framesPerSec, isFlipped);
}

void StateManager::keyDown(ci::app::KeyEvent event, cinder::Vec2f& pos, cinder::Vec2f& velocity)
{
	if (event.getCode() == cinder::app::KeyEvent::KEY_LEFT)
	{
		isFlipped = true;
		rightDown = false;
		leftDown = true;
		currState->keyDown(event, pos, velocity);
	}

	if (event.getCode() == cinder::app::KeyEvent::KEY_RIGHT)
	{
		isFlipped = false;
		rightDown = true;
		leftDown = false;
		currState->keyDown(event, pos, velocity);
	}

	if (event.getCode() == cinder::app::KeyEvent::KEY_SPACE)
	{
		currState->keyDown(event, pos, velocity);
		jumpPressed = true;
		grounded = false;
	}
}

void StateManager::keyUp(ci::app::KeyEvent event)
{
	if (event.getCode() == cinder::app::KeyEvent::KEY_LEFT)
	{
		leftDown = false;
		currState->keyDown(event, pos, velocity);
	}

	if (event.getCode() == cinder::app::KeyEvent::KEY_RIGHT)
	{
		rightDown = false;
		currState->keyDown(event, pos, velocity);
	}

	if (event.getCode() == cinder::app::KeyEvent::KEY_SPACE)
	{
		jumpPressed = false;
	}
	currState->keyUp(event);
}