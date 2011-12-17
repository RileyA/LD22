#include <iostream>
#include "Common.h"
#include "SDLMgr.h"

int main(int argc, char** argv)
{
	SDLMgr gfx(640,480);
	gfx.init();

	while(gfx.update(0.f));// usleep(50000);

	gfx.deinit();

	return 0;
}
