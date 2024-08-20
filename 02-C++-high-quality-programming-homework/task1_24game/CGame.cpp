#include "pch.h"

#include "CGame.h"

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
	
	bRet = getInputs();
	if (false == bRet)
	{
		return bRet;
	}

	bRet = findResults();
	if (false == bRet)
	{
		return bRet;
	}

	return bRet;
}

bool CGame::isDegital(const string& str)
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

bool CGame::getInputs()
{
	bool bRet = true;
	//cout << "Please input " << m_cardNum <<" cards: " << endl;

	m_cards.clear();
	string card;
	for (int i = 0; i < m_cardNum; i++)
	{
		cin >> card;
		if (!isDegital(card))
		{
			cout << "Invalid input: " << card << endl;
			return false;
		}

		m_cards.push_back(card);
	}

	return bRet;
}

bool CGame::findResults()
{
	bool bRet = true;
	bRet = search(m_cards);

	return bRet;
}

bool CGame::search(vector<string> cur_combine)
{
	bool bRet = true;

	if (cur_combine.size() == 1)
	{
		// todo: calculate the result
		cout << cur_combine[0] << endl;
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