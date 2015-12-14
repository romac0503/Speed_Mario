#pragma once

#include <map>
#include "Sprite.h"

#define JUMP_VELOCITY 45.0
#define GRAVITY 8.0

// forward declaration to avoid circular header file dependency
class State;

class StateManager
{
private:
	State* currState;
	bool leftDown, rightDown;
	bool jumpPressed;
	bool grounded;
	cinder::Vec2f playerStartPos;
	cinder::Vec2f pos;
	cinder::Vec2f velocity;
	float jumpVelocity;
	float gravity;

	std::map<std::string, State*> states; // map of all available states
	bool isFlipped;

	// just for testing reasons
	State* standing;
	State* running;
	State* jumping;

	void calcPos(float delta);

public:
	StateManager();
	~StateManager();

	void setState(std::string stateName);
	void registerState(std::string name, State* state);

	void update(float delta);
	void draw(Sprite& sprite, cinder::Vec2f& pos, int framesPerSec);

	cinder::Vec2f getPos() { return pos; }
	void setPos(cinder::Vec2f pos) { this->pos = pos; }
	void setVelocity(cinder::Vec2f velocity) { this->velocity = velocity; }
	cinder::Vec2f getVelocity() { return velocity; }

	void keyDown(ci::app::KeyEvent event, cinder::Vec2f& pos, cinder::Vec2f& velocity);
	void keyUp(ci::app::KeyEvent event);

};


