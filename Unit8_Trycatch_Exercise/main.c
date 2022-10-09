#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int value = 0;

#define THROW(num) longjmp(buf, num)
#define TRY if ((value = setjmp(buf)) == 0)
#define CATCH(num) else if (value == num)
#define CATCHALL else

#define bool unsigned char
#define true 1
#define false 0

bool equalArray(char arr_1[], char arr_2[], unsigned char size_arr_1, unsigned char size_arr_2)
{
    int count = 0;
    // check the size of array == NULL
    if (size_arr_1 == '\0' || size_arr_2 == '\0')
    {
        /* code */
        THROW(1);
    }
    // Check the size of array  different
    else if (size_arr_1 != size_arr_2)
    {
        /* code */
        THROW(2);
    }

    for (int i = 0; i < size_arr_1; i++)
    {
        printf("arr_1: %d\t", arr_1[i]);
        printf("arr_2: %d\t", arr_2[i]);
        printf("\n");
        /* code */
        // Check the array value different or same?
        if (arr_1[i] != arr_2[i])
        {
            /* code */
            THROW(3);
        }
        else
        {
            count++;
        }
    }
    if (count == size_arr_1)
    {
        /* code */
        return true;
    }
}

int main()
{
    TRY
    {
        char arr_1[] = {1, 3, 3, 4, 5, 6};
        char arr_2[] = {1, 3, 6, 4, 5, 8};
        unsigned char size_arr_1 = sizeof(arr_1) / sizeof(char);
        unsigned char size_arr_2 = sizeof(arr_2) / sizeof(char);
        unsigned char result = equalArray(arr_1, arr_2, size_arr_1, size_arr_2);
        if (result == 1)
        {
            /* code */
            printf("Two Array same.\n");
        }
    }
    CATCH(1)
    {
        printf("ERROR!!! SIZE FOR ARRAY IS NULL\n");
    }
    CATCH(2)
    {
        printf("ERROR!!! Sizeof arr_1 different arr_2\n");
    }
    CATCH(3)
    {
        printf("ERROR!!! arr_1 different arr_2\n");
    }
}