#pragma once

#include "cinder/app/AppNative.h"
#include "Sprite.h"
#include "State.h"
#include "StandingState.h"
#include "JumpingState.h"
#include "RunningState.h"

class SpriteAnimationApp : public ci::app::AppNative
{

friend class Sprite;

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

	/*! Draw mario on the given position.
	* \param position the bottom-center corner where mario should be drawn.
	* \param left true if mario should be flipped.
	* \param animation which animation should be used to draw mario.
	*/
	//void drawMario(const Vec2f& position, bool left, MarioAnimation animation = MARIO_STANDING);

	float lastTime, currTime, deltaTime;
	cinder::Vec2f playerStartPos;
	cinder::Vec2f pos;
	cinder::Vec2f velocity;
	MarioAnimation currState;
	bool isLeft;
	ci::gl::Texture texture;
	Sprite* player;
};