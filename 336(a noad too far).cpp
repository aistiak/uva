#include<bits/stdc++.h>
#define ll long long
using namespace std ;
map <int,set<int> > m ;
map<int,int> level ;
set<int> visited ;
int network_size ;


void bfs(int start )
{
    int network_count  = 0;
    queue <int> q ;
    q.push(start); // assuming 0 is always the root node
    //color[0] = 0 ;
    level.clear();
    //visited.insert(start);
    level[start] =  1 ;
    while(!q.empty()) {

        int n = q.front();
        q.pop();

        for(set<int>::iterator it = m[n].begin() ; it!=m[n].end() ; it++) {


            if(level[*it] == 0) {
                //  cout  << *it << endl;
                level[*it] = level[n] + 1 ;
                q.push(*it) ;
            }


//             //cout << *it << endl;
//            if(visited.find(*it)!=visited.end())  // the element is in the list
//            {                                     // or it had been previously visited
//
//                 //cout << *it << endl;
//            }
//            else
//            {
//                //cout << *it << endl;
//                //int temp = *it ;
//                level[*it] = level[n] + 1 ; // level one extra then its parent
//                network_count++;
//                visited.insert(*it) ;
//                q.push(*it) ;
//            }
        }
        //network_count+=m[n].size()-1;


    }
    return ;

}
int main()
{
    // freopen("out.txt","w",stdout);
    int n , i = 0 , a , b  ,temp = 0, flag = 0; ;
    set<int > hold;
    while(scanf("%d",&n),n) {
        m.clear();
        hold.clear() ;
        for(int j = 0 ; j<n ; j++) {
            scanf("%d%d",&a,&b);
            m[a].insert(b);
            m[b].insert(a) ;
            hold.insert(a);
            hold.insert(b);
        }
        int r = hold.size();

        // qury
//          for(set<int> ::iterator it = hold.begin() ;it!=hold.end() ;it++){
//                  cout << *it <<endl;
//          }
//        for( map< int ,list<int> > ::iterator it = m.begin() ; it!=m.end() ; it++){
//             cout << it->first << endl;
//        }
        while(scanf("%d%d",&a,&b)) {
            if(a == 0 && b == 0 ) {
                break ;
            }
            // level = b + 1 ;

            visited.clear();
            bfs(a) ;
            temp = 0 ;
            for(map<int,int>::iterator it = level.begin() ; it!=level.end() ; it++) {
                //cout << "val = " << it->first << " lvl = " << it->second << endl;
                if(it->second<=b+1) {
                    temp++;
                    // cout <<  "temp  = "<< temp << endl;
                }
            }

            // in case the value of a is not present in the graph then

            if(hold.find(a) == hold.end()) {
                flag = 1 ;
            }
            if(flag == 1) {
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++i,r,a,b);
            }

            else {
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++i,r-temp,a,b);
            }
            flag = 0;
        }

    }

    return 0 ;
}
