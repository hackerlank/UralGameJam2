#pragma once
#include "../Project.h"
#include "../Engine/Screen.h"
//#include "Character.h"
#include "Player.h"

class GameProcessScreen :
	public Screen
{
private:
	Input* input;
	Graphics* graphics;
	SDL_Renderer* renderer;
	//Character* player;
	Player* player;
	SDL_Texture* t1;
	SDL_Texture* t2;
	SDL_Rect r;
	SDL_Rect* r1;
	double angle = 45;
	int yDirection = 1;
	int mX = 0, mY = 0;
	double kek1;

	Timer fpsTimer;
	Timer capTimer;
	int countedFrames = 0;


public:
	GameProcessScreen();
	virtual ~GameProcessScreen();
	void Start();
	void Update();
	void Destroy();
};

