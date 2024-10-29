#pragma once

#include <map>	
#include <list>	

class C_GRAPH
{
private:
	struct S_NODE
	{
		int nId;
		std::list<S_NODE*> listChild;
		bool bVisit;
	};

private:
	std::map<int, S_NODE*> m_mapNode;

private:
	S_NODE* Create(int nId);
	S_NODE* FindCreate(int nId); //찾았는데 없으면 만든다
	void DFSRecursive(S_NODE* pNode);

public:
	C_GRAPH() = default;
	void Add(int nDst, int nSrc);
	void DFS(int nId);
	void BFS(int nId);
	void Print();

};