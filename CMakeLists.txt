project(chess)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
cmake_minimum_required(VERSION 3.0)

# Define explicit paths for SDL2 and SDL2_image
set(SDL2_PATH "${CMAKE_SOURCE_DIR}/SDL2/SDL2-2.24.2")
set(SDL2_IMAGE_PATH "${CMAKE_SOURCE_DIR}/SDL2_image")

# Find the packages using the explicit paths
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# Include directories
include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIR}
)

# Copy images folder to the build directory
file(COPY "images" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/") #otherwise we get chess without images

# Set source files
set(SOURCES main.cpp Game.cpp Window.cpp Piece.cpp Board.cpp BoardState.cpp MoveStack.cpp PieceLocations.cpp StoreMove.cpp)

# Create executable
add_executable(chess ${SOURCES})

# Link libraries
target_link_libraries(chess ${SDL2_LIBRARIES})
target_link_libraries(chess ${SDL2_IMAGE_LIBRARIES})

# Copy required DLLs to build directory
add_custom_command(TARGET chess POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_PATH}/lib/x64/SDL2.dll"
        $<TARGET_FILE_DIR:chess>
)
add_custom_command(TARGET chess POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_IMAGE_PATH}/lib/x64/SDL2_image.dll"
        $<TARGET_FILE_DIR:chess>
)
