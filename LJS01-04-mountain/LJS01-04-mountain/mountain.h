#pragma once

#include <stdio.h>
#include <list>	
class C_MOUNTAIN
{
private:
	void Parser(const char * strToken, std::list<int> &listData);
	int MakeInt(const char*& str); //�����͸� �Ѱ� int�� �о��ֶ�� �ϸ� ������ ��ġ ����ġ�� �Ͼ �� ������ &�� ������
public:
	C_MOUNTAIN() = default;
	void Paths(const char* strPath);
	void Gates(const char* strPath);
	void Summits(const char* strPath);

};