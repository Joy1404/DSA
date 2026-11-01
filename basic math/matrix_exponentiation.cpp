#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef vector<vector<long long>> Matrix;

Matrix matrixmultiplication(Matrix &A,Matrix&B){
    Matrix result(2,vector<long long>(2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                result[i][j]=(result[i][j]+ A[i][k]*B[k][j])%mod;
            }
        }
    }
    return result;
}
Matrix matrixExponentiation( Matrix &base, int exponent){
    if(exponent==0){
        Matrix identity(2,vector<long long>(2,0));
        for(int i=0;i<2;i++) identity[i][i]=1;    
        return identity;
    }
    if(exponent==1){
        return base;
    }
    Matrix half=matrixExponentiation(base,exponent/2);
    Matrix result=matrixmultiplication(half,half);
    if(exponent%2==1){
        result=matrixmultiplication(result,base);
    }
    return result;
    }

    int main(){
        int n;
        cin>>n;
        if(n==0){ cout<<"fibonacci"<<n<<"= 0"<<endl;
            return 0;
        }
        Matrix T = {{1,1},{1,0}};
        Matrix mat = {{1},{0}}; // base case f(1) = 1 , f(0) = 0;
        Matrix Tn = matrixExponentiation(T,n-1);
        Matrix result = matrixmultiplication(Tn,mat);
        cout<<result[0][0]<<endl;
    }
