#pragma once

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Cinder.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rect.h"
#include "cinder/Utilities.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Sprite {
public:
	Sprite(ci::gl::Texture& texture /*, int rows, int spritesPerRow*/);
	~Sprite();
	
	void draw(Vec2f& position, bool left, int animation, int framesPerSec);
	void update(float delta);
	void animate(Vec2f& position, bool left, int animation, int framesPerSec);
	void setFrameSize(Vec2f frameSize) { _frameSize = frameSize; }
	Vec2f getFrameSize() { return _frameSize; }

private:
	struct Animation
	{
		int _startIdx;  // start idx of the animation
		int _endIdx;   // end idx of the animation
		bool _flip;     // flag if frame should be flipped for left right direction
	};

	ci::gl::Texture _texture;
	Vec2f _frameSize;
};
