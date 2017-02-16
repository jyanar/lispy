#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "editline_win.h"

static char* buffer[2048];
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

// Fake add_history function, unnecessary for win
void add_history(char* unused) {}

