/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
void replaceAll(string &s, const string &from, const string &to)
{
    int pos = 0;
    while ((pos = s.find(from, pos)) != string::npos)
    {
        s.replace(pos, from.length(), to);
        pos += to.length();
    }
}
string delkg(string s)
{
    string res;
    bool f = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ')
        {
            if (!res.empty() && !f && (i + 1 < s.size() && !ispunct(s[i + 1])))
            {
                res += ' ';
                f = 1;
            }
        }
        else
        {
            if (ispunct(s[i]) && !res.empty() && res.back() == ' ')
            {
                res.pop_back();
            }
            res += s[i];
            f = 0;
        }
    }
    if (!res.empty() && res.front() == ' ')
        res.erase(0, 1);
    if (!res.empty() && res.back() == ' ')
        res.pop_back();
    return res;
}
bool isword(string s, int pos, int len)
{
    return (pos == 0 || ispunct(s[pos - 1]) || s[pos - 1] == ' ') &&
           (pos + len == s.size() || ispunct(s[pos + len]) || s[pos + len] == ' ');
}

string trsentence(string s)
{
    s = delkg(s);
    replaceAll(s, "?", "?");
    int pos = 0;
    while ((pos = s.find("can you", pos)) != string::npos)
    {
        if (isword(s, pos, 7))
        {
            s.replace(pos, 7, "I can");
            pos += 5;
        }
        else
            pos++;
    }
    pos = 0;
    while ((pos = s.find("could you", pos)) != string::npos)
    {
        if (isword(s, pos, 9))
        {
            s.replace(pos, 9, "I could");
            pos += 7;
        }
        else
            pos++;
    }
    pos = 0;
    while ((pos = s.find(" I ", pos)) != string::npos)
    {
        if (isword(s, pos + 1, 1))
        {
            s.replace(pos, 3, " you ");
        }
        pos += 2;
    }
    if (s.substr(0, 2) == "I ")
        s.replace(0, 1, "you");
    if (s.size() > 1 && s.substr(s.size() - 2) == " I")
        s.replace(s.size() - 1, 1, "you");
    for (char &c : s)
    {
        if (c != 'I')
            c = tolower(c);
    }
    replaceAll(s, "?", "!");

    return "AI: " + s;
}

void work()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s;
        getline(cin, s);
        cout << s << '\n';
        cout << trsentence(s) << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    // cin >> _;
    // sc("%d",&_);
    while (_--)
        work();
    return 0;
}