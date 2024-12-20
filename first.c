#include <stdio.h>
 
void main()
{
    int heap[10], no, i, j, c, root, temp;
 
    printf("\n Enter no of elements :");
    scanf("%d", &no);
    printf("\n Enter the nos : ");
    for (i = 0; i < no; i++)
       scanf("%d", &heap[i]);
    for (i = 1; i < no; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (heap[root] < heap[c])   /* to create MAX heap array */
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
 
    printf("Heap array : ");
    for (i = 0; i < no; i++)
        printf("%d\t ", heap[i]);
    for (j = no - 1; j >= 0; j--)
    {
        temp = heap[0];
        heap[0] = heap[j];   /* swap max element with rightmost leaf element */
        heap[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1;    /* left node of root element */
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            if (heap[root]<heap[c] && c<j)    /* again rearrange to max heap array */
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < j);
    } 
    printf("\n The sorted array is : ");
    for (i = 0; i < no; i++)
       printf("\t %d", heap[i]);
    printf("\n Complexity : \n Best case = Avg case = Worst case = O(n logn) \n");
}
#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct Activity            //Greedy Algorithm use
{
    int start;
    int finish;
};

void ActivitySelection(struct Activity a[],int n)
{
  int i,j,temp,temp2;
  for(i=0;i<n;i++)                //USED bubble sort
  {
      for(j=i+1;j<n-1;j++)
      {
          if(a[i].finish>a[j].finish)
           { temp = a[i].finish;
             temp2 = a[i].start;
             a[i].finish = a[j].finish;
             a[i].start = a[j].start;
             a[j].finish = temp;
             a[j].start = temp2;
            }
      }
  }
 /* printf("\nSorted ACTIVITY timings : ");
 for(i=0;i<n;i++)
 {
     printf("\nStart time of   %d : %d",i,a[i].start);
     printf("\nfinish  time of %d : %d",i,a[i].finish);
 }
 */

i = 0 ;
printf("\nActivities to be selected : ");
printf("\n(%d,%d)",a[i].start,a[i].finish);
count++;
for(j=1;j<n;j++)
{
    if(a[j].start >=a[i].finish)
        { count++;
          printf("\n(%d,%d)",a[j].start,a[j].finish);
           i=j;
        }
}
}
int main()
{
    int n,i;
    printf("Enter the numbers of activities : ");
    scanf("%d",&n);
    struct Activity obj[n];
    for(i=0;i<n;i++)
    {
        printf("\n Enter start time of %d activity : ",i);
        scanf("%d",&obj[i].start);
        printf("\n Enter finish time of %d activity : ",i);
        scanf("%d",&obj[i].finish);
    }
  /*    // for printing the input  
        for(i=0;i<n;i++)
    {
        printf("\n Start time of %d activity : ",i);
        printf("%d",obj[i].start);
        printf("\n Finish time of %d activity : ",i);
        printf("%d",obj[i].finish);
    }
    */
  printf("\n");
   ActivitySelection(obj,n);
   printf("\nTotal number of activities : %d ",count);

    return 0;

}
