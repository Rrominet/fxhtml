# fxhtml

A simple html and md viewer based on GTK Webkit engine.

## Dependencies

You need to have installed this 3 dependencies for the `make` scripts to work and actually build your program : 

 - [fxmake](https://github.com/Rrominet/py-utils/tree/main/build)
 - [cpp-utils](https://github.com/Rrominet/cpp-utils)
 - [fxos_gui-lib](https://github.com/Rrominet/fxos_gui-lib)


## Build

Execute the script `make` (not the program, the file in this repo) and hope for the best (a)

## Usage
```bash
fxhtml /your/file.html --title "Your Title" --size 680x840
```

It can take a classic URL too.

## API

Once installed, you can use an API in `C++` and `Python` to basically call this program in your code abstracting the subprocess part for you.

Check the directory `build/api` to see how it works. (It's pretty easy, there is only one function per language)
