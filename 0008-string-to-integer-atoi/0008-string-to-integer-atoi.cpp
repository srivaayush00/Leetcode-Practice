class Solution
{
    public:
        int myAtoi(string s)
        {
            int i = 0, n = s.length();

           	// Step 1: Skip leading whitespaces
            while (i < n && s[i] == ' ')
                i++;

           	// Step 2: Handle optional '+' or '-' sign
            int sign = 1;
            if (i < n && (s[i] == '+' || s[i] == '-'))
            {
                sign = (s[i] == '-') ? -1 : 1;
                i++;
            }

           	// Step 3: Convert digits and stop at first non-digit
            long long result = 0;
            while (i < n && isdigit(s[i]))
            {
                result = result *10 + (s[i] - '0');

               	// Step 4: Clamp to 32-bit signed integer range
                if (sign == 1 && result > INT_MAX)
                    return INT_MAX;
                if (sign == -1 && -result < INT_MIN)
                    return INT_MIN;

                i++;
            }

            return (int)(sign *result);
        }
};