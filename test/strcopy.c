//
// Created by DingYong on 2025/8/22.
//

#include "strcopy.h"

/**
 * @brief 自定义字符串复制函数
 * @param str1
 * @param str2
 */
void strcopy(char *str1, char *str2) {
    while (*str1 != '\0') {
        *str2 = *str1;
        str1++;
        str2++;
    }
    *str2 = '\0';
}