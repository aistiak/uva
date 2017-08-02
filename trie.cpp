// trie
// data structure

#include<bits/stdc++.h>
using namespace std ;
struct node{
    bool endmark ;
    node *next[27] ;

    // constructor
    node(){
       endmark = false ;
       for(int i = 0 ; i<26 ;i++)
          next[i] = NULL ;
     }

}*root;

void insrt(string str, int len){
     node* cur  = root ;

     for(int i = 0 ; i<len ;i++){
         int id = str[i] - 'a' ;
         if(cur->next[id] == NULL){
            cur->next[id] = new node();

         }
         cur = cur->next[id];
     }
      cur->endmark = true ;
}

bool serch(string str, int len){
     node* cur  = root ;

     for(int i = 0 ; i<len ;i++){
         int id = str[i] - 'a' ;
         if(cur->next[id] == NULL){
            return false ;
            //cur->next[id] = new node();

         }
         cur = cur->next[id];
     }
     return cur->endmark ;
}
void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
}
int main(){

    int n ;
    root = new node();
    string str;
    while(cin >> n){
         if(n == 1){

            // add
            cin >> str;
//            int len = strlen(str);
            insrt(str,str.length());
         }
         if(n == 2){
                cin >> str;
            //int len = strlen(str);

            if(serch(str,str.length()) == true) cout << "found" << endl;
            else cout << "not found" << endl;
         }else if(n == 3){
                del(root);
         }
    }
    return 0 ;
}

