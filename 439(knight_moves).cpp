
// knights move
#include<bits/stdc++.h>
//#define pii pair <int , int >
#define N 1010


using namespace std ;
// direction array
int fx[] = {-1, -1, 1, 1, -2, -2, 2, 2} ;
int fy[] = {2, -2, 2, -2, 1, -1, 1, -1 } ;
int blocked[N][N];
int visited[N][N] ;
int distance[N][N] ;
int d[N][N] ;
int row = 9, col= 9 ;
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
    queue <pii> q ;
    q.push(s_t) ; // pushing the root nodes on the queue

    while(!q.empty()) {
        // cout << "hello" << endl;
        pii t = q.front();
        q.pop();

        for(int k = 0 ; k<8 ; k ++) {
            int tx = t.first  + fx[k] ;
            int ty = t.second  + fy[k] ;

            // if the coordinates are valid
            // and node not visited or blocked then
            if(visited[tx][ty] == 0 and tx <row and tx>=0 and ty <col and ty>=0 ) {
                // cout << "hello" ;
                visited[tx][ty] = 1 ;
                // distance[tx][ty] =  1 ;
                d[tx][ty] =  1 + d[t.first][t.second] ;
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
    // cout << 'c' - 96 << endl;
    char ch1 , ch2 , ch3 ;
    int a , b , c ;
    int x1 , y1 , x2 , y2 ;
    while(scanf("%c%d %c%d\n",&ch1,&a,&ch2,&b)==4) {
        // start and end coordinates
        //cout << ch1 << a << " " << ch2 << b << endl;
        x1 = ch1 - 'a' ;
        y1 = a - 1 ;
        x2 = ch2 - 'a' ;
        y2 = b - 1;

        for (int i = 0 ; i<9 ; i++)
            for(int j = 0 ; j<9 ; j++) {
                d[i][j] = 0 ;
            }
        // cout << x1 << y1 << " " << x2 << y2 << endl;
        t_bfs(x1,y1);

        cout << d[x2][y2] << endl;
//       flush(cin);
    }

    return 0 ;
}
