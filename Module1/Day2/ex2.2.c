#include<stdio.h>
 
void swap(int*n1,int*n2)
{
int temp;
temp=&n2;
&n2=&n1;
&n1=temp;
}

int main(){
    int n1,n2;
    Printf("Enter first number:\n");
    scanf("%d",&n1);
    Printf("Enter Second number:\n");
    scanf("%d",&n2);
    
    Printf("Before swapping:\n");
    Printf("first number:%d\n",n1);
    Printf("Second number:%d\n",n2);
    
    swap(&n1,&n2)
    Printf("After swapping:\n");
    Printf("first number:%d\n",n1);
    Printf("Second number:%d\n",n2);
     
     return 0;
}
