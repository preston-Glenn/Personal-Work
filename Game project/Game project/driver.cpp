#include <ios>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Map.h"
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

bool gameOver;

int x, y, fruitX, fruitY, score;


char player = 'P';
char wherePlayerIs;
enum eDirection {STOP = 0,LEFT,RIGHT,UP,DOWN};











eDirection dir;
void setup(Map newMap)
{

   gameOver = false;
   dir = STOP;
   //coordinates of where player starts
   x = newMap.startx;
   y = newMap.starty;

   wherePlayerIs = newMap.map[y][x].displayItem;
   newMap.map[y][x].displayItem = player;


}

void Draw(Map newMap,int width,int height,int y,int x)
{
   system("cls");

   for (int i = 0; i < width; i++)
      cout << "0";
   cout << endl;
   int a = y + height / 2;
   int b = x + width / 2;
   for (int i = (y - height / 2); i < (y + height/2); i++)
   {
      cout << "0";


      for (int j = (x - width / 2); j < (x + width / 2); j++)
      {
         if (i < 0 || j < 0 || i >= newMap.height || j >= newMap.width)
            cout << "X";
         else
            cout << newMap.map[i][j].displayItem;

      }
      cout << "0";
      cout << endl;
   }

   for (int i = 0; i < width; i++)
      cout << "#";
   cout << endl;


}

void Input(Map newMap)
{

   if (_kbhit())
      switch (_getch())
      {
      case 'a':
         if (x <= 0 )
            int pass;
         else
            if(newMap.map[y][x-1].displayItem =='X'|| newMap.map[y][x - 1].displayItem == '-'|| newMap.map[y][x - 1].displayItem == '|'|| newMap.map[y][x - 1].displayItem == '#' || newMap.map[y][x - 1].displayItem == '+')
            { }
            else if (newMap.map[y][x - 1].displayItem == 'C')
            {
               newMap.map[y][x].displayItem = wherePlayerIs;
               wherePlayerIs = '.';
               newMap.map[y][x - 1].displayItem = player;
               x--;
            }
            else {
               newMap.map[y][x].displayItem = wherePlayerIs;

               wherePlayerIs = newMap.map[y][x - 1].displayItem;
               newMap.map[y][x - 1].displayItem = player;
               x--;
            }
               

         break;
      case 'w':
         if (y <= 0)
            int temp;
         else
            if (newMap.map[y-1][x].displayItem == 'X' || newMap.map[y - 1][x].displayItem == '-' || newMap.map[y - 1][x].displayItem == '|' || newMap.map[y - 1][x].displayItem == '#' || newMap.map[y - 1][x].displayItem == '+')
            {
            }
            else if (newMap.map[y - 1][x].displayItem == 'C')
            {
               newMap.map[y][x].displayItem = wherePlayerIs;
               wherePlayerIs = '.';
               newMap.map[y - 1][x].displayItem = player;
               y--;
            }
            else 
            {
               newMap.map[y][x].displayItem = wherePlayerIs;

               wherePlayerIs = newMap.map[y - 1][x].displayItem;
               newMap.map[y-1][x].displayItem = player;
               y--;
            }
         break;

      case 's':
         if (y >= newMap.height )
            int temp;
         else
            if (newMap.map[y + 1][x].displayItem == 'X' || newMap.map[y + 1][x].displayItem == '-' || newMap.map[y + 1][x].displayItem == '|' || newMap.map[y + 1][x].displayItem == '#' || newMap.map[y + 1][x].displayItem == '+')
            {
            }
            else if (newMap.map[y + 1][x].displayItem == 'C')
            {
               newMap.map[y][x].displayItem = wherePlayerIs;
               wherePlayerIs = '.';
               newMap.map[y + 1][x].displayItem = player;
               y++;
            }
            else {
               newMap.map[y][x].displayItem = wherePlayerIs;
               wherePlayerIs = newMap.map[y + 1][x].displayItem;
               newMap.map[y + 1][x].displayItem = player;
               y++;
            }
         break;

      case 'd':

         if (x >= newMap.width )
            int temp;
         else
            if (newMap.map[y][x + 1].displayItem == 'X' || newMap.map[y][x + 1].displayItem == '-' || newMap.map[y][x + 1].displayItem == '|' || newMap.map[y][x + 1].displayItem == '#' || newMap.map[y][x + 1].displayItem == '+')
            {
            }
            else if (newMap.map[y][x+1].displayItem == 'C')
            {
               newMap.map[y][x].displayItem = wherePlayerIs;
               wherePlayerIs = '.';
               newMap.map[y][x+1].displayItem = player;
               x++;
            }
            else {
               newMap.map[y][x].displayItem = wherePlayerIs;
               wherePlayerIs = newMap.map[y][x + 1].displayItem;
               newMap.map[y][x + 1].displayItem = player;
               x++;
            }
         break;

      case 'x':
         gameOver = true;



      }

   if (wherePlayerIs == 'E')
   {
      gameOver = true;
      cout << "You won" << endl;
   }

}

void Logic()
{

}









int main()
{
   int startx = 3;
   int starty = 2;
   int endx = 17;
   int endy = 12;

   Map newMap(30, 15, startx, starty, endx, endy);


   newMap.map[starty][startx].displayItem = 'B';
   newMap.map[endy][endx].displayItem = 'E';
   int count = 0;

   newMap.createMazeRecursion(3, 2, 17, 12,count);


   setup(newMap);

   while (!gameOver)
   {
      Draw(newMap, newMap.width, newMap.height, y, x);
      Input(newMap);
   }
   cout << endl << endl << count << endl;

   system("pause");
   return 0;
}