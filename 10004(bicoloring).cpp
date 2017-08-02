// bfs related problem
#include<bits/stdc++.h>
using namespace std ;
map <int,list<int> > node ;
int color[200] ;

bool bfs()
{

    queue <int> q ;
    q.push(0); // assuming 0 is always the root node
    color[0] = 0 ;

    while(!q.empty())
    {

        int n = q.front();
        q.pop();

        for(list<int>::iterator it = node[n].begin() ; it!=node[n].end() ; it++)
        {
            // just need to check if the parent and the child
            // node have the same color value
            // if they do they were siblings once upon a time
            // now as being parent they have a edge between them
            // so if this case the graph can`t be bi-color
            if(color[*it]==-1)  // not colored before
            {
                color[*it] = 1 - color[n] ;
                q.push(*it);

            }
            else if( color[*it] == color[n])
            {
                return false ;
            }
        }
    }

    return true ;


}
int main()
{

    int casees = 0 , n , edges , a , b  ;

    while(cin >> n >> edges,n)
    {
        node.clear();
        fill(color,color+n,-1);
        for(int i = 0 ; i<edges ; i+=1)
        {
            cin >> a >> b ;
            node[a].push_back(b);
            node[b].push_back(a);
        }

        if(bfs())
        {
            cout << "BICOLORABLE." <<endl;
        }
        else
        {
            cout << "NOT BICOLORABLE."<< endl;
        }

    }
    return 0 ;
}
