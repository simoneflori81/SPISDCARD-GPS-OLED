#ifndef __OLEDPRINT_H__
#define __OLEDPRINT_H__

#include "ssd1306.h"

void oledprintGPGGA1(char array[][128]);
void oledprintGPGGA2(char array[][128]);
void oledprintGPGSV(char array[][128]);

#endif /* __OLEDPRINT_H__ */