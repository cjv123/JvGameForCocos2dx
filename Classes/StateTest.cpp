#include "StateTest.h"
#include "JvSprite.h"
#include "JvU.h"

StateTest::StateTest()
{

	
}

StateTest::~StateTest()
{

}

void StateTest::initState()
{
	JvSprite* jvspritetest = JvSprite::create();
	jvspritetest->initWithFile("CloseNormal.png");
	jvspritetest->setPosition(ccp(400,400));
	add(jvspritetest);
	//jvspritetest->getJvObject()->velocity.x = 100;
	jvspritetest->getJvObject()->acceleration.y = 500;

	JvSprite* jvsptest2 = JvSprite::create();
	jvsptest2->initWithFile("HelloWorld.png");
	jvsptest2->setPosition(ccp(400,0));
	add(jvsptest2);
	jvsptest2->getJvObject()->SetFixed(true);
}

void StateTest::update( float delta )
{
	collide();
	JvState::update(delta);
}

