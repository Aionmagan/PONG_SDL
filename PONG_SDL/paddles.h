#ifndef _PADS_
#define _PADS_

#include <SDL.h>

class paddles
{
private:
    bool isCPU;
    SDL_Rect shape;
    SDL_Surface *drawSurface;
    
    void DrawPaddle();
    unsigned int r=255, g=255, b=255;
public:
    int x, y;
    paddles(int shapex, int shapey, int xx, int yy, bool cpu, SDL_Surface *sur)
    {
        shape.h     = shapey;
        shape.w     = shapex;
        shape.x     = xx;
        shape.y     = yy;
        isCPU       = cpu;
        drawSurface = sur;
    }
    ~paddles(){}
    
    //paddles can't move in the x axis
    void Move(int sy);
    void ReadColor();
    //unsigned because the screen starts a 0,0 
    void BoundryCheck(int limitUp, int limitDown);
};

#endif //_PADS_