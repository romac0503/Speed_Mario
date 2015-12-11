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
	manager = new StateManager();

	// create Character States
	StandingState* standing = new StandingState(manager);
	manager->registerState("standing", standing);

	RunningState* running = new RunningState(manager);
	manager->registerState("running", running);

	JumpingState* jumping = new JumpingState(manager);
	manager->registerState("jumping", jumping);

	 //enter first state
	manager->setState("standing");

	FRAMES_PER_SECOND = 8;
	FRAME_SIZE = cinder::Vec2f(64.0f, 64.0f);

	texture = loadImage(loadAsset("../assets/mario.png"));	
	player = new Sprite(texture);
	player->setFrameSize(FRAME_SIZE);

	// setting player Startposition and Velocity
	Vec2f playerStartPos = ci::app::getWindowCenter();
	manager->setPos(playerStartPos);
	manager->setVelocity(Vec2f(6.0, 0));

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
	manager->draw(*player, manager->getPos(), FRAMES_PER_SECOND);
}

void SpriteAnimationApp::keyDown(ci::app::KeyEvent event)
{
	manager->keyDown(event, manager->getPos(), manager->getVelocity());
}

void SpriteAnimationApp::keyUp(ci::app::KeyEvent event)
{
	manager->keyUp(event);
}

CINDER_APP_NATIVE( SpriteAnimationApp, RendererGl )
