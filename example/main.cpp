#include "mcrl2/atermpp/function_symbol.h"
#include "mcrl2/atermpp/aterm_appl.h"

using namespace atermpp;

int main(int argc, char* argv[])
{
  function_symbol f("f", 0);
  function_symbol g("g", 2);

  aterm_appl f_term(f);
  aterm_appl g_term(g, f_term, f_term);

  std::cout << g_term << std::endl;

  return 0;
}
