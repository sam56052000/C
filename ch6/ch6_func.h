#ifndef CH6_FUNC_H
#define CH6_FUNC_H

#include "stdio.h"

#define BUFSIZE 100

char buf[BUFSIZE];
char bufp = 0;

char getch(void);
void ungetch(char);

#endif