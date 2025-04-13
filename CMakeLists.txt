cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME language-stm32-project)

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME}
        User/Device/Lcd/Inc/lcd.h
        User/Device/Lcd/Src/lcd.c
        User/Device/Lcd/Inc/lcd_image.h
        User/Device/Lcd/Src/lcd_image.c
        User/Device/Lcd/Inc/lcd_fonts.h
        User/Device/Lcd/Src/lcd_fonts.c
        User/Device/Lcd/Inc/lcd_spi_154.h
        User/Device/Key/Inc/key.h
        User/Device/Key/Src/key.c
        User/Device/74hc165d/Inc/74hc165d.h
        User/Device/74hc165d/Src/74hc165d.c
        User/Device/Epd/Inc/epd.h
        User/Device/Epd/Src/epd.c
        User/Device/W2812/Inc/ws2812.h
        User/Device/W2812/Src/ws2812.c
        User/Device/Led/Inc/led.h
        User/Device/Led/Src/led.c
        User/Stm32/Usb/Inc/usb.h
        User/Stm32/Usb/Src/usb.h

)

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
        Drivers/User/Inc
        User/Device/74hc165d/Inc
        User/Device/Epd/Inc
        User/Device/Key/Inc
        User/Device/Lcd/Inc
        User/Device/W2812/Inc
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
