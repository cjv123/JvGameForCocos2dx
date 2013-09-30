#include "JvState.h"
#include "JvG.h"
#include "JvU.h"
#include "JvSprite.h"

JvState::JvState()
{
	mStateLayer = CCLayer::create();
	addChild(mStateLayer);

	camera.init(JvG::width,JvG::height);
	JvG::camera = &camera;

	scheduleUpdate();
}

JvState::~JvState()
{

}

void JvState::collide()
{
	JvU::collide(&defaultGroup,&defaultGroup);
}

void JvState::add(JvObject* ObjectP)
{
	defaultGroup.add(ObjectP);
}

void JvState::add( JvSprite* jvsprite ,bool isSwitch /*= true*/)
{
	JvObject* jvobject = jvsprite->getJvObject();
	if (isSwitch)
	{
		CCRect boundingrect = jvsprite->boundingBox();
		float cocospointX = (float)boundingrect.getMidX();
		float cocospointY = (float)boundingrect.getMaxY();
		JvPoint cocospoint(cocospointX,cocospointY);
		JvPoint jvgamePoint = JvU::cocos2dPoint_to_JvGamePoint(cocospoint,CCDirector::sharedDirector()->getWinSize().height);
		jvobject->x = jvgamePoint.x;
		jvobject->y = jvgamePoint.y;
		jvobject->width = boundingrect.size.width;
		jvobject->height = boundingrect.size.height;
	}

	add(jvobject);
	mStateLayer->addChild(jvsprite);
}

void JvState::update( float delta )
{
	JvG::elapsed = delta;

	camera.update();
}

