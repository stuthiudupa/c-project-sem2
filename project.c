#include <stdio.h>
#include <stdlib.h>
#include "project.h"

//displays the list
void disp(list* pl)
{
    printf("[ ");
    for(int i=0;i<l_len(pl);i++)
    {
        printf("%d ",*(int*)element_at(pl,i));
    }
    printf("]\n");
}    

int main()
{
	list l;
	void* n;
	init(&l);

    int ap1;
    printf("Enter the value of the first element:\n");
    scanf("%d", &ap1);
	append(&l, (void *)&ap1);
    int ap2;
    printf("Enter the value of the second element:\n");
    scanf("%d", &ap2);
	append(&l, (void *)&ap2);
    int ap3;
    printf("Enter the value of the third element:\n");
    scanf("%d", &ap3);
	append(&l, (void *)&ap3);
    int ap4;
    printf("Enter the value of the fourth element:\n");
    scanf("%d", &ap4);
	append(&l, (void *)&ap4);
	
    printf("List1= ");
    disp(&l);
    printf("\n");
    
    //printing elements at index
    printf("List[1]= ");
    n=element_at(&l,1);
    if(n==NULL)
    {
    	printf("~~Out of range~~\n");
    }
    else	printf("%d\n", *(int*)n);

    printf("List[4]= ");
    n=element_at(&l,4);
    if(n==NULL)
    {
    	printf("~~Out of range~~\n");
    }
    else	printf("%d\n", *(int*)n);
    printf("\n");
    
    int n1=50,n2=60,n3=70,n4=80;
    append(&l,(void*)&n1);
    append(&l,(void*)&n2);
    append(&l,(void*)&n3);
    append(&l,(void*)&n4);

    
	//reversing the list
    reverse(&l);
    printf("List after reversing= ");
    disp(&l);
    printf("\n");
    
    //printing length
    printf("\nLength of list1= %d\n\n",l_len(&l));
    
    //pop
    printf("Deleting last element\n");
    n=pop(&l);
    printf("deleted element= %d\n", *(int*)n);
    printf("\n");
    
    printf("List after popping: ");
    disp(&l);

    int ap;
    printf("Enter the value to be appended:\n");
    scanf("%d", &ap);
	append(&l, (void *)&ap);
	
    printf("The list after appending:\n");
    disp(&l);
    printf("\n");
    
    printf("\nLength of list1= %d\n\n",l_len(&l));
    
    //deleting element at given index
    printf("Deleting element at index 1:\n");
    n=pop_at(&l, 1);
    printf("deleted element= %d\n", *(int*)n);
    printf("\n");
    
    //checking whether a given element is in the list
    int no=20,is_in;
    void* ele;
    ele=&no;
    is_in=in_lst(&l,ele,sizeof(int));
    if(is_in==1) printf("The element 20 is present in the list\n");
    else printf("The element 20 is not present in the list\n");

    printf("The list:\n");
    disp(&l);
    printf("\n");

    //indexof
    int n5=30;
    printf("Index of 30 is %d\n",indexof(&l,(void*)&n5, sizeof(int)));

    //remove
    int n6=80;
    l_remove(&l,(void*)&n6,sizeof(int));
    printf("The list after removing 80:\n");
    disp(&l);
    printf("\n");

    //count
    int n7=50;
    int c=l_count(&l,(void*)&n7,sizeof(int));
    printf("The element 50 occurs %d times\n",c);

    //slice
    list* nlist;
    nlist=slice(&l,2,5);
    printf("List[2:5]:");
    disp(nlist);

    //stride
    list *nlist2;
    nlist2=stride(&l, 1, 5, 2);
    printf("List[1:5:2]:");
    disp(nlist2);


	return 0;
}

/*
functions that we have in this program currently:
- init
- l_len
- pop
- append
- display
- element_at
- pop at
- reverse
- in_lst
- remove
- slice
- indexof
- count

*/