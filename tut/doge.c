#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

#include "../src/mpc.h"

int main(int argc, char** argv) {

  puts("Doge Parser Version 0.0.0.0.1");
  puts("Press CTRL+C to Exit.\n");

  // Create some parsers
  mpc_parser_t* Adjective = mpc_new("adjective");
  mpc_parser_t* Noun      = mpc_new("noun");
  mpc_parser_t* Phrase    = mpc_new("phrase");
  mpc_parser_t* Doge      = mpc_new("doge");

  // Define them with the following Language
  mpca_lang(MPCA_LANG_DEFAULT,
    "                                                           \
      adjective : \"wow\" | \"many\" | \"so\" | \"such\" ;      \
      noun      : \"art\" | \"paint\" | \"happy\" | \"venice\"; \
      phrase    : <adjective> <noun> ;                          \
      doge      : /^/ <phrase>* /$/;                            \
    ",
    Adjective, Noun, Phrase, Doge);

  while (1) {

    char* input = readline("doge> ");
    add_history(input);

    // Now to parse user input
    mpc_result_t r;
    if (mpc_parse("<stdin>", input, Doge, &r)) {
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

  // Undefine and Delete our Parsers
  mpc_cleanup(4, Adjective, Noun, Phrase, Doge);

  return 0;
}

