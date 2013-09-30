#include "JvSprite.h"
#include "JvG.h"
#include "JvU.h"
#include "JvState.h"

JvSprite::JvSprite() 
{
	mJvObject = new JvObject();
	scheduleUpdate();
}

JvSprite::~JvSprite()
{
	delete mJvObject;
}


JvSprite* JvSprite::create()
{
	JvSprite* instance=new JvSprite();
	if (instance && instance->init())
	{
		instance->autorelease();
	}

	return instance;
}

void JvSprite::update( float delta )
{
	JvG::stateP->camera.render(this);

	CCSprite::update(delta);
}

JvObject* JvSprite::getJvObject()
{
	return mJvObject;
}



