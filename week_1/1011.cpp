#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    int howmany;
    cin>>howmany;
    for(int i=0;i<howmany;i++){
        int start, end, n;
        cin>>start>>end;
        n=sqrt(end-start);
        
        cout<<2*n-1+ceil((float)(end-start-n*n)/n)<<endl;
    }
    return 0;
}
