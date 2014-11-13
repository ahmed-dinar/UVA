 #include <stdio.h>
 #include <string.h>

char fi[5001][1050];

void fibo()
{
    int j,i,z,cry,ii,h,k;
    int fm,lnf,lns;
    char f[1050] = {"1"},s[1050] = {"0"},sum[1050]={"1"};
    for(ii=0; ii<=5000; ii++)
    {
        strcpy(fi[ii],f);
        lnf = strlen(f)-1;
        lns = strlen(s)-1;
        for(i=lnf,j=0,cry = 0; i>=0; i--,j++,lnf--,lns--)
        {
            if(i == 0)
            {
                if(lns<0)
                    fm = (f[lnf]-48) + cry;
                else if(lnf<0)
                    fm = (s[lns]-48) + cry;
                else
                    fm = (f[lnf]-48) + (s[lns]-48) + cry;

                if( fm >= 10){
                    sum[j] = fm%10+48;
                    sum[j+1] = fm/10+48;
                    break;
                }
                else{
                    sum[j] = fm+48;
                    break;
                }
            }

            if( lns < 0 )
            {
                fm = (f[lnf]-48) + cry;
                sum[j] = fm%10+48;
                cry = fm/10;
                continue;

            }
            else if( lnf < 0)
            {
                fm = (s[lns]-48) + cry;
                sum[j] = fm%10+48;
                cry = fm/10;
                continue;
            }
            fm = (f[lnf]-48) + (s[lns]-48) + cry;
            if( fm >= 10)
                sum[j] = fm%10+48;
            else
                sum[j] = fm+48;
            cry = fm/10;
        }
        sum[strlen(sum)] = '\0';
        strcpy(s,f);
        for(h=strlen(sum)-1,k=0; h>= 0; h--,k++)
        {
            f[k] = sum[h];
        }
        f[k] = '\0';
    }
}

int main()
{
    fibo();
    int ms;
    while( scanf("%d",&ms) == 1)
    {
        if( ms == 0)
            printf("The Fibonacci number for %d is %d\n",ms,ms);
        else
            printf("The Fibonacci number for %d is %s\n",ms,fi[ms-1]);
    }
    return 0;
}
