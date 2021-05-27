#include "util.h"

void wprintwrap(WINDOW * window, int width, char * str)
{
  int y, x;
  getyx(window, y, x);
  for(int i = 0; i < strlen(str); i++)
  {
    if(i%width == 0 && i > 0)
    {
      wmove(window, y + i/width, 1);
    }

    waddch(window, str[i]);
  }
}

void wfillwrap(WINDOW * window, int width, int num)
{
  int y, x;
  getyx(window, y, x);
  for(int i = 0; i < num; i++)
  {
    if(i%width == 0 && i > 0)
    {
      wmove(window, y + i/width, 1);
    }

    waddch(window, ' ');
  }
}
