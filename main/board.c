#include "board.h"
#include "ssd1306.h"
#include "driver/spi_master.h"
#include "driver/i2s_std.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char *TAG = "BOARD";

// OLED SPI pins (chuẩn của bạn)
#define PIN_SPI_SCK   12
#define PIN_SPI_MOSI  11
#define PIN_SPI_CS    10
#define PIN_SPI_DC    14
#define PIN_SPI_RST   13

// I2S pins (INMP441 + MAX98357)
#define PIN_I2S_BCLK  4
#define PIN_I2S_WS    5
