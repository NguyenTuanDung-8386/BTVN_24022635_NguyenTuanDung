#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

vector<int> adj[MAXN];

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int v : adj[i]) cout << v << " ";
        cout << "\n";
    }
}
