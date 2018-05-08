[[Documentation](https://gkarlos.github.io/ATermLib/doc)]
[[Overview](https://gkarlos.github.io/ATermLib/overview)]
[[ATerm users in mCRL2](https://gkarlos.github.io/ATermLib/overview#aterm-users-in-mcrl2)]


### Links
- [mCRL2](https://www.mcrl2.org/web/user_manual/index.html)
- [mCRL2 repo](https://github.com/mlaveaux/mCRL2)


### Usage

The easiest way to use/test the library is to modify the `example` source. After
compiling, an `example` executable will be created under `build/example/` which
can be simply run with `./example` from within that directory.

Alternatively, create a folder at the top level directory with all the necessary sources.
Then create a `CMakeLists.txt` within that folder with contents :

- `set(SOURCES file1.cpp file1.cpp ...)` where file1.cpp file2.cpp are replaced with the actual source files
- `add_executable(<target_name> ${SOURCES})`
- `target_link_libraries(<target_name> atermpp)`

After compiling, an executable named `<target_name>` is created under `build/<folder_name>/`
where `<folder_name>` is the name of the newly created source folder.

### Compile

```
mkdir build
cd build
cmake ..
make
```

### Documentation

A `Doxyfile` is included in the root directory. Simply run `doxygen` from the root
directory. A `doc` folder will be created containing the documentation. Can be viewed
with e.g. `firefox doc/html/index.html`
