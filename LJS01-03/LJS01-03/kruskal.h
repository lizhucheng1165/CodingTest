#pragma once
#include <map>
#include <queue>


class C_KRUSKAL
{
private:
	struct S_NODE
	{
		char cId;
		//���ϵ嵵 �˾ƾ��ϰ� ���ϵ���� �Ÿ��� ���� �����ؾ��Ѵ�
		std::map<S_NODE*, int > child;
		//id�� �θ� �����ϸ� id�� �� �˻��ؾ��ϴ� �׳� �����ͷ� ����
		S_NODE* pParent;
	};
	//��� ������ �������Ѵ�
	struct S_UNION
	{
		S_NODE* p1;
		S_NODE* p2;
		int nLength;
		//�켱����ť�� ����ϱ� ���� ���۷�����
		bool operator() (S_UNION s1, S_UNION s2)
		{
			//�ڿ��� �� ������ �ٲ۴�
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
	//������ �ּҰ��� �˾ƾ��ϴ� heap�� ����ؾ� �Ѵ� -> heap�� ��� stl�� priority Queue�� ����ؾ� �Ѵ�
	void Run();
};