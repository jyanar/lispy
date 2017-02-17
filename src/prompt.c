#include <stdio.h>
#include <stdlib.h>

#include "mpi.h"

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

    mpc_result_t r;
    if (mpc_parse("<stdin>", input, Lispy, &r)) {
      // Valid input!
      mpc_ast_print(r.output);
      mpc_ast_delete(r.output);
    } else {
      // Invalid, print error
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }

    free(input);
  }
  return 0;
}

