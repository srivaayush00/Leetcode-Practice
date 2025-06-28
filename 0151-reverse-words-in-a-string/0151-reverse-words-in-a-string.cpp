class Solution
{
    public:
        string reverseWords(string s)
        {
            vector<string> words;
            int i = 0, n = s.size();

            while (i < n)
            {
                while (i < n && s[i] == ' ')
                    i++;	// skip spaces
                if (i >= n)
                    break;
                int j = i;
                while (j < n && s[j] != ' ')
                    j++;	// find word end
                words.push_back(s.substr(i, j - i));
                i = j;
            }

            reverse(words.begin(), words.end());

            string result;
            for (int k = 0; k < words.size(); k++)
            {
                result += words[k];
                if (k != words.size() - 1)
                    result += " ";
            }

            return result;
        }
};