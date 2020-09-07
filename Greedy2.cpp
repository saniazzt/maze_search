#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

#define MAX 5

using namespace std;

bool isSafe(int row, int col, int m[][MAX],
            int n, bool visited[][MAX]) {
    cout << "4" << endl;
    if (row <= -1 || row >= n || col <= -1 ||
        col >= n || visited[row][col]
        || m[row][col] == 0)
        return false;

    return true;
}


void bestpath(int &row, int &col, int m[][MAX], int n, string &path,
              bool visited[MAX][MAX], int newrow[], int newcol[]) {

    if (row <= -1 || row >= n || col <= -1
        || col >= n || visited[row][col]
        || m[row][col] == 0)
        return;

    if(row == n-1 && col == n-1){
        cout<<path;
        exit(0);
    }

    visited[row][col] = true;
    int dis[4] = {1000,1000,1000,1000};

    cout << "3" << endl;

    if (isSafe(row + 1, col, m, n, visited)) {

        //down
        dis[0] = sqrt(pow((n - 1 - (row + 1)), 2) + pow((n - 1 - col), 2));
        newrow[0] = row + 1;
        newcol[0] = col;
    }

    if (isSafe(row, col + 1, m, n, visited)) {

        //right
        dis[3] = sqrt(pow((n - 1 - row), 2) + pow((n - 1 - (col + 1)), 2));
        newrow[3] = row;
        newcol[3] = col + 1;
    }

    if (isSafe(row - 1, col, m, n, visited)) {

        //up
        dis[1] = sqrt(pow((n - 1 - (row - 1)), 2) + pow((n - 1 - col), 2));
        newrow[1] = row - 1;
        newcol[1] = col;
    }

    if (isSafe(row, col - 1, m, n, visited)) {

        //left
        dis[2] = sqrt(pow((n - 1 - row), 2) + pow((n - 1 - (col - 1)), 2));
        newrow[2] = row;
        newcol[2] = col - 1;
    }

    int kk = 10000;
    int andis = -1;
    char a[4] = {'D', 'U', 'L', 'R'};
    for (int i = 0; i <= 3; i++) {
        if (dis[i] < kk) {
            kk = dis[i];
            andis = i;
        }
    }
    if(andis == -1){
        return;
    }
    cout << "5" << endl;
    path.push_back(a[andis]);
    cout<<a[andis]<<endl;
    row = newrow[andis];
    col = newcol[andis];
}

void printPath(int m[MAX][MAX], int n) {
    cout << "1" << endl;
    string path;
    bool visited[MAX][MAX];
    int newrow[4];
    int newcol[4];
    memset(visited, false, sizeof(visited));

    int row = 0;
    int col = 0;
    while ((row <= n - 1 && col <= n - 1) ) {
        bestpath(row, col, m, n, path, visited, newrow, newcol);
    }


    for (int i = 0; i < path.size(); i++)
        cout << path[i];
}

int main() {
    cout << "0" << endl;

    int m[MAX][MAX] = {{1, 0, 0, 0, 0},
                       {1, 1, 1, 1, 1},
                       {1, 1, 0, 0, 1},
                       {1, 0, 0, 0, 1},
                       {1, 1, 1, 1, 1}};
    int n = sizeof(m) / sizeof(m[0]);
    printPath(m, n);

    return 0;
}





