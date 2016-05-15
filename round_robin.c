#include<stdio.h>
int main()
{
  int i,n,time,remain,flag=0,time_quantum;
  int at[10],bt[10],rbt[10],ct[10],tat[10],wt[10],GC1[30],GC2[30],j=0,k=0;
  GC2[k++]=0;
  float avgwt1=0,avgtat1=0;
  printf("Enter Total Process:\t");
  scanf("%d",&n);
  remain=n;
  for(i=0;i<n;i++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",i+1);
    scanf("%d",&at[i]);
    scanf("%d",&bt[i]);
    rbt[i]=bt[i];
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&time_quantum);
 for(time=0,i=0;remain!=0;)
  {
    if(rbt[i]<=time_quantum && rbt[i]>0)
    {
      time+=rbt[i];
      rbt[i]=0;
      flag=1;
      GC1[j++]=i+1;
      GC2[k++]=time;
    }
    else if(rbt[i]>0)
    {
      rbt[i]-=time_quantum;
      time+=time_quantum;
      GC1[j++]=i+1;
      GC2[k++]=time;
    }
    if(rbt[i]==0 && flag==1)
    {
      remain--;
     ct[i]=time;
     tat[i]=ct[i]-at[i];
     wt[i]=tat[i]-bt[i];
      flag=0;
         avgtat1=tat[i]+avgtat1;
         avgwt1=wt[i]+avgwt1;
    }
    if(i==n-1)
      i=0;
    else if(at[i+1]<=time)
      i++;
    else
      i=0;
  }
 printf("\n\n\n____________________________________________________________________\n");
         printf("\n\nTABLE\n");
         printf("____________________________________\n");
         printf(" sn  |  at |  bt | ct  |  tat | wt | \n");
         printf("____________________________________\n");
    for(i=0;i<n;i++)
    {
         printf("%4d |%4d |%4d |%4d |%4d |%4d |"  ,i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
         printf("\n");
    }
        printf("\nGantt Chart\n");
       printf("_______________________________________________________________________\n");
         for(i=0;i<j;i++)
        {     printf("| P%d ",GC1[i]);     }
        printf("|\n-----------------------------------------------------------------------\n");
         printf("%d",GC2[0]);
         for(i=1;i<k;i++)
        {                    printf("%5d",GC2[i]);     }
          printf("\n\n");
          avgwt1=avgwt1/n;
         avgtat1=avgtat1/n;
         printf("\nAverage waiting time=%f",avgwt1);
         printf("\nAverage turn around time=%f",avgtat1);
         printf("\n----------------------------------------\n");
  return 0;
}

