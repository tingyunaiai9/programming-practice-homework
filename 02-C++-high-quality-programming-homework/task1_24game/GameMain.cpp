#include "pch.h"

#include "CGame.h"

int main()
{
	CGame* pGame = NULL;
	pGame = new CGame();

	if (pGame)
	{
		pGame->play();
		SAFE_DELETE(pGame);
	}
	else
	{
		cout << "Failed to create CGame instance." << endl;
	}

	return 0;
}