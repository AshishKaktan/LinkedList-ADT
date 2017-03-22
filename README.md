**Linked List ADT**

**Structure of Linked List**

    struct list {
   
    int value;

    struct list *next;
    
    }*start=NULL;

start is the global pointer.

Contains 5 classes :
**1.Insert**
**2.Search**
**3.Print**
**4.Listoperation**
**5.Del**


**1.Insert**

This class have 3 function to insert an element into a Linked List.

    1. beg(int n) : can be used to insert an element 'n' at begining of the list.

    2. end(int n) : can be used to insert an element 'n' at end of the list.
  
    3. mid(int n,int pos) : can be used to insert an element at 'pos' int the list.


**2.Search**

This class have 4 function to insert an element into a Linked List.

**NOTE : root is the first node of the list**

    1. find(int n, struct* root) it takes number to be searched and 'return Position' of the return if exsist in the
    list else 'return -1'.

    2. getnth(int n, struct* root) 'return element at nth position', if 'n' is greater than size of list then 
    'return last element in the list'.

    3. getnthlast(int n, struct* root) 'return element at nth position from last'.

    4. getmid(struct* root) 'return middle element of the list'.
