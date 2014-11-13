#include<stdio.h>
#include<stdlib.h>

int n[1000005],m[1000005];

int main()
{
    int N,M,co,i,j,k;
    while(scanf("%d %d",&N,&M)==2)
    {
        if(N==0&&M==0)
            break;

        for(i=0; i<N; i++)
            scanf("%d",&n[i]);

        for(i=0; i<M; i++)
            scanf("%d",&m[i]);

        co=0;
        k=0;
        if(N<M){
            for(i=0; i<N; i++){
                for(j=k; j<M; j++){
                    if(n[i]<m[j])
                        break;
                    if(n[i]==m[j]){
                        k=j+1;
                        co++;
                        break;
                    }
                }
            }
        }
        else{
            for(i=0; i<M; i++){
                for(j=k; j<N; j++){
                    if(m[i]<n[j])
                        break;
                    if(m[i]==n[j]){
                        k=j+1;
                        co++;
                        break;
                    }
                }
            }
        }
        printf("%d\n",co);
    }
	return 0;
}
