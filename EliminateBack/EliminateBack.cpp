#include<iostream>
#include<string>
using namespace std;

/**********************Ѱ������ַ�����λ��**********************************************/
int findMin(string wenfa[], int n)//nΪ�ķ�����,wenfa[0]���ƥ����ַ�
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
/**********************��������ַ��������***************************************/
void spiltWenfa(string wenfa[],int i,int location)//iΪ��Ҫ��ֵ�λ��
{	
	wenfa[0] = wenfa[location].at[i];
}


/***********************Ѱ��ƥ���ַ���*******************************************/

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