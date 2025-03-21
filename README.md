# Chess GUI

A chess game with a graphical user interface implemented in C++ using SDL2 and SDL2_image libraries.

## Project Overview

This is a chess program created with C++ and SDL2. It provides a graphical interface for playing chess, with all standard chess rules implemented.

## Dependencies

- [CMake](https://cmake.org/) (version 3.0 or higher)
- [SDL2](https://www.libsdl.org/)
- [SDL2_image](https://www.libsdl.org/projects/SDL_image/)

## Building the Project

There are several ways to build this project:

### Method 1: Using VCPKG (Recommended)

This method uses VCPKG to manage dependencies, making the build process more reliable across different environments.

1. Run `install_with_vcpkg.bat` to install dependencies:
   ```
   .\install_with_vcpkg.bat
   ```

2. Run `build_with_vcpkg.bat` to build the project:
   ```
   .\build_with_vcpkg.bat
   ```

3. The executable will be in `build\Release\chess.exe`

### Method 2: Using CMake Directly

If you already have SDL2 and SDL2_image installed on your system:

1. Run `install_dependencies.bat` to download and extract the dependencies:
   ```
   .\install_dependencies.bat
   ```

2. Run `setup_cmake_fixed.bat` to configure the build:
   ```
   .\setup_cmake_fixed.bat
   ```

3. Run `build_project.bat` to build the project:
   ```
   .\build_project.bat
   ```

### Method 3: Using Visual Studio Developer Command Prompt

1. Open the Visual Studio Developer Command Prompt
2. Navigate to the project directory
3. Run `vs_build.bat`:
   ```
   .\vs_build.bat
   ```

## Running the Game

After building, you can run the chess game by executing:
```
.\build\Release\chess.exe
```

## Controls

- Click on a chess piece to select it
- Click on a valid destination square to move the selected piece
- The game enforces all standard chess rules (check, checkmate, castling, etc.)

## Project Structure

- `src/`: Source code files
- `images/`: Contains the chess piece images
- `cmake/`: CMake find modules for SDL2 and SDL2_image
- Build scripts for various build methods

## License

This project is open source and available under the [MIT License](LICENSE).