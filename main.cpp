#include<SDL2/SDL.h>
#include<stdio.h>
#include<SDL2/SDL_image.h>
// #include "Game.h";

bool init();
bool loadMedia();
void close();

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// ref to window and screen surface
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* shipAsset = NULL;

bool init()
{
    bool success = true;
    //error handle
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not start. SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow( "My SDL Game", 
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
            SCREEN_WIDTH, SCREEN_HEIGHT, 
            SDL_WINDOW_SHOWN );

        if( gWindow == NULL )
        {
            printf( "Window could not be started. Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface( gWindow );
            SDL_FillRect( gScreenSurface, NULL, SDL_MapRGB( gScreenSurface->format, 80, 80, 80 ) );
            //fill rect on this surface with color in rgb
        }
    }
    return success;
}

bool loadMedia()
{
    bool success = true;
    shipAsset = IMG_Load( "assets/ship.png" );
    if( shipAsset == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        success = false;
    }
    else
    {
        SDL_BlitSurface( shipAsset, NULL, gScreenSurface, NULL );
    }
    return success;
}

void close()
{
    SDL_DestroyWindow( gWindow );
    SDL_Quit();
}

int main(int argc, char* args[])
{
    if ( !init())
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        if(!loadMedia() )
        {
            printf("Failed to load media. Exiting.");
        }
        else
        {
            bool quit = false;
            SDL_Event e;

            while(!quit)
            {
                while( SDL_PollEvent( &e ) != 0)
                {
                    if( e.type == SDL_QUIT)
                    {
                        quit=true;
                        close();
                    }
                }
                SDL_UpdateWindowSurface( gWindow );
            }
            
        }

    }
}