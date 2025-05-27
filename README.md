# cppmaker

Are you tired to create your project manually, create files, directories, etc? 
You can use cppmaker to make your life easier!
Run:
```bash
cppmaker --cmake hello_world
```

And this maker will create a cmake project with a standard hello world code in the src directory

Support
- [x] CMake
- [ ] Makefile
- [ ] Qmake
- [ ] Bezel
- [ ] Sh

## Compiling
```
sudo pacman -Syu boost boost-libs clang cmake make
mkdir build && cd build
cmake ..
make
./cppmake
```

