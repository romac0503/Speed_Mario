#pragma once

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Cinder.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rect.h"
#include "cinder/Utilities.h"
#include "SpeedMarioApp.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Sprite {
public:
	Sprite(/*ci::gl::Texture texture, int rows, int spritesPerRow*/);
	~Sprite();
	
	void draw(ci::gl::Texture& texture, Vec2f& position, bool left, int animation, int framesPerSec, Vec2f frameSize);
	void update(float delta);

	//! sets the active animation
	void setAnimation(int animation);

	//! add new animation
	//! \param name the name of the animation
	//! \param startIdx of the animation
	//! \param endIdx of the animation
	//! \param flip true if frame should be flipped for left right direction
	void addAnimation(std::string& state, int startIdx, int endIdx, bool flip);
	void animate(ci::gl::Texture& texture, Vec2f& position, bool left, int animation, int framesPerSec, Vec2f frameSize);
	

private:
	struct Animation
	{
		int _startIdx;  // start idx of the animation
		int _endIdx;   // end idx of the animation
		bool _flip;     // flag if frame should be flipped for left right direction
	};

	std::map<std::string, Animation> _animations;

	Animation _currentAnimation;	
};
