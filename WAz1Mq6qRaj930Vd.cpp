#pragma GCC optimize(3)
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include "bits/stdc++.h"

#define ll long long
#define pi acos(-1.0)
#define mod 1000000007
#define ls l, m, rt << 1
#define rs m + 1, r, rt << 1 | 1

using namespace std;
int f[20001][2], t[20001];
int min(int x, int y)
{
    return x < y ? x : y;
}

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     while (cin >> n)
//     {
//         for (int i = 0; i < n; i++)
//             cin >> p[i].x >> p[i].y;
//         cout << Graham() << endl;
//     }
//     return 0;
// }

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &t[i]);
    for (int i = 1; i <= n + 2; i++)
    {
        f[i][1] = min(f[i - 1][0], f[i - 1][1]) + t[i];
        f[i][0] = min(f[i - 1][1], f[i - 2][1]);
    }
    int ans = 0x7fffffff;
    for (int i = n; i <= n + 2; i++)
    {
        if (f[i][0] < ans)
            ans = f[i][0];
        if (f[i][1] < ans)
            ans = f[i][1];
    }
    printf("%d\n", ans);
    return 0;
}
