#include<stdio.h>
#include<stdlib.h>

#define Ultra 2147483647.0

typedef struct node
{
	int name;
	float wt;
	int dis;
	struct node *next;
}NODE;

typedef struct heap
{
	NODE* list[100010];
	int index;
}HEAP;

void resetList(NODE *list[], int);
void clearList(NODE *list[], int);
NODE* createNode(int,float,int);
void insertNode(NODE**,NODE*);
void resetHeap(HEAP *);
void insertHeap(HEAP *,NODE *);
NODE* popHeap(HEAP *);

int func1(NODE* list[],int src,int end,int n);
int func2(NODE* list[],int src,int end,int n);

int ans_t;
int ans_d;

int main()
{
	int t,i;
	int T,N,M,A,B;
	int a,b,d,v;
	NODE *dis[10010];
	NODE *time[10010];

	scanf("%d",&T);

	for(t=0; t<T; t++)
	{
		resetList(dis,10009);
		resetList(time,10009);

		scanf("%d %d",&N,&M);
		scanf("%d %d",&A,&B);
		for(i=0; i<M; i++)
		{
			scanf("%d %d %d %d",&a,&b,&d,&v);

			insertNode(&dis[a],createNode(b,d,d));
			insertNode(&dis[b],createNode(a,d,d));
			insertNode(&time[a],createNode(b,(float)d/(float)v,d));
			insertNode(&time[b],createNode(a,(float)d/(float)v,d));
		}
		ans_d=func1(dis,A,B,N);
		ans_t=func2(time,A,B,N);
		printf("%d %d\n",ans_d,ans_t);
	}

	return 0;
}

int func1(NODE* list[],int src,int end,int n)
{
	int i,j;
	int a,b;
	float w;
	short visit[10010];
	int min_d[10010];
	HEAP heap;
	NODE first;
	NODE *current,*tmp;

	resetHeap(&heap);
	for(i=1;i<=n;i++)
	{
		visit[i]=0;
		min_d[i]=Ultra;
	}
	min_d[src]=0;
	first.name=src;
	first.wt=0;
	insertHeap(&heap,&first);

	for(i=1;i<=n;i++)
	{
		a=-1;
		while(heap.index>0)
		{
			current=popHeap(&heap);/*printf("current={%d, %d}\n",current->name,current->wt);*/
			if(visit[current->name]==0)
			{
				a=current->name;
				//free(current);
				break;
			}
			free(current);
		}
		//printf("a=%d\n",a);
		if(a==-1 || a==end)
			break;
		else
			visit[a]=1;

		while(list[a]!=NULL)
		{
			b=list[a]->name;
			w=list[a]->wt;
			if(visit[b]==0 && min_d[a]+w < min_d[b])
			{
				//printf("path to %d relax from %.2f to %.2f\n",b,min_d[b],min_d[a]+w);
				min_d[b]=min_d[a]+w;
				list[a]->wt=min_d[b];
				/*printf("insert={%d, %f}\n",list[a]->name,list[a]->wt);*/
				insertHeap(&heap,list[a]);
			}
			list[a]=list[a]->next;
		}
	}
	clearList(list,n);

	return min_d[end];
}

