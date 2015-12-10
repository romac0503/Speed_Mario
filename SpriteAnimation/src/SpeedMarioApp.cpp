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
	standing = "standing";
	running = "running";
	jumping = "jumping";
}

void SpriteAnimationApp::setup()
{
	FRAMES_PER_SECOND = 8;
	FRAME_SIZE = cinder::Vec2f(64.0f, 64.0f);

	texture = loadImage(loadAsset("../assets/mario.png"));	
	isLeft = false;
	player = new Sprite(texture);
	player->setFrameSize(FRAME_SIZE);

	playerStartPos = ci::app::getWindowCenter();
	pos = playerStartPos;
	velocity = Vec2f(12.0, 0);

	// create Character States
	/*StandingState* standing = new StandingState(manager);*/
	/*manager->registerState("standing", standing);*/

	/*RunningState* running = new RunningState(manager);*/
	/*manager->registerState("running", running);*/

	/*JumpingState* jumping = new JumpingState(manager);*/
	/*manager->registerState("jumping", jumping);*/

	manager = new StateManager();
	// enter first state
	manager->setState("standing");

	lastTime = getElapsedSeconds();
}

void SpriteAnimationApp::update()
{
	currTime = getElapsedSeconds();
	deltaTime = currTime - lastTime;
	lastTime = currTime;
	manager->update(deltaTime);
}

void SpriteAnimationApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
	gl::enableAlphaTest();
	gl::enableAlphaBlending();
	manager->draw(*player, pos, FRAMES_PER_SECOND);
}

void SpriteAnimationApp::keyDown(ci::app::KeyEvent event)
{
	manager->keyDown(event, pos, velocity);
}

void SpriteAnimationApp::keyUp(ci::app::KeyEvent event)
{
	manager->keyUp(event);
}

CINDER_APP_NATIVE( SpriteAnimationApp, RendererGl )
