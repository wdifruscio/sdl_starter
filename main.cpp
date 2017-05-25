#include<SDL2/SDL.h>
#include <stdio.h>
// #include "Game.h";

int main(int argc, char* args[])
{
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    // ref to window and screen surface
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    //error handle
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not start. SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        window = SDL_CreateWindow( "My SDL Game", 
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
            SCREEN_WIDTH, SCREEN_HEIGHT, 
            SDL_WINDOW_SHOWN );

        if( window == NULL )
        {
            printf( "Window could not be started. Error: %s\n", SDL_GetError() );
        }
        else
        {
            screenSurface = SDL_GetWindowSurface( window );
            //fill rect on this surface with color in rgb
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 40, 40, 40 ) );
            //update surface
            SDL_UpdateWindowSurface( window );
            //delay 2s
            SDL_Delay( 2000 );
        }
    }
}