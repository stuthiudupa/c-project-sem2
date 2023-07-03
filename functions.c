#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    void* data;
    struct node *next;
    struct node *prev;
}node;

typedef struct list
{
    struct node *head;
    struct node *tail;
    int len;
}list;

//init-- initialises the list
void init(list* l)
{
        l->head=NULL;
        l->tail=NULL;
        l->len=0;
}

// element_at -- returns the element at a particular index
//returns NULL when: index out of range OR empty list

void *element_at(list* l,int n)
{
    int i=0;
    node* p;
    p=l->head;
    while(p!=NULL){
        if(i==n){
            return p->data;
        }
        p=p->next;
        i++;
    }
    return NULL;
}

//pop-- removes the last element and returns it
void *pop(list *l)  //when we pop out the last value of the list, list init to NULL
{
    void *rtn;

    if(l->head==NULL){
        return NULL;
    }
    
    rtn=l->tail->data;
    l->tail=l->tail->prev;
    free(l->tail->next);
    l->tail->next=NULL;
    l->len--;
    return rtn;
}

//pop_at-- removes the element at a given index and returns it
//returns NULL if index is out of range
void *pop_at(list *l, int n)
{
    if(n>=l->len){
        return NULL;
    }

    int i=0;
    void *rtn;
    node *patch;
    node *tracker;
    tracker=l->head;

    while(tracker!=NULL){
        if(i==n){
            rtn=tracker->data;
            patch=tracker->prev;
            if(patch==NULL){
                l->head=tracker->next;
            }
            else{
                patch->next=tracker->next;
            }
            patch=tracker->next;
            if(patch==NULL){
                l->tail=tracker->prev;
            }
            else{
                patch->prev=tracker->prev;
            }
            free(tracker);
            l->len--;
            return rtn;
        }
        tracker=tracker->next;
        i++;
    }

    if(tracker==NULL){
        return NULL;
    }

}

