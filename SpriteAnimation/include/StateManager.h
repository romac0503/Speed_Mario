#pragma once

#include <map>
#include "Sprite.h"

// forward declaration to avoid circular header file dependency
class State;

class StateManager
{
private:
	State* currState;
	StateManager(const StateManager& manager);
	StateManager& operator=(StateManager const& other);
	
	std::map<std::string, State*> states; // map of all available states
	bool isFlipped;

	// just for testing reasons
	State* standing;
	State* running;
	State* jumping;

	/*static StateManager* manager;
	static bool instanceFlag;*/

public:
	/*static StateManager* getInstance();*/
	void setState(std::string stateName);
	//void registerState(std::string name, State* state);
	
	void update(float delta);
	void draw(Sprite& sprite, cinder::Vec2f& pos, int framesPerSec);

	void keyDown(ci::app::KeyEvent event, cinder::Vec2f& pos, cinder::Vec2f& velocity);
	void keyUp(ci::app::KeyEvent event);

	StateManager();
	~StateManager() { /*instanceFlag = false;*/ }

};

//bool StateManager::instanceFlag = false;
//StateManager* StateManager::manager = NULL;

