#include "mountain.h"
void C_MOUNTAIN::Parser(const char* strToken, std::list<int>& listData)
{
	while (*strToken != ']')
	{
		if (*strToken >= '0' && *strToken <= '9')
		{
			//printf("%d\n",MakeInt(strToken));
			listData.push_back(MakeInt(strToken));
		}
		else
		{
			strToken++;
		}
	}


	//char strNum[10] = "44332";
	//const char* p = strNum;
	//printf("%d\n", MakeInt(p));
}
int C_MOUNTAIN::MakeInt(const char*& str)
{
	int nData{}; //0�� ���� int�� ��ȯ�� �� �ִ�
	while (*str >= '0' && *str <= '9')
	{
		nData = nData * 10 + (*str - '0');
		str++;
	}

	return nData;
}
void C_MOUNTAIN::Paths(const char* strPath)
{
	while (*strPath != '\0')
	{

	}




	//char strTest[64] = "[1,245,3,12, 51,4]"; // �� ���� �����͸� ���� �� �ֵ��� �켱 �۾� ���ȣ ������ �ε���� ���ȣ ������ �ε� ��
	//char strTest[64] = "[1,2,3,4],[5,6,7]";

	//std::list<int> listData{};
	//Parser(strTest, listData);
	//for (int nData : listData)
	//{
	//	printf("%d ", nData);
	//}
	//printf("\n");
}
void C_MOUNTAIN::Gates(const char* strPath)
{
}
void C_MOUNTAIN::Summits(const char* strPath)
{
}
