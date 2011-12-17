#include "Common.h"

// handles drawing stuff (and since I'm lazy and thi sisn't well designed: input and other stuff too!)
class SDLMgr
{
public:

	SDLMgr(int w, int h);
	~SDLMgr();

	void init();
	void deinit();
	bool update(float delta);

	void flip();
	uint32_t* getPx() {return (uint32_t*)mSurface->pixels;}

	int getMouseX() {return mMouseX;}
	int getMouseY() {return mMouseY;}

	SDL_Surface* getSurface() {return mSurface;}

	inline void setPixel(unsigned short x, unsigned short y, byte r, byte g, byte b)
	{
		uint32_t* pixel = ((uint32_t*)mSurface->pixels) + y * mSurface->pitch/4 + x;
		*pixel = SDL_MapRGB(mSurface->format, r,g,b);
	}

	inline void blendPixel(unsigned short x, unsigned short y, byte r, byte g, byte b, byte a)
	{
		setPixel(x,y,r,g,b);
	}

	inline void fillScreen(byte r, byte g, byte b)
	{
		SDL_FillRect(mSurface, 0, SDL_MapRGB(mSurface->format,r,g,b));
	}

	inline void fillRect(short x, short y, unsigned short w, unsigned short h,
		byte r, byte g, byte b, byte a)
	{
		SDL_Rect rect = {x,y,w,h};
		SDL_FillRect(mSurface, &rect, SDL_MapRGB(mSurface->format,r,g,b));
	}

	// draw a line with bresenham's algo
	inline void drawLine(short x1, short y1, short x2, short y2)
	{
		short dx = abs(x2 - x1);
		short dy = abs(y2 - y1);
		
		short sx = (x1 < x2) ? 1 : -1;
		short sy = (y1 < y2) ? 1 : -1;
		short err = dx - dy;

		while(0xdeadbeef)
		{
			setPixel(x1,y1,255,0,0);

			if(x1 == x2 && y1 == y2)
				break;
			
			short e2 = err << 1;

			if(e2 > -1)
			{
				err -= dy;
				x1 += sx;
			}

			if(e2 < dx)
			{
				err += dx;
				y1 += sy;
			}
		}
	}

private:

	SDL_Surface* mSurface;
	int mWidth, mHeight;
	int mMouseX, mMouseY;
	unsigned char mMouseButtons;

};
