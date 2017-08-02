
// 834 -Continued Fractions
#include<bits/stdc++.h>
using namespace std ;

int main(){
   //freopen("out.txt","w",stdout);
    int a , b , c ;
    vector<int> in ;

    while(cin >>a >> b ){
         in.clear();

        if(a == 1){
            printf("[0;%d]\n",b);
            continue ;
        }

        while(a!=1){

            c = a / b ;
            a-=c*b;

            in.push_back(c);
            swap(a,b);
        }

        printf("[%d;%d",in[0],in[1]);

        for(int i = 2 ; i<in.size() ; i++){
             printf(",%d",in[i]);
        }
        printf("]\n");
    }

    return 0 ;
}
