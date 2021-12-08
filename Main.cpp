#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

void lowerstring(string& str)
{
	size_t size = str.length();
	for (int i = 0; i < size; ++i)
	{
		str[i] = tolower(str[i]);
	}
}

int main()
{
	
	cout << "Enter string: \n";

	string str;
	getline(cin, str);

	int strlen = str.length();

	if (strlen == 0) { cout << "String Is Empty!\n";  return 0; }

	lowerstring(str);

	vector<tuple<char, bool,vector<int>>> chars; 
	chars.reserve(strlen);
	
	for (int i1 = 0; i1 < strlen; ++i1)
	{
		char currchar = str[i1];

		int vecsize = chars.size();
		bool finded = false;
		for (int i2 = 0; i2 < vecsize; ++i2)
		{
			if (get<0>(chars[i2]) == currchar)
			{
				get<1>(chars[i2]) = true;
				get<2>(chars[i2]).push_back(i1);
				finded = true;
				continue;
			}
		}
		if (finded) { continue; }

		vector<int> arr; arr.push_back(i1);
		chars.push_back(tuple<char, bool, vector<int>>(currchar,false,arr));
	}

	string result; 
	result.resize(strlen);

	int chararrsize = chars.size();
	for (int i1 = 0; i1 < chararrsize; ++i1)
	{
		char ch = get<1>(chars[i1]) ? ')' : '(';

		vector<int>& positions = get<2>(chars[i1]);
		
		int possize = positions.size();
		for (int i2 = 0; i2 < possize; ++i2)
		{
			result[positions[i2]] = ch;
		}
	}

	cout << result << endl;
}