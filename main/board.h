#ifndef __BOARD_H__
#define __BOARD_H__

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Khởi tạo toàn bộ hardware:
 *        - OLED SSD1306 SPI 128x64
 *        - I2S cho mic INMP441 + ampli MAX98357
 */
esp_err_t board_init(void);

#ifdef __cplusplus
}
#endif

#endif // __BOARD_H__
