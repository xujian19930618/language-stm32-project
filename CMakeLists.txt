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
#        User/Device/Lcd/Inc/lcd_spi_154.h
#        User/Device/Lcd/Src/lcd_spi_154.c
        User/Device/Key/Inc/key.h
        User/Device/Key/Src/key.c
        User/Device/74hc165d/Inc/74hc165d.h
        User/Device/74hc165d/Src/74hc165d.c
        User/Device/W2812/Inc/ws2812.h
        User/Device/W2812/Src/ws2812.c
        User/Device/Led/Inc/led.h
        User/Device/Led/Src/led.c
        User/Stm32/Usb/Inc/usb.h
        User/Device/Sdio/Inc/sdio.h
        User/Device/Sdio/Src/sdio.c
        User/Stm32/Usart/Inc/usart.h
        User/Stm32/Spi/Inc/spi.h
        User/Stm32/Pwr/Inc/pwr.h
        User/Stm32/Pwm/Inc/pwm.h
        User/Stm32/Interrupt/Inc/interrupt.h
        User/Stm32/I2C/Inc/i2c.h
        User/Stm32/GPIO/Inc/gpio.h
        User/Stm32/Fsmc/Inc/fsmc.h
        User/Stm32/Exti/Inc/exti.h
        User/Stm32/Dma/Inc/dma.h
        User/Stm32/Dac/Inc/dac.h
        User/Stm32/Can/Inc/can.h
        User/Stm32/Adc/Inc/adc.h
        User/Stm32/Adc/Src/adc.c
        User/Stm32/Can/Src/can.c
        User/Stm32/Dac/Src/dac.c
        User/Stm32/Dma/Src/dma.c
        User/Stm32/Exti/Src/exti.c
        User/Stm32/Fsmc/Src/fsmc.c
        User/Stm32/GPIO/Src/gpio.c
        User/Stm32/I2C/Src/i2c.c
        User/Stm32/Interrupt/Src/interrupt.c
        User/Stm32/Pwm/Src/pwm.c
        User/Stm32/Pwr/Src/pwr.c
        User/Stm32/Spi/Src/spi.c
        User/Stm32/Usart/Src/usart.c
        User/Stm32/Usb/Src/usb.c
        User/Stm32/wwdg/Src/wwdg.c
        User/Stm32/wwdg/Inc/wwdg.h
        User/Device/Epd/Inc/EPD_font.h
        User/Device/Epd/Src/EPD_GUI.c
        User/Device/Epd/Inc/EPD_GUI.h
        User/Device/Epd/Src/EPD_SPI.c
        User/Device/Epd/Inc/EPD_SPI.h
        User/Device/Epd/Src/EPD.c
        User/Device/Epd/Inc/EPD.h
        User/Device/Epd/Inc/Pic.h
        User/Device/St7789/Inc/st7789.h
        User/Device/St7789/Src/st7789.c
        User/Device/St7789/Inc/fonts.h
        User/Device/St7789/Src/fonts.c
        User/Device/Key/Inc/keyX.h

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
        User/Device/Led/Inc
        User/Device/W2812/Inc
        User/Device/Key/Inc
        User/Device/St7789/Inc
        User/Stm32/Usb/Inc
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
