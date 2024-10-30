// LJS01-03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "kruskal.h"

int main()
{
	C_KRUSKAL cKruskal{};

	cKruskal.Add('a', 'b', 3);
	cKruskal.Add('a', 'i', 7);
	
	cKruskal.Add('b', 'i', 6);
	cKruskal.Add('b', 'c', 5);

	cKruskal.Add('c', 'h', 4);
	cKruskal.Add('c', 'g', 6);
	cKruskal.Add('c', 'f', 8);
	cKruskal.Add('c', 'd', 9);

	cKruskal.Add('d', 'f', 12);
	cKruskal.Add('d', 'e', 9);

	cKruskal.Add('e', 'f', 10);

	cKruskal.Add('f', 'g',2);

	cKruskal.Add('g', 'i',11);

	cKruskal.Add('h', 'i',7);

	cKruskal.Print();
	cKruskal.Run();

}

