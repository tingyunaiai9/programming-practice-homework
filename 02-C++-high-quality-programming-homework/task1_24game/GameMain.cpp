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
	bool bRet = true;

	CFormula* pFormula = nullptr;
	pFormula = new CFormula();

	if (pFormula)
	{
		string formula = "";
		cin >> formula;
		bRet = pFormula->load_formula(formula);
		if (false == bRet)
		{
			cout << "Failed to load formula." << endl;
			SAFE_DELETE(pFormula);
		}

		bRet = pFormula->calc_formula();
		if (false == bRet)
		{
			cout << "Failed to calculate formula." << endl;
			SAFE_DELETE(pFormula);
		}

		cout << "result: " << pFormula->get_result() << endl;
		SAFE_DELETE(pFormula);
	}
	else
	{
		cout << "Failed to create CFormula instance." << endl;
	}
}

int main()
{
	_CrtDumpMemoryLeaks();
	//play24();
	test();

	return 0;
}