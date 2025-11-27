#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "driver/i2s_std.h"
#include "ssd1306.h"
#include "esp_wifi.h"
#include "wifi_connect.h"     // sẽ tạo sau
#include "mcp_client.h"      // sẽ tạo sau
#include "cat_actions.h"

static const char *TAG = "CAT_AI";

void app_main(void)
{
    ESP_LOGI(TAG, "=== Con Meo AI khoi dong ===");

    // 1. Khoi tao NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // 2. Khoi tao hardware (OLED + I2S)
    board_init();

    // 3. Khoi tao con meo
    cat_init();
    cat_perform_action(CAT_IDLE);           // meo xuat hien ngay lap tuc

    // 4. Ket noi WiFi
    wifi_init_sta();

    // 5. Ket noi server AI XiaoZhi (wss://xiaozhi.me)
    mcp_client_start();

    ESP_LOGI(TAG, "Da san sang! Noi \"Meo oi\" hoac \"XiaoZhi\" de danh thuc");

    // Vong lap chinh (chi hien thi idle + cho AI xu ly)
    while (1) {
        cat_perform_action(CAT_IDLE);
        vTaskDelay(pdMS_TO_TICKS(8000));
    }
}
