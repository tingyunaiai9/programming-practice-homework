#pragma once

class CGame
{
private:
	const int m_cardNum = 4;
	const int m_target = 24;
	const int m_rangeMin = 1;
	const int m_rangeMax = 13;

	const vector<string> m_operators = { "+", "-", "*", "/" };

	vector<string> m_cards;
	vector<string> m_results;

	bool m_hasResult = false;

public:
	CGame();
	~CGame();

	bool play();

private:
	bool is_degital(const string& str);

	bool get_inputs();
	bool find_results();
	bool search(vector<string> cur_combine);
};

