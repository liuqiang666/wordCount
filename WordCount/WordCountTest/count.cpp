// WordCount.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string"
#include "iostream"
#include "fstream"

using namespace std;

FILE *file;
int chars = 0, words = 0, lines = 1;
char c;


bool isSpace(char a)//判断是否是空格
{
	if (a == ' ')
		return true;
	return false;
}

bool isNewline(char a)//判断是否是新行
{
	if (a == '\n')
		return true;
	return false;
}

bool isTab(char a)//判断是否是tab
{
	if (a == '\t')
		return true;
	return false;
}

bool isLetter(char a)//判断是否是字母
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return true;
	return false;
}

bool isDigit(char a)//判断是否是数字
{
	if (a >= '0' && a <= '9')
		return true;
	return false;
}

bool isComma(char a)//判断是否是逗号
{
	if (a == ',')
		return true;
	return false;
}

bool isDivi(char a)//判断是否是斜杠
{
	if (a == '/')
		return true;
	return false;
}

bool isSeparator(char a)//判断是不是分隔符，如空格，换行等
{
	if (a == ',' || a == ' ' || a == '\t' || a == '\n' || a == '\r')
		return true;
	return false;
}

void wordCount()//单词统计
{
	chars = 0; 
	words = 0; 
	lines = 0;
	while ((c = fgetc(file)) != EOF)
	{
		chars++;
		if (!isSeparator(c)) //若不是分隔符则是组成单词的一个字符
		{
			words++;
			while ((c = fgetc(file)) != EOF)//继续向后读
			{
				chars++;
				if (!isSeparator(c))//若不是分隔符则是组成单词的一个字符，
				{
				}
				else if (isNewline(c))//若是新行，行数+1
				{
					lines++;
					break;
				}
				else if (isSpace(c) || isComma(c) || isTab(c))//单词结束
				{
					break;
				}
			}
		}
		else if (isNewline(c))
			lines++;
	}
	if (chars !=0)//若该行为结束行，无换行符，行数也应+1
		lines++;
}


int count(int argc, char *argv[])
{
	char *resultFile = "result.txt", *fileName = NULL;
	int cflag=0, wflag=0, lflag=0,oflag = 0;
	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "-o") == 0)//若为-o，则确定输出文件，以及输入文件名
		{
			if (oflag == 0)
				oflag = i;
			else
			{
				cout << "error 5:parameter repeated." << endl;
				return 5;//参数重复
			}
			if (i < argc - 1)
				resultFile = argv[i + 1];
			else
			{
				cout << "error 2:output file was needed" << endl;
				return 2;
			}
		}
		else if (strcmp(argv[i], "-c") == 0)
		{
			if (cflag == 0)
				cflag = i;
			else
			{
				cout << "error 5:parameter repeated." << endl;
				return 5;//参数重复
			}
		}
		else if (strcmp(argv[i], "-w") == 0)
		{
			if (wflag == 0)
				wflag = i;
			else
			{
				cout << "error 5:parameter repeated." << endl;
				return 5;//参数重复
			}
			
		}
		else if (strcmp(argv[i], "-l") == 0)
		{
			if (lflag == 0)
				lflag = i;
			else
			{
				cout << "error 5:parameter repeated." << endl;
				return 5;//参数重复
			}
			
		}
		else if (i!=0 && i < 5 && fileName == NULL && argv[i][0] != '-')
		{
			fileName = argv[i];
		}
			
	}
	if (oflag !=0 && (oflag < cflag || oflag < wflag || oflag < lflag))
	{
		cout << "error 6: `-o` must be the last parameter." << endl;
		return 6;// `-o`不是最后一个参数
	}
	

	if (fileName == NULL)
	{
		cout << "error 1:input file was needed" << endl;
		return 1;
	}
	
	file = fopen(fileName, "r");//读取输入文件
	if (file == NULL)
	{
		cout << "error 3:can not open file." << endl;
		return 3;
	}
	wordCount();
	fclose(file);

	fstream resFile;
	resFile.open(resultFile, ios_base::out);
	for (int i = 0; i < argc; i++)//将结果输入到结果文件
	{
		if (strcmp(argv[i], "-c") == 0)
		{
			cout << "char count:" << chars << endl;
			if (resFile.is_open())
			{
				resFile << fileName << ", 字符数：" << chars << endl;
			}
		}
		else if (strcmp(argv[i], "-w") == 0)
		{
			cout << "word count:" << words << endl;
			if (resFile.is_open())
			{
				resFile << fileName << ", 单词数：" << words << endl;
			}
		}
		else if (strcmp(argv[i], "-l") == 0)
		{
			cout << "line count:" << lines << endl;
			if (resFile.is_open())
			{
				resFile << fileName << ", 总行数：" << lines << endl;
			}
		}
		else if (argv[i][0] == '-' && strcmp(argv[i], "-c") != 0 && strcmp(argv[i], "-w") != 0 && strcmp(argv[i], "-l") != 0 && strcmp(argv[i], "-o") != 0)
		{
			cout << "error 4:parameter error." << endl;
			return 4;//参数错误
		}
	}
	resFile.close();//关闭文件
	return 0;
}


