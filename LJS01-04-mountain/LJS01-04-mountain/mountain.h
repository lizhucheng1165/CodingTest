#pragma once

#include <stdio.h>
#include <list>	
class C_MOUNTAIN
{
private:
	void Parser(const char * strToken, std::list<int> &listData);
	int MakeInt(const char*& str); //포인터를 넘겨 int를 읽어주라고 하면 포인터 위치 불일치가 일어날 수 있으니 &로 보낸다
public:
	C_MOUNTAIN() = default;
	void Paths(const char* strPath);
	void Gates(const char* strPath);
	void Summits(const char* strPath);

};