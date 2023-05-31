#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<vector<int> >& edges, int distanceThreshold) {
    
  //complete the function
    const int INF = numeric_limits<int>::max();

    vector<vector<int>> adjMatrix(n, vector<int>(n, INF));

    for (const vector<int>& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && adjMatrix[i][k] != INF && adjMatrix[k][j] != INF) {
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
    }

    int smallestReachableCities = n;
    int cityWithSmallestReachable = -1;

    for (int i = 0; i < n; i++) {
        int reachableCount = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && adjMatrix[i][j] <= distanceThreshold) {
                reachableCount++;
            }
        }
        if (reachableCount <= smallestReachableCities) {
            smallestReachableCities = reachableCount;
            cityWithSmallestReachable = i;
        }
    }

    return cityWithSmallestReachable;
}

//do not modify the below code
int main()
{
    int n, m, distanceThreshold;
    cin >> n >> m >> distanceThreshold;
    vector<vector<int> > edges;
    for(int i = 1; i <= m; i ++)
    {
        int x, y, weight;
        cin >> x >> y >> weight;
        vector<int> f;
        f.push_back(x);
        f.push_back(y);
        f.push_back(weight);
        edges.push_back(f);
    }

    cout << solve(n, edges, distanceThreshold);
}
