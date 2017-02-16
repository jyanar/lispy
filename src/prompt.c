#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
  #include "editline_win.h"
#elif __APPLE__
  #include <editline/readline.h>
#else
  #include <editline/readline.h>
  #include <editline/add_history.h>
#endif

int main(int argc, char** argv) {

  puts("Lispy Version 0.0.0.0.1");
  puts("Press CTRL+C to Exit.\n");

  while (1) {

    char* input = readline("lispy> ");
    add_history(input);

    printf("No, you're a %s\n", input);

    free(input);
  }

  return 0;
}

