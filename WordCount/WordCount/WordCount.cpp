// WordCount.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string"
#include "stdio.h"
#include "string"
#include "iostream"
#include "fstream"

using namespace std;

FILE *file;
int chars = 0, words = 0, lines = 1;
char c;


bool isSpace(char a)
{
	if (a == ' ')
		return true;
	return false;
}

bool isNewline(char a)
{
	if (a == '\n')
		return true;
	return false;
}

bool isTab(char a)
{
	if (a == '\t')
		return true;
	return false;
}

bool isLetter(char a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return true;
	return false;
}

bool isDigit(char a)
{
	if (a >= '0' && a <= '9')
		return true;
	return false;
}

bool isComma(char a)
{
	if (a == ',')
		return true;
	return false;
}

bool isDivi(char a)
{
	if (a == '/')
		return true;
	return false;
}

bool isSeparator(char a)
{
	if (a == ',' || a == ' ' || a == '\t' || a == '\n' || a == '\r')
		return true;
	return false;
}


void wordCount()
{
	while (!feof(file))
	{
		c = fgetc(file);
		chars++;
		if ( !isSeparator(c) )
		{
			words++;
			while (!feof(file))
			{
				c = fgetc(file);
				chars++;
				if (!isSeparator(c))
				{
				}
				else if (isNewline(c))//新行
				{
					lines++;
					break;
				}
				else if (isSpace(c) || isComma(c) || isTab(c))//单词结束
					break;
			}
		}
		else if (c == '\n')
			lines++;
	}
}


int main(int argc, char *argv[])
{
	cout << "argc:" << argc << endl;
	
	char *resultFile="result.txt", *fileName = NULL;
 
	for (int i = 0; i < argc; i++)
	{
		if (argv[i] == "-o")
		{
			fileName = argv[i - 1];
			if (i < argc - 1)
				resultFile = argv[i + 1];
			else
			{
				cout << "未指定输出文件!" << endl;
				return 0;
			}
		}
		else if (i == argc - 1)
			fileName = argv[i];
	}
	if (fileName == NULL)
	{
		cout << "未指定输入文件！" << endl;
		return 0;
	}
	file = fopen(fileName, "r");
	if (file == NULL)
	{
		cout << "can not open file." << endl;
		exit(0);
	}
	wordCount();
	fclose(file);

	fstream resFile;
	resFile.open(resultFile, ios_base::out);
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
		
		if (argv[i] == "-c")
		{
			cout << "字符数：" << chars << endl;
			if (resFile.is_open())
			{
				resFile << fileName << ", 字符数：" << chars << endl;
			}
		}
		else if (argv[i] == "-w")
		{
			cout << "单词数：" << words << endl;
			if (resFile.is_open())
			{
				resFile << fileName << ", 单词数：" << words << endl;
			}
		}
		else if (argv[i] == "-l")
		{
			cout << "总行数：" << lines << endl;
			if (resFile.is_open())
			{
				resFile << fileName << ", 总行数：" << lines << endl;
			}
		}
	}
	resFile.close();

	return 0;
}

