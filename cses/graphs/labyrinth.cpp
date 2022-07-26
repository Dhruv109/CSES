// shortest path
// bfs can give shortest path when egdes dont have weight
// we just need to implement bfs in this

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int mxN = 1e6;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll k, t, n, m;
char grid[1001][1001];
bool vis[1001][1001];
int dist[1001][1001];
char parent[1001][1001];
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

bool isValid(int y, int x)
{
    if (x < 0 || x >= m || y < 0 || y >= n)
        return false;
    if (grid[y][x] == '#')
        return false;
    return true;
}

void BFS(int y, int x)
{
    int ans = 0;

    queue<vector<int>> q; // 0-> newX, 1-> newY, 2 -> parentX , 3 -> parentY
    q.push({y, x, -1, -1});
    while (!q.empty())
    {
        int currX = q.front()[1];
        int currY = q.front()[0];
        q.pop();
        if (vis[currY][currX])
            continue;

        vis[currY][currX] = 1;
        for (int i = 0; i < 4; ++i)
        {
            // i=0->D, i=1->U, i=2->R, i=3->L
            int newX = currX + moveX[i];
            int newY = currY + moveY[i];
            if (isValid(newY, newX) && !vis[newY][newX])
            {
                switch (i)
                {
                case 0:
                    parent[newY][newX] = 'D';
                    break;
                case 1:
                    parent[newY][newX] = 'U';
                    break;
                case 2:
                    parent[newY][newX] = 'R';
                    break;
                case 3:
                    parent[newY][newX] = 'L';
                    break;
                }
                dist[newY][newX] = dist[currY][currX] + 1;
                // cout << newY << " " << newX << endl;
                q.push({newY, newX, currY, currX});
            }
        }
        // we moved one unit in all direction so
        ans++;
    }
}

int main()
{
    cin >> n >> m;
    pair<int, int> start;
    pair<int, int> end;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start.first = i;
                start.second = j;
            }
            if (grid[i][j] == 'B')
            {
                end.first = i;
                end.second = j;
            }
        }
    }
    BFS(start.first, start.second); // n rows -> i = y , m cols -> j = x
    if (!vis[end.first][end.second])
        cout << "NO";
    else
    {
        cout << "YES" << endl
             << dist[end.first][end.second] << endl;
        string ans;
        while (start.first != end.first || start.second != end.second)
        {
            char c = parent[end.first][end.second];
            switch (c)
            {
            case 'R':
                end.second--;
                break;
            case 'L':
                end.second++;
                break;
            case 'D':
                end.first--;
                break;
            case 'U':
                end.first++;
                break;
            }
            ans += c;
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    return 0;
}