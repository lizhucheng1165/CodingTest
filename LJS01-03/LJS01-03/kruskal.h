#pragma once
#include <map>
#include <queue>


class C_KRUSKAL
{
private:
	struct S_NODE
	{
		char cId;
		//차일드도 알아야하고 차일드와의 거리도 같이 저장해야한다
		std::map<S_NODE*, int > child;
		//id로 부모를 저장하면 id로 또 검색해야하니 그냥 포인터로 문다
		S_NODE* pParent;
	};
	//모든 간선을 가져야한다
	struct S_UNION
	{
		S_NODE* p1;
		S_NODE* p2;
		int nLength;
		//우선순위큐를 사용하기 위한 오퍼레이터
		bool operator() (S_UNION s1, S_UNION s2)
		{
			//뒤에가 더 작으면 바꾼다
			return s1.nLength > s2.nLength;
		}
	};

private:
	std::map<char, S_NODE*> m_mapNode;
	std::priority_queue<S_UNION, std::vector<S_UNION>, S_UNION> m_heapNode{};

private:
	S_NODE* FindCreate(char c);
	S_NODE* CreateNode(char c);
	S_NODE* FindParent(S_NODE* pNode);
public:
	C_KRUSKAL() = default;
	void Add(char c1, char c2, int nLength);
	void Print();
	//간선의 최소값을 알아야하니 heap을 사용해야 한다 -> heap이 없어서 stl의 priority Queue를 사용해야 한다
	void Run();
};