add_executable(blink
        main.c
)
pico_enable_stdio_usb(blink 1)
target_link_libraries(blink pico_stdlib freertos)
pico_add_extra_outputs(blink)