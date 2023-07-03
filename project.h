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

void init(list *l);
void *element_at(list* l,int n);
void *pop(list *l);
void *pop_at(list *l, int n);
int in_lst(list* l, void* element, int el_len);
int l_len(list *l);
void append(list *l, void *element);
void l_remove(list *l, void *element, int el_len);
list *slice(list *l, int start, int end);
int l_count(list *l, void *element, int el_len);
int indexof(list *l, void *element, int el_len);
void reverse(list* pl);
list *stride(list *l, int start, int end, int step);