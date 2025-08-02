#include <iostream>
using namespace std;
void print7(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print8(int n){
      for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j <i; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 0; j <2*(n-i)-1; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j <i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print10(int n){
    for(int i=1;i<=2*n-1;i++){
        int stars=i;
        if(i>n) stars=2*n-i;
        for(int j=1;j<=stars;j++){
            cout<<"*";
        }
        cout<<endl;

    }
}
void print11(int n){
    int st=1;
    for(int i=0;i<n;i++){
        if(i%2==0) st=1;
        else st=0;
        for(int j=0;j<=i;j++){
            cout<<st;
            st=1-st;
        }
        cout<<endl;

    }
}
void print12(int n){
    int space=2*(n-1);
    for(int i=1;i<=n;i++){
        //number
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        //space
        for(int j=1;j<=space;j++){
            cout<<" ";
           
        }
        //number
        for(int j=i;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
         space-=2;
    }
}
void print13(int n){
   int dig=1;
   for(int i=1;i<=n;i++){
    for(int j=0;j<i;j++){
        cout<<dig<<" ";
        dig++;
    }
    cout<<endl;
   }
}
void print14(int n){
//     for(int i=1;i<=n;i++){
//        char dig='A';
//     for(int j=0;j<i;j++){
//         cout<<dig;
//         dig++;
//     }
//     cout<<endl;
//    }
    for(int i=1;i<=n;i++){
    for(char ch='A';ch<'A'+i;ch++){
        cout<<ch<<" ";
    }
    cout<<endl;
   }
}
void print15(int n){
     for(int i=1;i<=n;i++){
    for(char ch='A';ch<='A'+(n-i);ch++){
        cout<<ch<<" ";
    }
    cout<<endl;
   }
}
void print16(int n){
    char ch='A';
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<ch;
        }
        cout<<endl;
        ch++;
    }

}
void print17(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // char
        char ch='A';
        for(int j=1;j<=2*i+1;j++){
            if(j<=((2*i+1)/2)){ 
                cout<<ch;
                ch++;
            }
            else {
                cout<<ch;
                ch--;
            }


        }
       
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void print18(int n){
    for(int i=0;i<n;i++){
        for(char ch='E'-i;ch<='E';ch++){
            cout<<ch;
        }
        cout<<endl;
    }
    // for(int i=0;i<n;i++){
    //     char ch='E'-i;
    //     for(int j=0;j<=i;j++){
    //         cout<<ch;
    //         ch++;
    //     }
    //     cout<<endl;
    // }
}
void print19(int n){
    // for(int i=0;i<n;i++){
    //     //star
    //     for(int j=0;j<=n-i-1;j++){
    //         cout<<"*";
    //     }
    //     //space
    //     for(int j=0;j<2*i;j++){
    //         cout<<" ";
    //     }
    //     //star
    //     for(int j=0;j<=n-i-1;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    //  for(int i=1;i<=n;i++){
    //     //star
    //     for(int j=1;j<=i;j++){
    //         cout<<"*";
    //     }
    //     //space
    //     for(int j=1;j<=2*(n-i);j++){
    //         cout<<" ";
    //     }
    //     //star
    //     for(int j=1;j<=i;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    int inis=0;
    for(int i=0;i<n;i++){
        //star
        for(int j=1;j<=n-i;j++){
            cout<<"*";
        }
        //space
        for(int j=0;j<inis;j++){
            cout<<" ";
        }
        //star
        for(int j=1;j<=n-i;j++){
            cout<<"*";
        }
        inis+=2;
        cout<<endl;
    }
     inis=8;
     for(int i=1;i<=n;i++){
        //star
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        //space
        for(int j=0;j<inis;j++){
            cout<<" ";
        }
        //star
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        inis-=2;
        cout<<endl;
    }
    
}
void print20(int n){
    int inis=2*n-2;
     for(int i=1;i<=2*n-1;i++){
        int stars=i;
        if(i>n){ stars=2*n-i;
        }
        //star
        for(int j=1;j<=stars;j++){
            cout<<"*";
        }
        //space
       for(int j=0;j<inis;j++){
            cout<<" ";
        }
        if(i<n)inis-=2;
       else inis+=2;
        
        
    
    //star
     for(int j=1;j<=stars;j++){
            cout<<"*";
        }
        cout<<endl;
     }
    }
void print21(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0||i==n-1||j==0||j==n-1){
                cout<<"*";
            }
           else  cout<<" ";
        }
        cout<<endl;
    }
}
void print22(int n){
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top=i;
            int left=j;
            int down=(2*n-2)-i;
            int right=(2*n-2)-j;
            cout<<(n-min(min(top,down),min(left,right)));
        }
        cout<<endl;
    }
}

int main()
{
    int t;
    cin >> t;
    int n;
    for (int i = 0; i < t; i++)
    {
        cout << "enter the number of rows:";
        cin >> n;
        print21(n);
    }
    return 0;
}