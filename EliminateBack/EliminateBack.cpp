#include<iostream>
#include<string>
using namespace std;

/**********************寻找最短字符串的位置**********************************************/
int findMin(string wenfa[], int n)//n为文法数量,wenfa[0]存放匹配的字符
{
	int location;
	size_t minLength =wenfa[1].length();
	for (int i = 1; i < n; i++)
	{
		
		if(minLength>=wenfa[i].length())
		{
			minLength = wenfa[i].length();
			location = i;
		}
	}
		return location;
}
/**********************复制最短字符串，拆解***************************************/
void spiltWenfa(string wenfa[],int i,int location)//i为需要拆分的位置
{	
	wenfa[0] = wenfa[location];
}


/***********************寻找匹配字符串*******************************************/

bool match(string wenfa[],int n,int i)
{
	int count = 0;
	for (int no = 1; no < n; no++)
	{
		for (size_t num = 0; num < wenfa[no].length(); num++)
		{
			if (wenfa[0][i]==wenfa[no][num])
				count++;
		}
	}
	if (count == n) return true;
	else false;
}

/***************************移动匹配字符串到第一位，准备提取左因子*******************************/
void moveStr(string wenfa[],int n,int i)//i为wenfa[0]的定位值
{
	for (int no = 1; no < n; no++)
	{
		size_t k = wenfa[no].find(wenfa[0][i]);//k为wenfa[no]中匹配字符串的位置
		swap(wenfa[no][k], wenfa[no][0]);//将文法匹配的字符串交换到第一个位置
	}
}
/*************************提取左因子*************************************************/
void delStr(string wenfa[],int n)
{
	int i = 0;
	for (int no = 1; no < n; no++)
	{
		for (i; i < wenfa[no].length() - 1; i++)
		{
			if(i!=wenfa[no].length())
				wenfa[no][i] = wenfa[no][i + 1];
		}
	}
}
void main()
{
	int length;
	string wenfa[1000];
	string newStr[1000];
	cout << "请输入文法的数量" << endl;
	cin >> length;
/******************************文法输入单元,确定长度型****************************************/
	for (int i = 1; i <= length; i++)
	{
		cout << "请输入第"<<i<<"条文法" << endl;
		cin >> wenfa[i];
	}
	cout << "原始文法：";
	for (int i = 1; i <= length; i++)
	{
		cout << wenfa[i];
		if (i != length)
			cout << "|";
		else
			cout << endl;
	}
/*******************************文法处理*******************************************************/
	int location = 0;
	location = findMin(wenfa, length);
	for (int no = 0; no < wenfa[location].length(); no++)
	{
		spiltWenfa(wenfa, no, location);
	//	cout <<wenfa[0];//最短的文法
	}
/*******************************匹配文法*******************************************************/
	for(int j=0;j<wenfa[0].length();j++)
		for (int i = 0; i < wenfa[0].length(); i++) {
			if (match(wenfa, length, j))//匹配成功则说明这个文法存在回溯，可以提取左因子
			{
				moveStr(wenfa, length, i);
				delStr(wenfa, length);
				newStr[i] = wenfa[0][i];
			}
		}
	//cout << newStr[0]<<newStr[1];
	cout << wenfa[1];
	
}