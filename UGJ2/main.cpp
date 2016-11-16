#include "Project.h"
#include <Windows.h>
class MySceen : public Screen
{
private:
	Input* input;
public:
	void Start()
	{
		input = game->GetInput();
		MessageBox(0,"Kek","KekMessage",MB_OK);
	}
	void Update()
	{
		if(input->IsKeyDown('w') || input->IsExit())
			game->Exit();
	}
};

int main(int argc, char** argv)
{
	/*
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Init(SDL_INIT_EVERYTHING);	
	window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	screenSurface = SDL_GetWindowSurface( window );
	SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
	SDL_UpdateWindowSurface( window );
	SDL_Delay( 2000 );
	SDL_DestroyWindow( window );	
	SDL_Quit();
	*/
	Game game;
	return game.Execute(new MySceen(), 640,480);
}