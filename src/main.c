#include <ncurses.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"

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

int main()
{
  initscr();
  raw();
  noecho();
  refresh();

  WINDOW * question = newwin(3*LINES/8, COLS/3, LINES/8, COLS/3);
  box(question, 0, 0);
  wrefresh(question);

  WINDOW * answer = newwin(3*LINES/8, COLS/3, 4*LINES/8, COLS/3);
  box(answer, 0, 0);
  wrefresh(answer);
  keypad(answer, TRUE);

  wmove(answer, 1, 1);
  wrefresh(answer);
  int x; int y;
  int windowWidth = COLS/3 - 2;
  int windowHeight = LINES/3 - 2;
  char * str = malloc(windowWidth * windowHeight * sizeof(char));
  str[0] = '\0';
  char tmp[2];
  tmp[1] = '\0';
  int ch = 0;
  int i = 0;
  struct Card * deck = MakeDeck("/home/liam/dev/deck/res/d.deck");
  wmove(question,1,1);
  wprintw(question, deck[0].question);
  wrefresh(question);

  while(ch != 27){
    ch = getch();
    switch (ch)
    {
      case 10:
        if(!strcmp(str, deck[i].answer))
        {
          i++;
          wmove(answer, 1, 1);
          wfillwrap(answer, windowWidth, windowWidth * windowHeight);
          str[0] = '\0';

          wmove(answer, 1, 1);
          wprintw(answer, "");
          wrefresh(answer);

          wmove(question, 1, 1);
          wfillwrap(question, windowWidth, windowWidth * windowHeight);
          wmove(question, 1, 1);
          wprintw(question, deck[i].question);
          wrefresh(question);
        }
        break;
      case 127:
        wmove(answer, 1, 1);
        str[strlen(str) - 1] = '\0';
        wmove(answer, 1, 1);
        wfillwrap(answer, windowWidth, windowWidth * windowHeight);
        wmove(answer, 1, 1);
        wprintwrap(answer, windowWidth, str);
        wrefresh(answer);
        break;
      default:
        wmove(answer, 1, 1);
        tmp[0] = ch;
        strcat(str, tmp);
        wprintwrap(answer, windowWidth,str);
        wrefresh(answer);
        break;
    }
  }
  endwin();
}
