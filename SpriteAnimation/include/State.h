#pragma once

#include <cinder/Cinder.h>
#include <cinder/app/AppBasic.h>

//forward declaration
class GameStateManager;

class State
{
public:
	virtual ~State() {};
	virtual void init(GameStateManager* manager) = 0;
	virtual void exit() = 0;
	virtual void update(float delta) = 0;
	virtual void draw() = 0;
	virtual void keyDown(ci::app::KeyEvent event) = 0;
	virtual void keyUp(ci::app::KeyEvent event) = 0;
};