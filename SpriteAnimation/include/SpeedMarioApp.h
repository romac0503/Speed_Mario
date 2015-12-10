#pragma once

#include "cinder/app/AppNative.h"
#include <cinder/Cinder.h>
#include "Sprite.h"
#include "StateManager.h"
#include "StandingState.h"
#include "JumpingState.h"
#include "RunningState.h"

class SpriteAnimationApp : public ci::app::AppNative
{

public:
	/// initialize game
	void setup();

	void prepareSettings(Settings* settings);

	/// keydown callback
	void keyDown(ci::app::KeyEvent event);

	/// keyup callback
	void keyUp(ci::app::KeyEvent event);

	/// update the game
	void update();

	/// render the game
	void draw();

private:
	enum MarioAnimation
	{
		MARIO_STANDING,	/*!< Standing pose */
		MARIO_RUNNING,	/*!< Running animation */
		MARIO_JUMPING	/*!< Jumping pose */
	};

	int FRAMES_PER_SECOND;
	cinder::Vec2f FRAME_SIZE;

	std::string standing;
	std::string running;
	std::string jumping;

	float lastTime, currTime, deltaTime;
	cinder::Vec2f playerStartPos;
	cinder::Vec2f pos;
	cinder::Vec2f velocity;
	MarioAnimation animation;
	bool isLeft;
	ci::gl::Texture texture;
	Sprite* player;
	StateManager* manager;
};