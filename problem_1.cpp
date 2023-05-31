#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int originalColor) {
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != originalColor || image[sr][sc] == newColor) {
        return;
    }

    image[sr][sc] = newColor;
    dfs(image, sr + 1, sc, newColor, originalColor);
    dfs(image, sr - 1, sc, newColor, originalColor);
    dfs(image, sr, sc + 1, newColor, originalColor);
    dfs(image, sr, sc - 1, newColor, originalColor);
}

vector<vector<int>> solve(vector<vector<int>>& image, int sr, int sc, int color) {
    int originalColor = image[sr][sc];
    if (originalColor != color) {
        dfs(image, sr, sc, color, originalColor);
    }
    return image;
}

// Do not modify the code below
int main() {
    int n;
    cin >> n;
    vector<vector<int>> image(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> image[i][j];
        }
    }
    int sr, sc, color;
    cin >> sr >> sc >> color;

    vector<vector<int>> ans = solve(image, sr, sc, color);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
            if (j != n - 1) {
                cout << ' ';
            }
        }
        if (i != n - 1) {
            cout << '\n';
        }
    }
}
