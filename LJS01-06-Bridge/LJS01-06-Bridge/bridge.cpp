#include <queue>
#include "bridge.h"

C_BRIDGE::C_BRIDGE() : m_arLand
{
{1,1,1,0,0,0,0,1,1,1},
{1,1,1,1,0,0,0,0,1,1},
{1,0,1,1,0,0,0,0,1,1},
{0,0,1,1,1,0,0,0,0,1},
{0,0,0,1,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,1,0,0,0,0},
{0,0,0,0,1,1,1,0,0,0},
{0,0,0,0,0,0,0,0,0,0}
},
m_arNode{}
{
}

void C_BRIDGE::makeNode()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m_arNode[i][j].bLand = m_arLand[i][j];
			//m_listNode.push_front(&m_arNode[i][j]);
			//m_arNode[i][j].iterNode = m_listNode.begin();
			m_listNode.push_back(&m_arNode[i][j]);
			auto iter = m_listNode.end();
			iter--;
			m_arNode[i][j].iterNode = iter;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int arMove[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };
			for (int k = 0; k < 4; k++)
			{
				int nY = i + arMove[k][0];
				int nX = j + arMove[k][1];
				if (nY >= 0 && nY < 10 && nX >= 0 && nX < 10)
					m_arNode[i][j].child.push_back(&m_arNode[nY][nX]);
			}
		}
	}
}

void C_BRIDGE::findLand(S_NODE* pNode, std::list<S_NODE*>* pLand)
{
	if (pNode->iterNode == m_listNode.end())
		return;

	pLand->push_back(pNode);
	m_listNode.erase(pNode->iterNode);
	pNode->iterNode = m_listNode.end();
	for (S_NODE* pChild : pNode->child)
	{
		findLand(pChild, pLand);
	}
}

void C_BRIDGE::Print()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d ", m_arNode[i][j].nTest);
		}
		printf("\n");
	}
}

void C_BRIDGE::run()
{
	auto iter = m_listNode.begin();
	while (iter != m_listNode.end())
	{
		if (!(*iter)->bLand)
		{
			(*iter)->iterNode = m_listNode.end();
			iter = m_listNode.erase(iter);
		}
		else
			iter++;
	}

	while (!m_listNode.empty())
	{
		std::list<S_NODE*>* pLand = new std::list<S_NODE*>{};
		findLand(*m_listNode.begin(), pLand);
		m_listLand.push_back(pLand);
	}

	for (auto iterLand : m_listLand)
	{
		std::queue<S_NODE*> queNode{};
		for (S_NODE* pNode : *iterLand)
		{
			for (S_NODE* pChild : pNode->child)
			{
				if (!pChild->bLand && !pChild->bVisit)
				{
					queNode.push(pChild);
					pChild->bVisit = true;
					pChild->nTest = 9;
				}
			}
		}


		int nStep{};
		while (!queNode.empty())
		{
			nStep++;
			size_t nSize = queNode.size();
			for (size_t i = 0; i < nSize; i++)
			{
				S_NODE* pNode = queNode.front();
				queNode.pop();
				pNode->nTest = nStep;
				for (S_NODE* child : pNode->child)
				{
					if (!child->bLand && !child->bVisit)
					{
						queNode.push(child);
						child->bVisit = true;
					}
				}
			}
		}

		break;
	}
	Print();
}
