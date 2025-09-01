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

#
#set(FETCHCONTENT_FULLY_DISCONNECTED TRUE)
#include(FetchContent)
# 设置所有 FetchContent 的下载目录
#set(LVGL_PATH ${CMAKE_SOURCE_DIR}/third_party/lvgl)
#set(FREERTOS_PATH ${CMAKE_SOURCE_DIR}/third_party/freertos)
#FetchContent_Declare(
#        FreeRTOS
#        GIT_REPOSITORY https://github.com/FreeRTOS/FreeRTOS-Kernel.git
#        GIT_TAG main
#        SOURCE_DIR ${FREERTOS_PATH}
#        BINARY_DIR ${FREERTOS_PATH}-build
#)
#
#FetchContent_Declare(
#        LVGL
#        GIT_REPOSITORY https://github.com/lvgl/lvgl.git
#        GIT_TAG release/v9.2
#        SOURCE_DIR ${LVGL_PATH}        # 指定源码目录
#        BINARY_DIR ${LVGL_PATH}-build  # 指定构建目录
#)


#FetchContent_MakeAvailable(FreeRTOS)

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
        User/Stm32/Src/stm32_usart.c
        User/Stm32/Src/stm32_i2c.c
#        User/Device/Src/lcd.c
#        User/Device/Src/lcd_image.c
#        User/Device/Src/lcd_fonts.c
#        User/Device/Lcd/Src/lcd_spi_154.c
#        User/Device/Src/key.c
#        User/Device/Src/74hc165d.c
#        User/Device/Src/ws2812.c
#        User/Device/Src/led.c
#        User/Device/Src/sdio.c
#        User/Stm32/Src/adc.c
#        User/Stm32/Src/can.c
#        User/Stm32/Src/dac.c
#        User/Stm32/Src/dma.c
#        User/Stm32/Src/exti.c
#        User/Stm32/Src/fsmc.c
#        User/Stm32/Src/gpio.c
#        User/Stm32/Src/interrupt.c
#        User/Stm32/Src/pwm.c
#        User/Stm32/Src/pwr.c
#        User/Stm32/Src/spi.c
#        User/Stm32/Src/usb.c
#        User/Stm32/Src/wwdg.c
#        User/Device/Src/EPD_GUI.c
#        User/Device/Src/EPD_SPI.c
#        User/Device/Src/EPD.c
#        User/Device/Src/st7789.c
#        User/Device/Src/fonts.c

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
        User/Device/Inc
        User/Stm32/Inc
        User/LCD/Inc
        User/EPD/Inc
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
