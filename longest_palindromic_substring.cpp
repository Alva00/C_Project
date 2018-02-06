#include <iostream>
#include <string>
using namespace std;

/*
 *Given a string s, find the longest palindromic substring in s.
 */
string longestPalindrome(string s)
{
	string longestString = "";
	/* split string into substring */
	for(int i = 0; i < s.length(); i++)
	{
		string substring = "";
		for(int j = i; j < s.length(); j++)
		{
			substring += s[j];
			/* whether substring is palindrome */
			bool flag = false;
			for(int k = 0; k < substring.length(); k++)
			{
				if(substring[k] != substring[substring.length() - k - 1])
				{
					flag = true;
					break;
				}
			}
			if(!flag)
			{
				if(substring.length() > substring.length())
				{
					longestString = substring;
				}
			}
		}
	}
	return longestString;
}
int main()
{
	string s;
	cin >> s;
	cout << longestPalindrome(s) << endl;
	return 0;
}
