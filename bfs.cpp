#include <bits/stdc++.h> 
#include <iostream>
#include <list>
#define ROW 7
#define COL 7

using namespace std;

class queueNode 
{
public:
    int Point [2];
    int dist;
    string path;
};


int rowNum[] = {-1, 1, 0, 0}; 
int colNum[] = {0, 0, -1, 1};
char move [] = {'U','D','L','R'};

void BFS(int m[][COL], int src[], int dest[])
{
	cout<<"1"<<endl;
	
    bool visited[ROW][COL]; 
    memset(visited, false, sizeof visited); 
    
    visited[(src[0])][(src[1])] = true;
    
    queue<queueNode> q;
    queueNode s;
    s.Point[0] = src[0];
    s.Point[1] = src[1];
    s.dist = 0;
    s.path = "";
    
    q.push(s);
    
    while (!q.empty()) 
    {
    	cout<<"2"<<endl;

    	queueNode curr = q.front();
        int pt[2] = {curr.Point[0],curr.Point[1]};
        
        if (pt[0] == dest[0] && pt[1] == dest[1]) {
        	cout<<"Here's a path:"<<curr.path<<endl;
        	cout<<"path lenght:"<<curr.dist;
            return;
        }

        q.pop();
        
        for (int i = 0; i < 4; i++) 
        {
	    	cout<<"3"<<endl;

        	int row = pt[0] + rowNum[i]; 
            int col = pt[1] + colNum[i];
            
            
            if (row >= 0 && row < ROW && 
                col >= 0 && col < COL &&
			    m[row][col]!=0 && !visited[row][col]) 
            	{
    	    		cout<<"4"<<endl;
    	    		cout<<"posotion:"<<row<<","<<col<<endl;

            		visited[row][col] = true; 
            		queueNode neighbor;
            		neighbor.Point[0] = row; neighbor.Point[1] = col;
            		neighbor.dist = curr.dist + 1 ;
            		neighbor.path = curr.path + move[i];

            		q.push(neighbor);
            	}
        }
    }
    return;
}

int main(){
	cout<<"0"<<endl;
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
	int source [] = {6, 2}; 
	int dest [] = {0, 5};
	
	BFS(m, source, dest);

	  
	    return 0;  
}
