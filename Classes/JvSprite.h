#ifndef _JVSPRITE_H
#define _JVSPRITE_H

#include "JvH.h"

class JvSprite : public CCSprite
{
public:
	JvSprite();
	~JvSprite();

	JvSprite* create();

	virtual void setPosition( const CCPoint& pos );

protected:
	JvObject* mJvObject;
};

#endif