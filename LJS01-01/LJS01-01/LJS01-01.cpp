﻿// LJS01-01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "graph.h"

int main()
{
	C_GRAPH cGraph{};
	//cGraph.DFS(1);
	cGraph.BFS(1);
}
