idf_component_register(
    SRCS "app_main.c" "cat_actions.c" "cat_actions.h" "board.c"
    INCLUDE_DIRS "."
    REQUIRES driver esp_wifi nvs_flash esp_event log freertos
)
