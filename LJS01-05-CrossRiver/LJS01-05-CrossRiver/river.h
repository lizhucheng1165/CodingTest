#pragma once

#include <stdio.h>

class C_RIVER
{
private:
	enum
	{
		E_CABBAGE	= 0x01,
		E_SHEEP		= 0x02,
		E_WOLF		= 0x04,
		E_FARMER	= 0x08,
		E_BOAT		= 0x10,
		E_MAX		= 0x20
	};
	bool m_arMove[E_MAX];
	bool m_arVisit[E_MAX];

private:
	void Move(int nData);
	void Print(int nData);
public:
	C_RIVER() = default;
	void Init();
	void Run();
};