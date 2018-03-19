// WordCountTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "assert.h"
#include "count.h"
#include "iostream"

using namespace std;

void test1()//测试正确输入
{
	cout << "testcase1:" << endl;
	int argc = 5;
	char *argv[] = { "WordCountTest.exe", "-c", "-w", "-l", "D:\\wordCount\\test.txt" };
	int result = count(argc, argv);
	assert(result == 0);
}

void test2()//测试指定输出文件
{
	cout << "testcase2:" << endl;
	int argc = 7;
	char *argv[] = { "WordCountTest.exe", "-c", "-w", "-l", "D:\\wordCount\\test.txt" , "-o", "outfile.txt"};
	int result = count(argc, argv);
	assert(result == 0);
}

void test3()//测试错误参数
{
	cout << "testcase3:" << endl;
	int argc = 7;
	char *argv[] = { "WordCountTest.exe", "-b", "-w", "-l", "D:\\wordCount\\test.txt" , "-o", "outfile.txt" };
	int result = count(argc, argv);
	assert(result == 4);
}

void test4()//测试不指定输入文件
{
	cout << "testcase4:" << endl;
	int argc = 6;
	char *argv[] = { "WordCountTest.exe", "-c", "-w", "-l" , "-o", "outfile.txt" };
	int result = count(argc, argv);
	assert(result == 1);
}

void test5()//测试不指定输出文件，即'-o'单独出现
{
	cout << "testcase5:" << endl;
	int argc = 6;
	char *argv[] = { "WordCountTest.exe", "-c", "-w", "-l" , "D:\\wordCount\\test.txt", "-o"};
	int result = count(argc, argv);
	assert(result == 2);
}

void test6()//测试输入文件指定错误，即指定为打不开的文件
{
	cout << "testcase6:" << endl;
	int argc = 7;
	char *argv[] = { "WordCountTest.exe", "-c", "-w", "-l" , "D:\\wordCount\\tes.txt", "-o" , "outfile.txt" };
	int result = count(argc, argv);
	assert(result == 3);
}

void test7()//测试参数重复
{
	cout << "testcase7:" << endl;
	int argc = 4;
	char *argv[] = { "WordCountTest.exe", "-c", "-c", "D:\\wordCount\\tes.txt" };
	int result = count(argc, argv);
	assert(result == 5);
}

void test8()//'-o'参数出现在输入文件之前
{
	cout << "testcase8:" << endl;
	int argc = 6;
	char *argv[] = { "WordCountTest.exe", "-c", "-o", "-l" , "D:\\wordCount\\tes.txt" , "outfile.txt" };
	int result = count(argc, argv);
	assert(result == 6);
}

void test9()//测试空文件
{
	cout << "testcase9:" << endl;
	int argc = 7;
	char *argv[] = { "WordCountTest.exe", "-c", "-w", "-l" , "D:\\wordCount\\test8.txt", "-o" , "outfile.txt" };
	int result = count(argc, argv);
	assert(result == 0);
}

void test10()//测试只含有',', ' ' 的文件
{
	cout << "testcase10:" << endl;
	int argc = 7;
	char *argv[] = { "WordCountTest.exe", "-c", "-w", "-l" , "D:\\wordCount\\test9.txt", "-o" , "outfile.txt" };
	int result = count(argc, argv);
	assert(result == 0);
}

int main()
{
	test1();
	cout << endl;
	test2();
	cout << endl;
	test3();
	cout << endl;
	test4();
	cout << endl;
	test5();
	cout << endl;
	test6();
	cout << endl;
	test7();
	cout << endl;
	test8();
	cout << endl;
	test9();
	cout << endl;
	test10();
	cout << endl;
	getchar();
    return 0;
}

