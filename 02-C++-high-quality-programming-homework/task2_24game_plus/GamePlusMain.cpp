#include "pch.h"

#include "CGamePlus.h"
#include "CFormula.h"

void play24_plus()
{
	CGamePlus* pGame = nullptr;
	pGame = new CGamePlus();

	if (pGame)
	{
		pGame->play();
		SAFE_DELETE(pGame);
	}
	else
	{
		cout << "Failed to create CGamePlus instance." << endl;
	}
}

int main()
{
	_CrtDumpMemoryLeaks();
	play24_plus();

	return 0;
}