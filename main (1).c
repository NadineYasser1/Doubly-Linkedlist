
#include <stdio.h>
#include <stdlib.h>
/*
 *
 */
typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
/*
 *
 */
typedef struct
{
    Node* head;
    Node* tail;
} DoublyLinkedList;
/*
 *
 */

DoublyLinkedList* init()
{
    DoublyLinkedList *list =malloc(sizeof(DoublyLinkedList));
    list->head=NULL;
    list->tail=NULL;
    return list;
}

 Node* newNode(int x)
{
    Node* n =malloc(sizeof(Node));
    n->data=x;
    n->next=NULL;
    return n;
}
void insertBegining(DoublyLinkedList*list,int x)
{
Node* n =newNode(x);
if(list->head==NULL)
{
 list->head=n;
 list->tail=n;
 }
 else
{
 n->next=list->head;
 list->head->prev=n;
 list->head=n;
}
}
void insertEnd(DoublyLinkedList*list,int x)
{
Node* n =newNode(x);
if(list->head==NULL)
{
list->head=n;
list->tail=n;
}
else
{
list->tail->next=n;
n->prev=list->tail;
list->tail=n;
}
}
int isEmpty(DoublyLinkedList*list)
{
if (list->head==NULL)
return 1;
else
return 0 ;
}
DoublyLinkedList* convertArrayToDoublyLinkedList(int array[], int size)
{
     DoublyLinkedList *list = init();
    int i;

    for(i=0; i<size ;i++)
    {
      insertEnd(list,array[i]);

}

    return list;
}


void destroy(DoublyLinkedList* list)
{
    if((list->head)==NULL)
printf("list is empty\n");
else {
        while((list->head)!=NULL){
    Node *temp=list->head;
    list->head=list->head->next;
     free(temp);
        }
        printf("list is destroyed!\n");
}

}

DoublyLinkedList* copy(DoublyLinkedList* list)
{
    DoublyLinkedList *newlist = init();
   int x;
  while(!isEmpty(list)){
      x = list->head->data;
      insertBegining(newlist,x);
      list->head=list->head->next;
    }
    return newlist;
}

void concatenate(DoublyLinkedList*  list1, DoublyLinkedList*  list2)
{
   while(!isEmpty(list2)){
     int x = list2->head->data;
     insertEnd(list1,x);
     list2->head=list2->head->next;
   }
}

DoublyLinkedList* getDifferenceBetweenLists(DoublyLinkedList*  list1, DoublyLinkedList*  list2)
{
    DoublyLinkedList *newlist = init();
    int x,y;
    while(!isEmpty(list2)){
         x = list1->head->data;
         y = list2->head->data;
        if(x!=y) insertEnd(newlist,x);
        list1->head=list1->head->next;
        list2->head=list2->head->next;
    }
    if(!isEmpty(list1)){
    insertEnd(newlist,x);
    }
    return newlist;
}
size_t length(DoublyLinkedList*  list)
{
    size_t count = 0;
   while(!isEmpty(list)){
       count++;
       list->head=list->head->next;
   }
    return count;
}
int checkSumofFirstHalfEqualSumOfSecondHalf(DoublyLinkedList*  list)
{
    size_t n=length(list);
    if(n%2==0){
        int i,j;
        int sum1=0;
        int sum2=0;
        for(i=0;i<(n/2);i++){
            int x = list->head->data;
            sum1=sum1+x;
            list->head=list->head->next;
        }
        for(j=0;j<(n/2);j++){
            int y = list->tail->data;
            sum2=sum2+y;
            list->tail=list->tail->prev;
        }
        if(sum1==sum2) return 1;
        else return 0;
    }
    else return 0;
}

int isPalindrome(DoublyLinkedList * list)
{
    size_t n = length(list);
    int i,j;
    int flag=0;
    for(i=0;i<(n/2);i++){
      int x = list->head->data;
      int y = list->tail->data;
      if(x!=y)
      {   flag=1;
          return 0;
      }
      else {
          list->head=list->head->next;
          list->tail=list->tail->prev;

      }

    }
    if(flag==0) return 1;

}