int func2(NODE* list[],int src,int end,int n)
{
	int i,j;
	int a,b;
	float w;
	short visit[10010];
	int min_d[10010];
	float min_t[10010];
	HEAP heap;
	NODE first;
	NODE *current,*tmp;

	resetHeap(&heap);
	for(i=1;i<=n;i++)
	{
		visit[i]=0;
		min_t[i]=Ultra;
	}
	min_d[src]=0;
	min_t[src]=0;
	first.name=src;
	first.wt=0;
	insertHeap(&heap,&first);

	for(i=1;i<=n;i++)
	{
		a=-1;
		while(heap.index>0)
		{
			current=popHeap(&heap);/*printf("current={%d, %d}\n",current->name,current->wt);*/
			if(visit[current->name]==0)
			{
				a=current->name;
				//free(current);
				break;
			}
			free(current);
		}
		//printf("a=%d\n",a);
		if(a==-1 || a==end)
			break;
		else
			visit[a]=1;

		while(list[a]!=NULL)
		{
			b=list[a]->name;
			w=list[a]->wt;
			if(visit[b]==0 && min_t[a]+w < min_t[b])
			{
				//printf("time to %d relax from %.2f to %.2f\n",b,min_t[b],min_t[a]+w);
				//printf("path to %d change from %.2f to %.2f\n",b,min_d[b],min_d[a]+list[a]->dis);
				min_t[b]=min_t[a]+w;
				min_d[b]=min_d[a]+list[a]->dis;
				list[a]->wt=min_t[b];
				/*printf("insert={%d, %f}\n",list[a]->name,list[a]->wt);*/
				insertHeap(&heap,list[a]);
			}
			list[a]=list[a]->next;
		}
	}
	clearList(list,n);

	return min_d[end];
}

void resetList(NODE *list[],int len)
{
	int i;
	for(i=0;i<=len;i++)
	{
		list[i]=(NODE*)NULL;
	}

	return;
}

void clearList(NODE *list[],int len)
{
	int i;
	NODE *tmp;

	for(i=0;i<=len;i++)
	{
		while(list[i]!=NULL)
		{
			tmp=list[i];
			list[i]=list[i]->next;
			//printf("free node:{name:%d,weight:%f}\n",tmp->name,tmp->wt);
			free(tmp);
		}
	}

	return;
}

void insertNode(NODE **tgt,NODE* input)
{
	if(*tgt==NULL)
	{
		/*printf("new\n");*/
		*tgt=input;
	}
	else
	{
		/*printf("insert\n");*/
		input->next=*tgt;
		*tgt=input;
	}
	return;
}

NODE* createNode(int name,float wt,int dis)
{
	NODE *newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->name=name;
	newnode->wt=wt;
	newnode->dis=dis;
	newnode->next=NULL;
	/*printf("create node:{%d,%f}\n",name,wt);*/
	return newnode;
}

void resetHeap(HEAP *heap)
{
	heap->index=0;
	return;
}

void insertHeap(HEAP *heap,NODE *node)
{
	int i;
	NODE *tmp;

	i=++(heap->index);
	heap->list[i]=node;
	while(i>1)
	{
		/*printf("i : %d\n",i);*/
		if((heap->list[i])->wt < (heap->list[i/2])->wt)
		{
			/*printf("switch : %d\n",(heap->list[i])->name);*/
			tmp=heap->list[i];
			heap->list[i]=heap->list[i/2];
			heap->list[i/2]=tmp;
			i/=2;
		}
		else
			break;
	}

	/*printf("push:index=%d\n",heap->index);
	printf("heap={\n");
	for(i=1;i<=heap->index;i++)
	{
		printf("%d_th={ %d,%f}\n",i,(heap->list[i])->name,(heap->list[i])->wt);
	}
	printf("}\n");*/
	return;
}

NODE* popHeap(HEAP *heap)
{
	int i;
	NODE* output;
	NODE* tmp;

	output=heap->list[1];
	heap->list[1]=heap->list[(heap->index)--];

	i=1;
	while(i*2 <= heap->index )
	{
		if(i*2+1 > heap->index)
		{
			if((heap->list[i])->wt < (heap->list[i*2])->wt)
			{
				tmp=heap->list[i];
				heap->list[i]=heap->list[i*2];
				heap->list[i*2]=tmp;
				i*=2;
			}
			else
			{
				i+=1;
			}
		}
		else
		{
			if((heap->list[i*2])->wt < (heap->list[i*2+1])->wt)
				i*=2;
			else
				i=i*2+1;
			if((heap->list[i])->wt < (heap->list[i/2])->wt)
			{
				tmp=heap->list[i];
				heap->list[i]=heap->list[i/2];
				heap->list[i/2]=tmp;
			}
		}
	}
	return output;
}
