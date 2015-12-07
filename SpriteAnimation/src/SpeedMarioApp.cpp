#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "SpeedMarioApp.h"

#define WINDOW_WIDTH 1980
#define WINDOW_HEIGHT 1080

using namespace ci;
using namespace ci::app;
using namespace std;

void SpriteAnimationApp::prepareSettings(Settings* settings)
{
	// following 3 lines are for opening a consol window, as this is not standard for a cinder app
	FILE* f;
	AllocConsole();
	freopen_s(&f, "CON", "w", stdout);

	settings->setTitle("Main | http://www.multimediatechnology.at");
	settings->setWindowSize(1280,860);
	settings->setResizable(false);
}

void SpriteAnimationApp::setup()
{
	FRAMES_PER_SECOND = 8;
	FRAME_SIZE = cinder::Vec2f(64.0f, 64.0f);

	texture = loadImage(loadAsset("../assets/mario.png"));	
	isLeft = false;
	player = new Sprite();

	playerStartPos = ci::app::getWindowCenter();
	pos = playerStartPos;
	velocity = Vec2f(12.0, 0);
	lastTime = getElapsedSeconds();
}

void SpriteAnimationApp::update()
{
	currTime = getElapsedSeconds();
	deltaTime = currTime - lastTime;
	lastTime = currTime;
}

void SpriteAnimationApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
	gl::enableAlphaTest();
	gl::enableAlphaBlending();
	player->animate(texture, pos, isLeft, currState, FRAMES_PER_SECOND, FRAME_SIZE);
	//drawMario(pos, isLeft, currState );
}

//void SpriteAnimationApp::drawMario(const Vec2f& position, bool left, SpriteAnimationApp::MarioAnimation animation)
//{
//	gl::pushMatrices();
//
//	// move mario to the position
//	gl::translate(position);
//	
//	// flip if left
//	if (left)
//	{
//		gl::scale(Vec2f(-1, 1));
//	}
//
//	int frame = 0;
//
//	// calculate the correct frame
//	switch (animation)
//	{
//	case MARIO_STANDING:
//		frame = 0;
//		break;
//	case MARIO_RUNNING:
//		frame = (ci::app::getElapsedFrames() / FRAMES_PER_SECOND) % 2 + 1;
//		break;
//	case MARIO_JUMPING:
//		frame = 2;
//		break;
//	}
//
//	// set origin to bottom-center.
//	gl::translate(Vec2f(-FRAME_SIZE.x / 2, -FRAME_SIZE.y));
//
//	// draw the final frame.
//	gl::draw(texture, Area(Vec2i(64 * frame, 0), Vec2i(64 * (frame + 1), 64)), Rectf(0, 0, 64, 64));
//	gl::popMatrices();
//}



void SpriteAnimationApp::keyDown(ci::app::KeyEvent event)
{
	if (event.getCode() == app::KeyEvent::KEY_LEFT)
	{
		currState = MarioAnimation::MARIO_RUNNING;
		isLeft = true;
		pos.x -= (deltaTime + velocity.x);
	}

	if (event.getCode() == app::KeyEvent::KEY_RIGHT)
	{
		currState = MarioAnimation::MARIO_RUNNING;
		isLeft = false;
		pos.x += (deltaTime + velocity.x);
	}
}

void SpriteAnimationApp::keyUp(ci::app::KeyEvent event)
{
	if (event.getCode() == app::KeyEvent::KEY_LEFT)
	{
		currState = MarioAnimation::MARIO_STANDING;
	}

	if (event.getCode() == app::KeyEvent::KEY_RIGHT)
	{
		currState = MarioAnimation::MARIO_STANDING;
	}
}

CINDER_APP_NATIVE( SpriteAnimationApp, RendererGl )