int areEqual(DoublyLinkedList*  list1, DoublyLinkedList*  list2)
{
    size_t n1=length(list1);
    size_t n2=length(list2);
    int flag =0;
    if(n1!=n2) return 0;
    else{
        while(!isEmpty(list1)){
            int x = list1->head->data;
            int y = list2->head->data;
            if(x!=y)
            {   flag =1;
                return 0;
            }
            else {
                list1->head=list1->head->next;
                list2->head=list2->head->next;
            }
        }
        if(flag==0) return 1;
    }
}

void printlnListForward(DoublyLinkedList * l)
{

    Node*temp=l->head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");

}

void printlnListBackward(DoublyLinkedList * list)
{
    Node* temp=list->tail;
   while(temp!=NULL)
   {
  printf("%d\t",temp->data);
   temp=temp->prev;
}
    printf("\n");
}
/*
 *
 */
void Investigate(char* title, DoublyLinkedList * list)
{
    printf("%s\n", title);
    printf("List =         ");
    printlnListForward(list);
    printf("Reverse List = ");
    printlnListBackward(list);
    printf("List Length = %u\n", length(list));
    printf("List isPalindrome = %d\n", isPalindrome(list));
    printf("...................................................\n");
}
/*
 *
 */
void testConcatenate1(DoublyLinkedList *list1)
{
    puts("\nSTART testConcatenate1\n");
    DoublyLinkedList * EmptyList =init();
    DoublyLinkedList* list3,*emptyList1;
    list3 = copy(list1);
    Investigate("List3 = copy(List1)\n==================", list3);
    emptyList1 = copy(EmptyList);
    Investigate("EmptyList1 = copy(EmptyList)\n===========================", EmptyList);
    concatenate(list3, emptyList1);
    Investigate("List3<->EmptyList1\n==========================", list3);
    destroy(list3);
    Investigate("List3 (after destroy)\n=====================", list3);
    destroy(emptyList1);
    puts("\nEND testConcatenate1\n");
}
/*
 *
 */
void testConcatenate2(DoublyLinkedList * list1)
{
    puts("\nSTART testConcatenate2\n");
    DoublyLinkedList * EmptyList =init();
    DoublyLinkedList * list3, * emptyList1;
    list3 = copy(list1);
    Investigate("List3 = copy(List1)\n==================", list3);
    emptyList1 = copy(EmptyList);
    Investigate("EmptyList1 = copy(EmptyList)\n===========================", EmptyList);
    concatenate(emptyList1, list3);
    Investigate("EmptyList1<->List3\n==========================", emptyList1);
    destroy(emptyList1);
    Investigate("EmptyList1 (after destroy)\n=====================", emptyList1);
    puts("\nEND testConcatenate2\n");

}
/*
 *
 */
void testConcatenate3(DoublyLinkedList *list1, DoublyLinkedList *list2)
{
    puts("\nSTART testConcatenate3\n");
    DoublyLinkedList* list3, *list4,* emptyList1;
    list3 = copy(list1);
    Investigate("List3 = copy(List1)\n==================", list3);
    list4 = copy(list2);
    Investigate("list4 = copy(List2)\n==================", list4);
    concatenate(list3, list4);
    Investigate("List3<->List4\n=====================", list3);
    destroy(list3);
    Investigate("list3 (after destroy)\n=====================", list3);
    puts("\nEND testConcatenate3\n");

}
/*
 *
 */
void testConcatenate()
{
    int array1[] = {0, 1, 2, 3, 4, 5, 6};
    int array2[] = {7, 8, 9};

    DoublyLinkedList *list1 = convertArrayToDoublyLinkedList(array1, sizeof(array1)/sizeof(*array1));
    Investigate("List1\n=====", list1);
    DoublyLinkedList *list2 = convertArrayToDoublyLinkedList(array2, sizeof(array2)/sizeof(*array2));
    Investigate("List2\n=====", list2);

    testConcatenate1(list1);
    testConcatenate2(list1);
    testConcatenate3(list1, list2);

    destroy(list1);
    destroy(list2);
}
/*
 *
 */
void testPalindrome()
{
    puts("\nSTART testPalindrome\n");
    int array3[] = {0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 0};
    int array4[] = {7, 8, 9, 9, 8, 7};

    DoublyLinkedList* list5 = convertArrayToDoublyLinkedList(array3, sizeof(array3)/sizeof(*array3));
    Investigate("List5\n=====", list5);
    DoublyLinkedList *list6 = convertArrayToDoublyLinkedList(array4, sizeof(array4)/sizeof(*array4));
    Investigate("List6\n=====", list6);

    destroy(list5);
    destroy(list6);
    puts("\nEND testPalindrome\n");

}
/*
 *
 */
