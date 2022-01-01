#include<bits/stdc++.h>

using namespace std;

bool visited[51][51];
    
bool check(int x, int y, int xc, int yc){
    if (x >= 0 && x < xc && y >= 0 && y < yc)
        return true;
    return false;
}

int dfs(vector<vector<int>>& grid, int x, int y, int xc, int yc){
    visited[y][x] = true;
    if (grid[y][x] == 0) return 0;
    int res = 1;
    if (check(x + 1, y, xc, yc) && !visited[y][x + 1])
        res += dfs(grid, x + 1, y, xc, yc);
    if (check(x - 1, y, xc, yc) && !visited[y][x - 1])
        res += dfs(grid, x - 1, y, xc, yc);
    if (check(x, y + 1, xc, yc) && !visited[y + 1][x])
        res += dfs(grid, x, y + 1, xc, yc);
    if (check(x, y - 1, xc, yc) && !visited[y - 1][x])
        res += dfs(grid, x, y - 1, xc, yc);
    
    return res;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max = 0, area = 0, xc = 0, yc = 0;
    memset(visited, false, sizeof(visited));
    yc = grid.size();
    for(int y = 0; y < yc; y++){
        xc = grid[y].size();
        for(int x = 0; x < xc; x++){
            if (grid[y][x] == 1 && !visited[y][x]){
            	visited[y][x] = true;
                area = dfs(grid, x, y, xc, yc);
			}
            if (area > max){
                max = area;
            }
        }
    }
    
    return max;
}

int main(){
	vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
	cout << maxAreaOfIsland(grid);
	return 0;
}
