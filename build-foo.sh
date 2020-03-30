#!/bin/bash

cmake -Hfoo-component -Bbuild/foo-component -DCMAKE_INSTALL_PREFIX=foo-component
cmake --build build/foo-component --target install

