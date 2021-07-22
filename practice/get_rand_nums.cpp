/*
思路：

将300000万数据分成5组，每组60000万人，然后从每组中选出20000人作为获奖者。
关键是如何用rand()函数实现0-59999等概论的数。

可以用rand()函数生成0-65535之间的数，然后大于等于60000的数不考虑，
这样得到的数都是在0-59999中，且概率相等。

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
unsigned short int isChoose[60000];

void GetNum()
{
	for (unsigned short int i = 0; i < 60000; i++)
		isChoose[i] = i + 1;
	unsigned short int data;
	unsigned short int index = 60000;
	srand((unsigned int)time(0));
	/*从1-60000中选20000人*/
	for (unsigned short int i = 0; i < 20000; i++)
	{
		do {  //为保证概率相等，大于等于Index的不要
			data = rand();
		} while (data >= index);
		swap(isChoose[data], isChoose[index]); //为了防止重复，将已经选中的号交换到最后
		index--;
	}
	for (unsigned short int i = 0; i < 20000; i++)
		cout << isChoose[60000 - i] << " ";
	cout << endl;

	/*从60001-120000中选20000人*/
	for (unsigned int i = 0; i < 6000; i++)
		isChoose[i] = i + 1;
	index = 60000;
	for (unsigned int i = 0; i < 20000; i++)
	{
		do {  
			//为保证概率相等，大于等于Index的不要
			data = rand();
		} while (data >= index);
		swap(isChoose[data], isChoose[index]);
		index--;
	}
	for (unsigned int i = 0; i < 20000; i++)
		cout << isChoose[60000 - i] + 60000 << " ";
	cout << endl;

	/*从120001-180000中选20000人*/
	for (unsigned int i = 0; i < 6000; i++)
		isChoose[i] = i + 1;
	index = 60000;
	for (unsigned int i = 0; i < 20000; i++)
	{
		do {  
			//为保证概率相等，大于等于Index的不要
			data = rand();
		} while (data >= index);
		swap(isChoose[data], isChoose[index]);
		index--;
	}
	for (unsigned int i = 0; i < 20000; i++)
		cout << isChoose[60000 - i] + 120000 << " ";
	cout << endl;

	/*从180001-240000中选20000人*/
	for (unsigned int i = 0; i < 6000; i++)
		isChoose[i] = i + 1;
	index = 60000;
	for (unsigned int i = 0; i < 20000; i++)
	{
		do {  //为保证概率相等，大于等于Index的不要
			data = rand();
		} while (data >= index);
		swap(isChoose[data], isChoose[index]);
		index--;
	}
	for (unsigned int i = 0; i < 20000; i++)
		cout << isChoose[60000 - i] + 180000 << " ";
	cout << endl;

	/*从240001-300000中选20000人*/
	for (unsigned int i = 0; i < 6000; i++)
		isChoose[i] = i + 1;
	index = 60000;
	for (unsigned int i = 0; i < 20000; i++)
	{
		do {  //为保证概率相等，大于等于Index的不要
			data = rand();
		} while (data >= index);
		swap(isChoose[data], isChoose[index]);
		index--;
	}
	for (unsigned int i = 0; i < 20000; i++)
		cout << isChoose[60000 - i] + 240000 << " ";
	cout << endl;
}

int main(int argc,char ** argv)
{
	GetNum();
	return 0;
}
