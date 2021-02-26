#ifndef _SLIDE_LINE_H_
#define _SLIDE_LINE_H_
#define SLIDE_RIGHT 1
#define SLIDE_LEFT 0

#include <stdio.h>
#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
int left(int *line, size_t size);
int right(int *line, size_t size);

#endif
