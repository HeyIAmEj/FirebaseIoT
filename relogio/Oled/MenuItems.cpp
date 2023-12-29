#include "MenuItems.h"
#include "images.h"

int contentStartAt = 15;

void MenuItems::drawFrame1(OLEDDisplay* display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  display->drawXbm(x + 35, y + contentStartAt, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
}

void MenuItems::drawFrame2(OLEDDisplay* display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->drawString(0 + x, y + contentStartAt, "Olá, tudo bem?");
  display->drawString(0 + x, y + contentStartAt * 2, "Isso é um teste!");
  display->drawString(0 + x, y + contentStartAt * 3, "Acredito que funcionou!");
}

void MenuItems::drawFrame3(OLEDDisplay* display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->drawString(0 + x, y + contentStartAt, "Alinhado a esquerda");

  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->drawString(64 + x, y + contentStartAt * 2, "Alinhado ao centro");

  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->drawString(128 + x, y + contentStartAt * 3, "Alinhado a direita");
}

void MenuItems::drawFrame4(OLEDDisplay* display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->drawStringMaxWidth(0 + x, y + contentStartAt, 128, "Você não possui mais mensagens...");
}

void MenuItems::drawFrame5(OLEDDisplay* display, OLEDDisplayUiState* state, int16_t x, int16_t y)
{
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->drawString(0 + x, y + contentStartAt, "Veve");
}

void MenuItems::topBar(OLEDDisplay* display, OLEDDisplayUiState* state)
{
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  // display->drawString(128, 0, String(millis()));
  display->drawRect(0, 0, 128, 16);
  display->fillRect(0, 0, 128, 16);
}

void MenuItems::clockOverlay(OLEDDisplay* display, OLEDDisplayUiState* state)
{
}

MenuItems menuItems;