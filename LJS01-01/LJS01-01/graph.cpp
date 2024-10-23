#include "graph.h"

C_GRAPH::C_GRAPH() :
	m_arVisit{},
	m_arNode{
		{0,0,0,0,0,0,0,0,0},
		{0,0,1,1,0,0,0,0,0},
		{0,1,0,1,1,1,0,0,0},
		{0,1,1,0,0,1,0,1,1},
		{0,0,1,0,0,1,0,0,0},
		{0,0,1,1,1,0,1,0,0},
		{0,0,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,0,1},
		{0,0,0,1,0,0,0,1,0} }
{

}

void C_GRAPH::DFS(int nNode)
{
	if (m_arVisit[nNode]) //방문했다면 중지
	{
		return;
	}

	m_arVisit[nNode] = true;
	printf("%d ", nNode);

	for (int i = 0; i < 9; i++)
	{
		if (m_arNode[nNode][i] == 1)
		{
			DFS(i);
		}
	}
}

void C_GRAPH::BFS(int nNode)
{
	
	std::queue<int> queIndex{};

	queIndex.push(nNode);
	m_arVisit[nNode] = true; //방문체크



	while (!queIndex.empty()) // 비어있지 않은동안
	{
		int nCount = (int)queIndex.size();
		for (int i = 0; i < nCount; i++)
		{
			int nIndex = queIndex.front();
			queIndex.pop();
			printf("%d ", nIndex);
			//m_arVisit[nIndex] = true;

			for (int j = 0; j < 9; j++)
			{
				if (m_arNode[nIndex][j] == 1 && !m_arVisit[j])
				{
					queIndex.push(j);
					m_arVisit[j] = true;
				}
			}
		}
		printf("| ");
	}

}
