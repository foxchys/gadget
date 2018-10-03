#include <iostream>
#include <fstream>
#include <string>
#include<vector>
void write(std::string filename)
{
	std::ofstream in;
	in.open(filename, std::ios::trunc); //ios::trunc表示在打开文件前将文件清空,由于是写入,文件不存在则创建
	int i;
	char a = 'a';
	for (i = 1; i <= 26; i++)//将26个数字及英文字母写入文件
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
	in.close();//关闭文件
}


int CountLines(char *filename)//获取文件的行数
{
	std::ifstream ReadFile;
	int n = 0;
	std::string temp;
	ReadFile.open(filename, std::ios::in);//ios::in 表示以只读的方式读取文件
	if (ReadFile.fail())//文件打开失败:返回0
	{
		return 0;
	}
	else//文件存在,返回文件行数
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
		std::cout << "文件不存在." << std::endl;
		file.close();
		std::cin.get();
		std::cin.get();
	}
	else//文件存在
	{
		int  column = 2;//定义列数为column
		int row;//定义行数为row
		row = CountLines(const_cast<char*>(filename.c_str()));//求出行数赋值为LINES
		std::vector<std::vector<std::string> >swp(row, std::vector<std::string>(column));//定义二维数组swp[row][column]，n行 m列
		int i = 0;
		for (int i = 0; i < row; i++)
		{
			file.eof();//读取一行txt到file
			for (int j = 0; j<column; j++)
				file >> swp[i][j];
		}
		file.close(); //关闭txt文件
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