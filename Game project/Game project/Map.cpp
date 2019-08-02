#include "Map.h"
#include <random>


Map::Map(int w, int h, int sx, int sy, int ex, int ey)
{
   startx = sx;
   starty = sy;
   endy = ey;
   endx = ex;

   height = h;
   width = w;

   map = new Cell*[height];

   for (int i = 0; i < height; ++i) {
      map[i] = new Cell[width];
   }


}


Map::~Map()
{
}


void Map::createMapFromFile()
{
   string h, w;

   fstream file("map.txt", ios::in | ios::out);


   map = new Cell*[height];

   for (int i = 0; i < height; ++i) {
      map[i] = new Cell[width];
   }

   char temp;


   for (int i = 0; i < height; i++)
   {
      for (int j = 0; j < width; j++)
      {
         file >> map[i][j].displayItem;
         if (map[i][j].displayItem == '0')
            map[i][j].displayItem = ' ';
      }
      file.seekg(2L, ios::cur);

   }


}

bool Map::createMazeRecursion(int startX, int startY,int endX,int endY,int & counts)
{

   counts++;
   if (startX == endX && startY == endY)
   {

      return true;
   }


   map[startY][startX].visited = true;
   if (map[startY][startX].displayItem != 'B' && map[startY][startX].displayItem != 'E')
   {

      map[startY][startX].displayItem = ' ';

   }
      for (int i = 0; i < height; i++)
      {
         for (int j = 0; j < width; j++)
         {

            if(j == 0 || j == width - 1 || i == 0 || i == height - 1)
               if(map[i][j].visited == false)
                  map[i][j].displayItem = 'X';


         }

      }

/*
   Map backUp(width, height,startx,starty,endx,endy);




   for (int i = 0; i < height; i++)
   {
      for (int j = 0; j < width; j++)
      {
         backUp.map[i][j].displayItem = map[i][j].displayItem;
         backUp.map[i][j].visited = map[i][j].visited;
      }
   }
   */
   int randomDirection[4] = { 1,2,3,4 };

   //randomly chooses number from 0-3
   std::random_device dev;
   std::mt19937 rng(dev());
   std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 3);

   int numb = dist6(rng);



   bool loop = false;
   int count = 0;
   while (loop == false && count < 4) 
   {

      int newY = startY;
      int newX = startX;
      int number = randomDirection[numb%4];

      if(map[newY][newX + 1].displayItem == 'E')
         number= 2;
      if (map[newY][newX - 1].displayItem == 'E')
         number = 4;
      if (map[newY-1][newX].displayItem == 'E')
         number = 1;
      if (map[newY+1][newX].displayItem == 'E')
         number = 3;

      if (number == 1)
         newY -= 1;
      else if (number == 2)
         newX += 1;
      else if (number == 3)
         newY += 1;
      else
         newX -= 1;

      if (newX == 0 || newX >= width - 1 || newY == 0 || newY >= height - 1)
      {
         loop = false;
         

      }
      else
      {
         int usedTileCounter = 0;
          if (map[newY][newX + 1].visited == true)
            usedTileCounter++;
         if (map[newY][newX - 1].visited == true)
            usedTileCounter++;
         if (map[newY + 1][newX].visited == true)
            usedTileCounter++;
         if (map[newY - 1][newX].visited == true)
            usedTileCounter++;

         if (usedTileCounter < 2)
         {
            //system("pause");
            //printMap();
            //cout << endl << endl << endl;

            loop = createMazeRecursion(newX, newY, endX, endY,counts);
            /*
            if (loop)
               return loop;

/*            
            for (int i = 0; i < height; i++)
            {
               for (int j = 0; j < width; j++)
               {
                  map[i][j].displayItem = backUp.map[i][j].displayItem;
                  map[i][j].visited = backUp.map[i][j].visited;
               }
            }

            */
         }
         else
            loop = false;
      }

      numb++;
      count++;
   }



   return false;

}
















void Map::printMap()
{
   for (int i = 0; i < height; i++)
   {
      for (int j = 0; j < width; j++)
      {
         cout << map[i][j].displayItem;

      }
      cout << endl;
   }

}