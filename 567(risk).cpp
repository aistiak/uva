// shortest path problem
// bfs
#include<bits/stdc++.h>
#define ll long long
#define inf 999999
using namespace std ;
map<int  ,set<int> > nodes ;
map<int ,int > m ;

struct str
{
    int from ;
    int to ;
    int val ;
};
vector <str> v ;
void bfs(int start )
{
    queue <int > q ;
    set <int> hold ;
    q.push(start);
    hold.insert(start) ;
    m[start] =    0; // the root node is at level zero
    while(!q.empty())
    {
        int  n = q.front() ;
        q.pop();
        for(set<int>::iterator it =nodes[n].begin() ; it!=nodes[n].end() ; it++ )
        {
            // cout << *it << endl;
            // if(m[*it]>m[n]+1){
            if(m[*it] == -1 )
            {
                m[*it]  = m[n] + 1 ; // extra one to buffer the -1 from value
                //if()
                q.push(*it) ; // if it had not been previously visited then it is pushed
            }
        }

    }
}
int main()
{
  //  freopen("out.txt","w",stdout) ;
    int n , temp, a , b , flag = 0 , counter = 1 ;
    while(1)
    {

        nodes.clear() ;
        v.clear() ;
        for(int i = 1; i <=19 ; i++)
        {

            if(scanf("%d",&n) == EOF) return 0;

//            cin >> n ;
//            if( n == EOF)
//            {
//                return 0 ;
//                flag = 1 ;
//                break ;
//            }
            while(n--)
            {
                cin >> temp ;
                nodes[i].insert(temp) ;
                nodes[temp].insert(i)  ;
            }
        }


//  see the representation
//     int p = 1 ;
//     for(map<int , set<int> > ::iterator it1 = nodes.begin()  ;it1!=nodes.end() ;it1++){
//            cout <<  p++ <<"  = "   ;
//            for(set<int>::iterator it = nodes[it1->first].begin() ;it!=nodes[it1->first].end() ;it++){
//                 cout << *it << " ";
//            }
//            cout << endl;
//     }

        cin >> n ;

        for(int i = 0 ; i<n ; i++)
        {
            cin >> a >> b ;
            m.clear() ;
            for(int j = 1 ; j <=20 ; j++)
            {
                m[j] =  -1;
            }
            bfs(a) ;
//        for(map<int,int>::iterator it = m.begin() ; it!=m.end() ; it++){
//        cout << it->first << " " << it->second << endl;
//        }
            //bfs(a) ;
            str t ;
            t.from = a ;
            t.to = b ;
            t.val = m[b] ;
            v.push_back(t);
            //cout << m[b] << endl;
        }

        printf("Test Set #%d\n",counter++);
        for(int k = 0 ; k<v.size() ; k++)
        {
            printf("%2d to %2d: %d\n",v[k].from , v[k].to , v[k].val);
        }
        printf("\n");
    }
    return 0;
}
