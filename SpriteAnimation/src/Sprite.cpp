#include "Sprite.h"

Sprite::Sprite(ci::gl::Texture& texture /*, int rows, int spritesPerRow*/)
{
	_texture = texture;
}

Sprite::~Sprite()
{
}

void Sprite::animate(Vec2f& position, bool left, int animation, int framesPerSec)
{
	gl::pushMatrices();

	// move mario to the position
	gl::translate(position);

	// flip if left
	if (left)
	{
		gl::scale(Vec2f(-1, 1));
	}

	int frame = 0;

	// calculate the correct frame
	switch (animation)
	{
	case 0:		// standing
		frame = 0;
		break;
	case 1:		// running
		frame = (ci::app::getElapsedFrames() / framesPerSec) % 2 + 1;
		break;
	case 2:		// jumping
		frame = 2;
		break;
	}

	// set origin to bottom-center.
	gl::translate(Vec2f(-_frameSize.x / 2, _frameSize.y));

	// draw the final frame.
	gl::draw(_texture, Area(Vec2i(64 * frame, 0), Vec2i(64 * (frame + 1), 64)), Rectf(0, 0, 64, 64));
	gl::popMatrices();
}

void Sprite::update(float delta)
{

}

void Sprite::draw(Vec2f& position, bool left, int animation, int framesPerSec)
{
	animate(position, left, animation, framesPerSec);
}





