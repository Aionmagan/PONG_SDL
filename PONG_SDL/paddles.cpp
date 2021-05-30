#include "paddles.h"
#include "colorChange.h"

void paddles::DrawPaddle()
{
    SDL_FillRect(drawSurface, &shape, SDL_MapRGB(drawSurface->format, r, g, b));
}

void paddles::Move(int sy)
{
    if(!isCPU)
    {
        shape.y += sy;
    }else
    {
        if(shape.y > sy)
        {
            shape.y -= 1;
        }else if(shape.y < sy)
        {
            shape.y += 1;  
        }
    }
    
    y = shape.y;
    x = shape.x;
    
}

void paddles::ReadColor()
{
    if(!isCPU)
    {
        ColorFileRead('p', r, g, b); 
    }else{
        ColorFileRead('c', r, g, b);
    }
}

void paddles::BoundryCheck(int limitUp, int limitDown)
{
    if(shape.y > limitDown){shape.y = limitDown;}
    if(shape.y < limitUp  ){shape.y = limitUp;  }
    
    /*sense boundryCheck is called every 
     * frame then we draw here for cleaner main code
     */
     DrawPaddle();
}