#pragma once

#include <cinder/Cinder.h>
#include <cinder/app/AppBasic.h>
#include "State.h"
#include "Sprite.h"

//forward declaration
class JumpingState;
class StandingState;

class RunningState : public State
{
public:
	RunningState(StateManager* _manager) :State(_manager) {}
	virtual ~RunningState();
	
	virtual void init(StateManager* manager);
	virtual void exit();

	virtual void update(float deltaTime);
	virtual void draw(Sprite& sprite, cinder::Vec2f& position, int framesPerSec, bool isFlipped);

	virtual void keyDown(ci::app::KeyEvent event, cinder::Vec2f& pos, cinder::Vec2f& velocity);
	virtual void keyUp(ci::app::KeyEvent event);

private:
	float _frameDelta;
	int _currentFrame;
	float _deltaTime;
};
