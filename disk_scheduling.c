#include<stdio.h>
#define s 199
void main()
{
    int n,i,track[s],ch,c,t,head,seek=0,min,j,p,visit[s];
    clrscr();
    printf("\n enter the number of requests: ");
    scanf("%d",&n);
    printf("enter the track numbers: ");
    for(i=1; i<=n; i++)
    {
	scanf("%d",&track[i]);
	visit[i]=0;
    }
    printf("\n enter the head position");
    scanf("%d",&head);
    track[0]=head;
    do
    {
	printf("\n enter the choice:\n 1. FCFS\n 2. SSTF\n 3. SCAN \n 4. LOOK\n 5. CSCAN\n 6. CLOOK\n 7. exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	    for(i=0; i<n; i++)
		seek=seek+abs(track[i+1]-track[i]);
	    printf("%d",seek);
	    break;
	case 2:
	    seek=0;
	    while(1)
	    {
		min=199;
		for(i=1; i<=n; i++)
		    if (visit[i] == 0)
		    {
			if(min > abs(head - track[i]) && (head-track[i])!=0)
			{
			    min = abs(head - track[i]);
			    p = i;
			}
		    }
		if(min == 199)
		    break;
		visit[p]=1;
		seek=seek + min;
		head = track[p];
	    }
	    printf("\n Total seek time is: %d",seek);
	    break;
	case 3:
	head=track[0];
	    for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
		    if(track[i]>track[j])
		    {
			t=track[i];
			track[i] = track[j];
			track[j] = t;
		    }
	    seek=0;
	    for(i=0; i<n; i++)
	    {
		if(head < track[i])
		{
		    for(j=i-1; j>= 0; j--)
		    {
			seek=seek+abs(head - track[j]);
			head = track[j];
		    }
		    seek=seek+track[0];
		    head=0;
		    for(j = 1; j < n; j++)
		    {
			seek=seek+abs(head - track[j]);
			head = track[j];
		    }
		    break;
		}
	    }
	    printf("\n Total seek time : %d",seek);
	    break;
	case 4:
	    head=track[0];
	    for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
		    if(track[i]>track[j])
		    {
			t=track[i];
			track[i] = track[j];
			track[j] = t;
		    }
	    seek=0;
	    for(i=0; i<n; i++)
	    {
		if(head < track[i])
		{
		    for(j=i-1; j>= 0; j--)
		    {
			seek=seek+abs(head - track[j]);
			head = track[j];
		    }
		    for(j = 1; j < n; j++)
		    {
			seek=seek+abs(head - track[j]);
			head = track[j];
		    }
		    break;
		}
	    }
	    printf("\n Total seek time : %d",seek);
	    break;
	case 6:
	    head=track[0];
	    for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
		    if(track[i]>track[j])
		    {
			t=track[i];
			track[i] = track[j];
			track[j] = t;
		    }
	    seek=0;
	    for(i=0;i<n;i++)
	    visit[i]=0;
	    for(i=0; i<n; i++)
	    {
		if(head < track[i])
		{
		  for(j=i-1; j>= 0; j--)
		    {
			seek=seek+abs(head - track[j]);
			head = track[j];
			visit[j]=1;
		    }
		    seek=seek+abs(track[n-1]-track[0]);
		    head=track[n-1];
		    for(j = n; j >=i-1; j--)
		    {    if(visit[j]==0)
			  {
			   seek=seek+abs(head - track[j]);
			   head = track[j];
			   visit[j]=1;
			  }
		    }
		    break;
		}
	    }
	    printf("\n Total seek time : %d",seek);
	    break;
	case 5:
	 head=track[0];
	    for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
		    if(track[i]>track[j])
		    {
			t=track[i];
			track[i] = track[j];
			track[j] = t;
		    }
	    seek=0;
	    for(i=0;i<n;i++)
	    visit[i]=0;
	    for(i=0; i<n; i++)
	    {
		if(head < track[i])
		{
		    for(j=i-1; j>= 0; j--)
		    {
			seek=seek+abs(head - track[j]);
			head = track[j];
			visit[j]=1;
		    }
		    seek=seek+s;
		    head=s;
		    for(j = n; j>i-1; j--)
		    {    if(visit[j]==0)
			  {
			   seek=seek+abs(head - track[j]);
			   head = track[j];
			   visit[j]=1;
			  }
		    }
		    break;
		}
	    }
	    printf("\n Total seek time : %d",seek);
	    break;
	case 7:
	    exit(0);
	}
	printf("\n do you want to continue: 1. yes 2. no");
	scanf("%d",&c);
    }
    while(c==1);
}
