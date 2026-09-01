#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        char* start_pointer = &s[0];
        char* end_pointer = &s[s.size() - 1];

        int longestPalindrome_length = 0;
        char* maybe_longest_start = nullptr;
        char* maybe_longest_end = nullptr;

        char* result_palindrome_start = nullptr;
        char* result_palindrome_end = nullptr;
        int result_length = 0;
        while (start_pointer < end_pointer)
        {
            if (*start_pointer == *end_pointer)
            {
                maybe_longest_start = start_pointer;
                maybe_longest_end = end_pointer;
                while (maybe_longest_start < maybe_longest_end)
                {
                    if (*maybe_longest_start == *maybe_longest_end)
                    {
                        maybe_longest_start = maybe_longest_start + 1;
                        maybe_longest_end = maybe_longest_end - 1;
                    }
                    else
                    {
                        maybe_longest_start = nullptr;
                        maybe_longest_end = nullptr;
                        break;
                    }
                    if (maybe_longest_start >= maybe_longest_end)
                    {
                        int compare_length = end_pointer - start_pointer;
                        if (result_length < compare_length)
                        {
                            result_palindrome_start = start_pointer;
                            result_palindrome_end = end_pointer;
                            result_length = compare_length;
                            maybe_longest_start = nullptr;
                            maybe_longest_end = nullptr;
                        }
                    }
                }
            }

            if (start_pointer + 1 == end_pointer)
            {
                start_pointer = ++start_pointer;
                end_pointer = &s[s.size() - 1];
            }
            else
            {
                end_pointer = --end_pointer;
            }
        }
        string result = s.substr(0, 1);
        if (result_palindrome_start != nullptr)
        {
            result = std::string(result_palindrome_start, result_palindrome_end + 1);
        }
        return result;
    }
};

int main()
{
    Solution object;
    string example = "abbcccba";
    string result;
    result = object.longestPalindrome(example);
}