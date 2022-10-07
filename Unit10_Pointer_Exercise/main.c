#include <stdint.h>
uint8_t Led_01 = 6, Led_02 = 7, Led_03 = 8;
uint32_t time_01 = 0, time_02 = 0, time_03 = 0;
uint32_t Led_01_State = 0, Led_02_State = 0, Led_03_State = 0;

typedef struct
{
    void (*task)();
    uint32_t time;
    uint32_t delay;
} Task;
void Thread_Pointer(void (*task)(), uint32_t *time, uint32_t delay)
{
    if (millis() - *time >= delay)
    {
        *time = millis();
        task();
        Serial.print("//////////////");
        Serial.println();
        Serial.print("Led 6: ");
        Serial.print(Led_01_State);
        Serial.println();
        Serial.print("Led 7: ");
        Serial.print(Led_02_State);
        Serial.println();
        Serial.print("Led 8: ");
        Serial.print(Led_03_State);
        Serial.println();
    }
}
// Using *task transmitter infor void (*task), *time, delay to *task
void Thread_Struct(Task *task)
{
    // Use pointer when have struct: task->time get members in struct Task
    if (millis() - task->time >= task->delay)
    {
        task->time = millis();
        task->task();
        Serial.print("//////////////");
        Serial.println();
        Serial.print("Led 6: ");
        Serial.print(Led_01_State);
        Serial.println();
        Serial.print("Led 7: ");
        Serial.print(Led_02_State);
        Serial.println();
        Serial.print("Led 8: ");
        Serial.print(Led_03_State);
        Serial.println();
    }
}

// I can't Optimize the blinkLed_01(),blinkLed_02(),blinkLed_03() functions
void blinkLed_01()
{
    // When using in STM32: Led_01 = !Led_01;
    Led_01_State = !Led_01_State;
    digitalWrite(Led_01, Led_01_State);
}
void blinkLed_02()
{
    // When using in STM32: Led_02 = !Led_02;
    Led_02_State = !Led_02_State;
    digitalWrite(Led_02, Led_02_State);
}
void blinkLed_03()
{
    // When using in STM32: Led_03 = !Led_03;
    Led_03_State = !Led_03_State;
    digitalWrite(Led_03, Led_03_State);
}

void setup()
{
    Serial.begin(9600);
    pinMode(Led_01, OUTPUT);
    pinMode(Led_02, OUTPUT);
    pinMode(Led_03, OUTPUT);
}
void loop()
{

    Task task_led_01 = {.task = blinkLed_01, .time = &time_01, .delay = 1000};
    Task task_led_02 = {.task = blinkLed_02, .time = &time_02, .delay = 2000};
    Task task_led_03 = {.task = blinkLed_03, .time = &time_03, .delay = 3000};

    // Task task_led_01, task_led_02, task_led_03;
    // task_led_01.task = blinkLed_01;
    // task_led_01.time = &time_01;
    // task_led_01.delay = 1000;

    // task_led_02.task = blinkLed_02;
    // task_led_02.time = &time_02;
    // task_led_02.delay = 2000;

    // task_led_03.task = blinkLed_03;
    // task_led_03.time = &time_03;
    // task_led_03.delay = 3000;
    while (1)
    {
        // if you want to using typedef struct
        Thread_Struct(&task_led_01);
        Thread_Struct(&task_led_02);
        Thread_Struct(&task_led_03);

        // if you want to using Pointer function
        // Thread_Pointer(blinkLed_01, &time_01, 1000);
        // Thread_Pointer(blinkLed_02, &time_02, 2000);
        // Thread_Pointer(blinkLed_03, &time_03, 3000);
    }
}