#include "oledprint.h"
#include "ssd1306_fonts.h"

static char buff[40]; //buffer for OLED Display

void oledprintGPGGA1(char collection[][128]){
  ssd1306_Fill(Black);
  
  snprintf(buff, sizeof(buff), "UTC:%s ", collection[1]); //time
  ssd1306_SetCursor(2, 2);
  ssd1306_WriteString(buff, Font_7x10, White);
  
  
  snprintf(buff, sizeof(buff), "Lat:%s %s ", collection[2], collection[3]); //Lat and N/S
  ssd1306_SetCursor(2, 14);
  ssd1306_WriteString(buff, Font_7x10, White);
  
  
  snprintf(buff, sizeof(buff), "Lon:%s %s ", collection[4], collection[5]); //Lon and E/W
  ssd1306_SetCursor(2, 26);
  ssd1306_WriteString(buff, Font_7x10, White);
  
  
  snprintf(buff, sizeof(buff), "Sat:%s ", collection[7]); //Sat #
  ssd1306_SetCursor(2, 38);
  ssd1306_WriteString(buff, Font_7x10, White);
  
  
  snprintf(buff, sizeof(buff), "Elv:%s ", collection[9]); //Elev 
  ssd1306_SetCursor(2, 50);
  ssd1306_WriteString(buff, Font_7x10, White); 
  
  ssd1306_UpdateScreen();
  
}

void oledprintGPGGA2(char collection[][128]){
  ssd1306_Fill(Black);
  
  snprintf(buff, sizeof(buff), "Quality:%s ", collection[6]); //Quality fix
  ssd1306_SetCursor(2, 2);
  ssd1306_WriteString(buff, Font_7x10, White);
  
  
  snprintf(buff, sizeof(buff), "HDoP   :%s ", collection[8]); //Horizonal Precision
  ssd1306_SetCursor(2, 14);
  ssd1306_WriteString(buff, Font_7x10, White);
  
  
  snprintf(buff, sizeof(buff), "Geoid  :%s ", collection[10]); //Geoid height
  ssd1306_SetCursor(2, 26);
  ssd1306_WriteString(buff, Font_7x10, White);
  
  
  snprintf(buff, sizeof(buff), "DGPS ID:%s ", collection[12]); //DPGS ID
  ssd1306_SetCursor(2, 38);
  ssd1306_WriteString(buff, Font_7x10, White);
  
  ssd1306_UpdateScreen();
  
}

//$GPGSV
//
//GPS Satellites in view
//
//eg. $GPGSV,3,1,11,03,03,111,00,04,15,270,00,06,01,010,00,13,06,292,00*74
//    $GPGSV,3,2,11,14,25,170,00,16,57,208,39,18,67,296,40,19,40,246,00*74
//    $GPGSV,3,3,11,22,42,067,42,24,14,311,43,27,05,244,00,,,,*4D
//
//
//    $GPGSV,1,1,13,02,02,213,,03,-3,000,,11,00,121,,14,13,172,05*67
//
//
//1    = Total number of messages of this type in this cycle
//2    = Message number
//3    = Total number of SVs in view
//4    = SV PRN number
//5    = Elevation in degrees, 90 maximum
//6    = Azimuth, degrees from true north, 000 to 359
//7    = SNR, 00-99 dB (null when not tracking)
//8-11 = Information about second SV, same as field 4-7
//12-15= Information about third SV, same as field 4-7
//16-19= Information about fourth SV, same as field 4-7

void oledprintGPGSV(char collection[][128]){
  ssd1306_Fill(Black);
  
  snprintf(buff, sizeof(buff), "SVs:%s ", collection[3]); //Quality fix
  ssd1306_SetCursor(2, 2);
  ssd1306_WriteString(buff, Font_7x10, White);
  
  
  snprintf(buff, sizeof(buff), "PRN:%s ", collection[4]); //Horizonal Precision
  ssd1306_SetCursor(2, 14);
  ssd1306_WriteString(buff, Font_7x10, White);
  
  
  snprintf(buff, sizeof(buff), "Ele:%s ", collection[5]); //Geoid height
  ssd1306_SetCursor(2, 26);
  ssd1306_WriteString(buff, Font_7x10, White);
  
  
  snprintf(buff, sizeof(buff), "Azi:%s ", collection[6]); //DPGS ID
  ssd1306_SetCursor(2, 38);
  ssd1306_WriteString(buff, Font_7x10, White);
  
  snprintf(buff, sizeof(buff), "SNR:%s ", collection[7]); //Elev 
  ssd1306_SetCursor(2, 50);
  ssd1306_WriteString(buff, Font_7x10, White); 
  
  ssd1306_UpdateScreen();
  
}