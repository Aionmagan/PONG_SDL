#include "ball.h"
#include "colorChange.h"

void ball::DrawBall()
{
    SDL_FillRect(drawSurface, &shape, SDL_MapRGB(drawSurface->format, r, g, b));
}

void ball::Move()
{
    shape.x += moveSpeedX;
    shape.y += moveSpeedY;
    y = shape.y; 
    x = shape.x;
}

void ball::ResetCenter()
{
    shape.x = centerX; 
    shape.y = centerY;
    shape.h = shape.w = shapped;
}

void ball::ReadColor()
{
    ColorFileRead('b', r, g, b);
}

void ball::BoundryCheck(int limitUp, int limitDown, paddles leftPaddle, paddles rightPaddle)
{
    //static int player=0, cpu=0;
    //if(shape.x > 640){++cpu;    printf(stderr, "CPU: %d \n"  ,    cpu); ResetCenter();}
    //if(shape.x < 0  ){++player; printf(stderr, "player: %d \n", player); ResetCenter();}
    
    if(shape.x >= 640 || shape.x <= 0){ResetCenter();}
    
    if(shape.y > limitDown || shape.y < limitUp){moveSpeedY = moveSpeedY*-1;}
    
    if (shape.x < 320)
    {
        if(shape.x < leftPaddle.x + 19 && shape.x > leftPaddle.x - 2 &&
           shape.y < leftPaddle.y + 90 && shape.y > leftPaddle.y - 20)
        {
            moveSpeedX *= -1;
            //moveSpeedY *= -1;
        }
    }else if (shape.x > 320)
    {
        if(shape.x < rightPaddle.x + 19 && shape.x > rightPaddle.x - 19 &&
           shape.y < rightPaddle.y + 90 && shape.y > rightPaddle.y - 20)
        {
            moveSpeedX *= -1;
           // moveSpeedY *= -1;
        }
    }
    /*call every other needed functions*/
    Move();
    DrawBall();
}