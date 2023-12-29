#include <Wire.h>
#include "SSD1306Wire.h"
#include "OLEDDisplayUi.h"
#include "images.h"

SSD1306Wire display(0x3c, SDA, SCL);
OLEDDisplayUi ui(&display);

#include "FrameCRUD.h"
#include "MenuItems.h"

FrameCallback frames[] = {MenuItems::drawFrame1, MenuItems::drawFrame2, MenuItems::drawFrame3, MenuItems::drawFrame4, MenuItems::drawFrame5};
int frameCount = sizeof(frames) / sizeof(frames[0]);

OverlayCallback overlays[] = {MenuItems::topBar};
int overlaysCount = sizeof(overlays) / sizeof(overlays[0]);

void setup()
{
  Serial.begin(115200);
  setupTransitionInfo();

  // frameCrud.addFrame(MenuItems::clockOverlay);
  // display.display();
}

void setupTransitionInfo()
{
  // The ESP is capable of rendering 60fps in 80Mhz mode
  // but that won't give you much time for anything else
  // run it in 160Mhz mode or just set it to 30 fps
  ui.setTargetFPS(60);
  ui.setActiveSymbol(activeSymbol);
  ui.setInactiveSymbol(inactiveSymbol);
  ui.setIndicatorPosition(BOTTOM);
  ui.setIndicatorDirection(LEFT_RIGHT);
  ui.setFrameAnimation(SLIDE_LEFT);
  ui.setTimePerFrame(1000);

  ui.setFrames(frames, frameCount);
  ui.setOverlays(overlays, overlaysCount);

  ui.init();
  display.flipScreenVertically();

  // unsigned long secsSinceStart = millis();
  // // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
  // const unsigned long seventyYears = 2208988800UL;
  // // subtract seventy years:
  // unsigned long epoch = secsSinceStart - seventyYears * SECS_PER_HOUR;
  // setTime(epoch);
}

void loop()
{
  int remainingTimeBudget = ui.update();

  if (remainingTimeBudget > 0)
  {
    // You can do some work here
    // Don't do stuff if you are below your
    // time budget.
    delay(remainingTimeBudget);
  }
}