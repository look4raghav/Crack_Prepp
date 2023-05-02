#include <bits/stdc++.h>
using namespace std;
bool isOperator(char op)
{
	return (op == '+' || op == '-' || op == '*');
}
vector<int> possibleResultUtil(string input,
			map< string, vector<int> > memo)
{
	if (memo.find(input) != memo.end())
		return memo[input];
	vector<int> res;
	for (int i = 0; i < input.size(); i++)
	{
		if (isOperator(input[i]))
		{
			vector<int> resPre =
			possibleResultUtil(input.substr(0, i), memo);
			vector<int> resSuf =
			possibleResultUtil(input.substr(i + 1), memo);
			for (int j = 0; j < resPre.size(); j++)
			{
				for (int k = 0; k < resSuf.size(); k++)
				{
					if (input[i] == '+')
						res.push_back(resPre[j] + resSuf[k]);
					else if (input[i] == '-')
						res.push_back(resPre[j] - resSuf[k]);
					else if (input[i] == '*')
						res.push_back(resPre[j] * resSuf[k]);
				}
			}
		}
	}
	if (res.size() == 0)
		res.push_back(atoi(input.c_str()));
	memo[input] = res;
	return res;
}
vector<int> possibleResult(string input)
{
	map< string, vector<int> > memo;
	return possibleResultUtil(input, memo);
}
int main()
{
	string input = "1 + 3 − 2 − 5 + 1 − 6 + 7";
	vector<int> res = possibleResult(input);

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}
