#include <iostream>
#include <fstream>
#include <string>
#include<vector>
void write(std::string filename)
{
	std::ofstream in;
	in.open(filename, std::ios::trunc); //ios::trunc��ʾ�ڴ��ļ�ǰ���ļ����,������д��,�ļ��������򴴽�
	int i;
	char a = 'a';
	for (i = 1; i <= 26; i++)//��26�����ּ�Ӣ����ĸд���ļ�
	{
		if (i<10)
		{
			in << "0" << i << "\t" << a << "\n";
			a++;
		}
		else
		{
			in << i << "\t" << a << "\n";
			a++;
		}
	}
	in.close();//�ر��ļ�
}


int CountLines(char *filename)//��ȡ�ļ�������
{
	std::ifstream ReadFile;
	int n = 0;
	std::string temp;
	ReadFile.open(filename, std::ios::in);//ios::in ��ʾ��ֻ���ķ�ʽ��ȡ�ļ�
	if (ReadFile.fail())//�ļ���ʧ��:����0
	{
		return 0;
	}
	else//�ļ�����,�����ļ�����
	{
		while (std::getline(ReadFile, temp))
		{
			n++;
		}
		return n;
	}
	ReadFile.close();
}

void main()
{
	std::string filename = "com.txt";
	write(filename);
	std::ifstream file;

	file.open(filename);
	if (file.fail())
	{
		std::cout << "�ļ�������." << std::endl;
		file.close();
		std::cin.get();
		std::cin.get();
	}
	else//�ļ�����
	{
		int  column = 2;//��������Ϊcolumn
		int row;//��������Ϊrow
		row = CountLines(const_cast<char*>(filename.c_str()));//���������ֵΪLINES
		std::vector<std::vector<std::string> >swp(row, std::vector<std::string>(column));//�����ά����swp[row][column]��n�� m��
		int i = 0;
		for (int i = 0; i < row; i++)
		{
			file.eof();//��ȡһ��txt��file
			for (int j = 0; j<column; j++)
				file >> swp[i][j];
		}
		file.close(); //�ر�txt�ļ�
		for (int ii = 0; ii < row; ii++)
		{
			for (int j = 0; j < column; j++)
				std::cout << swp[ii][j] << "\t";
			std::cout << std::endl;
		}
		std::cin.get();
		std::cin.get();
	}
}