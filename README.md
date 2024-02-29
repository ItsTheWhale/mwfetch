# mwfetch: whale's minimalistic fetch

A simple and tiny fetch.

# dependencies

- C compiler and the standard library
- `USER`, `XDG_CURRENT_DESKTOP`, `SHELL` and `TERM` environmental variables set
- `/etc/os-release` file with an `ID` key delimited by double quotes

# installing

`./build.sh` for Clang, `gcc main.c -o mwfetch` for GCC.

# configuration

Edit `config.h` and change the `#define`s. Set to `1` to enable, `0` to disable. Names should be self-explanatory.
