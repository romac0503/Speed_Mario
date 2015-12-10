#include "StateManager.h"
#include "State.h"
#include "StandingState.h"
#include "RunningState.h"
#include "JumpingState.h"

StateManager::StateManager():currState(nullptr)
{
	standing = new StandingState(this);
	running = new RunningState(this);
	jumping = new JumpingState(this);
	currState = standing;
	isFlipped = false;
}

StateManager::StateManager(const StateManager& cpy)
{
	// here the assignment operator is called, which
	// does all the work.
	*this = cpy;
}

StateManager& StateManager::operator=(StateManager const &other)
{
	// TODO: insert return statement here
	if (this == &other)
	{
		return *this;
	}
}

//StateManager* StateManager::getInstance()
//{
//	if (!instanceFlag)
//	{
//		instanceFlag = true;
//		manager = new StateManager();
//		return manager;
//	}
//	else
//	{
//		return manager;
//	}
//}

void StateManager::setState(std::string stateName)
{
	/*State* state = states[stateName];*/
	if (currState != nullptr)
	{
		if (stateName == "standing")
		{
			if (currState != standing)
			{
				currState->exit();
			}
			currState = new StandingState(this);
			currState->init(this);
		}
		else if (stateName == "running")
		{
			if (currState != running)
			{
				currState->exit();
			}
			currState = new RunningState(this);
			currState->init(this);
		}
		else if (stateName == "jumping")
		{
			if (currState != jumping)
			{
				currState->exit();
			}
			currState = new JumpingState(this);
			currState->init(this);
		}
	}
	
	/*if (state != currState)
	{
		currState->exit();
	}
	currState = state;
	currState->init();*/
}

//void StateManager::registerState(std::string name, State* state)
//{
//	states[name] = state;
//}

void StateManager::update(float delta)
{
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
	}

	if (event.getCode() == cinder::app::KeyEvent::KEY_RIGHT)
	{
		isFlipped = false;
	}
	currState->keyDown(event, pos, velocity);
}

void StateManager::keyUp(ci::app::KeyEvent event)
{
	currState->keyUp(event);
}