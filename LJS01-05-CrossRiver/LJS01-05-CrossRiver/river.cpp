#include "river.h"


void C_RIVER::Init()
{
	for (int i = 0; i < E_MAX; i++)
	{
		m_arMove[i] = true;
        m_arVisit[i] = false;
	}

	m_arMove[E_CABBAGE | E_SHEEP] = false;
	m_arMove[E_WOLF | E_SHEEP] = false;
	m_arMove[E_WOLF | E_SHEEP | E_CABBAGE] = false;
}

void C_RIVER::Run()
{
	Move(E_BOAT | E_FARMER | E_SHEEP | E_CABBAGE | E_WOLF);
}

void C_RIVER::Move(int nData)
{

	if (m_arVisit[nData])
	{
		return;
	}

	m_arVisit[nData] = true;
	Print(nData);


	for (int i = 0; i <= 3; i++)
	{

		if (nData & E_FARMER >> i)
		{
			int nMove = E_FARMER | E_BOAT | (E_FARMER >> i);
			if (m_arMove[nData ^ nMove])
			{
				Move(~(nData ^ nMove));
			}
		}
	}

}

void C_RIVER::Print(int nData)
{
	if (nData & E_BOAT)
	{
		printf("¹è ");
	}
	if (nData & E_FARMER)
	{
		printf("³óºÎ ");
	}
	if (nData & E_WOLF)
	{
		printf("´Á´ë ");
	}
	if (nData & E_CABBAGE)
	{
		printf("¾ç¹èÃß ");
	}
	if (nData & E_SHEEP)
	{
		printf("¾ç ");
	}
	printf("\n");
}

