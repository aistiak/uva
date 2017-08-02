// getting wa !!!
#include<bits/stdc++.h>
//#define pii pair <int , int >
#define N 1010


using namespace std ;
// direction array
int fx[] = {1,-1,0,0} ;
int fy[] = {0,0,1,-1} ;
int blocked[N][N];
int visited[N][N] ;
int distance[N][N] ;
int d[N][N] ;
int row , col ;
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
        pii t = q.front();
        q.pop();

        for(int k = 0 ; k<4 ; k ++) {
            int tx = t.first  + fx[k] ;
            int ty = t.second  + fy[k] ;

            // if the coordinates are valid
            // and node not visited or blocked then
            if(visited[tx][ty] == 0 and blocked[tx][ty]!=-1 and tx <row and tx>=0 and ty <col and ty>=0 ) {
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

    // freopen("out.txt","w",stdout) ;
    int r ,c , t, n  , tc, tr , tn ;
    while (cin >> row >> col ) {
        // row-=1 ; col-=1 ;
        if(row == 0 && col == 0 ) {
            break ;
        }
        cin >> t ;
        while(t--) {
            cin >> tr ;
            cin >> tn ;
            for(int k = 0 ; k <tn ; k++) {

                cin >> tc ;
                blocked[tr][tc] = -1 ;
            }

        }
        int m , n , a,  b ;
        cin >> m >> n ;
//    if(a == 0 && b ==0) {
//        cout << 0 << endl;
//        return 0;
//    }
        t_bfs(m,n) ;
        cin >> a >> b;


        cout << d[a][b] << endl ;

    }
    return 0 ;
}
