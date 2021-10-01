
char arr[1000][1000];
int floodFill(int n, int m, int r, int c, char mChar, char color)
{
    if(r < 0 || r >= n || c < 0 || c >= m)    return 0;
    if(arr[r][c] != mChar)    return 0;
    arr[r][c] = color;
    int ans = 1;
    for(int i = 0; i < 8; i++) {
        ans += floodFill(n, m, r + fx[i], c + fy[i], mChar, color);
    }
    return ans;
}

int main()
{
	
	// Dimension of the graph
	int row = 20, col = 20;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			cin >> arr[i][j];
	
	// cell row and column from where to start searching and coloring
	int celR = 2, celC = 5;
	
	// This will count the number of Connected Component
	// And also change the color of the cell contains 'W', and change it to '.'
	cout << floodFill(row, col, celR, celC, 'W', '.');
	return 0;
}
