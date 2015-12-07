#include "Sprite.h"

Sprite::Sprite(/*ci::gl::Texture texture, int rows, int spritesPerRow*/)
{
	//m_texture = texture;
	//m_frameDelta = 0;
	//m_rows = rows;
	//m_spritesPerRow = spritesPerRow;
	//position.x = ci::app::getWindowWidth() / 2;
	//position.y = ci::app::getWindowHeight() / 2;

	//setFrameSize();
	//
	//m_frameCountX = m_texture.getWidth() / m_frameSize.x;
	//m_frameCountY = m_texture.getHeight() / m_frameSize.y;

	//// calculating the amount of sprites in the spritesheet
	//m_frameCount = (m_currentAnimation.m_endIdx - m_currentAnimation.m_startIdx) + 1;
	//m_currentFrame = m_currentAnimation.m_startIdx;
	////m_frameCount = m_frameCountX * m_frameCountY;
}

Sprite::~Sprite()
{
}

void Sprite::setAnimation(int animation)
{
	switch (animation)
	{
	case 0:
		_currentAnimation = _animations["standing"];
		break;
	case 1:
		_currentAnimation = _animations["running"];
		break;
	case 2:
		_currentAnimation = _animations["jumping"];
		break;
	}
}

void Sprite::addAnimation(std::string& state, int startIdx, int endIdx, bool flip)
{
	Animation anim;
	anim._startIdx = startIdx;
	anim._endIdx = endIdx;
	anim._flip = flip;
	_animations[state] = anim;
}

void Sprite::animate(ci::gl::Texture& texture, Vec2f& position, bool left, int animation, int framesPerSec, Vec2f frameSize)
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
	gl::translate(Vec2f(-frameSize.x / 2, frameSize.y));

	// draw the final frame.
	gl::draw(texture, Area(Vec2i(64 * frame, 0), Vec2i(64 * (frame + 1), 64)), Rectf(0, 0, 64, 64));
	gl::popMatrices();
}

void Sprite::update(float delta)
{

}

void Sprite::draw(ci::gl::Texture& texture, Vec2f& position, bool left, int animation, int framesPerSec, Vec2f frameSize)
{
	animate(texture, position, left, animation, framesPerSec, frameSize);
}

//void Sprite::update(float delta)
//{
//	m_frameDelta += delta;
//
//	const float FRAME_RATE = 10.0f;
//	float frameDuration = 1.0f / FRAME_RATE;
//
//	if (m_frameDelta > frameDuration)
//	{
//		m_currentFrame = (m_currentFrame + 1) % m_frameCount;
//		m_frameDelta -= frameDuration;
//	}
//}

//void Sprite::draw(Vec2f position)
//{
//	const Vec2f FRAME_SIZE(50, 50);
//
//	int frameIdxY = m_currentFrame / m_frameCountX;
//	int frameIdxX = m_currentFrame % m_frameCountX;
//
//	Vec2f offset(m_frameSize.x * frameIdxX, m_frameSize.y * frameIdxY);
//	Area srcArea(offset, offset + m_frameSize);
//
//	if (m_currentAnimation.m_flip)
//	{
//		gl::scale(Vec2f(-1, 1));
//	}
//	gl::draw(m_texture, srcArea, ci::Rectf(position, position + m_frameSize));
//}




