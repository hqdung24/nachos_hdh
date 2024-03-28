#include "syscall.h"


void numberToCharArray(float *number, char* charArray) {
    const int arraySize = 256;
    char tempArray[arraySize];
    int length ; 
    int intPart = (int)(*number);
    int index = 0;
    int i = 0;
    char temp;
    float fractionalPart;
    int precision;
    int digit;
    do {
        tempArray[index++] = '0' + ((int)(*number) % 10);
        intPart /= 10;
    } while (intPart != 0);

    // Reverse the integer part to get the digits in correct order
    length = index;
    for (i = 0; i < length / 2; ++i) {
        temp = tempArray[i];
        tempArray[i] = tempArray[length - i - 1];
        tempArray[length - i - 1] = temp;
    }

    // Add decimal point
    tempArray[length++] = '.';

    // Convert the fractional part of the float number to a string
    fractionalPart = abs(*number - (float)(int)(*number));
    precision = 6; // Precision for fractional part
    for (i = 0; i < precision; ++i) {
        fractionalPart *= 10;
        digit = (int)(fractionalPart);
        tempArray[length++] = '0' + digit;
        fractionalPart -= digit;
    }

    // Null-terminate the character array
    tempArray[length] = '\0';

    // Copy the string to charArray
    for (i = 0; i <= length; ++i) {
        charArray[i] = tempArray[i];
    }
}

int main()
{
    float* arr[5];
    int i = 0;
    int n = 5;
    char num[20];
    PrintChar('\n');
    for (i = 0; i < n; i++)
    {
    PrintString("Nhap so thuc:");
    arr[i] = ReadFloat();
    }


    for (i = 0; i < 20; i++)
    {
        // PrintFloat(arr[i]);
        // PrintChar('\n');
        numberToCharArray(arr[i], num);
        PrintString(num);
    }
}