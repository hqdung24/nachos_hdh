#include "syscall.h"

int main()
{
    float* n;
    PrintChar('\n');
    PrintString("Nhap so thuc:");
    n = ReadFloat();
    PrintString("so thuc vua nhap:");
    PrintFloat(n);
    PrintChar('\n');
    Halt();
}