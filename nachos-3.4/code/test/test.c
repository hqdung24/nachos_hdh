#include "syscall.h"

int main()
{
    float* n;
    float temp;
    PrintChar('\n');
    PrintString("Nhap so thuc:");
    n = ReadFloat();
    temp = *n ;
    PrintString("so thuc vua nhap:");
    PrintFloat(n);
    PrintChar('\n');
    Halt();
}