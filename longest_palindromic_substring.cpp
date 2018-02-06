#include <iostream>
#include <string>
using namespace std;

/*
 *Given a string s, find the longest palindromic substring in s.
 */
string longestPalindrome_Normal(string s)
{
	/* 动态规划 */
	int n = s.size(); 
	bool dp[n][n] = {0};
	int max_len = 1; 
	int start = 0;
	
	for(int i = 0; i < s.size(); i++)  
	{  
		for(int j = 0; j <= i; j++)  
		{
			if(i == j)
			{
				dp[j][i] = true;
			}
			else if(i - j == 1)
			{
				dp[j][i] = (s[i] == s[j]);  
			}
			else if(i - j > 1)
			{
				dp[j][i] = (s[i] == s[j] && dp[j + 1][i - 1]);
			}
			
			if(dp[j][i] && max_len < (i - j + 1))  
			{  
				max_len = i - j + 1;  
				start = j;  
			}   
		}  
	}  
	return s.substr(start, max_len);  
}

string longestPalindrome_DP(string s)
{
	/* 暴力穷举  */
	string longestString = "";
	for(int i = 0; i < s.length(); i++)
	{
		string substring = "";
		for(int j = i; j < s.length(); j++)
		{
			substring += s[j];
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
				if(substring.length() > longestString.length())
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
	cout << longestPalindrome_Normal(s) << endl;
	return 0;
}
