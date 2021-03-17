cdd-cpp
=======
[![License](https://img.shields.io/badge/license-Apache--2.0%20OR%20MIT-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![C++17](https://img.shields.io/badge/C++-17-blue)](https://en.wikipedia.org/wiki/C%2B%2B17)

Compiler driven development implementation for C++.

## Dependencies

  - CMake
  - C++ compiler (e.g., `clang`, `gcc`, MSVC's `cl`) and linker
  - git

### LLVM and clang

    # ninja (builds faster than the default CMake method)
    git clone --depth=1 https://github.com/martine/ninja
    ./configure.py --bootstrap
    sudo cp ninja /usr/local/bin

    git clone --depth=1 https://github.com/llvm/llvm-project
    mkdir llvm-project/build && cd $_
    cmake -G Ninja ../llvm -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra" -DLLVM_BUILD_TESTS=ON
    ninja

## Build

Prefix `export`ed environment variables with absolute location that you cloned above^ to:

    git clone https://github.com/offscale/cdd-cpp
    export LLVM_DIR='llvm-project/build-ninja/lib/cmake/llvm'
    export Clang_DIR='llvm-project/build-ninja/lib/cmake/clang'
    mkdir cdd-cpp/cmake-build-release && cd $_
    cmake -DCMAKE_BUILD_TYPE=Release ..
    cmake --build .

---

## License

Licensed under either of

- Apache License, Version 2.0 ([LICENSE-APACHE](LICENSE-APACHE) or <https://www.apache.org/licenses/LICENSE-2.0>)
- MIT license ([LICENSE-MIT](LICENSE-MIT) or <https://opensource.org/licenses/MIT>)

at your option.

### Contribution

Unless you explicitly state otherwise, any contribution intentionally submitted
for inclusion in the work by you, as defined in the Apache-2.0 license, shall be
dual licensed as above, without any additional terms or conditions.
