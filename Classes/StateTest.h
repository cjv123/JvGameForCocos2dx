#ifndef _STATETEST_H
#define _STATETEST_H

#include "JvState.h"

class StateTest : public JvState
{
public:
	StateTest();
	~StateTest();

	void initState();

	virtual void update( float delta );

protected:
private:
};

#endif