//could return int to indicate success or failure
void l_remove(list *l, void *element, int el_len)
{
    if(l->len==0){
        return;
    }
    node *tracker;
    tracker=l->head;
    char *cmp=(char *)element;
    int flag=1;
    node *patch;

    while(tracker!=NULL){
        char *org;
        org=(char *)(tracker->data);
        for(int i=0; i<el_len; i++){
            if(org[i]!=cmp[i]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            break;
        }
        tracker=tracker->next;
    }

    if(tracker==NULL){
        return;
    }


    patch=tracker->prev;
    if(patch==NULL){
        l->head=tracker->next;
    }
    else{
        patch->next=tracker->next;
    }
    patch=tracker->next;
    if(patch==NULL){
        l->tail=tracker->prev;
    }
    else{
        patch->prev=tracker->prev;
    }
    free(tracker);
    l->len--;
}

int in_lst(list* l, void* element, int el_len)
{
    if(l->len==0){
        return 0;
    }
    node *tracker;
    tracker=l->head;
    char *cmp=(char *)element;

    while(tracker!=NULL){
        int flag=1;
        char *org;
        org=(char *)(tracker->data);
        for(int i=0; i<el_len; i++){
            if(org[i]!=cmp[i]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            return 1;
        }
        tracker=tracker->next;
    }

    if(tracker==NULL){
        return 0;
    }

}



int l_len(list *l)
{
    return l->len;
}

void append(list *l, void *element)
{

    node *np;
    np=(node *)malloc(sizeof(node));
    np->data=element;
    np->next=NULL;
    np->prev=NULL;

    if(l->head==NULL){
        l->head=np;
        l->tail=np;
    }
    else{
        l->tail->next=np;
        np->prev=l->tail;
        l->tail=np;
    }

    l->len++;
}

list *slice(list *l, int start, int end)
{
    if(start>end){
        return NULL;
    }

    list *rtn_l;
    rtn_l=(list *)malloc(sizeof(list));
    init(rtn_l);

    if(start==end || start>=l->len){
        return rtn_l;
    }

    node *tracker;
    tracker=l->head;
    int count=0;

    while(count<end && tracker!=NULL){
        if(count>=start){
            node *np;
            np=(node *)malloc(sizeof(node));
            np->data=tracker->data;
            np->next=NULL;
            np->prev=NULL;
            
            if(rtn_l->head==NULL){

                rtn_l->head=np;
                rtn_l->tail=np;
            }
            else{
                rtn_l->tail->next=np;
                np->prev=rtn_l->tail;
                rtn_l->tail=np;
            }
            rtn_l->len++;
        }
        count++;
        tracker=tracker->next;
    }

    return rtn_l;

}

void reverse(list* pl)
{
	node* temp=pl->tail;
	pl->tail=pl->head;
	pl->head=temp;
	node* tracker;
	tracker=pl->head;
	while(tracker!=NULL)
    {
    	temp=tracker->prev;
    	tracker->prev=tracker->next;
    	tracker->next=temp;
	    tracker=tracker->next;
    }
}

int l_count(list *l, void *element, int el_len)
{
    int cnt=0;
    node *tracker;
    tracker=l->head;
    char *cmp;
    cmp=(char *)element;

    while(tracker!=NULL){
        int flag=1;
        char *org;
        org=(char *)tracker->data;
        for(int i=0; i<el_len; i++){
            if(cmp[i]!=org[i]){
                flag=0;
                break;
            }
        }
        
        if(flag==1){
            cnt++;
        }

        tracker=tracker->next;
    }

    return cnt;
}

int indexof(list *l, void *element, int el_len)
{
    int index=0;
    node *tracker;
    tracker=l->head;
    char *cmp;
    cmp=(char *)element;

    while(tracker!=NULL){
        int flag=1;
        char *org;
        org=(char *)tracker->data;
        for(int i=0; i<el_len; i++){
            if(cmp[i]!=org[i]){
                flag=0;
                break;
            }
        }
        
        if(flag==1){
            return index;
        }

        tracker=tracker->next;
        index++;
    }

    return -1;   
}

list *stride(list *l, int start, int end, int step)
{
    if(step==0){
        return NULL;
    }

    list *new_l=(list *)malloc(sizeof(list));
    init(new_l);

    if(start==end || l->len==0){
        return new_l;
    }

    int index;
    int pos=0;
    node *tracker;
    int mod_step;
    int stop;
    int rev;
    list *rev_l=(list *)malloc(sizeof(list));

    if(start<end && step>0){
        tracker=l->head;
        index=start;
        mod_step=step;
        stop=end;
        rev=0;
    }
    else if(start>end && step<0){
        rev_l=l;
        reverse(rev_l);
        tracker=rev_l->head;
        mod_step=-step;
        index=rev_l->len-start;
        stop=rev_l->len-end;
        rev=1;
    }
    else{
        return new_l;
    }

    for(int pos=0; index<stop && tracker!=NULL; pos++){
        if(pos==index){
            node *n=(node *)malloc(sizeof(node));
            n->data=tracker->data;
            n->next=NULL;
            n->prev=NULL;

            if(new_l->head==NULL){
                new_l->head=n;
                new_l->tail=n;
            }
            else{
                new_l->tail->next=n;
                n->prev=new_l->tail;
                new_l->tail=n;
            }

            new_l->len++;
            index+=mod_step;
        }

        tracker=tracker->next;
    }
    
    if(rev==1){
        reverse(rev_l);
    }

    free(rev_l);
    return new_l;

}











/*
list *stride(list *l, int start, int end, int step)
{
    if(step==0){
        return NULL;
    }

    list *new_l=(list *)malloc(sizeof(list));
    node *tracker;
    int mod_step;
    int index;
    int stop;
    int pos=0;

    if(start<end && step>0){
        index=start;
        stop=end;
        tracker=l->head;
        mod_step=step;
    }
    else if(start>end && step<0){
        index=end;
        stop=start;
        tracker=l->tail;
        mod_step=-step;
    }
    else{
        init(new_l);
        return new_l;
    }

    while(index<l->len || index<stop){
        if(pos==index){
            node *n=(node *)malloc(sizeof(node));
            n=tracker;

        }
    }

}

*/