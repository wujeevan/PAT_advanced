#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 1e4 + 100;
int hash[maxn], len;

bool prime(int x)
{
    if(x == 1) return false;
    int up = (int)sqrt(x);
    for(int i = 2; i <= up; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int insert(int x)
{
    int n = 1, p = x;
    for(; n <= len; n++) {
        if(hash[p % len] == 0) {
            hash[p % len] = x;
            break;
        }
        p = x + n*n;
    }
    return n;
}

int query(int x)
{
    int n = 1, p = x;
    for(; n <= len; n++) {
        if (hash[p % len] == x || hash[p % len] == 0) break;
        p = x + n*n;
    }
    return n;
}

int main()
{
    freopen("input.dat", "r", stdin);
    int n, m, x;
    scanf("%d%d%d", &len, &n, &m);
    while(!prime(len)) len++;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        int cnt = insert(x);
        if (cnt > len) {
            printf("%d cannot be inserted.\n", x);
        }
    }
    printf("len=%d\n", len);
    double sum = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        int cnt = query(x);
        printf("cnt=%d\n", cnt);
        sum += cnt;
    }
    printf("%.1f", sum/m);
    return 0;
}