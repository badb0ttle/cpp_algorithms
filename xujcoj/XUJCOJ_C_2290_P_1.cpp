
/*blank*/
#include<bits/stdc++.h>
using namespace std;
string rem(string a)//大数去除前置0
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] != '0')
            return a.substr(i);
    return "0";
}
string luodouble(string a)
{
    a = rem(a);
    if (a.find('.') != -1)
    {
        while (a.size() && a.back() == '0')
            a.pop_back();
        if (a.back() == '.')
            a.pop_back();
    }
    if (a.empty() || a[0] == '.')
        a = "0" + a;
    return a;
}
bool che(string a, string b)//检测两个大数大小
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}
string remb(string a)//去除浮点数前置0和后置0
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != '0')
        {
            a = a.substr(i);
            break;
        }
        if (i == a.size() - 1)
            return "0";
        //如果全是0，直接return "0"
    }
    if (a[0] == '.')a = "0" + a;
    //以上代码去除前置0
    if (a.find('.') > a.size())
        return a;
    //如果没有小数点，直接return
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] != '0')
        {
            a = a.substr(0, i + 1);
            break;
        }
    }
    //以上代码去除后置0
    if (a[a.size() - 1] == '.')
        a = a.substr(0, a.size() - 1);
    //以上代码除去小数部分为0时的小数点
    return a;
}
string tr(string a)//去除浮点数的小数点
{
    string res;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != '.')res += a[i];
    }
    return res;
}
string BP(string a, string b)//不考虑负数的大数加法
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int leng = max(a.size(), b.size());
    vector<int>vec(leng + 5);
    for (int i = 0; i < a.size(); i++)
        vec[i] += a[i] - '0';
    for (int i = 0; i < b.size(); i++)
        vec[i] += b[i] - '0';
    string res;
    for (int i = 0; i < leng + 2; i++)
    {
        vec[i + 1] += vec[i] / 10;
        vec[i] %= 10;
        res += vec[i] + '0';
    }
    reverse(res.begin(), res.end());
    return rem(res);
}
string BS(string a, string b)//不考虑负数的大数减法
{
    string op = "";
    if (che(a, b))
    {
        swap(a, b);
        op = "-";
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int leng = max(a.size(), b.size());
    vector<int>vec(leng + 5);
    for (int i = 0; i < a.size(); i++)
        vec[i] += a[i] - '0';
    for (int i = 0; i < b.size(); i++)
        vec[i] -= b[i] - '0';
    string res;
    for (int i = 0; i < leng + 2; i++)
    {
        while (vec[i] < 0)
        {
            vec[i + 1]--;
            vec[i] += 10;
        }
        res += vec[i] + '0';
    }
    reverse(res.begin(), res.end());
    return op + rem(res);
}
string BPOS(string a, string b, char m)//考虑负数的大数加减法
{
    string op = "";
    bool aa = 0, bb = 0;
    if (a[0] == '-')
    {
        aa = 1;
        a = a.substr(1);
    }
    if (b[0] == '-')
    {
        bb = 1;
        b = b.substr(1);
    }
    if (aa && bb)//a<0&&b<0
    {
        if (m == '+')//-(a+b)
            return "-" + BP(a, b);
        else if (m == '-')//b-a
            return BS(b, a);
    }
    else if (!aa && !bb)//a>=0&&b>=0
    {
        if (m == '+')//a+b
            return BP(a, b);
        else if (m == '-')//a-b
            return BS(a, b);
    }
    else if (aa && !bb)//a<0&&b>=0
    {
        if (m == '+')//b-a
            return BS(b, a);
        else if (m == '-')//-(a+b)
            return "-" + BP(a, b);
    }
    else if (!aa && bb)//a>=0&&b<0
    {
        if (m == '+')//a-b
            return BS(a, b);
        else if (m == '-')//a+b
            return BP(a, b);
    }
}
string BM(string a, string b)//大数乘法
{
    if (a == "0" || b == "0")return "0";
    int num = 0;
    if (a[0] == '-')
    {
        a = a.substr(1);
        num++;
    }
    if (b[0] == '-')
    {
        b = b.substr(1);
        num++;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len = a.size() + b.size();
    vector<int>ropz(len + 5);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            ropz[i + j] += (a[i] - '0') * (b[j] - '0');
    string res;
    for (int i = 0; i < len; i++)
    {
        ropz[i + 1] += ropz[i] / 10;
        ropz[i] %= 10;
        res += ropz[i] + '0';
    }
    reverse(res.begin(), res.end());
    if (!(num & 1))return rem(res);
    return "-" + rem(res);
}
string BD(string a, string b)//大数除法
{
    int num = 0;
    if (a[0] == '-')
    {
        a = a.substr(1);
        num++;
    }
    if (b[0] == '-')
    {
        b = b.substr(1);
        num++;
    }
    string res;
    string sum;
    for (int i = 0; i < a.size(); i++)
    {
        sum = rem(sum + a[i]);
        res += "0";
        while (!che(sum, b))
        {
            sum = rem(BPOS(sum, b, '-'));
            res[i]++;
        }
    }
    if (!(num & 1))return rem(res);
    return "-" + rem(res);
}
string BDLEFT(string a, string b)//大数除法余数
{
    string res;
    string sum;
    for (int i = 0; i < a.size(); i++)
    {
        sum = rem(sum + a[i]);
        res += "0";
        while (!che(sum, b))
        {
            sum = rem(BPOS(sum, b, '-'));
            res[i]++;
        }
    }
    return rem(sum);
}
string LDP(string a, string b)//浮点数相加
{
    int lena = a.find('.');
    int lenb = b.find('.');
    int lenaa = a.size() - lena - 1;
    int lenbb = b.size() - lenb - 1;
    int LEN = max(lenaa, lenbb);
    //以上代码找出小数部分长度
    for (int i = lenaa; i <= LEN; i++)
    {
        a += "0";
    }
    for (int i = lenbb; i <= LEN; i++)
    {
        b += "0";
    }
    //小数部分补0至小数部分长度相同
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len = max(a.size(), b.size());
    vector<int>ropz(len + 5);
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != '.')ropz[i] += a[i] - '0';
        else ropz[i] = INT_MAX;
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] != '.')ropz[i] += b[i] - '0';
        else ropz[i] = INT_MAX;
    }
    string ans;
    for (int i = 0; i < len + 2; i++)
    {
        if (ropz[i] == INT_MAX)ans += ".";
        else
        {
            if (ropz[i + 1] != INT_MAX)
            {
                ropz[i + 1] += ropz[i] / 10;
                ropz[i] %= 10;
            }
            else
            {
                ropz[i + 2] += ropz[i] / 10;
                ropz[i] %= 10;
            }
            ans += ropz[i] + '0';
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
string LDM(string a, string b)//浮点数相乘
{
    if (a.find('.') > a.size())a += ".0";
    if (b.find('.') > b.size())b += ".0";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len = a.size() + b.size();
    int pos = a.find('.') + b.find('.');
    a = tr(a);
    b = tr(b);
    vector<int>ropz(len + 5);
    for (int i = 0;i < a.size();i++)
        for (int j = 0;j < b.size();j++)
            ropz[i + j] += (a[i] - '0') * (b[j] - '0');
    string res;
    for (int i = 0;i < len;i++)
    {
        ropz[i + 1] += ropz[i] / 10;
        ropz[i] %= 10;
        res += ropz[i] + '0';
    }
    res = res.substr(0, pos) + "." + res.substr(pos);
    reverse(res.begin(), res.end());
    return remb(res);
}
string LDD(string a, string b)//浮点数除法
{
    if (a.find('.') > a.size())
    {
        a += ".";
    }
    if (b.find('.') > b.size())
    {
        b += ".";
    }
    string res;
    string num;
    int cnt = 0;
    string c = rem(tr(b));
    while (b[b.size() - 1] != '.')
    {
        int posb = b.find('.');
        if (posb != b.size() - 1)
            swap(b[posb], b[posb + 1]);
        cnt++;
    }
    for (int i = 1; i <= cnt; i++)
    {
        int posa = a.find('.');
        if (posa != a.size() - 1)
        {
            swap(a[posa], a[posa + 1]);
        }
        else
        {
            a = a.substr(0, a.size() - 1) + "0.";
        }
    }
    for (int i = 0; i <= cnt + 100; i++)
    {
        a += "0";
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != '.')
        {
            num = rem(num + a[i]);
            res += "0";
            while (!che(num, c))
            {
                num = rem(BPOS(num, c, '-'));
                res[i]++;
            }
        }
        else
        {
            res += ".";
        }
    }
    string ans = rem(res);
    if (ans[0] == '.')ans = "0" + ans;
    return ans;
}
std::string gcd(string a,string b)
{
    return b!="0"?gcd(b,BDLEFT(a,b)):a;
}
std::string lcm(std::string a,std::string b){
		return BM(BD(a,gcd(a,b)),b);
}
void work()
{
   string  a,b,c,d;
   std::cin>>a>>b>>c>>d;
   string num="9999999999999999999999999999999999";
   if(che(a,num))num=a;
   if(che(b,num))num=b;
   if(che(c,num))num=c;
   if(che(d,num))num=d;

    string t=lcm(a,(lcm(b,lcm(c,d))));
    // cout<<t<<'\n';
    std::cout<<BM(BD(t,num),"400")<<'\n';
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _=1;
    std::cin>>_;
    while(_--)work();
    return 0;
}