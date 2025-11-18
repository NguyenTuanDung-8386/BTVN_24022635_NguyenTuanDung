#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int main() {
    int n, m;
    cin >> n >> m;

    int A[MAXN][MAXN] = {0};

    while (m--) {
        int u, v;
        cin >> u >> v;
        A[u][v] = 1;
        A[v][u] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }
}
