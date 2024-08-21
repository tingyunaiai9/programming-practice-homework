#include "pch.h"

#include "CGame.h"
#include "CFormula.h"

void play24()
{
	CGame* pGame = nullptr;
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
}

void test()
{
	CFormula* pFormula = nullptr;
	pFormula = new CFormula();

	if (pFormula)
	{
		string formula = "";
		cin >> formula;
		pFormula->load_formula(formula);
		SAFE_DELETE(pFormula);
	}
	else
	{
		cout << "Failed to create CFormula instance." << endl;
	}
}

int main()
{
	//play24();
	test();

	return 0;
}