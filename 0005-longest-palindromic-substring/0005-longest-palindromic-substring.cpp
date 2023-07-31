class Solution {
public:
    string longestPalindrome(string s) {
        int str_len = s.length();

		if (str_len == 0 || str_len == 1)
			return s;

		string longest = "";
		for (int i = 0; i < str_len - 1; i++)
		{
			int low_pt = i;
			int high_pt = i + 1;

			while (low_pt >= 0 && high_pt < str_len)
			{
				if (low_pt == i && s[low_pt] == s[high_pt])
				{
					high_pt++;
					continue;
				}

				if (low_pt > 0 && s[low_pt - 1] == s[high_pt])
				{
					low_pt--;
					high_pt++;
				}

				else
					break;
			}

			string sub = s.substr(low_pt, high_pt - low_pt);

			if (longest.length() < sub.length())
				longest = sub;
		}

		return longest;
    }
};