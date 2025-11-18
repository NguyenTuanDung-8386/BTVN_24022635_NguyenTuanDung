#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
bool visited[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    // danh sach ke
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // bfs
    int start = 1;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
