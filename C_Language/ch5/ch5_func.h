#ifndef CH5_FUNC_H
#define CH5_FUNC_H

#include "stdio.h"

#define ALLOCSIZE 10000
#define MAXLINE 1000

char *alloc(int n);
void afree(char *p);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

#endif