#include<stdio.h>
#include<stdbool.h>
int main()
{
	int m,n,i,j,k,count,max=0,t,pos;
	printf("Enter the values of m and n:\n");
	scanf("%i%i",&m,&n);
	int avail[m],alloc[n][m],req[n][m],work[m],temp[m];
	
		
	printf("Enter the Allocation:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{	
			scanf("%i",&alloc[i][j]);
		}
	}
	
	printf("Enter the Request:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{	
			scanf("%i",&req[i][j]);
		}
	}
	
	printf("Enter the Available:\n");
	for(i=0;i<m;i++)
	{
		scanf("%i",&avail[i]);
	}
	
		bool finish[100]={false};
		for(i=0;i<m;i++)
			work[i]=avail[i];
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(alloc[i][j]==0)
				{
					finish[i]=true;
				}
				else
				{
					finish[i]=false;
					break;
				}
			}
			
			if(finish[i]==true)
				printf("Executed:p%i\n",i);
		}
	
		for(i=0;i<n;i++)
		{
			if(finish[i]==false)
			{
				for(j=0;j<m;j++)
				{
					if(req[i][j]>work[j])
					{
						break;
					}
				}
				
				if(j==m)
				{
					finish[i]=true;
					printf("Executed:p%i\n",i);
					for(j=0;j<m;j++)
					{
						work[j]+=alloc[i][j];
						
					}
					i=-1;
				}
			}
		}
		
			
		for(i=0;i<n;i++)
		{
			if(finish[i] == false)
			{
				for(k=0;k<m;k++)
					temp[k] = work[k];
					
				count = 0;
				printf("\n\n\nProcess in deadlock:p%i\n",i);
				for(j=0;j<n;j++)
				{
					max=-1;
					if(finish[j]==true || j==i)
						continue;
					else
					{	
						for(t=0;t<n;t++)
						{
							if(t==i || finish[t]==true)
								continue;
							else
							{
								if(max < (alloc[t][0]+alloc[t][1]+alloc[t][2]) )
								{
									max=(alloc[t][0]+alloc[t][1]+alloc[t][2]);
									pos = t;
								}
							}
						}
						
						printf("terminating process: p%i\n",pos);
						count++;
						for(k=0;k<m;k++)
						{
							temp[k]+=alloc[pos][k];				
						}
						for(k=0;k<m;k++)
						{
							if(req[i][k]>temp[k])
								break;
						}
						if(k==m)
							break;
					}
				}
				for(k=0;k<m;k++)
				{
					if(req[i][k]>temp[k])
						break;
				}
				if(k==m)
					printf("We have to terminate %i process\n",count);
				else
					printf("Even after terimanting all process process:p%i cannot be out of deadlock\n",i);
			}
		}
	
	
	return 0;	
}
