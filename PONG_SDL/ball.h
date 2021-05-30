#ifndef _BALL_
#define _BALL_

#include <SDL.h>
#include "paddles.h"

class ball
{
private:
    int moveSpeedX, moveSpeedY;
    int centerX, centerY, shapped;
    SDL_Rect shape;
    SDL_Surface *drawSurface;
    
    void DrawBall();
    void Move();
    void ResetCenter();
    unsigned int r=255, g=255, b=255;
    
public:
    int y, x;
    ball(int shap, int x, int y, SDL_Surface *sur, int speed)
    {
        shape.h     = shape.w = shapped = shap;
        shape.x     = centerX = x;
        shape.y     = centerY = y;
        drawSurface = sur;
        moveSpeedX  = moveSpeedY = speed;
    }
    ~ball(){};
    
    void ReadColor();
    //boundryCheck is going to call all functions
    void BoundryCheck(int limitUp, int limitDown, paddles leftPaddle, paddles rightPaddle);
};

#endif //_BALL_