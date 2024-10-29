#pragma once

#include <stdio.h>	
#include <queue>

class C_GRAPH
{
private:
	int m_arNode[9][9];
	bool m_arVisit[9];
public:
	C_GRAPH();
	void DFS(int nNode);
	void BFS(int nNode);
};