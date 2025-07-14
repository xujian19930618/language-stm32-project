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
        User/Stm32/Src/stm32_usart.c
#        User/Device/Inc/lcd.h
#        User/Device/Src/lcd.c
#        User/Device/Inc/lcd_image.h
#        User/Device/Src/lcd_image.c
#        User/Device/Inc/lcd_fonts.h
#        User/Device/Src/lcd_fonts.c
#        User/Device/Lcd/Inc/lcd_spi_154.h
#        User/Device/Lcd/Src/lcd_spi_154.c
#        User/Device/Inc/key.h
#        User/Device/Src/key.c
#        User/Device/Inc/74hc165d.h
#        User/Device/Src/74hc165d.c
#        User/Device/Inc/ws2812.h
#        User/Device/Src/ws2812.c
#        User/Device/Inc/led.h
#        User/Device/Src/led.c
#        User/Stm32/Inc/usb.h
#        User/Device/Inc/sdio.h
#        User/Device/Src/sdio.c
#        User/Stm32/Inc/usart.h
#        User/Stm32/Inc/spi.h
#        User/Stm32/Inc/pwr.h
#        User/Stm32/Inc/pwm.h
#        User/Stm32/Inc/interrupt.h
#        User/Stm32/Inc/i2c.h
#        User/Stm32/Inc/gpio.h
#        User/Stm32/Inc/fsmc.h
#        User/Stm32/Inc/exti.h
#        User/Stm32/Inc/dma.h
#        User/Stm32/Inc/dac.h
#        User/Stm32/Inc/can.h
#        User/Stm32/Inc/adc.h
#        User/Stm32/Src/adc.c
#        User/Stm32/Src/can.c
#        User/Stm32/Src/dac.c
#        User/Stm32/Src/dma.c
#        User/Stm32/Src/exti.c
#        User/Stm32/Src/fsmc.c
#        User/Stm32/Src/gpio.c
#        User/Stm32/Src/i2c.c
#        User/Stm32/Src/interrupt.c
#        User/Stm32/Src/pwm.c
#        User/Stm32/Src/pwr.c
#        User/Stm32/Src/spi.c
#        User/Stm32/Src/usb.c
#        User/Stm32/Src/wwdg.c
#        User/Stm32/Inc/wwdg.h
#        User/Device/Inc/EPD_font.h
#        User/Device/Src/EPD_GUI.c
#        User/Device/Inc/EPD_GUI.h
#        User/Device/Src/EPD_SPI.c
#        User/Device/Inc/EPD_SPI.h
#        User/Device/Src/EPD.c
#        User/Device/Inc/EPD.h
#        User/Device/Inc/Pic.h
#        User/Device/Inc/st7789.h
#        User/Device/Src/st7789.c
#        User/Device/Inc/fonts.h
#        User/Device/Src/fonts.c
#        User/Device/Inc/keyX.h

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
