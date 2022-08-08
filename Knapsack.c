#include<stdio.h>
#include<conio.h>
int a[10][10],n;
void bfs(int);
void main()
{
 int i,j,src;
 clrscr();
 printf("\nenter the no of nodes:\t");
 scanf("%d",&n);
 printf("\nenter the adjacency matrix:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 printf("\nenter the source node:\t");
 scanf("%d",&src);
 bfs(src);
 getch();
}

void bfs(int src)
{
 int q[10],f=0,r=-1,vis[10],i,j;
 for(j=1;j<=n;j++)
 {
  vis[j]=0;
 }
 vis[src]=1;
 r=r+1;
 q[r]=src;
 while(f<=r)
 {
  i=q[f];
  f=f+1;
  for(j=1;j<=n;j++)
  {
   if(a[i][j]==1&&vis[j]!=1)
   {
    vis[j]=1;
    r=r+1;
    q[r]=j;
   }
  }
 }
 for(j=1;j<=n;j++)
 {
  if(vis[j]!=1)
  {
   printf("\nnode %d is not reachable\n",j);
  }
  else
  {#include<stdio.h>

#include<conio.h>

void knapsack();

int max(int,int);

int i,j,n,m,p[10],w[10],v[10][10];

void main()

{

 clrscr();

 printf("\nenter the no. of items:\t");

 scanf("%d",&n);

 printf("\nenter the weight of the each item:\n");

 for(i=1;i<=n;i++)

 {

  scanf("%d",&w[i]);

 }

 printf("\nenter the profit of each item:\n");

 for(i=1;i<=n;i++)

 {

  scanf("%d",&p[i]);

 }

 printf("\nenter the knapsack's capacity:\t");

 scanf("%d",&m);

 knapsack();

 getch();

}



void knapsack()

{

 int x[10];

 for(i=0;i<=n;i++)

 {

  for(j=0;j<=m;j++)

  {

   if(i==0||j==0)

   {

    v[i][j]=0;

   }

   else if(j-w[i]<0)

   {

    v[i][j]=v[i-1][j];

   }

   else

   {

    v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);

   }

  }

 }

 printf("\nthe output is:\n");

 for(i=0;i<=n;i++)

 {

  for(j=0;j<=m;j++)

  {

   printf("%d\t",v[i][j]);

  }

  printf("\n\n");

 }

 printf("\nthe optimal solution is %d",v[n][m]);

 printf("\nthe solution vector is:\n");

 for(i=n;i>=1;i--)

 {

  if(v[i][m]!=v[i-1][m])

  {

   x[i]=1;

   m=m-w[i];

  }

  else

  {

   x[i]=0;

  }

 }

 for(i=1;i<=n;i++)

 {

  printf("%d\t",x[i]);

 }

}



int max(int x,int y)

{

 if(x>y)

 {

  return x;

 }

 else

 {

  return y;

 }

}
   printf("\nnode %d is reachable\n",j);
  }
 }
}
