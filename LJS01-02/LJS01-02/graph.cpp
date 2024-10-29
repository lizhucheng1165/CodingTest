#include <queue>
#include "graph.h"

C_GRAPH::S_NODE* C_GRAPH::Create(int nId)
{
	S_NODE* pNode = new S_NODE{};
	pNode->nId = nId;
	pNode->bVisit = false;
	return pNode;
}

C_GRAPH::S_NODE* C_GRAPH::FindCreate(int nId)
{
	auto pairResult = m_mapNode.insert({ nId, nullptr }); //auto는 선언시에 결정됨 / insert시 값이 있으면 값을 가리키는 iter와 성공실패유무 bool값을 묶은 pair를 준다 / 값이 없으면 만들고 그 iter를 줌
	
	if (pairResult.second) // 없으니 집어넣음
	{
		pairResult.first->second = Create(nId);
	}

	return pairResult.first->second;
}

//void C_GRAPH::DFS(int nId)
//{
//	auto findResult = m_mapNode.find(nId);
//	DFSRecursive(findResult->second);
//	for (auto iter : m_mapNode)
//	{
//		iter.second->bVisit = false;
//	}
//	printf("\n");
//}

//void C_GRAPH::DFSRecursive(S_NODE* pNode)
//{
//	if (!pNode || pNode->bVisit)
//	{
//		return;
//	}
//
//	pNode->bVisit = true;
//	printf("%d ", pNode->nId);
//
//	for (auto iter : pNode->listChild)
//	{
//		DFSRecursive(iter);
//	}
//}

void C_GRAPH::DFS(int nId)
{
	auto iterFind = m_mapNode.find(nId);
	if (iterFind == m_mapNode.end())
	{
		return;
	}

	DFSRecursive(iterFind->second);
	printf("\n");
}

//void C_GRAPH::BFS(int nId)
//{
//	std::queue<S_NODE*> queNode{};
//
//	auto Find = m_mapNode.find(nId);
//	queNode.push(Find->second);
//	Find->second->bVisit = true;
//
//	while (!queNode.empty())
//	{
//		int nCount = (int)queNode.size();
//		for (int i = 0; i < nCount; i++)
//		{
//			S_NODE* pNode = queNode.front();
//			queNode.pop();
//			printf("%d ", pNode->nId);
//
//			for (auto node : pNode->listChild)
//			{
//				if (!node->bVisit)
//				{
//					queNode.push(node);
//					node->bVisit = true;
//				}
//			}
//
//		}
//		printf("/ ");
//	}
//
//
//}

void C_GRAPH::BFS(int nId)
{
	auto iterFind = m_mapNode.find(nId);
	if (iterFind == m_mapNode.end())
	{
		return;
	}

	std::queue<S_NODE*> queNode{};
	iterFind->second->bVisit = true; //방문체크
	queNode.push(iterFind->second);

	while (!queNode.empty())
	{
		size_t nLength = queNode.size();//꺼낼때마다 사이즈가 바뀌므로 백업
		for (int i = 0; i < nLength; i++)
		{
			S_NODE* pNode = queNode.front();
			queNode.pop();

			printf("%d ", pNode->nId);

			for (S_NODE* pChild : pNode->listChild)
			{
				if (!pChild->bVisit)
				{
					queNode.push(pChild);
					pChild->bVisit = true;
				}

			}
			
		}
		printf(" / ");
	}
}

void C_GRAPH::DFSRecursive(S_NODE* pNode)
{
	if (pNode->bVisit)
	{
		return;
	}

	pNode->bVisit = true;
	printf("%d ", pNode->nId);

	for (S_NODE* pChild : pNode->listChild)
	{
		DFSRecursive(pChild);
	}
}

void C_GRAPH::Add(int nDst, int nSrc)
{
	S_NODE* pDst = FindCreate(nDst);
	S_NODE* pSrc = FindCreate(nSrc);

	pDst->listChild.push_back(pSrc);
	pSrc->listChild.push_back(pDst);
}


void C_GRAPH::Print()
{
	for (auto iter : m_mapNode) //자동순회 foreach
	{
		printf("%d : ", iter.first);
		for (S_NODE* pChild : iter.second->listChild)
		{
			printf("%d ", pChild->nId);
		}
		printf("\n");
	}
}
