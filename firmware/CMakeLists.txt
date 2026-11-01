cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(picoscope_x C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(picoscope_x
    main.cpp
)

target_link_libraries(picoscope_x
    pico_stdlib
    hardware_adc
    hardware_i2c
    hardware_spi
    hardware_pio
)

pico_enable_stdio_usb(picoscope_x 1)
pico_enable_stdio_uart(picoscope_x 0)

pico_add_extra_outputs(picoscope_x)