void testAreEqual()
{
    puts("\nSTART testAreEqual\n");
    int array7[] = {0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 0};
    int array8[] = {7, 8, 9, 9, 8, 7};
    int array9[] = {0, 1, 2, 3, 4, 5};
    DoublyLinkedList * EmptyList =init();
    DoublyLinkedList *list7 = convertArrayToDoublyLinkedList(array7, sizeof(array7)/sizeof(*array7));
    Investigate("List7\n=====", list7);
    DoublyLinkedList *list8 = convertArrayToDoublyLinkedList(array8, sizeof(array8)/sizeof(*array8));
    Investigate("List8\n=====", list8);
    DoublyLinkedList *list9 = convertArrayToDoublyLinkedList(array9, sizeof(array9)/sizeof(*array9));
    Investigate("List9\n=====", list9);
    DoublyLinkedList *emptyList1 = copy(EmptyList);
    Investigate("EmptyList1 = copy(EmptyList)\n===========================", emptyList1);
    DoublyLinkedList *emptyList2 = copy(EmptyList);
    Investigate("EmptyList2 = copy(EmptyList)\n===========================", emptyList2);

    printf("areEqual(list7, list7) = %d\n", areEqual(list7, list7));
    printf("areEqual(list7, list8) = %d\n", areEqual(list7, list8));
    printf("areEqual(list7, list9) = %d\n", areEqual(list7, list9));
    printf("areEqual(list8, list7) = %d\n", areEqual(list8, list7));
    printf("areEqual(list7, EmptyList1) = %d\n", areEqual(list7, emptyList1));
    printf("areEqual(EmptyList1, list7) = %d\n", areEqual(emptyList1, list7));
    printf("areEqual(EmptyList1, EmptyList2) = %d\n", areEqual(emptyList1, emptyList2));

    destroy(list7);
    destroy(list8);
    destroy(list9);
    puts("\nEND testAreEqual\n");

}
/*
 *
 */
void testDifference()
{
    puts("\nSTART testDifference\n");
    int array10[] = {2, 4, 8, 9, 13, 17,20};
    int array11[] = {2, 8, 17,20};
    DoublyLinkedList *list10 = convertArrayToDoublyLinkedList(array10, sizeof(array10)/sizeof(*array10));
    Investigate("list10\n=====", list10);
    DoublyLinkedList *list11 =convertArrayToDoublyLinkedList(array11, sizeof(array11)/sizeof(*array11));
    Investigate("List11\n=====", list11);
    DoublyLinkedList *list12 = getDifferenceBetweenLists(list10,list11);
    Investigate("list12\n=====", list12);
    destroy(list10);
    destroy(list11);
    destroy(list12);
    puts("\nEND testDifference\n");

}
void testSum()
{
    puts("\nSTART testSum\n");
    int array5[] = {12, 4, 8, 9, 13, 2};
    int array6[] = {2, 18, 17,4};
    int array7[]= {2,3,4};
    DoublyLinkedList *list13 = convertArrayToDoublyLinkedList(array5, sizeof(array5)/sizeof(*array5));
    Investigate("list13\n=====", list13);
    DoublyLinkedList *list14 =convertArrayToDoublyLinkedList(array6, sizeof(array6)/sizeof(*array6));
    Investigate("list14\n=====", list14);
    DoublyLinkedList *list15 =convertArrayToDoublyLinkedList(array7, sizeof(array7)/sizeof(*array7));
    Investigate("list15\n=====", list15);
    printf("checkSumofFirstHalfEqualSumOfSecondHalf(list13) = %d\n", checkSumofFirstHalfEqualSumOfSecondHalf(list13));
    printf("checkSumofFirstHalfEqualSumOfSecondHalf(list14) = %d\n", checkSumofFirstHalfEqualSumOfSecondHalf(list14));
    printf("checkSumofFirstHalfEqualSumOfSecondHalf(list15) = %d\n", checkSumofFirstHalfEqualSumOfSecondHalf(list15));

    destroy(list13);
    destroy(list14);
    destroy(list15);
    puts("\nEND testSum\n");
}
int main()
{
    testConcatenate();
    testPalindrome();
    testAreEqual();
    testDifference();
    testSum();


    return 0;
}


