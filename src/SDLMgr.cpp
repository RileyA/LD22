#include "SDLMgr.h"

SDLMgr::SDLMgr(int w, int h)
{
	mWidth = w;
	mHeight = h;
	mMouseX = 0;
	mMouseY = 0;
}

SDLMgr::~SDLMgr()
{
	
}

void SDLMgr::init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		throw std::runtime_error("SDL failed to start.");

	mSurface = SDL_SetVideoMode(mWidth, mHeight, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	if(!mSurface) 
		throw std::runtime_error("SDL surface couldn't be created.");

	SDL_WM_SetCaption("Ludum Dare 22 - Riley Adams", 0);
}

void SDLMgr::deinit()
{
	SDL_Quit();
}

bool SDLMgr::update(float delta)
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_KEYDOWN:
			if(event.key.keysym.sym == SDLK_ESCAPE)
				return false;
			printf("Key press detected\n");
			break;

		case SDL_KEYUP:
			printf("Key release detected\n");
			break;

		case SDL_QUIT:
			return false;

		default:
			break;
		}
	}

	fillScreen(0,0,0);

	int oldMX = mMouseX;
	int oldMY = mMouseY;

	mMouseButtons = SDL_GetMouseState(&mMouseX, &mMouseY);

	int relativeX = oldMX - mMouseX;
	int relativeY = oldMY - mMouseY;

	if(mMouseButtons)
		drawLine(oldMX, oldMY, mMouseX, mMouseY);

	flip();

	return true;
}

void SDLMgr::flip()
{
	SDL_Flip(mSurface);
}

