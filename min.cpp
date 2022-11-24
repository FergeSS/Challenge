#include <iostream>

bool c(const char *s,int c){while(*s&&c>=0)*s++==40?++c:--c;return !c;}

bool testCase(const char s[], bool expected, bool& res) {
    res = c(s,0);
    return res == expected;
}

int main()
{
    const char* str_cases[] = {
        "",
        "(",
        ")",
        "()",
        ")(",
        "()()",
        "(()",
        "())",
        "(())",
        ")(()))",
        "(())((()())())"
    };
    const size_t cNumCases = sizeof(str_cases) / sizeof(char*);
    bool expected[cNumCases] = { true, false, false, true, false, true, false, false, true, false, true };
    bool result = true;
    for (size_t iter = 0; iter < cNumCases; ++iter)
    {
        bool curr_check;
        bool curr_test = testCase(str_cases[iter], expected[iter], curr_check);
        std::cout << "test \"" << str_cases[iter] << "\" is " << (curr_test ? "ok" : "failed") << '\n';
        std::cout << "\tresult: " << curr_check << " expected " << expected[iter] << '\n';
        result = result && curr_test;
    }
    std::cout << "Total result: " << result << '\n';

    return 0;
}
