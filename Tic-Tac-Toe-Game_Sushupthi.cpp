/******************************************************************************

An interactive TIC TAC TOE game which makes use of the standard template library

******************************************************************************/
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int keepx=4,keepy=4;  // let these be the coordinates of the 'observation cell'
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,1,-1,-1,1,1,-1};
int dx1[4]={1,-1,0,0};
int dy1[4]={0,0,1,-1};
vector<pair<int,int>>diag1,diag2;



bool checkIfFull(vector<vector<char>>&board) // function to check if the tic tac toe board is full.
{
    int count=0;
    for(int i=2;i>=0;i--)  // O(N^2)  time complexity where N is 3
    {
        for(int j=0;j<3;j++)
        {
            if(board[j][i]!='\0')
            {
                count++;
            }
        }
    }
    if(count==9)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void printBoard(vector<vector<char>>&board)   //function to print the tic tac toe board
{
    for(int i=2;i>=0;i--)  //   O(N^2)  time complexity  where N is 3
    {
        for(int j=0;j<3;j++)
        {
            if(board[j][i]=='\0')
            {
                cout<<"("<<j<<","<<i<<")"<<"\t";
            }
            else
            {
                cout<<board[j][i]<<"\t";
            }
        }
        cout<<"\n";
    }
}

void findEmptyCell(vector<vector<char>>&board)  // finds an empty cell on the tic tac toe board
{
    for(int i=0;i<3;i++)  //  O(N^2)  time complexity  where N is 3
    {
        for(int j=0;j<3;j++)
        {
            if(board[j][i]=='\0')
            {
                board[j][i]='*';
                keepx=j;keepy=i;
                return;
            }
        }
    }
}

void checkFourorEightDirections(vector<vector<char>>&board)  // checks four directions around the 'observation cell' if not on diagonal else checks eight directions if on diagonal
{
    if(keepx!=4&&keepy!=4)
    {
        if(keepy==keepx)  // 'observation cell' lies on right diagonal
        {
            for(int i=0;i<8;i++) // O(N) time complexity where N is 9
            {
                if(keepx+dx[i]<3&&keepx+dx[i]>=0&&keepy+dy[i]<3&&keepy+dy[i]>=0)
                {
                    if(board[keepx+dx[i]][keepy+dy[i]]=='\0')
                    {
                        board[keepx+dx[i]][keepy+dy[i]]='*';
                        keepx=keepx+dx[i];
                        keepy=keepy+dy[i];
                        return;
                    }
                }
            }
        }
        else if(keepy+keepx==2)  //'observation cell' lies on left diagonal
        {
            for(int i=0;i<8;i++)  // O(N) time complexity where N is 9
            {
                if(keepx+dx[i]<3&&keepx+dx[i]>=0&&keepy+dy[i]<3&&keepy+dy[i]>=0)
                {
                    if(board[keepx+dx[i]][keepy+dy[i]]=='\0')
                    {
                        board[keepx+dx[i]][keepy+dy[i]]='*';
                        keepx=keepx+dx[i];
                        keepy=keepy+dy[i];
                        return;
                    }
                }
            }
        }
        else  //'observation cell' does  not lie on any of the diagonal
        {
            for(int i=0;i<4;i++)  // O(N) time complexity where N is 9
            {
                if(keepx+dx1[i]<3&&keepx+dx1[i]>=0&&keepy+dy1[i]<3&&keepy+dy1[i]>=0)
                {
                    if(board[keepx+dx1[i]][keepy+dy1[i]]=='\0')
                    {
                        board[keepx+dx1[i]][keepy+dy1[i]]='*';
                        keepx=keepx+dx1[i];
                        keepy=keepy+dy1[i];
                        return;
                    }
                }
            }
        }
    }
    findEmptyCell(board);
}

bool findIfYouLLost(vector<vector<char>>&board) // function to check if the player lost
{
    int counth1=0,countv1=0,donex=0,doney=0,countd1=0,countd2=0,doned1=0,doned2=0;
    pair<int,int>px1,py1,dg1,dg2;
    if(keepx!=4&&keepy!=4)  // condition to check if the game has started 
    {
        for(int i=0;i<3;i++)  // O(N)  time complexity where N is 3
        {
            if(board[keepx][i]=='*')
            {
                counth1++;
            }
            else if(board[keepx][i]=='\0')
            {
                px1=make_pair(keepx,i);
                donex=1;
            }
        }
        for(int i=0;i<3;i++)  // O(N)  time complexity where N is 3
        {
            if(board[i][keepy]=='*')
            {
                countv1++;
            }
            else if(board[i][keepy]=='\0')
            {
                py1=make_pair(i,keepy);
                doney=1;
            }
        }
        for(int i=0;i<diag1.size();i++)  // O(N)  time complexity where N is 3
        {
            if(board[diag1[i].first][diag1[i].second]=='*')
            {
                countd1++;
            }
            else if(board[diag1[i].first][diag1[i].second]=='\0')
            {
                dg1=diag1[i];
                doned1=1;
            }
        }
        for(int i=0;i<diag2.size();i++)  // O(N)  time complexity where N is 3
        {
            if(board[diag2[i].first][diag2[i].second]=='*')
            {
                countd2++;
            }
            else if(board[diag2[i].first][diag2[i].second]=='\0')
            {
                dg2=diag2[i];
                doned2=1;
            }
        }
        if(countv1==2&&doney==1)
        {
            board[py1.first][py1.second]='*';
            cout<<"Better Luck Next Time"<<"\n";
            return 1;
        }
        else if(counth1==2&&donex==1)
        {
            board[px1.first][px1.second]='*';
            cout<<"Better Luck Next Time"<<"\n";
            return 1;
        }
        else if(countd1==2&&doned1==1)
        {
            board[dg1.first][dg1.second]='*';
            cout<<"Better Luck Next Time"<<"\n";
            return 1;
        }
        else if(countd2==2&&doned2==1)
        {
            board[dg2.first][dg2.second]='*';
            cout<<"Better Luck Next Time"<<"\n";
            return 1;
        }
    }
    return 0;
}
bool findIfYouWon(vector<vector<char>>&board,int *counth,int *countv,int *dia1,int *dia2,pair<int,int>&d1,pair<int,int>&d2,pair<int,int>&px,pair<int,int>&py,int *done1,int *di1,int *di2,int *done2,int x,int y)  //function to check if the player won
{
    for(int i=0;i<3;i++)  // O(N)  time complexity where N is 3
    {
        if(board[x][i]=='.')
        {
            *counth=*counth + 1;
        }
        else if(board[x][i]=='\0')
        {
            px=make_pair(x,i);
            *done1=1;
        }
    }
    for(int i=0;i<3;i++)   // O(N)  time complexity where N is 3
    {
        if(board[i][y]=='.')
        {
            *countv = *countv + 1;
        }
        else if(board[i][y]=='\0')
        {
            py=make_pair(i,y);
            *done2=1;
        }
    }
    for(int i=0;i<3;i++)  // O(N)  time complexity where N is 3
    {
        if(board[diag1[i].first][diag1[i].second]=='.')
        {
            *dia1 = *dia1 + 1;
        }
        else if(board[diag1[i].first][diag1[i].second]=='\0')
        {
            d1=diag1[i];
            *di1=1;
        }
    }
    for(int i=0;i<3;i++)  // O(N)  time complexity where N is 3
    {
        if(board[diag2[i].first][diag2[i].second]=='.')
        {
            *dia2 = *dia2 + 1;
        }
        else if(board[diag2[i].first][diag2[i].second]=='\0')
        {
            d2=diag2[i];
            *di2=1;
        }
    }
    if(*counth==3||*countv==3||*dia1==3||*dia2==3)
    {
        cout<<"You Won!!!"<<"\n";
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void findAlmostWon(vector<vector<char>>&board,int *counth,int *countv,int *dia1,int *dia2,pair<int,int>&px,pair<int,int>&py,pair<int,int>&d1,pair<int,int>&d2,int *done1,int *done2,int *di1,int *di2)  // program makes sure to give a tough competition
{
    if(*counth==2&&*done1==1)
    {
        board[px.first][px.second]='*';
        keepx=px.first;
        keepy=px.second;
        return;
        
    }
    if(*countv==2&&*done2==1)
    {
        board[py.first][py.second]='*';
        keepx=py.first;
        keepy=py.second;
        return;
    }
    if(*dia1==2&&*di1==1)
    {
        board[d1.first][d1.second]='*';
        keepx=d1.first;
        keepy=d1.second;
        return;
    }
    if(*dia2==2&&*di2==1)
    {
        board[d2.first][d2.second]='*';
        keepx=d2.first;
        keepy=d2.second;
        return;
    }
    checkFourorEightDirections(board);
}
void process(vector<vector<char>>&board)
{
    while(1) // O(N) time complexity  where N is 5 in worst cases
    {
        if(checkIfFull(board))  
        {
            cout<<"Its a Tie!!!"<<"\n";
            break;
        }
        int x,y;
        cout<<"These are the coordinates of the Tic Tac Toe board, enter the x and y coordinates accordingly"<<"\n";
        printBoard(board);
        cin>>x>>y;
        board[x][y]='.';
        
        
        int counth=0,countv=0,done1=0,done2=0,dia1=0,dia2=0,di1=0,di2=0;
        pair<int,int>px,py,d1,d2;
        
        if(findIfYouWon(board,&counth,&countv,&dia1,&dia2,d1,d2,px,py,&done1,&di1,&di2,&done2,x,y))
        {
            break;
        }
        if(checkIfFull(board))
        {
            cout<<"Its a Tie!!!"<<"\n";
            break;
        }
        if(findIfYouLLost(board))
        {
            break;
        }
        
        findAlmostWon(board,&counth,&countv,&dia1,&dia2,px,py,d1,d2,&done1,&done2,&di1,&di2);
    }
}
int main()
{
    diag1.push_back(make_pair(0,2));
    diag1.push_back(make_pair(1,1));
    diag1.push_back(make_pair(2,0));
    
    diag2.push_back(make_pair(0,0));
    diag2.push_back(make_pair(1,1));
    diag2.push_back(make_pair(2,2));
    
    int n;
    cout<<"HOW MANY GAMES YOU WANNA PLAY??"<<"\n";
    cin>>n;
    while(n)
    {
        vector<vector<char>>board(3,vector<char>(3));
        cout<<"Do You wanna start ???  Enter Yes or No"<<"\n";
        string quest;
        cin>>quest;
        if(quest=="Yes")
        {
            process(board);
        }
        else
        {
            board[0][2]='*';
            keepx=0;keepy=2;
            process(board);
        }
        n--;
    }
    return 0;
}