#include "Point.h"
#include "Map.h"
static const int dx_data[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
const int * Point::dx = dx_data;
static const int dy_data[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int *Point::dy = dy_data;

bool Point::isValid(const VecVecBool & pole) const
{
	if (y < 0 || y >= pole.size())  return false;
	if (x < 0 || x >= pole[y].size()) return false;
	return  pole[y][x];
}

Point Point::getBestNeighbor(const Map & map, const VecVecInt & input) const
{
	auto len = input[y][x];
	for (int i = 0; i < 8; ++i)                    // �������� �� ���� ������������ �������
	{
		Point nextPoint(x + dx[i], y + dy[i]);
		if (!map.isPointValid(nextPoint))
			continue;
		int nextLen = input[nextPoint.y][nextPoint.x];
		if (nextLen != -1 && nextLen < len)
			return nextPoint;
	}
	return Point(0, 0);
}

bool operator==(const Point & l, const Point & r)
{

	if (l.x != r.x) return false;
	if (l.y != r.y) return false;
	return true;

}

bool operator!=(const Point & l, const Point & r)
{
	return !(l == r);
}


