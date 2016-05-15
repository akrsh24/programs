#include<stdio.h>
void main()
{
    int i,min,t=0,pno[10],at[10],bt[10],rbt[10],n,st[10];
    int ct[10],wt[10],tat[10],flag[10],temp,x,last_id=0,k,pri[10],rt[10];
    float avgwt=0,avgtat=0;
    printf("Enter the no of process : ");
    scanf("%d",&n);
    printf("Enter the arrival time\n");
    for (i=0; i<n; i++)
    {
        scanf("%d",&at[i]);
        pno[i]=i+1;
        flag[i]=0;
    }
    printf("Enter the burst time\n");
    for (i=0; i<n; i++)
    {
        scanf("%d",&bt[i]);
        rbt[i]=bt[i];
    }
    printf("Enter the priority\n");
    for (i=0; i<n; i++)
    {
        scanf("%d",&pri[i]);
    }
    printf("\nThe Gantt chart is :\n");
    for(k=0; k<3; k++)
    {
        t=0;
        last_id=0;
        for (i=0; i<n; i++)
        {
            rbt[i]=bt[i];
            flag[i]=0;
        }
        if(k==1)
            printf("|");
        while(fl(flag,n)==0)
        {
            min=100;
            x=0;
            for(i=0; i<n; i++)
            {
                if((at[i]<=t)&&(rbt[i]!=0))
                {
                    x=1;
                    if(min>pri[i])
                    {
                        min=pri[i];
                        temp=i;
                    }
                }
            }
            if(x==1)
            {
                if(last_id!=pno[temp]&&k==0)
                    printf("________");
                else if(last_id!=pno[temp]&&k==1)
                    printf("__P-%d__|",pno[temp]);
                else if(last_id!=pno[temp]&&k==2)
                    printf("%d\t",t);
                if(bt[temp]==rbt[temp])
                    st[temp]=t;
                rbt[temp]--;
                if(rbt[temp]==0)
                {
                    ct[temp]=t+1;
                    flag[temp]=1;
                }
                last_id=pno[temp];
            }
            if(x==0)
            {
                if(k==0&&last_id!=-1)
                    printf("________");
                else if(k==1&&last_id!=-1)
                    printf("_idle._|");
                else if(k==2&&last_id!=-1)
                    printf("%d\t",t);
                last_id=-1;
            }
            t++;
        }
        printf("\n");
    }
    for(i=0; i<n; i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        rt[i]=st[i]-at[i];
        avgwt+=wt[i];
        avgtat+=tat[i];
    }
    avgwt/=n;
    avgtat/=n;
    printf("\nP.No.\tAT\tBT\tPri.\tST\tCT\tTAT\tWT\tRT\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pno[i],at[i],bt[i],pri[i],st[i],ct[i],tat[i],wt[i],rt[i]);
        printf("\nThe average waiting time is = %f",avgwt);
        printf("\nThe average turn around time is = %f",avgtat);
    }
    int fl(int flag[],int n)
    {
        int f=1,i;
        for(i=0; i<n; i++)
        {
            if(flag[i]==0)
            {
                f=0;
                break;
            }
        }
        return f;
    }

