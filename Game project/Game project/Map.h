#pragma once
#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Cell.h"

using namespace std;


class Map
{
public:
   int width;
   int height;

   int startx, starty, endx, endy;
   Cell **map;

   Map(int w, int h, int sx, int sy, int ex, int ey);
   ~Map();
   void createMapFromFile();

   bool createMazeRecursion(int startX, int startY, int endX, int endY, int& counts);
   void printMap();



};

