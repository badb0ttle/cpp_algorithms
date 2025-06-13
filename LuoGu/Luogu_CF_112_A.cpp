/*blank*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long // 一时偷懒不收敛，乱开ll终遭谴
#define sc scanf
#define pr printf
int n;
string s, word;
bool isword(string s)
{
    for (char i : s)
        if (!isalpha(i))
            return 0;
    return 1;
}
void low(string &s)
{
    for (char &i : s)
        if (i != 'I')
            i = tolower(i);
}
void work()
{
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; ++i)
    {
        getline(cin, s);
        cout << s << '\n';
        cout << "AI: ";
        stringstream ss(s);
        vector<string> v;
        vector<int> vis;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (ispunct(s[i]))
            {
                if (s[i + 1] == ' ')
                    {
                        int x=1,y=i+2;bool ff=0;
                        while(s[y]==' ')
                        {
                            x++;
                            y++;
                            if(y==s.size())
                            {
                                ff=1;
                            }
                        }
                        if(!ff)
                        vis.push_back(x);
                    }
                else
                    vis.push_back(0);
            }
        }

        while (ss >> word)
        {
            if (isword(word))
            {
                if (word != "I")
                {
                    low(word);
                }
                v.push_back(word);
            }
            else
            {

                string t1 = "";
                for (int i = 0; i < word.size(); ++i)
                {
                    if (ispunct(word[i]))
                    {
                        if (!t1.empty())
                        {
                            if (t1 != "I")
                                low(t1);
                            v.push_back(t1);
                            t1 = "";
                        }
                        v.push_back(string(1, word[i]));
                    }
                    else
                    {
                        t1 = t1 + word[i];
                    }
                }
                if (!t1.empty())
                {
                    if (t1 != "I")
                        low(t1);
                    v.push_back(t1);
                }
            }
        }
        bool f = 0;
        // cout<<v.size()<<'\n';
        // for(string i:v){cout<<i<<'\n';}
        for (int i = 0; i < v.size(); ++i)
        {
            // cout<<v[i]<<'\n';
            if (v[i] == "I" || v[i] == "me")
            {
                v[i] = "you";
            }
            else if (i + 1 < v.size())
            {
                if (v[i] == "can" && v[i + 1] == "you")
                {
                    v[i] = "I";
                    v[i + 1] = "can";
                    i++;
                }
                else if (v[i] == "could" && v[i + 1] == "you")
                {
                    v[i] = "I";
                    v[i + 1] = "could";
                    i++;
                }
            }
        }
        bool f2 = 1;
        int cnt = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i].size() == 1 && ispunct(v[i][0]))
            {
                if (v[i][0] == '?')
                    cout << '!';
                else
                {
                    cout << v[i];
                }
                if (i + 1 < v.size() && vis[cnt] == 0)
                {
                    cout << v[i + 1];
                    i++;
                }
                else if(i + 1 < v.size() && vis[cnt] != 0)
                {
                    for(int i=0;i<vis[cnt];++i)cout<<' ';
                    cout<<v[i+1];
                    i++;
                }
                cnt++;
            }
            else
            {
                if (!f2)
                    cout << ' ';
                cout << v[i];
                f2 = 0;
            }
        }
        cout << '\n';
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