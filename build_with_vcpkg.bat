@echo off
echo Building BChess project with VCPKG libraries...

:: Make sure we're in the right directory
cd /d "%~dp0"

:: Clean the build directory and recreate it
echo Cleaning build directory...
rmdir /S /Q build
mkdir build
cd build

:: Configure the project with VCPKG
echo Configuring project with CMake...
"C:\Program Files\CMake\bin\cmake.exe" .. -G "Visual Studio 17 2022" -A x64 -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake

:: Build the project
echo Building project...
"C:\Program Files\CMake\bin\cmake.exe" --build . --config Release

:: Copy required DLLs to the Release directory
echo Copying required DLLs to Release directory...
copy "..\vcpkg\installed\x64-windows\bin\SDL2.dll" "Release\"
copy "..\vcpkg\installed\x64-windows\bin\SDL2_image.dll" "Release\"
copy "..\vcpkg\installed\x64-windows\bin\libpng16.dll" "Release\"
copy "..\vcpkg\installed\x64-windows\bin\zlib1.dll" "Release\"

echo Build completed.
echo If successful, the executable should be in the build\Release directory.
pause 