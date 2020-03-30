Building a library with CMake
====

This example shows how to build a library with CMake.

The library, foo, can either be built from source or distributed pre-built.

Building with `foo` from source
---

This is the default. The regular CMake way: 

```bash
mkdir build && cd build
cmake .. 
make -j
./cmake-library-example
```

Building with pre-built `foo`
---

Sometimes, you might want to distribute the _functionality_ of a program, but not its source. 
Distributing its headers and pre-compiled library might be helpful here.

> How does this work? The library has its own CMakeLists that specifies the appropriate `add_library()` commands. 
> The CMakeLists.txt file declares what the library provides through `install()` commands. 
> Now, we can _install_ the built library in a local path (the prefix). Incidentally, we can choose 
> the `CMAKE_INSTALL_PREFIX` to be `foo`'s source directory. 
> Now, the depending program can use `find_package(foo)` when it sets the `CMAKE_PREFIX_PATH` to include 
> the install prefix of the library (which we chose to be the same as its source directory). 
> 
> After installation of `foo`: 
```
cmake-library-example
├── build (intermediate build directory)
└── foo-component (foo library, also install prefix)
    ├── include (library headers)
    └── lib (pre-compiled library)
        └── cmake (cmake config files)
            └── foo
```

First step: Typically, `foo` will be compiled on a machine that has access to its sourcecode. 

```bash
mkdir -p build/foo-component && cd build/foo-component
cmake ../../foo-component -DCMAKE_INSTALL_PREFIX=../../foo-component
make -j install
# or run the convenience script
./build-foo.sh
```

Second step: Then, the library is distributed with the original foo source redacted, and the foo-component/lib directory included. 

```
mkdir build && cd build
cmake .. -DWITH_PREBUILT_FOO=1
make -j
./cmake-library-example
```
