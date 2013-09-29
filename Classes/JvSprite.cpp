#include "JvSprite.h"

JvSprite::JvSprite() 
{
	mJvObject = new JvObject();
}

JvSprite::~JvSprite()
{
	delete mJvObject;
}


JvSprite* JvSprite::create()
{
	JvSprite* instance=new JvSprite;;
	if (instance && instance->init())
	{
		instance->autorelease();
	}

	return instance;
}

void JvSprite::setPosition( const CCPoint& pos )
{
	CCSprite::setPosition(pos);
	
}

