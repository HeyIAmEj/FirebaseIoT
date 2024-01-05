#ifndef MENU_ITEMS_H
#define MENU_ITEMS_H

#include "OLEDDisplayUi.h"

class MenuItems
{
public:
  static void wifiFrame(OLEDDisplay* display, OLEDDisplayUiState* state, int16_t x, int16_t y);
  static void drawFrame2(OLEDDisplay* display, OLEDDisplayUiState* state, int16_t x, int16_t y);
  static void drawFrame3(OLEDDisplay* display, OLEDDisplayUiState* state, int16_t x, int16_t y);
  static void drawFrame4(OLEDDisplay* display, OLEDDisplayUiState* state, int16_t x, int16_t y);
  static void drawFrame5(OLEDDisplay* display, OLEDDisplayUiState* state, int16_t x, int16_t y);


  static void clockOverlay(OLEDDisplay* display, OLEDDisplayUiState* state);
  static void topBar(OLEDDisplay* display, OLEDDisplayUiState* state);
};

extern MenuItems menuItems;
#endif // MENU_ITEMS_H
