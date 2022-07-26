#include <iostream>
using namespace std;
const int mxN = 1000;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll k, t, n, m;
char map[mxN][mxN];
bool visited[mxN][mxN];
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

bool isValid(int y, int x)
{
    // out of bounds condition
    if (x < 0 || x >= m || y < 0 || y >= n)
        return false;
    // ATQ
    if (map[y][x] == '#')
        return false;
    return true;
}

void dfs(int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int newX = x + moveX[i];
        int newY = y + moveY[i];
        if (isValid(newY, newX) && !visited[newY][newX])
            dfs(newY, newX);
    }
}

int main()
{
    // n rows ->i, m cols->j
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> map[i][j];
            visited[i][j] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (map[i][j] == '.' && !visited[i][j])
            {
                dfs(i, j); // notice that j is x and i is y
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}