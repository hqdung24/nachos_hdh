#include "syscall.h"
#include "copyright.h"

void main()
{
	// Khai bao
	int f_Success; // Bien co dung de kiem tra thanh cong
	SpaceId si_hanhkhach, si_mayquet;	// Bien id cho file
	char c_readFile;	// Bien ki tu luu ki tu doc tu file
	int flag_VN;		// Bien co de nhay den tien trinh mayquet
	int flag_MAIN;		// Bien co de nhay den tien trinh main
	int lengthFile;		// Luu do dai file
	int i_File;		// Luu con tro file
	//-----------------------------------------------------------
	Up("m_vn");	

	while(1)
	{
		lengthFile = 0;

		Down("hanhkhach");
		// Tao file result.txt de ghi voi nao su dung
		f_Success = Create("result.txt");
		if(f_Success == -1)
		{
			Up("main"); // tro ve tien trinh chinh
			return;
		}

		// Mo file hanhkhach.txt len de doc
		si_hanhkhach = Open("hanhkhach.txt", 1);
		if(si_hanhkhach == -1)
		{
			Up("main"); // tro ve tien trinh chinh
			return;
		}
		
		lengthFile = Seek(-1, si_hanhkhach);
		Seek(0, si_hanhkhach);
		i_File = 0;
	
		// Tao file mayquet.txt
		f_Success = Create("mayquet.txt");
		if(f_Success == -1)
		{
			Close(si_hanhkhach);
			Up("main"); // tro ve tien trinh chinh
			return;
		}
		

		// Mo file mayquet.txt de ghi tung dung tich nuoc cua hanhkhach
		si_mayquet = Open("mayquet.txt", 0);
		if(si_mayquet == -1)
		{
			Close(si_hanhkhach);
			Up("main"); // tro ve tien trinh chinh
			return;
		}
		
		// Ghi dung tich vao file mayquet.txt tu file hanhkhach.txt
		while(i_File < lengthFile)
		{
			flag_VN = 0;
			Read(&c_readFile, 1, si_hanhkhach);
			if(c_readFile != ' ')
			{
				Write(&c_readFile, 1, si_mayquet);
			}
			else
			{
				flag_VN = 1;
			}
			if(i_File == lengthFile - 1)
			{
				Write("*", 1, si_mayquet);
				flag_VN = 1;
			}
			
				
			if(flag_VN == 1)
			{
				Close(si_mayquet);
				Up("mayquet");
				// Dung chuong trinh hanhkhach lai de mayquet thuc thi
				Down("hanhkhach");
				
				// Tao file mayquet.txt
				f_Success = Create("mayquet.txt");
				if(f_Success == -1)
				{
					Close(si_hanhkhach);
					Up("main"); // tro ve tien trinh chinh
					return;
				}
		

				// Mo file mayquet.txt de ghi tung dung tich nuoc cua hanhkhach
				si_mayquet = Open("mayquet.txt", 0);
				if(si_mayquet == -1)
				{
					Close(si_hanhkhach);
					Up("main"); // tro ve tien trinh chinh
					return;
				}
				
			}
			i_File++;			
							
		}				
		// Ket thuc tien trinh hanhkhach va mayquet quay lai ham SvVn
		Up("main");			
	}
	// Quay lai ham Svvn	
}
