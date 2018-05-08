### Files
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

<br><br>

[`include/mcrl2/atermpp/algorithm.h`](doc/algorithm_8h.html)<span id="include_mcrl2_atermpp_algorithm_h"></span> Contains functionality for searching terms an
  replacing subterms in a term.

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
  std::cout << find_if( a, if_f()) << std::endl;

  vector<atermpp::aterm> v;

  /* Will find all occurrences of symbol f and store the function appl(s) in v */
  find_all_if( a, is_f(), back_inserter(v));
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
