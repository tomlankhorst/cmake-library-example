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
