#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef enum
{
    GPIO_PIN_0 = 0x01,
    GPIO_PIN_1 = 0x01 << 1,
    GPIO_PIN_2 = 0x01 << 2,
    GPIO_PIN_3 = 0x01 << 3,
    GPIO_PIN_4 = 0x01 << 4,
    GPIO_PIN_5 = 0x01 << 5,
    GPIO_PIN_6 = 0x01 << 6,
    GPIO_PIN_7
} GPIO_PIN;

typedef enum
{
    LOW = 0,
    HIGH
} STATUS;

uint8_t PORTA = 0x00;

int digitalWrite(GPIO_PIN PIN, STATUS Status)
{
    if (Status == 1)
    {
        // 0x00000001
        //  0x00000001
        //|  0x00000001

        //   0x00010000
        //   0x00010001
        PORTA |= PIN;
    }
    else
    {
        //  0x00010001
        //~ 0x11111110
        //& 0x00010000

        //  0x00010000
        //  0x11101111
        PORTA &= ~PIN;
    }
}
int blinkLed(GPIO_PIN PIN){
    // 0x00000000
    // 0x00010000

    //^0x00010000
    // 0x00010000
    //^0x00000000
    // 0x00010000
    PORTA = 0x00;
    PORTA ^= PIN;
}
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
// Driver code to test above function
int main()
{
    printf("Status of led: %d\n",digitalWrite(GPIO_PIN_0, HIGH));
    printf("Status of led: %d\n",digitalWrite(GPIO_PIN_3, HIGH));
    printf("Status of led: %d\n",digitalWrite(GPIO_PIN_0, LOW));
    delay(2);
    printf("Status of led: %d\n",blinkLed(GPIO_PIN_4));
    delay(2);
    printf("Status of led: %d\n",blinkLed(GPIO_PIN_4));
    
}