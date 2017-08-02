#include<bits/stdc++.h>
//#define pii pair <int , int >
#define N 1010


using namespace std ;
// direction array
int fx[] = {-2,-2,2,2,1,1,-1,-1} ;
int fy[] = {1,-1,1,-1,-2,2,-2,2} ;
int blocked[N][N];
int visited[N][N] ;
int distance[N][N] ;
int d[N][N] ;
int row  = 8, col = 8 ;
struct pii {
    int first ;
    int second ;
};
void t_bfs( int x , int y )  // source node`s
{

    memset(visited,0,sizeof(visited));
    visited[x][y] = 1 ;
    pii s_t ;
    s_t.first = x ;
    s_t.second = y ;
    d[x][y] = 0 ;
    queue <pii> q ;
    q.push(s_t) ; // pushing the root nodes on the queue

    while(!q.empty()) {

        pii t = q.front();
        q.pop();

        for(int k = 0 ; k<8; k ++) {
            int tx = t.first  + fx[k] ;
            int ty = t.second  + fy[k] ;

            // if the coordinates are valid
            // and node not visited or blocked then
            if(visited[tx][ty] == 0 and tx <=row and tx>0 and ty <=col and ty>0 ) {
                // cout << "hello" ;
                visited[tx][ty] = 1 ;
                // distance[tx][ty] =  1 ;
                d[tx][ty] = 1 +  d[t.first][t.second];
                //d[tx][ty] =  min(1 + d[t.first][t.second],d[tx][ty]) ;
                //cout << "d = " << d[tx][ty] << endl;
                s_t.first = tx ;
                s_t.second = ty ;
                q.push(s_t);
            }
        }
    }

}
int main()
{

//    freopen("out.txt","w",stdout) ;

    char ch ,ch2;
    int in1 , in2 , in3 , in4 ;

    while(cin >> ch >> in2 >> ch2 >> in4) {

        in1 = ch - 96 ;
        in3 = ch2 - 96 ;
        /// clearing the d arry
        for(int i = 1 ; i<=8 ; i++){
            for(int j = 1 ; j<=8 ;j++){
               d[i][j] = 0;
            }
        }
        t_bfs(in1,in2);

        cout << "To get from "<< ch << in2<<" to "<< ch2 << in4 <<" takes " << d[in3][in4] << " knight moves." << endl;



    }
    return 0 ;
}

