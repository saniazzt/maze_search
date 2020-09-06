#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stack>
#include <list>
#define ROW 7
#define COL 7

using namespace std;

struct Point
{
    int x;
    int y;
};

struct Node
{
    Point pt;
    int dist;
};

int rowNum[] = {-1, 1, 0, 0};
int colNum[] = {0, 0, -1, 1};
char move [] = {'U','D','L','R'};

void DFS(int m[][COL], Point src,Point dest){

	cout<<"1"<<endl;

    bool visited[ROW][COL];
    string fpath;
    memset(visited, false, sizeof visited);
    stack <Node> stack1;

    visited[src.x][src.y]= true;
    Node s;
    s.pt=src; s.dist=0;
    stack1.push(s);

    while (!stack1.empty()){

        s.pt= stack1.top().pt;
        s.dist= stack1.top().dist;
    	stack1.pop();
        int n = s.pt.x; int j = s.pt.y;
        int i=0;
        while (i<4)
        {

            int row = s.pt.x + rowNum[i];
            int col = s.pt.y + colNum[i];

            if (row == dest.x && col == dest.y) {
	    		fpath.push_back(move[i]);
                cout<<"Here's a path:"<<fpath<<endl;
                cout<<"path lenght:"<<s.dist;
                return;
            }

            if (row >= 0 && row < ROW &&
                col >= 0 && col < COL &&
                m[row][col]!=0 && !visited[row][col])
            {
                cout<<"position:"<<row<<","<<col<<endl;

                visited[row][col]= true;
	    		fpath.push_back(move[i]);

                s.pt.x = row; s.pt.y = col; s.dist++;
                stack1.push(s);
                i=0;
            }
            else i++;
        }
    	cout<< "DEADEND" <<endl;
    	fpath.erase(fpath.size()-1);
    	s.dist--;
    }
}

int main(){
        int m[ROW][COL] =
        {
            {1,1,1,1,0,1},
            {1,0,1,1,1,1},
            {1,1,0,0,0,0},
            {1,0,0,1,1,1},
            {1,1,1,1,0,1},
            {1,0,0,0,0,1},
            {1,1,1,1,1,1}
        };
        string finalpath;
        Point source = {6, 2};
        Point dest = {0, 5};

        DFS(m,source,dest);
}
