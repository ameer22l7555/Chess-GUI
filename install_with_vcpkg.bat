@echo off
echo Installing dependencies with vcpkg...

:: Clone vcpkg if it doesn't exist
if not exist vcpkg (
    echo Cloning vcpkg repository...
    git clone https://github.com/microsoft/vcpkg.git
    cd vcpkg
    call bootstrap-vcpkg.bat
    cd ..
) else (
    echo vcpkg already exists.
)

:: Install SDL2 and SDL2_image
echo Installing SDL2 and SDL2_image with vcpkg...
vcpkg\vcpkg install sdl2:x64-windows sdl2-image:x64-windows

:: Create a build directory
echo Setting up build...
if not exist build mkdir build
cd build

:: Configure CMake with vcpkg
echo Configuring CMake with vcpkg...
cmake .. -G "Visual Studio 17 2022" -A x64 -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake

echo Configuration completed.
echo You can now build the project by running:
echo cmake --build . --config Release
echo Or open the generated solution in Visual Studio.
pause 