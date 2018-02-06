#include <iostream>
#include <string>
using namespace std;

/* record length */
int longestLen;
/* find the lonest substring */
int lengthOFLongestSubstring(string s)
{
	for(int i = 0; i < s.length() - 1; i++)
	{
		string substring = "";
		for(int j = i + 1; j < s.length(); j++)
		{
			/* whether character in the substring */
			bool existFlag = false;
			for(int k = 0; k < substring.length(); k++)
			{
				if(s[j] == substring[k])
				{
					existFlag = true;
					break;
				}
			}
			if(existFlag)
			{
				break;
			}
			else
			{
				substring += s[j];
			}
		}
		/* get a substring and record its length */
		longestLen = substring.length();
	}
}

int main()
{
	string s;
	cin >> s;
	cout << lengthOFLongestSubstring(s) << endl;
	return longestLen;
}
