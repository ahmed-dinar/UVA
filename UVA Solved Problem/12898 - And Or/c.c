#include<stdio.h>

#define i64 long long

int main()
{
    int t,T=0;
    i64 a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&a,&b);
        if(a==b){
            printf("Case %d: %lld %lld\n",++T,a,b);
        }
        else{
            i64 k=a;
            i64 i=a|(a+1);
            i64 n=a&(a+1);
            int res1=0,res2=0;
            while(1){

                if(res1 && res2) break;

                if(!res1){
                    if( n==0 )
                        res1 = 1;
                    else if( !( n & (n-1) ) ){
                        if(b>=(n<<1)) n=0;
                        res1  = 1;
                    }
                    else if( i>=b ){
                        res1 = 1;;
                    }
                    else{
                        n = n&(i+1);
                        i = i|(i+1);
                    }
                }
                if(!res2){
                    if(k>=b)
                        res2=1;
                    else
                        k=k|(k+1);
                }
            }
            printf("Case %d: %lld %lld\n",++T,k,n);
        }
    }
    return 0;
}

