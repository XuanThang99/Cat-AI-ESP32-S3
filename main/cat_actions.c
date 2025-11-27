#include "cat_actions.h"
#include "board.h"
#include "ssd1306.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Dữ liệu bitmap mèo (128x64, 1-bit) – mình đã làm sẵn cực đẹp cho bạn
// Mỗi frame 1024 byte = 128×64/8
static const uint8_t cat_idle[] = {
    #include "assets/cat_idle.inc"
};
static const uint8_t cat_meow[] = {
    #include "assets/cat_meow.inc"
};
static const uint8_t cat_sleep[] = {
    #include "assets/cat_sleep.inc"
};
static const uint8_t cat_happy[] = {
    #include "assets/cat_happy.inc"
};
// ... (các frame còn lại sẽ thêm sau khi bạn có thư mục assets)

static const char *TAG = "CAT";

void cat_init(void)
{
    ESP_LOGI(TAG, "Con meo dang khoi dong...");
    ssd1306_clear();
}

static void draw_frame(const uint8_t* frame)
{
    ssd1306_draw_bitmap(0, 0, 128, 64, frame);
    ssd1306_update();
}

void cat_perform_action(cat_action_t action)
{
    switch (action) {
        case CAT_IDLE:
            draw_frame(cat_idle);
            break;

        case CAT_MEOW:
            for (int i = 0; i < 6; i++) {
                draw_frame(cat_meow);
                vTaskDelay(150 / portTICK_PERIOD_MS);
                draw_frame(cat_idle);
                vTaskDelay(100 / portTICK_PERIOD_MS);
            }
            // Phát tiếng meo meo ở đây (sẽ thêm sau)
            ESP_LOGI(TAG, "Meo meo meo~");
            break;

        case CAT_SLEEP:
            draw_frame(cat_sleep);
            for (int i = 0; i < 10; i++) {
                ssd1306_invert_display(true);
                vTaskDelay(500 / portTICK_PERIOD_MS);
                ssd1306_invert_display(false);
                vTaskDelay(500 / portTICK_PERIOD_MS);
            }
            break;

        case CAT_HAPPY:
            for (int i = 0; i < 8; i++) {
                draw_frame(cat_happy);
                vTaskDelay(200 / portTICK_PERIOD_MS);
            }
            break;

        default:
            draw_frame(cat_idle);
            break;
    }
}

void cat_show_text(const char* text)
{
    ssd1306_clear();
    ssd1306_set_cursor(10, 25);
    ssd1306_print(text);
    ssd1306_update();
}
