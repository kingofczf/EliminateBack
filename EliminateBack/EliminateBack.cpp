#include<iostream>
#include<string>
using namespace std;

/**********************寻找最短字符串的位置**********************************************/
int findMin(string wenfa[], int n)//n为文法数量,wenfa[0]存放匹配的字符
{
	int location;
	int minLength = wenfa[1].length;
	for (int i = 1; i < n; i++)
	{
		
		if(minLength>=wenfa[i].length)
		{
			minLength = wenfa[i].length;
			location = i;
		}
	}
		return location;
}
/**********************复制最短字符串，拆解***************************************/
void spiltWenfa(string wenfa[],int i,int location)//i为需要拆分的位置
{	
	wenfa[0] = wenfa[location].at[i];
}


/***********************寻找匹配字符串*******************************************/

bool match(string wenfa[],int n,int location)
{
	int count = 0;
	for (int no = 1; no < n; no++)
	{
		for (int num = 0; num < wenfa[no].length; num++)
		{
			if (wenfa[0] == wenfa[no].at[num])
				count++;
		}
	}
	if (count == n) return true;
	else false;
}

void main()
{

}