#include<stdio.h>
int m=0;//recursive dept
int binarysearch(int *a,int left ,int right,int target)//array should be sorted for algorith to work
{int mid;
m++;//calculating recurive dept
if(left==right)//base case checking for target 
{
    if(a[left]==target)
    {
        return left;
    }
    else return -1;

}
else
{
    mid=(left+right)/2;
    if(a[mid]==target)
    {
        return mid;
    }
    else if(target<a[mid]&& left<mid)
    {
      return binarysearch(a,left,mid-1,target);//comparison reduce to n/2

    }
    else if(target>a[mid]&&mid <right)
    {
        return binarysearch(a,mid+1,right,target);//comparison reduce to n/2
    }
    else return -1;
}
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)//inserting value in the array ,
     {
         scanf("%d",&a[i]);

     } 
     int s;//element to be search
     scanf("%d",&s);
     int k;
     k=binarysearch(a,0,n-1,s);
     printf("%d\n",m);
     printf("%d",k);
     return 0;

}