#include<stdio.h>

void main()
{

    int n,s[50],a[10],i,j,k,l,ch,st,c,ct,f,pf=0,nw[3],flag[3];

    printf("enter no of pages to be entered\n");

    scanf("%d",&n);

    printf("Enter the page nos.\n");

    for(i=0; i<n; i++)
    {

        scanf("%d",&s[i]);
    }

    do
    {

        printf("\nEnter choice\n1.FIFO\n2.LRU\n3.optimal\n4.end\n");

        scanf("%d",&ch);

        if(ch==1)
        {

            for(i=0; i<3; i++)
            {

                a[2-i]=s[i];

                pf=pf+1;

            }

            for(i=3; i<n; i++)
            {

                if(s[i]!=a[0] && s[i]!=a[1] && s[i]!=a[2])
                {

                    a[2]=a[1];

                    a[1]=a[0];

                    a[0]=s[i];

                    pf=pf+1;

                }

            }
            printf("no of page fault = ");

            printf("%d",pf);

        }

        else if(ch==2)
        {

            pf=0;

            for(i=0; i<3; i++)
            {

                a[2-i]=s[i];

                pf=pf+1;

            }

            for(i=3; i<n; i++)
            {

                if(s[i]!=a[0] && s[i]!=a[1] && s[i]!=a[2])
                {

                    a[2]=a[1];
                    a[1]=a[0];

                    a[0]=s[i];

                    pf=pf+1;

                    else if(s[i]==a[1])
                    {

                        c=a[1];

                        a[1]=a[0];

                        a[0]=c;

                        else if(s[i]==a[2])
                        {

                            c=a[2];

                            a[2]=a[1];

                            a[1]=a[0];

                            a[0]=c;

                            printf("no of page fault = ");

                            printf("%d",pf);

                            else if(ch==3)
                            {

                                for(i=0; i<3; i++)
                                {

                                    a[2-i]=s[i];

                                    pf=pf+1;

                                    for(i=3; i<n; i++)
                                    {

                                        for(j=0; j<2; j++)
                                        {

                                            flag[j]=0;
                                        }

                                        if(s[i]!=a[0] && s[i]!=a[1] && s[i]!=a[2])
                                        {

                                            ct=0;

                                            for(k=i+1; k<n; k++)
                                            {

                                                for(l=0; l<3; l++)
                                                {

                                                    if(s[k]==a[l] && flag[l]==0)
                                                    {

                                                        nw[ct]=s[k];

                                                        flag[l]=1;

                                                        ct++;

                                                    }

                                                }

                                            }

                                            for(k=0; k<3; k++)
                                            {

                                                if(a[k]==nw[2])
                                                {

                                                    a[k]=s[i];

                                                }

                                            }

                                            pf=pf+1;

                                        }

                                    }

                                    printf("no of page fault = ");

                                    printf("%d",pf);

                                }

                                else

                                    printf("wrong choice");

                            }
                            while(ch!=4);
                        }
