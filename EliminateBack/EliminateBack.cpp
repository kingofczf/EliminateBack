#include<iostream>
#include<string>
using namespace std;

/**********************寻找最短字符串的位置**********************************************/
int findMin(string wenfa[], int n)//n为文法数量,wenfa[0]存放匹配的字符
{
	int location=0;
	size_t minLength =65535;
	for (int i = 1; i <= n; i++)
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
void spiltWenfa(string wenfa[],int location)//location为需要拆分的位置
{	 
	wenfa[0] = wenfa[location];
}


/***********************寻找匹配字符串*******************************************/

bool match(string wenfa[],int n,int i)
{
	int count = 0;
	for (int no = 1; no <= n; no++)
	{
		for (size_t num = 0; num < wenfa[no].length(); )
		{
			if (wenfa[0][i] == wenfa[no][num])
			{
				count++;
				break;
			}
			else num++;
		}
	}
	if (count == n) return true;
	else return false;
}

/***************************移动匹配字符串到第一位，准备提取左因子*******************************/
void moveStr(string wenfa[],int n,int i)//i为wenfa[0]的定位值
{
	for (int no = 1; no <= n; no++)
	{
		size_t k = wenfa[no].find(wenfa[0][i]);//k为wenfa[no]中匹配字符串的位置
		swap(wenfa[no][k], wenfa[no][0]);//将文法匹配的字符串交换到第一个位置
	}
}
/*************************提取左因子,按照*************************************************/
void delStr(string wenfa[],int n)
{
	for (int no = 1; no <= n; no++)
	{	
		wenfa[no][0] = NULL;
	}
}
void main()
{
	int length,newLength=0;
	bool change = false;
	string wenfa[1000];
	string newStr[1000];
	cout << "请输入文法的数量" << endl;
	cin >> length;
	/******************************文法输入单元,确定长度型****************************************/
	for (int i = 1; i <= length; i++)
	{
		cout << "请输入第" << i << "条文法" << endl;
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
	int location;
	location = findMin(wenfa, length);
	spiltWenfa(wenfa, location);
	cout << "最短的文法是" << wenfa[0] << endl;
	/*******************************匹配文法*******************************************************/
	for (int j = 0; j < wenfa[0].length(); j++)
	{
		if (match(wenfa, length, j))//匹配成功则说明这个文法存在回溯，可以提取左因子
		{
			moveStr(wenfa, length, j);
			//cout << wenfa[1]<<endl;
			delStr(wenfa, length);
			newStr[j] = wenfa[0][j];
			newLength++;
			change = true;
		}
	
	}
	/*********************************调整字符串输出********************************************************/
	for (int i = 1; i <= length; i++)
	{
		for (int k = 0; k < wenfa[i].length(); k++)
			if (wenfa[i][k] == NULL) swap(wenfa[i][k], wenfa[i][k + 1]);
	}
	if (change) {
		cout << "消除回溯后的文法如下" << endl;
		for (int i = 0; i < newLength; i++)
		{
			cout << newStr[i];
		}
		for (int i = 1; i <= length; i++)
		{
			cout << wenfa[i];
			if (i != length)
				cout << "|";
			else
				cout << endl;
		}
	}
	else cout << "文法不存在回溯" << endl;
}