#include<iostream>
#include<string>
using namespace std;

/**********************Ѱ������ַ�����λ��**********************************************/
int findMin(string wenfa[], int n)//nΪ�ķ�����,wenfa[0]���ƥ����ַ�
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
/**********************��������ַ��������***************************************/
void spiltWenfa(string wenfa[],int i,int location)//iΪ��Ҫ��ֵ�λ��
{	
	wenfa[0] = wenfa[location];
}


/***********************Ѱ��ƥ���ַ���*******************************************/

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

/***************************�ƶ�ƥ���ַ�������һλ��׼����ȡ������*******************************/
void moveStr(string wenfa[],int n,int i)//iΪwenfa[0]�Ķ�λֵ
{
	for (int no = 1; no < n; no++)
	{
		size_t k = wenfa[no].find(wenfa[0][i]);//kΪwenfa[no]��ƥ���ַ�����λ��
		swap(wenfa[no][k], wenfa[no][0]);//���ķ�ƥ����ַ�����������һ��λ��
	}
}
/*************************��ȡ������*************************************************/
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
	cout << "�������ķ�������" << endl;
	cin >> length;
/******************************�ķ����뵥Ԫ,ȷ��������****************************************/
	for (int i = 1; i <= length; i++)
	{
		cout << "�������"<<i<<"���ķ�" << endl;
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
	int location = 0;
	location = findMin(wenfa, length);
	for (int no = 0; no < wenfa[location].length(); no++)
	{
		spiltWenfa(wenfa, no, location);
	//	cout <<wenfa[0];//��̵��ķ�
	}
/*******************************ƥ���ķ�*******************************************************/
	for(int j=0;j<wenfa[0].length();j++)
		for (int i = 0; i < wenfa[0].length(); i++) {
			if (match(wenfa, length, j))//ƥ��ɹ���˵������ķ����ڻ��ݣ�������ȡ������
			{
				moveStr(wenfa, length, i);
				delStr(wenfa, length);
				newStr[i] = wenfa[0][i];
			}
		}
	//cout << newStr[0]<<newStr[1];
	cout << wenfa[1];
	
}