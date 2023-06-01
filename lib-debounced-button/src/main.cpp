#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>
#include <DebouncedButton.h>

void LeftRising(int8_t pin)
{
  Serial.println("Left rising");
}

void LeftFalling(int8_t pin)
{
  Serial.println("Left falling");
}

void RightRising(int8_t pin)
{
  Serial.println("Right rising");
}

void RightFalling(int8_t pin)
{
  Serial.println("Right falling");
}

void SlideRising(int8_t pin)
{
  Serial.println("Slide rising");
}

void SlideFalling(int8_t pin)
{
  Serial.println("Slide falling");
}

DebouncedButton btnLeft(CPLAY_LEFTBUTTON);
DebouncedButton btnRight(CPLAY_RIGHTBUTTON);
DebouncedButton btnSlide(CPLAY_SLIDESWITCHPIN);

void setup()
{
  // Start serial communication
  Serial.begin(115200);
  delay(2000);
  Serial.println("We're alive");

  pinMode(CPLAY_LEFTBUTTON, INPUT_PULLDOWN);
  pinMode(CPLAY_RIGHTBUTTON, INPUT_PULLDOWN);
  pinMode(CPLAY_SLIDESWITCHPIN, INPUT_PULLUP);

  btnLeft.RisingEdgeCallback = LeftRising;
  btnLeft.FallingEdgeCallback = LeftFalling;
  btnRight.RisingEdgeCallback = RightRising;
  btnRight.FallingEdgeCallback = RightFalling;
  btnSlide.RisingEdgeCallback = SlideRising;
  btnSlide.FallingEdgeCallback = SlideFalling;
}

void loop()
{
  btnLeft.Update();
  btnRight.Update();
  btnSlide.Update();

  if (btnLeft.IsHigh())
  {
  }
}
