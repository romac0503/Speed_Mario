#pragma once

#include <cinder/Cinder.h>
#include <cinder/app/AppBasic.h>
#include "State.h"

//forward declaration
class JumpingState;
class StandingState;

class RunningState : public State
{
public:
	virtual ~RunningState();
	void init();
	void update(float deltaTime);
	void draw();
	void keyDown(ci::app::KeyEvent event);
	void keyUp(ci::app::KeyEvent event);

private:
	float m_frameDelta;
	int m_currentFrame;
};
