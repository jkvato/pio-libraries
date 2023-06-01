#include <Arduino.h>
#include "DebouncedButton.h"

DebouncedButton::DebouncedButton(int8_t pin, uint8_t delay)
{
  this->pin = pin;
  this->delay = delay;

  RisingEdgeCallback = NULL;
  FallingEdgeCallback = NULL;

  buttonState = LOW;
  lastButtonState = LOW;
  lastDebounceTime = 0;

  changeCount = 0;
}

uint16_t DebouncedButton::GetChangeCount(void)
{
  uint16_t result = changeCount;
  changeCount = 0;
  return result;
}

void DebouncedButton::Update(void)
{
  int reading = digitalRead(pin);

  if (reading != lastButtonState)
  {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > delay)
  {
    if (reading != buttonState)
    {
      buttonState = reading;
      changeCount++;

      if (buttonState == HIGH)
      {
        if (RisingEdgeCallback != NULL)
        {
          RisingEdgeCallback(pin);
        }
      }
      else if (buttonState == LOW)
      {
        if (FallingEdgeCallback != NULL)
        {
          FallingEdgeCallback(pin);
        }
      }
    }
  }
  lastButtonState = reading;
}