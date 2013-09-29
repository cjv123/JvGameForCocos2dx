#include "JvState.h"
#include "JvG.h"
#include "JvU.h"

JvState::JvState()
{
	_bgColor =0;
}

JvState::~JvState()
{

}

void JvState::create()
{
	camera.init(JvG::width,JvG::height);
	JvG::camera = &camera;

}

void JvState::update()
{
	if (JvG::pause)
	{
		pause();
		return;
	}

	defaultGroup.update();
	camera.update();
}

void JvState::render()
{
	if (_bgColor!=0)
	{
		//FillRect(0,0,JvG::width,JvG::height,_bgColor,DISPLAY_PIXEL_FORMAT_8888);
	}
	defaultGroup.render();
	//camera.renderFlash();
}

void JvState::collide()
{
	JvU::collide(&defaultGroup,&defaultGroup);
}

void JvState::add(JvObject* ObjectP)
{
	defaultGroup.add(ObjectP);
}

void JvState::setBgColor(int Color)
{
	_bgColor = Color;
}

void JvState::pause()
{

}

void JvState::loading()
{
	
}
