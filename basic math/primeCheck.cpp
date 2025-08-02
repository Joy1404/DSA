#include<iostream>
#include<set>
using namespace std;
int main(){
int n,count=0;
 cin>>n;
//  for(int i=1;i<=n;i++){
//     if(n%i==0){
//         count++;
        
//     }
// }
 for(int i=1;i*i<=n;i++){
    if(n%i==0){
        count++;  
        if((n/i)!=i){
            count++;
        }
    }
}
if(count==2){
    cout<<"prime number";
}else{
    cout<<"non prime number";
}
    
 return 0;
}