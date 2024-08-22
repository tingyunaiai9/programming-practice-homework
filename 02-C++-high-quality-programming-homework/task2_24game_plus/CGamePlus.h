#pragma once

class CGamePlus
{
private:
	int m_cardNum;
	long long m_target;
	long long m_minLarger = LLONG_MAX;
	const long long m_rangeMin = 1;
	const long long m_rangeMax = LLONG_MAX;

	const vector<string> m_operators = { "+", "*" };

	vector<string> m_cards;
	set<string> m_results;

	bool m_hasResult = false;
	bool m_hasLarger = false;

public:
	CGamePlus();
	~CGamePlus();

	bool play();

private:
	bool is_degital(const string& str);

	bool get_inputs();
	bool find_results();
	bool search(vector<string> cur_combine);
	bool check_result(const string& formula);
};

