#ifndef __UTIL_H__
#define __UTIL_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <ncurses.h>
#include <string.h>

void wprintwrap(WINDOW * window, int width, char * str);
void wfillwrap(WINDOW * window, int width, int num);


#ifdef __cplusplus
}
#endif


#endif
