#ifndef __CAT_ACTIONS_H__
#define __CAT_ACTIONS_H__

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    CAT_IDLE = 0,
    CAT_MEOW,
    CAT_WALK,
    CAT_SLEEP,
    CAT_PLAY,
    CAT_HAPPY,
    CAT_SAD,
    CAT_EAT,
    CAT_ANGRY
} cat_action_t;

/**
 * @brief Khởi tạo con mèo (load animation, âm thanh...)
 */
void cat_init(void);

/**
 * @brief Thực hiện hành động của mèo
 */
void cat_perform_action(cat_action_t action);

/**
 * @brief Hiển thị text đơn giản lên OLED (dùng để debug hoặc chào)
 */
void cat_show_text(const char* text);

#ifdef __cplusplus
}
#endif

#endif // __CAT_ACTIONS_H__
