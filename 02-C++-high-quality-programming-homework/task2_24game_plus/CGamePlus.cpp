#include "pch.h"

#include "CGamePlus.h"
#include "CFormula.h"

CGamePlus::CGamePlus()
{
	m_cards.clear();
	m_results.clear();
}

CGamePlus::~CGamePlus()
{
}

bool CGamePlus::play()
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

bool CGamePlus::is_degital(const string& str)
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

bool CGamePlus::get_inputs()
{
	bool bRet = true;
	//cout << "Please input the number of cards: " << endl;
	cin >> m_cardNum;
	//cout << "Please input the target number: " << endl;
	cin >> m_target;
	
	m_cards.clear();
	string card;
	//cout << "Please input " << m_cardNum <<" cards: " << endl;
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

bool CGamePlus::find_results()
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
		cout << "No" << endl;
		if (false == m_hasLarger)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << m_minLarger << endl;
		}
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

bool CGamePlus::search(vector<string> cur_combine)
{
	bool bRet = true;

	if (m_hasResult)
	{
		return bRet;
	}

	if (cur_combine.size() == 1)
	{
		bRet = check_result(cur_combine[0]);
		return bRet;
	}

	int size = cur_combine.size();

	// pick the first two elements from cur_combine to combine
	vector<string> next_combine;
	for (int k = 2; k < size; k++)
	{
		next_combine.push_back(cur_combine[k]);
	}

	for (auto op : m_operators)
	{
		next_combine.insert(next_combine.begin(), 
							cur_combine[0] + op + cur_combine[1]);
		search(next_combine);
		next_combine.erase(next_combine.begin());
	}

	return bRet;
}

bool CGamePlus::check_result(const string& formula)
{
	bool bRet = true;

	CFormula* pFormula = nullptr;
	pFormula = new CFormula();

	if (!pFormula)
	{
		cout << "Failed to create CFormula instance." << endl;
		return false;
	}

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
		m_results.insert(formula);
		m_hasResult = true;
	}
	else if (result > m_target)
	{
		m_hasLarger = true;
		m_minLarger = min(m_minLarger, (int)result);
	}

	SAFE_DELETE(pFormula);
	return bRet;
}

