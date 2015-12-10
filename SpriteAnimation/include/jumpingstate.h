#pragma once

#include <cinder/Cinder.h>
#include <cinder/app/AppBasic.h>
#include "State.h"
#include "Sprite.h"

//forward declaration
class StandingState;
class RunningState;

class JumpingState : public State
{
public:
	JumpingState(StateManager* _manager) :State(_manager) {}
	virtual ~JumpingState();
	
	virtual void init(StateManager* manager);
	virtual void exit();

	virtual void update(float deltaTime);
	virtual void draw(Sprite& sprite, cinder::Vec2f& position, int framesPerSec, bool isFlipped);

	virtual void keyDown(ci::app::KeyEvent event, cinder::Vec2f& pos, cinder::Vec2f& velocity);
	virtual void keyUp(ci::app::KeyEvent event);

private:

	float m_frameDelta;
	int m_currentFrame;
	float _deltaTime;
	ci::Vec2f _pos;
};

