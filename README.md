[![Build Status](https://travis-ci.org/azriel91/sl_ax_game_object.svg?branch=master)](https://travis-ci.org/azriel91/sl_ax_game_object) [![Build status](https://ci.appveyor.com/api/projects/status/8inh3fy2via457of/branch/master?svg=true)](https://ci.appveyor.com/project/azriel91/sl-ax-game-object/branch/master) [![Build Status](https://webapi.biicode.com/v1/badges/azriel/azriel/sl_ax_game_object/master)](https://www.biicode.com/azriel/sl_ax_game_object)

## sl\_ax\_game\_object

Contains the headers for game objects.

## Development

This is implemented as a [CppMicroServices](https://github.com/saschazelzer/CppMicroServices) module, and is built using
[biicode](https://www.biicode.com/).

### Requirements

* [biicode](https://www.biicode.com/downloads)
* [CMake](http://www.cmake.org/install/)
* [g++ 4.8](https://gcc.gnu.org/)

### Building

#### Linux

After cloning, in the repository directory run the following to build the block:

```bash
git submodule update --init        # initialize git submodules
bii-support/linux/build/shared.sh  # builds shared libraries
```

The test executable will be output as `bin/azriel_sl_ax_game_object_test_main`.

#### Windows

After cloning, in the repository directory run the following to build the block:

```bat
git submodule update --init           :: initialize git submodules
bii-support\windows\build\shared.bat  :: builds shared libraries
```

The test executable will be output as `bin\azriel_sl_ax_game_object_test_main.exe`.

## License

Copyright (c) Azriel Hoh. Licensed under the [Apache License v2.0](http://www.apache.org/licenses/LICENSE-2.0).
