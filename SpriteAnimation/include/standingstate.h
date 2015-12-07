#pragma once

#include <cinder/Cinder.h>
#include <cinder/app/AppBasic.h>
#include "State.h"

//forward declaration
class JumpingState;
class RunningState;

class StandingState : public State
{
public:
	virtual ~StandingState();
	void init();
	void update(double deltaTime);
	void draw();
	void keyDown(ci::app::KeyEvent event);
	void keyUp(ci::app::KeyEvent event);

private:
	float m_frameDelta;
	int m_currentFrame;
};