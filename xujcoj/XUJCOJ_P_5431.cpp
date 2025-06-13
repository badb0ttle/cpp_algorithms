/*🤣*/
#include <bits/stdc++.h>

using i64 = long long;
i64 mat[3][3],a[4][4];
i64 det3(i64 mat[3][3])
{
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}
i64 det4(i64 mat[4][4])
{
    i64 det = 0;
    i64 submat[3][3];
    for (int col = 0; col < 4; ++col)
    {
        int subi = 0;
        for (int i = 1; i < 4; ++i)
        {
            int subj = 0;
            for (int j = 0; j < 4; ++j)
            {
                if (j == col)
                    continue;
                submat[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }
        i64 cf = (col % 2 == 0 ? 1 : -1) * det3(submat);
        det += mat[0][col] * cf;
    }
    return det;
}
void work()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j< 4; ++j)
        {
            std::cin >> a[i][j];
        }
       
    }
     if(det4(a)==0)std::cout<<"INF\n";
        else std::cout<<"1\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _ = 1;
    std::cin>>_;
    while (_--)
        work();
    return 0;
}