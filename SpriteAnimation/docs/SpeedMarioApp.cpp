#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SpeedMarioApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void keyDown(ci::app::KeyEvent event);
	void keyUp(ci::app::KeyEvent event);

	void update();
	void draw();

private:
	enum MarioAnimation 
	{
		MARIO_STANDING,	/*!< Standing pose */
		MARIO_RUNNING,	/*!< Running animation */
		MARIO_JUMPING	/*!< Jumping pose */
	};

	/*! Draw mario on the given position.
	 * \param position the bottom-center corner where mario should be drawn.
	 * \param left true if mario should be flipped.
	 * \param animation which animation should be used to draw mario.
	 */
	void drawMario(const Vec2f& position, int left, MarioAnimation animation = MARIO_STANDING);

	// mario texture
	gl::Texture texture;
};

void SpeedMarioApp::setup()
{
	texture = loadImage(loadAsset("mario.png"));
}

void SpeedMarioApp::mouseDown(MouseEvent event)
{
}

void SpeedMarioApp::keyDown(ci::app::KeyEvent event)
{
	if (event.getCode() == app::KeyEvent::KEY_LEFT)
	{}

	if (event.getCode() == app::KeyEvent::KEY_RIGHT)
	{}
}
void SpeedMarioApp::keyUp(ci::app::KeyEvent event)
{
	if (event.getCode() == app::KeyEvent::KEY_LEFT)
	{}

	if (event.getCode() == app::KeyEvent::KEY_RIGHT)
	{}
}

void SpeedMarioApp::update()
{
}

void SpeedMarioApp::draw()
{
	// clear out the window with black
	gl::clear(Color(0, 0, 0));

	// set alpha blending to true
	gl::enableAlphaTest();
	gl::enableAlphaBlending();


	drawMario(Vec2f(50, 50), 0);
}

void SpeedMarioApp::drawMario(const Vec2f& position, int left, SpeedMarioApp::MarioAnimation animation)
{
	const int FRAMES_PER_SECOND = 8;
	const Vec2f FRAME_SIZE(64.0f, 64.0f);

	gl::pushMatrices();

	// move mario to the position
	gl::translate(position );

	// flip if left
	if (left)
	{
		gl::scale(Vec2f(-1, 1));
	}

	int frame = 0;

	// calculate the correct frame
	switch (animation)
	{
		case MARIO_STANDING:
			frame = 0;
			break;
		case MARIO_RUNNING:
			frame = (ci::app::getElapsedFrames() / FRAMES_PER_SECOND) % 2 + 1;
			break;
		case MARIO_JUMPING:
			frame = 2;
			break;
	}

	// set origin to bottom-center.
	gl::translate(Vec2f(-FRAME_SIZE.x / 2, -FRAME_SIZE.y));

	// draw the final frame.
	gl::draw(texture, Area(Vec2i(64 * frame, 0), Vec2i(64 * (frame + 1), 64)), Rectf(0, 0, 64, 64));
	gl::popMatrices();
}

CINDER_APP_NATIVE( SpeedMarioApp, RendererGl )
