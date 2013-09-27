#include "JvSprite.h"

JvSprite::JvSprite()
{

}

JvSprite::~JvSprite()
{

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

