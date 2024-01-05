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

const int bt_out1 =  14;
const int bt_out2 =  12;
const int bt_out3 =  13;
const int bt_out4 =  15;

void setup()
{
  Serial.begin(115200);
  setupPinMode();
  setupTransitionInfo();


  // frameCrud.addFrame(MenuItems::clockOverlay);
  // display.display();
}

void setupPinMode(){
  pinMode(bt_out1, INPUT);
  pinMode(bt_out2, INPUT);
  pinMode(bt_out3, INPUT);
  pinMode(bt_out4, INPUT);
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
    setupButtons();
    delay(remainingTimeBudget);
  }
}

void setupButtons(){
  if(digitalRead(bt_out1) == HIGH){ 
      select(1);
  }
  if(digitalRead(bt_out2) == HIGH){ 
      select(2);
  }
  if(digitalRead(bt_out3) == HIGH){
      select(3);
  }
  if(digitalRead(bt_out4) == HIGH){ 
      select(4);
  }

  delay(1000);
}

void select(int number){
  switch (number) {
  case 1:
  Serial.println("acendeu 1");
  ui.previousFrame();
  break;
  case 2:
  break;
  case 3:
  break;
  case 4:
  ui.switchToFrame(3);
  break;
  }
}