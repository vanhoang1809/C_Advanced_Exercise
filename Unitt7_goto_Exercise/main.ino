#include<stdint.h>
uint8_t arr_led[] = {8, 9, 11, 12, 13};
uint8_t count = 5;
#define BTN_BLINK_LED 4
#define BTN_SEQUENTIAL_LED 6
uint8_t temp = 1;
typedef enum
{
  BLINK_LED,
  SEQUENTIAL_LED,
  BTN_OFF
} SWITCHS;

// when i use typedef enum STATUS for delay_checks() function then at sequential_Led() and blinkLed() function cannot get return value of delay_checks() function.
typedef enum
{
  TURN_OFF_BLINK_LED,
  TURN_OFF_SEQUENTIAL_LED
} STATUS;


int delay_checks()
{
  SWITCHS btn;

  btn = button();

  switch (btn)
  {
  case BLINK_LED:
    /* code */
    Serial.print("Button Led Blink light.\n");
    blinkLed();
    return 1;
    break;
  case SEQUENTIAL_LED:
    Serial.print("Button Led Sequential light.\n");
    sequential_Led();
    return 2;
    break;
  case BTN_OFF:
    Serial.print("Turn off\n");
    turnOffAll();
    return 0;
    break;
  default:
    Serial.println("No Control Led\n");
    break;
  }
}
SWITCHS button()
{

  /* code */
  if (digitalRead(BTN_BLINK_LED) == 1)
  {
    return BLINK_LED;
    // blinkLed();
  }
  else if (digitalRead(BTN_SEQUENTIAL_LED) == 1)
  {
    // followLed();
    return SEQUENTIAL_LED;
  }
  else
  {
    return BTN_OFF;
    // turnOffAll();
  }
}
void turnOnAll()
{
  for (int i = 0; i < count; i++)
  {
    digitalWrite(arr_led[i], HIGH);
  }
}
void turnOffAll()
{
  for (int i = 0; i < count; i++)
  {
    digitalWrite(arr_led[i], LOW);
  }
}
void sequential_Led()
{
  while (1)
  {
    for (int i = 0; i < count; i++)
    {

      if (delay_checks() == 1)
      {
        /* code */
        goto Out;
      }
      digitalWrite(arr_led[i], HIGH);
      delay(1000);
      digitalWrite(arr_led[i], LOW);
      Serial.print("Led light: ");
      Serial.println(arr_led[i]);
    }
  }
Out:
  temp = 2;
}
void blinkLed()
{
  while (1)
  {
    turnOnAll();
    delay(1000);
    if (delay_checks() == 2)
    {
      /* code */
      goto Out;
    }
    turnOffAll();
    delay(1000);
  }
Out:
  temp = 1;
}
void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < count; i++)
  {
    pinMode(arr_led[i], OUTPUT);
  }
  pinMode(BTN_BLINK_LED, INPUT_PULLUP);
  pinMode(BTN_SEQUENTIAL_LED, INPUT_PULLUP);
  pinMode(BTN_BLINK_LED, LOW);
  pinMode(BTN_SEQUENTIAL_LED, LOW);
}
void loop()
{
  while (1)
  {
    delay_checks();
  }
}