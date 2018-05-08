### ATerm Files
- [source/aterm_io_text.cpp](#source_aterm_io_text_cpp)
- [include/mcrl2/atermpp/algorithm.h](#include_mcrl2_atermpp_algorithm_h)


<br><br><br><br>

[`source/aterm_io_text.cpp`](doc/aterm__io__text_8cpp.html)<span id="source_aterm_io_text_cpp"></span> Contains mostly the parser for textual ATerms. Example:
```c++
  aterm_appl a( read_term_from_string("f(f(x))"));
```
It all ends up in
```c++
  static aterm fparse_term(int* c, istream& is) { ... }
```
which handles the different cases:

- `aterm_list()` (empty aterm list) when next two chars are `[` and `]`
- `fparse_terms()` when the next char is `[` and is not followed by `]`
- `parse_arguments( fparse_quoted_string( ...), ...)` when next char is `"`
- `fparse_num()` when next char `isDigit()` or `-` (negative number)
- `parse_arguments( fparse_unquoted_string( ...), ...)` otherwise

<br>`aterm_list()` and `fparse_terms()` return an `aterm_list`
<br>`parse_arguments()` returns an `aterm_appl`
<br>`fparse_num` returns an `aterm_int`

  This file also contains functionality for writing textual ATerms to output streams.

<br>

---

<br>

[`include/mcrl2/atermpp/algorithm.h`](doc/algorithm_8h.html)<span id="include_mcrl2_atermpp_algorithm_h"></span> Contains functionality for searching and replacing subterms in a term.

Search Example:
```c++
  struct is_function_f {
    bool operator()(const atermpp::aterm& term) const {
      return ( term.type_is_app()) && aterm_appl(term).function().name() == "f";
    }
  }

  /* Create a function application term a */
  aterm_appl a( read_term_from_string("g( f(x), h(y), f(z))"));

  /* Will find the first occurrence of a function symbol f. Will print f(x) */
  std::cout << find_if( a, is_function_f()) << std::endl;

  vector<atermpp::aterm> v;

  /* Will find all occurrences of symbol f and store the function appl(s) in v */
  find_all_if( a, is_function_f(), back_inserter(v));
  /* Will print f(x) */
  std::cout << v.front() << std::endl;
  /* Will print f(z) */
  std::cout << v.back() << std::endl;

```

Replace Example:
```c++
  /* Create the term f(f(x)) */
  aterm_appl a( read_term_from_string( "f(f(x))"));

  /* Replace f(x) in a, by x */
  aterm_appl b = replace( a, aterm_appl( read_term_from_string( "f(x)")),
                             aterm_appl( read_term_from_string( "x")) );

  /* Will print f(x) */
  std::cout << b << std::endl;
```

<br>

---

<br>

### ATerm users in mCRL2
<span id="aterm-users"></span>
The following libraries/tools make direct use of the ATerm library

[[Core](#core-lib-user)] [[Data](#data-lib-user)]

#### Libraries
- Core <span id="core-lib-user"></span>
  * `source/core.cpp`
  * `include/mcrl2/core/add_binding.h`
  * `include/mcrl2/core/builder.h`
  * `include/mcrl2/core/identifier_string.h`
  * `include/mcrl2/core/index_traits.h`
  * `include/mcrl2/core/load_aterm.h`
  * `include/mcrl2/core/parse.h`
  * `include/mcrl2/core/print.h`
  * `include/mcrl2/core/detail/construction_utility.h`
  * `include/mcrl2/core/detail/default_values.h`
  * `include/mcrl2/core/detail/function_symbols.h`
  * `include/mcrl2/core/detail/soundness_checks.h`

  <br>
- Data <span id="data-lib-user"></span>
  * `source/data_specification.cpp`
  * `source/data.cpp`, only in `sort_expression data_expression::sort() const { ...}`
  * `source/typecheck.cpp`
  * +`source/detail/rewrite/jitty.cpp`
  * +`source/detail/rewrite/jittyc.cpp`
  * +`source/detail/rewrite/rewrite.cpp`
  * `include/mcrl2/data/abstraction.h`
  * `include/mcrl2/data/alias.h`
  * `include/mcrl2/data/anonymize.h`
  * `include/mcrl2/data/application.h`
  * `include/mcrl2/data/assignment.h`
  * `include/mcrl2/data/bag.h`
  * `include/mcrl2/data/basic_sort.h`
  * `include/mcrl2/data/binder_type.h`
  * `include/mcrl2/data/bool.h`
  * `include/mcrl2/data/builder.h`
  * `include/mcrl2/data/container_sort.h`
  * `include/mcrl2/data/container_type.h`
  * `include/mcrl2/data/data_equation.h`
  * `include/mcrl2/data/data_expression.h`
  * `include/mcrl2/data/data_specification.h`
  * `include/mcrl2/data/enumerator.h`
  * `include/mcrl2/data/exists.h`
  * `include/mcrl2/data/expression_traits.h`
  * `include/mcrl2/data/fbag.h`
  * `include/mcrl2/data/find_equalities.h`
  * `include/mcrl2/data/fourier_motzkin.h`
  * `include/mcrl2/data/fset.h`
  * `include/mcrl2/data/function_sort.h`
  * `include/mcrl2/data/function_symbol.h`
  * `include/mcrl2/data/function_update.h`
  * `include/mcrl2/data/index_traits.h`
  * `include/mcrl2/data/int.h`
  * `include/mcrl2/data/linear_inequalities.h`
  * `include/mcrl2/data/list.h`
  * `include/mcrl2/data/nat.h`
  * `include/mcrl2/data/parse.h`
  * `include/mcrl2/data/pos.h`
  * `include/mcrl2/data/print.h`
  * `include/mcrl2/data/real.h`
  * `include/mcrl2/data/set.h`
  * `include/mcrl2/data/sort_expression.h`
  * `include/mcrl2/data/structured_sort_constructor_argument.h`
  * `include/mcrl2/data/structured_sort_constructor.h`
  * `include/mcrl2/data/structured_sort.h`
  * `include/mcrl2/data/typecheck.h`
  * `include/mcrl2/data/untyped_data_parameter.h`
  * `include/mcrl2/data/untyped_identifier.h`
  * `include/mcrl2/data/untyped_possible_sorts.h`
  * `include/mcrl2/data/untyped_sort_variable.h`
  * `include/mcrl2/data/untyped_sort.h`
  * `include/mcrl2/data/variable.h`
  * `include/mcrl2/data/where_clause.h`
  * `include/mcrl2/data/detail/data_functional.h`
  * `include/mcrl2/data/detail/data_sequence_algorithm.h`, set ops intersection and difference
  * `include/mcrl2/data/data_specification.h`
  * `include/mcrl2/data/detail/enumerator_identifier_generator.h`
  * `include/mcrl2/data/detail/io.h`
  * `include/mcrl2/data/detail/prover/bdd2dot.h`
  * `include/mcrl2/data/detail/prover/info.h`
  * `include/mcrl2/data/detail/rewrite/jitty_jittyc.h`
  * `include/mcrl2/data/detail/rewrite/match_tree.h`
  * `include/mcrl2/data/detail/rewrite/strategy_rule.h`
