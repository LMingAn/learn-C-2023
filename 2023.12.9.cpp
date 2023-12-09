#include <iostream>
using namespace std;

int ans[100006] = { 0 }, num = 0;
int main()
{
    long long N = 0, M = 0;
    cin >> N >> M;
    if (M > 9)
    {
        long long n = M / 9;
        if (N >= n)//能全放
        {
            N -= n;
            M -= n * 9;
            for (; n > 0; n--)
                ans[num++] = 9;
            if (N > 0)
            {
                ans[num++] = M;
                N--;
            }
            M = 0;
        }
        else if (N < n)//不能全放
        {
            for (; N > 0; N--)
                ans[num++] = 9;
        }
    }
    else if (M)
    {
        ans[num++] = M;
        N--;
    }
    for (long a = 1; a <= N; a++)
    {
        ans[num++] = 0;
    }
    for (long n = 0; n < num; n++)
        cout << ans[n];
    return 0;
}