#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<stdio.h>
#include<string>

#include "Ship.h";
// #include "Game.h";

bool init();
bool loadMedia();
void close();

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int PLAYER_SPEED = 2;

// ref to window and screen surface
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* shipAsset = NULL;

int SHIP_HEIGHT = 75;
int SHIP_WIDTH = 98;

SDL_Rect shipRect;



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
        printf( "Unable to load image %s! SDL Error: %s\n", "assets/ship.png", SDL_GetError() );
        success = false;
    }
    else
    {
        SDL_Rect shipRect;
        shipRect.x = 0;
        shipRect.y = 0;
        shipRect.h = SHIP_HEIGHT;
        shipRect.w = SHIP_WIDTH;
        SDL_BlitSurface( shipAsset, NULL,  gScreenSurface, &shipRect );
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
            string newName = "hi";
            Ship myShipClass(" Ship One ");
            cout << myShipClass.getName() << endl;
            SDL_Event e;

            while(!quit)
            {
                while( SDL_PollEvent( &e ) != 0)
                {
                    if( e.type == SDL_QUIT || e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE )
                    {
                        quit=true;
                        close();
                    }
                    if( e.type == SDL_KEYDOWN )
                    {
                        //clear screen
                        SDL_FillRect( gScreenSurface, NULL, SDL_MapRGB( gScreenSurface->format, 80, 80, 80 ) );

                        switch( e.key.keysym.sym )
                        {
                            case SDLK_UP:
                            shipRect.y -= PLAYER_SPEED;
                            myShipClass.setName("will");
                            cout << myShipClass.getName() << endl;
                            break;

                            case SDLK_DOWN:
                            shipRect.y += PLAYER_SPEED;

                            break;

                            case SDLK_LEFT:
                            shipRect.x -= PLAYER_SPEED;
                            break;

                            case SDLK_RIGHT:
                            shipRect.x += PLAYER_SPEED;
                            break;

                            default:
                            break;
                        }
                        SDL_BlitSurface( shipAsset, NULL, gScreenSurface, &shipRect );
                    }
                }
                SDL_UpdateWindowSurface( gWindow );
            }
            
        }

    }
}