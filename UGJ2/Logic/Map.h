#pragma once
#include <vector>
#include <fstream>
#include "Point.h"
#include "Door.h"
#include "GlassWindow.h"
#include "../Engine/Graphics.h"
#include "../defines.h"
#include <string>

enum PointState
{
	Free = -1,
	OpenDoor = -2,
	CloseDoor = -3,
	Wall = -4,
	Window = -5
};

typedef std::vector< std::vector <PointState> >VecVecPointState;
typedef std::vector< std::vector <Entity*> >VecVecEntity;

const int cellWidth = 32;
const int cellHeight = 32;

class Map
{
public:
	Map(SDL_Texture* wallTexture, SDL_Texture* windowTexture, SDL_Texture* openDoorTexture, SDL_Texture* closeDoorTexture, SDL_Texture* floorTexture);
	bool isPointValid(const Point & p) const;
	PointState getPoint(const uint x, const uint y) const;
	size_t getXSize() const;
	size_t getYSize() const;
	Point getNeighbor(const Point & p, const uint i) const; //�������� i-�� ������
	void update(Point & playerDeltaPosition);
	void render(SDL_Renderer * renderer);
	const int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 }; // ��������, ��������������� ������� ������
	const int dy[8] = { 1, -1, 0, 0, -1, 1, 1, -1 };
	virtual ~Map();
private:
	VecVecPointState map;
	VecVecEntity entityMap;
	Point playerPosition;
	Point leftUpCellOnScreen;
	Point rightDownCellOnScreen;
	const int cellInScreenX = SCREEN_WIDTH / cellWidth;
	const int cellInScreenY = SCREEN_HEIGHT / cellHeight;
	void readFromFile(std::ifstream & file);
};

