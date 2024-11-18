#pragma once
#include <list>

class C_BRIDGE
{
private:
	struct S_NODE
	{
		bool bLand;
		std::list<S_NODE*> child;
		std::list<S_NODE*>::iterator iterNode;
	};
private:
	int	m_arLand[10][10];
	S_NODE m_arNode[10][10];
	std::list<S_NODE*> m_listNode;
	std::list< std::list<S_NODE*>* > m_listLand;

private:
	void findLand(S_NODE *pNode , std::list<S_NODE*>* pLand);

public:
	C_BRIDGE();
	void makeNode();
	void run();
};