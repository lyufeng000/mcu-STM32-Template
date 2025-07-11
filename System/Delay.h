#ifndef __DELAY_H
#define __DELAY_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


void delay_us(uint32_t us);
void delay_ms(uint32_t ms);
void delay_s(uint32_t s);

#ifdef __cplusplus
}
#endif


#endif
