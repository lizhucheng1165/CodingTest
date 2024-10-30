#include "kruskal.h"

C_KRUSKAL::S_NODE* C_KRUSKAL::FindCreate(char c)
{
	auto pairResult = m_mapNode.insert({ c, nullptr });
	if (pairResult.second)
	{
		pairResult.first->second = CreateNode(c);
	}

	return pairResult.first->second;
}

C_KRUSKAL::S_NODE* C_KRUSKAL::CreateNode(char c)
{
	S_NODE* pNode = new S_NODE{};
	pNode->cId = c;
	//�⺻ �θ�� �ڱ� �ڽ�
	pNode->pParent = pNode;

	return pNode;
}

C_KRUSKAL::S_NODE* C_KRUSKAL::FindParent(S_NODE* pNode)
{
	if (pNode == pNode->pParent)
	{
		return pNode;
	}
	return FindParent(pNode->pParent);

}

void C_KRUSKAL::Add(char c1, char c2, int nLength)
{
	S_NODE* p1 = FindCreate(c1);
	S_NODE* p2 = FindCreate(c2);
	p1->child.insert({ p2, nLength });
	p2->child.insert({ p1, nLength });

	m_heapNode.push({ p1, p2, nLength });
}

void C_KRUSKAL::Print()
{
	for (auto iter : m_mapNode)
	{
		printf("id : %c :", iter.first);
		for(auto child : iter.second->child)
		{
			printf("(%c : %d)", child.first->cId ,child.second);
		}
		printf("\n");
	}
}

void C_KRUSKAL::Run()
{
	while (!m_heapNode.empty())
	{
		S_UNION sUnion = m_heapNode.top();
		m_heapNode.pop();
		//ũ�罺Į �˰��� �ڸ�
		S_NODE* pParent1 = FindParent(sUnion.p1);
		S_NODE* pParent2 = FindParent(sUnion.p2);

		//�ΰ��� �θ� ��
		//�θ� ������ �н�
		//�θ� �ٸ��� �����༮�� �θ��� ���ʿ� �����Ѵ�
		//if (sUnion.p1->pParent->cId != sUnion.p2->pParent->cId)
		if (pParent1->cId != pParent2->cId)
		{
			//S_NODE* pParent = sUnion.p1->pParent;
			//if (sUnion.p1->pParent->cId > sUnion.p2->pParent->cId)
			//{
			//	pParent = sUnion.p2->pParent;
			//}

			//sUnion.p1->pParent = pParent;
			//sUnion.p2->pParent = pParent;

			//printf("%c, %c, %d\n", sUnion.p1->cId, sUnion.p2->cId, sUnion.nLength);

			printf("%c, %c, %d\n", sUnion.p1->cId, sUnion.p2->cId, sUnion.nLength);
			

			S_NODE* pNewParent = pParent1;
			if (pParent2->cId < pParent2->cId)
			{
				pNewParent = pParent2;
			}

			sUnion.p1->pParent = pNewParent;
			sUnion.p2->pParent = pNewParent;
		}



	}
}
