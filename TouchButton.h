#ifndef TOUCHBUTTON_H
#define TOUCHBUTTON_H

#include "Touch.h"
#include "Display.h"

#define CHARWIDTH 6
#define CHARHEIGHT 8
#define BACKGROUNDCOLOUR ILI9340_BLUE
#define TEXTCOLOUR ILI9340_WHITE

#ifdef DEBUG
  #define ERASECOLOUR ILI9340_RED
#endif
  #define ERASECOLOUR ILI9340_BLUE
#ifndef DEBUG
#endif
#define BUTTONCOLOUR ILI9340_WHITE
#define BUTTONPUSHEDCOLOUR ILI9340_MAGENTA
#define RADIUS 4
#define SHADDOW ILI9340_BLACK

class TouchButton : public TouchElement{
  protected:
    char *label = "";
    int shaddow = 2;
    int radius = 2;
    int colour = BUTTONCOLOUR;
    int shaddowColour = 0;

  public:
    TouchButton(int x, int y, int w, int h, char* label="") : TouchElement {x,y,w,h}
    {
		#ifdef DEBUG
		  Serial.print(F("TouchButton(...) "));
		  Serial.println(F(label));
		#endif
		this->label = label;
    }

    void setLabel(char *newLabel) {
      #ifdef DEBUG
        Serial.print(F("TouchButton::setLabel() "));
        Serial.print(F(label));
        Serial.print(F(" to "));
        Serial.println(F(newLabel));
      #endif
      this->label = newLabel;
    }

    void draw() {
      #ifdef DEBUG
        Serial.print(F("TouchButton::draw() "));
        Serial.println(F(label));
      #endif
      int startX = x-w/2;
      int startY = y-h/2;
      int r = 4;
      Display::device->fillRect(startX-shaddow, startY-shaddow, w+shaddow, h+shaddow, ERASECOLOUR);
      Display::device->drawFastHLine(x+r -shaddow, startY -shaddow  , w-2*r, shaddowColour); // Top
      Display::device->drawFastVLine(x -shaddow  , startY+r -shaddow, h-2*r, shaddowColour); // Left
      Display::device->drawCircleHelper(x+r -shaddow, startY+r -shaddow, r, 1, shaddowColour); //top left corner
      Display::device->drawCircleHelper(x+w-r-1 -shaddow, startY+r -shaddow, r, 2, shaddowColour); //top right corner
      Display::device->drawCircleHelper(x+r -shaddow, startY+h-r-1 -shaddow, r, 8, shaddowColour); //bottom left corner
      Display::device->drawRoundRect(startX, startY, w, h, radius, colour);
      int newY = startY + (h - CHARHEIGHT)/2;
      int newX = startX + (w - (strlen(label) * CHARWIDTH))/2;
      Display::device->setCursor(newX, newY);
      Display::device->print(label);
    }

    void push() {
      #ifdef DEBUG
        Serial.print(F("TouchButton::push() "));
        Serial.println(F(label));
      #endif
      int startX = x-w/2;
      int startY = y-h/2;
      Display::device->fillRect(startX-shaddow, startY-shaddow, w+shaddow, h+shaddow, ERASECOLOUR);
      Display::device->drawRoundRect(startX, startY, w, h, radius, shaddowColour);
      int newY = startY + (h - CHARHEIGHT)/2;
      int newX = startX + (w - (strlen(label) * CHARWIDTH))/2;
      Display::device->setCursor(newX, newY);
      Display::device->print(label);
    }

};
#endif