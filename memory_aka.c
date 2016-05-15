#include<stdio.h>
int MP[10],PS[10],p,mp;
void Best_Fit();
void Worst_Fit();
void First_Fit();
void main()
{    int i,j,ch;
    printf("\nEnter no. of memory partition\n");
    scanf("%d",&mp);
    printf("Enter memory partition\n");
    for(i=0; i<mp; i++)
    {        scanf("%d",&MP[i]);    }
    printf("Enter no. process\n");
    scanf("%d",&p);
    printf("Enter memory partition\n");
    for(i=0; i<p; i++)
    {        scanf("%d",&PS[i]);    }
    do
    {   printf("\n1->Best fit\n2->Worst fit\n3->First fit\n4->default\t");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nBEST FIT\n");
            Best_Fit();
            break;
        case 2:
            printf("\nWORST FIT\n");
            Worst_Fit();
            break;
        case 3:
            printf("\nFIRST FIT\n");
            First_Fit();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice\n");
        }
    }while(ch!=4);
}
void Best_Fit()
{    int temp,po[10],temp1,count,y,z,i,k;
    for(y=0; y<mp; y++)
    {
               for(z=y; z<mp; z++)
        {            if(MP[y]>MP[z])
            {        temp=MP[y];
                     MP[y]=MP[z];
                     MP[z]=temp;
            }       }    }
    for(i=0; i<p; i++)
    {   count=0;
        for(k=0; k<mp; k++)
        {   if(PS[i]<=MP[k])
            {   printf("\nprocess of  size %d KB allocated into memory size of %d\n",PS[i],MP[k]);
                MP[k]=MP[k]-PS[i];
                break;   }
            else
            {                count++;   }   }
        if(count>p)
        {  printf("\nprocess of  size %d KB can't be allocated\n",PS[i]);   }   }
}
void Worst_Fit()
{   int temp,po[10],temp1,count,y,z,i,k;
    for(y=0; y<mp; y++)
    {  for(z=y; z<mp; z++)
        {    if(MP[y]<MP[z])
            {   temp=MP[y];
                MP[y]=MP[z];
                MP[z]=temp;  }  }  }
    for(i=0; i<p; i++)
    {   count=0;
        for(k=0; k<mp; k++)
        {  if(PS[i]<=MP[k])
            {   printf("\nprocess of  size %d KB allocated into memory size of %d\n",PS[i],MP[k]);
                MP[k]=MP[k]-PS[i];
                break;   }
           else
            {  count++;  }   }
        if(count>p)
        {   printf("\nprocess of  size %d KB can't be allocated\n",PS[i]);   }   }
}
void First_Fit()
{   int i,j,k,count;
    for(i=0; i<p; i++)
    {   count=0;
        for(k=0; k<mp; k++)
        {  if(PS[i]<=MP[k])
            {   printf("\nprocess of  size %d KB allocated into memory size of %d\n",PS[i],MP[k]);
                MP[k]=MP[k]-PS[i];
                printf("new memory partition of size %d is created",MP[k]);
                break;    }
            else
            {  count++;  }   }
        if(count>p)
        { printf("\nprocess of  size %d KB can't be allocated\n",PS[i]);  }
    }
}
