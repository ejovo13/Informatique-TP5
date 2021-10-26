# TP5
***
![Ubuntu](https://github.com/ejovo13/informatique-TP5/actions/workflows/Ubuntu.yml/badge.svg)
![MacOs](https://github.com/ejovo13/informatique-TP5/actions/workflows/Mac.yml/badge.svg)
![Windows](https://github.com/ejovo13/informatique-TP5/actions/workflows/Windows.yml/badge.svg)

This repo contains my solutions to the exercises presented in TP5. All of the exercises can be made with CMake.

### Build
Build with cmake. The executable files will be output in the `bin` directory.
```Bash
mkdir build && cd build
cmake ../        # Generate configuration and makefiles
cmake --build ./ # Build the project according to the configuration
ctest --output-on-failure
```

### Test

Tests can be run with `ctest` or `make test` while in the build directory. The tests verify that the functions declared in the `ejovo_*` are working properly.
### Docs
Documentation for all of the functions declared in the `ejovo` headers can be found [here](https://ejovo13.github.io/informatique-TP4/)

# TODO

- [ ] Update readme
- [ ] Add proper documentation
- [ ] Setup documentation with gh pages
- [ ] Add test suite to verify that my sorting functions work as expected