#ifndef DEBOUNCED_BUTTON_H
#define DEBOUNCED_BUTTON_H

#include <Arduino.h>

class DebouncedButton
{
  public:
    DebouncedButton(int8_t pin, uint8_t delay = 50);
    void Update(void);

    bool IsHigh(void) { return buttonState == HIGH; };
    bool IsLow(void) { return buttonState == LOW; };
    uint16_t GetChangeCount(void);

    typedef void (*ButtonEventCallback) (int8_t pin);

    ButtonEventCallback RisingEdgeCallback;
    ButtonEventCallback FallingEdgeCallback;

  protected:
    int8_t pin;
    uint8_t delay;

    int buttonState;
    int lastButtonState;
    uint32_t lastDebounceTime;

    uint16_t changeCount;
};

#endif