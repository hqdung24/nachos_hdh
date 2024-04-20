#include "syscall.h"
#include "copyright.h"

int charArrayLength(const char* charArray) {
    int length = 0;
    while (charArray[length] != '\0') {
        length++;
    }
    return length;
}

void numberToCharArray(int number, char* charArray) {

    char tempArray[256]; 
    int i = 0;
    int index = 0;
    while (number != 0) {
        tempArray[index++] = '0' + (number % 10);
        number /= 10;
    }

    // Reverse the temporary array to get the digits in correct order
    for (i = 0; i < index; ++i) {
        charArray[i] = tempArray[index - i - 1];
    }
    charArray[index] = '\0';
}


void main()
{
	// Khai bao
	int f_Success; // Bien co dung de kiem tra thanh cong
	SpaceId  si_mayquet, si_result;	// Bien id cho file
	char c_readFile;	// Bien ki tu luu ki tu doc tu file
	int v1, v2, v3;		// Voi 1, voi 2, Voi 3
	int v;			// Dung tich nuoc cua sinh vien
	int flag_done_result;	// Bien co luu dau hieu doc xong file result
	char num[255];
	//-----------------------------------------------------------
	
	v1 = v2 = v3 = 0;
	// Xu ly voi nuoc
	// WHILE(11111111111111111111111111111111111111)
	while(1)
	{
		Down("m_vn");

		// Mo file result.txt de ghi voi nao su dung
		si_result = Open("result.txt", 0);
		if(si_result == -1)
		{		//?
			Up("hanhkhach");
			return;
		}
		// WHILE(2222222222222222222222222222222222222222)
		while(1)
		{
			Down("mayquet");
			c_readFile = 0;			
			// Mo file mayquet.txt de doc 
			si_mayquet = Open("mayquet.txt", 1);
			if(si_mayquet == -1)
			{
				//?
				Close(si_result);
				Up("hanhkhach");
			
				return;
			}
		
			v = 0;
			flag_done_result = 0;
			while(1)
			{			
				if(Read(&c_readFile, 1, si_mayquet)  == -2)
				{	
					Close(si_mayquet);			
					break;
				}
				if(c_readFile != '*')
				{
					v = v* 10 + (c_readFile - 48);
					numberToCharArray(v, num);
					if (v >= 0)
					Write(num, charArrayLength(num), si_result);
				}
				else
				{
					flag_done_result = 1;				
					Close(si_mayquet);
					break;			
				}
			
			}
			if(v!= 0)
			{
				// Dung may 1
				if(v1 <= v2)
				{
					v1 += v;
					Write("1", 1, si_result);
				}
				else if (v2 <= v3) //dung may 2
				{					
					v2 += v;
					Write("2", 1, si_result);
					
				}
				else
				{					
					v3 += v;
					Write("3", 1, si_result);
					
				}

			}
		
			if(flag_done_result == 1)
			{
				v1 = v2 = v3 = 0;
				Close(si_result);				
				Up("hanhkhach");
				break;				
			}

			Up("hanhkhach");
		}
	}			
}
