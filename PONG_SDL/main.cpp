#include <stdio.h>
#include <iostream>

#include "ball.h"
#include "DebugOutput.h"

#define DELAY 3

int main(int argc, char **argv)
{
    
    struct SCREEN_DATA
    {
        const int H = 480, W = 640;
    }SCREEN;
    
    Debug debug;
    SDL_Surface *g_surface, *g_display;
    SDL_Event g_Event;
    SDL_Rect g_paddle1, g_paddle2, g_ball;
    Uint32 g_Color;
    Uint8 *keys;
    
	if(!SDL_Init(SDL_INIT_VIDEO))
	{
        g_display = SDL_SetVideoMode(SCREEN.W, SCREEN.H, 32, SDL_ANYFORMAT|SDL_NOFRAME);
        g_surface = SDL_DisplayFormat(g_display);
        SDL_PumpEvents();
        keys = SDL_GetKeyState(NULL);
        
        paddles playerPaddle(20, 100, 20, 240, true, g_surface);
        paddles CPUPaddle   (20, 100, SCREEN.W-40, 240, true, g_surface);
        ball    ball        (20, 320, 240, g_surface, 1);
        
        reset:
        playerPaddle.ReadColor();
        CPUPaddle.ReadColor   ();
        ball.ReadColor        ();
        
        for(;g_Event.type != SDL_QUIT;)
        {
            SDL_PollEvent(&g_Event);
            if(keys[SDLK_ESCAPE]){break;}
            
            if(ball.x < 320){playerPaddle.Move(ball.y-45);}
           
            //playerPaddle.Move(-keys[SDLK_UP]+keys[SDLK_DOWN]);
            if(ball.x > 320){CPUPaddle.Move(ball.y-45);}
            
            ball.BoundryCheck(5, 460, playerPaddle, CPUPaddle);
            playerPaddle.BoundryCheck(10, 370);
            CPUPaddle.BoundryCheck   (10, 370);
            
            SDL_BlitSurface(g_surface, NULL, g_display, NULL);
            
            SDL_Flip(g_display);
            
            //for(int i = 0; i < DELAY; ++i);
            
            SDL_Delay(DELAY);
            
            memset(g_display->pixels,0,SCREEN.W*SCREEN.H*4);
            memset(g_surface->pixels,0,SCREEN.W*SCREEN.H*4);
            
            if(keys[SDLK_c]){goto reset;}
            
        }
        
        SDL_Quit();
	}
    
	return 0;
}
