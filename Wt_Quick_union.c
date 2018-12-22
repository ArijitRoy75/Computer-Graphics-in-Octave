#include<stdio.h>
#include<stdlib.h>
#define max 10
int q_find[max],sz[max],i;
void find()
{
	int p,q,pid,qid;
	printf("\nEnter components for quick union root:\n");
	scanf("%d%d",&p,&q);
	pid=root(q_find,p);
	qid=root(q_find,q);
	if(qid==pid)
		printf("\nComponents %d and %d are connected\n",pid,qid);
	else
		printf("\nComponents %d and %d are not connected\n",pid,qid);
}
int root(int q_find[], int p)
{
	if(p==q_find[p])
		return p;
	else
		root(q_find,q_find[p]);	
}
void q_union()
{
	int qid,pid,p,q;
	printf("\nEnter components for Union:\n");
	scanf("%d%d",&p,&q);
	qid=root(q_find,q_find[q]);
	pid=root(q_find,q_find[p]);
	if(sz[pid]>=sz[qid])
	{
		sz[pid]+=sz[qid];
		q_find[qid]=q_find[pid];
	}
	else
	{
		sz[qid]+=sz[pid];
		q_find[pid]=q_find[qid];
	}
}
void disp()
{
	printf("\n");
	for(i=0;i<max;i++)
		printf("%d",i);
	printf("\n");
	for(i=0;i<max;i++)
		printf("%d",q_find[i]);
	printf("\n");
	for(i=0;i<max;i++)
		printf("%d",sz[i]);
	printf("\n");
}
int main()
{
	int opt;
	for(i=0;i<max;i++)
		q_find[i]=i;
	for(i=0;i<max;i++)
		sz[i]=1;
	while(1)
	{
		printf("\n Option 1: Union");
		printf("\n Option 2: Connected");
		printf("\n Option 3: Display");
		printf("\n Option 4: Exit");
		printf("\n Enter Your Choice: ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: 
				q_union();
				break;
			case 2:
				find();
				break;
			case 3:
				disp();
				break;
			case 4: 
				exit(0);
			default:
				printf("\nUnrecognized Action. Please Try Again!");
		}
	}
}

