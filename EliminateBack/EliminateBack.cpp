#include<iostream>
#include<string>
using namespace std;

/**********************Ѱ������ַ�����λ��**********************************************/
int findMin(string wenfa[], int n)//nΪ�ķ�����,wenfa[0]���ƥ����ַ�
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
/**********************��������ַ��������***************************************/
void spiltWenfa(string wenfa[],int location)//locationΪ��Ҫ��ֵ�λ��
{	 
	wenfa[0] = wenfa[location];
}


/***********************Ѱ��ƥ���ַ���*******************************************/

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

/***************************�ƶ�ƥ���ַ�������һλ��׼����ȡ������*******************************/
void moveStr(string wenfa[],int n,int i)//iΪwenfa[0]�Ķ�λֵ
{
	for (int no = 1; no <= n; no++)
	{
		size_t k = wenfa[no].find(wenfa[0][i]);//kΪwenfa[no]��ƥ���ַ�����λ��
		swap(wenfa[no][k], wenfa[no][0]);//���ķ�ƥ����ַ�����������һ��λ��
	}
}
/*************************��ȡ������,����*************************************************/
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
	cout << "�������ķ�������" << endl;
	cin >> length;
	/******************************�ķ����뵥Ԫ,ȷ��������****************************************/
	for (int i = 1; i <= length; i++)
	{
		cout << "�������" << i << "���ķ�" << endl;
		cin >> wenfa[i];
	}
	cout << "ԭʼ�ķ���";
	for (int i = 1; i <= length; i++)
	{
		cout << wenfa[i];
		if (i != length)
			cout << "|";
		else
			cout << endl;
	}
	/*******************************�ķ�����*******************************************************/
	int location;
	location = findMin(wenfa, length);
	spiltWenfa(wenfa, location);
	cout << "��̵��ķ���" << wenfa[0] << endl;
	/*******************************ƥ���ķ�*******************************************************/
	for (int j = 0; j < wenfa[0].length(); j++)
	{
		if (match(wenfa, length, j))//ƥ��ɹ���˵������ķ����ڻ��ݣ�������ȡ������
		{
			moveStr(wenfa, length, j);
			//cout << wenfa[1]<<endl;
			delStr(wenfa, length);
			newStr[j] = wenfa[0][j];
			newLength++;
			change = true;
		}
	
	}
	/*********************************�����ַ������********************************************************/
	for (int i = 1; i <= length; i++)
	{
		for (int k = 0; k < wenfa[i].length(); k++)
			if (wenfa[i][k] == NULL) swap(wenfa[i][k], wenfa[i][k + 1]);
	}
	if (change) {
		cout << "�������ݺ���ķ�����" << endl;
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
	else cout << "�ķ������ڻ���" << endl;
}