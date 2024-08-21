#include "pch.h"

#include "CGame.h"
#include "CFormula.h"

CGame::CGame()
{
	m_cards.clear();
	m_results.clear();
}

CGame::~CGame()
{
}

bool CGame::play()
{
	bool bRet = true;
	
	bRet = get_inputs();
	if (false == bRet)
	{
		return bRet;
	}

	bRet = find_results();
	if (false == bRet)
	{
		return bRet;
	}

	return bRet;
}

bool CGame::is_degital(const string& str)
{
	if (str.empty())
	{
		return false;
	}

	for (int i = 0; i < str.size(); i++)
	{
		if (i == 0 && str.at(i) == '-' && str.size() > 1)
			continue;
		if (str.at(i) > '9' || str.at(i) < '0')
			return false;
	}

	return true;
}

bool CGame::get_inputs()
{
	bool bRet = true;
	//cout << "Please input " << m_cardNum <<" cards: " << endl;

	m_cards.clear();
	string card;
	for (int i = 0; i < m_cardNum; i++)
	{
		cin >> card;
		if (!is_degital(card))
		{
			cout << "Invalid input: " << card << endl;
			return false;
		}

		m_cards.push_back(card);
	}

	return bRet;
}

bool CGame::find_results()
{
	bool bRet = true;
	bRet = search(m_cards);
	if (false == bRet)
	{
		cout << "Failed to search results." << endl;
		return bRet;
	}

	if (false == m_hasResult)
	{
		cout << "no" << endl;
	}
	else
	{
		for (auto& result : m_results)
		{
			cout << result << endl;
		}
	}
	return bRet;
}

bool CGame::search(vector<string> cur_combine)
{
	bool bRet = true;

	if (cur_combine.size() == 1)
	{
		CFormula* pFormula = nullptr;
		pFormula = new CFormula();

		if (!pFormula)
		{
			cout << "Failed to create CFormula instance." << endl;
			return false;
		}

		string formula = cur_combine[0];
		bRet = pFormula->load_formula(formula);
		if (false == bRet)
		{
			cout << "Failed to load formula." << endl;
			SAFE_DELETE(pFormula);
			return false;
		}

		bRet = pFormula->calc_formula();
		if (false == bRet)
		{
			cout << "Failed to calculate formula." << endl;
			SAFE_DELETE(pFormula);
			return false;
		}

		double result = pFormula->get_result();
		if (abs(result - m_target) < 0.0001)
		{
			// check if the result is already in the results
			if (find(m_results.begin(), m_results.end(), formula) != m_results.end())
			{
				SAFE_DELETE(pFormula);
				return bRet;
			}
			else
			{
				m_results.push_back(formula);
				m_hasResult = true;
			}
		}

		SAFE_DELETE(pFormula);
		return bRet;
	}

	int size = cur_combine.size();

	// pick two elements from cur_combine to combine
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j) // same card
			{
				continue;
			}

			vector<string> next_combine;
			for (int k = 0; k < size; k++)
			{
				if (k != i && k != j)
				{
					next_combine.push_back(cur_combine[k]);
				}
			}

			// add the new element to the next_combine
			for (auto op : m_operators)
			{
				next_combine.push_back("(" + cur_combine[i] + op + cur_combine[j] + ")");
				search(next_combine);
				next_combine.pop_back();
			}
		}
	}

	return bRet;
}

