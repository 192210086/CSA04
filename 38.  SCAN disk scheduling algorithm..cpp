#include <stdio.h>

void main() {
  int n, h, d, i, j, temp, k, atr[20], tot, p, sum=0;
  clrscr();
  printf("enter the no of tracks to be traveresed");
  scanf("%d'",&n);
  printf("enter the position of head");
  scanf("%d",&h);
  t[0]=0;t[1]=h;
  t[2]=tot-1;
  for(i=3;i<n;i++)
  {
    t[i]=rand()%100;
  }
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(t[i]>t[j])
      {
        temp=t[i];
        t[i]=t[j];
        t[j]=temp;
      }
    }
  }
  printf("enter the no of requests");
  scanf("%d",&p);
  for(i=0;i<p;i++)
  {
    scanf("%d",&atr[i]);
  }
  for(i=0;i<p;i++)
  {
    for(j=i+1;j<p;j++)
    {
      if(atr[i]>atr[j])
      {
        temp=atr[i];
        atr[i]=atr[j];
        atr[j]=temp;
      }
    }
  }
  i=0;
  while(i<p)
  {
    if(t[i]>h)
    {
      for(j=h;j<=t[i];j++)
      {
        sum+=abs(j-h);
      }
      h=t[i];
    }
    else
    {
      for(j=h;j>=t[i];j--)
      {
        sum+=abs(j-h);
      }
      h=t[i];
    }
    i++;
  }
  printf("total distance covered is %d",sum);
}
