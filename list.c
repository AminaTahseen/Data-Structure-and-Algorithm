#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include "fatal.h"
#include "list.h"


//takes in the size of the array, creates it and returns it
Rec CreateArray(int size)
{
	int i;
	Rec Array;
	Array = (Rec) malloc(size * sizeof(struct Record));  //allocate the space for an array
	if(Array == NULL)
        FatalError( "Out of space!!!" );
	else
    {
		for(i = 0; i < size; ++i)
			Array[i].Info = Empty;    //declare the entries of the array empty
		return Array;
	}
}

//inserts data from the file into an array
Rec Insert_Data(int size, Rec R, FILE *fptr)
{
	int count;
    for(count = 0; count < size; ++count)
    {
   		fscanf(fptr, "%d %s %s %s",&R[count].ID, R[count].Name, R[count].city, R[count].Rank);
   		R[count].Info = Legitimate;
    }
   	return R;
}

//makes list empty
List
MakeEmpty( List L )
{
    if( L != NULL )
        DeleteList( L );
    L = malloc( sizeof( struct Node ) );
    if( L == NULL )
        FatalError( "Out of memory!" );
    L->Next = NULL;
    return L;
}

// Return true if L is empty

int
IsEmpty( List L )
{
    return L->Next == NULL;
}

// Return true if P is the last position in list L
// Parameter L is unused in this implementation

int IsLast( Position P, List L )
{
    return P->Next == NULL;
}

// Return Position of X in L by comparing the ID of the element with the ID of the nodes of L; NULL if not found
Position
Find( ElementType X, List L )
{
    Position P;

    P = L->Next;
    while( P != NULL && (P->Element.ID) != X.ID )
      P = P->Next;

return P;
}

// Delete from a list
// Cell pointed to by P->Next is wiped out
// Assume that the position is legal
// Assume use of a header node
void
Delete( ElementType X, List L )
{
    Position P, TmpCell;

    P = FindPrevious( X, L );

    if( !IsLast( P, L ) )  // Assumption of header use
    {                      // X is found; delete it
        TmpCell = P->Next;
        P->Next = TmpCell->Next;  //Bypass deleted cell
        free( TmpCell );
    }
}

// If X is not found, then Next field of returned value is NULL
// Assumes a header
// finds the node previous to X and returns a pointer to it. this is done by comparing IDs of records in nodes
Position
FindPrevious( ElementType X, List L )
{
    Position P;

    P = L;
    while( P->Next != NULL && P->Next->Element.ID != X.ID )
      P = P->Next;

return P;
}

// Insert (after legal position P)
// Header implementation assumed
// Parameter L is unused in this implementation
void
Insert( ElementType X, List L, Position P )
{
    Position TmpCell;

    TmpCell = malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
      FatalError( "Out of space!!!" );

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

//deleted the list by freeing all the nodes
void
DeleteList( List L )
{
    Position P, Tmp;

    P = L->Next;  // Header assumed
    L->Next = NULL;
    while( P != NULL )
    {
        Tmp = P->Next;
        free( P );
        P = Tmp;
    }
}


Position
Header( List L )
{
    return L;
}

Position
First( List L )
{
    return L->Next;
}

Position
Advance( Position P )
{
    return P->Next;
}

ElementType
Retrieve( Position P )
{
    return P->Element;
}

Position
GotoIndex( List L, int n ) {
    int count;
    Position P;
    P = L;
    count = -1;
    while (P != NULL && count != n) {
        P = Advance( P );
        count += 1;
    }
    return P;
}

//swaps two nodes of the list
List Swap(List L, int n1, int n2)
{
    //Declaration of four locations
    Position P1;
    Position P2;
    Position Prev;
    Position PPrev;

    // Calling the GotoIndex
    P1 = GotoIndex(L, n1);
    P2 = GotoIndex(L, n2);
    Prev = GotoIndex(L, (n1-1));
    PPrev = GotoIndex(L, (n2-1));
    // Swaps node 1 and node 2
    //Nodes aren't adjacent
    if(abs(n2-n1)!=1)
    {
    // swap next pointers of nodes
    struct Node* temp = P1->Next; // stores next pointer of node 1 in temp
    P1->Next = P2->Next; // pointer of node 1 is pointed to node 2's next
    P2->Next = temp; // pointer to the previous node of node 1

    PPrev->Next= P1; // previous node of node 2 is pointed to node 1
    Prev->Next= P2; // previous node of node 1 is pointed to node 2
    }
    //Nodes are adjacent
    // node 2 greater than node 1
    else if((n2-n1)==1)
    {
    struct Node* temp2 = P1->Next;
    Prev->Next = temp2;

    struct Node* temp3 = P2->Next;
    P1->Next= temp3;
    P2->Next= P1;
    }
    //Nodes are adjacent
    // node 1 greater than node 2
    else if((n1-n2)==1)
    {
    struct Node* temp2 = P2->Next;
    PPrev->Next = temp2;

    struct Node* temp3 = P1->Next;
    P2->Next= temp3;
    P1->Next= P2;
    }
    return L;
}

// Sorting by Selection Sort
List Sort(List L)
{
    Position Tmp; // points to head of linked list
    Position min; // 'min' - pointer to store the node having minimum data value
    Position r; // current node
    int i, j, k; //index of nodes
    i = 0;
    Tmp = L;
    // Traverse the List till the last node
    while (Tmp->Next != NULL) {
        j = i; // stores index to first node
        min = Tmp->Next; // initially points to the first node
        k = i;
        r = Tmp->Next;
        // Traverse the unsorted sublist
        while (r != NULL) {
            // check if the ID of the current node is minimum
             if (min->Element.ID > r->Element.ID) // if true, then updates 'min'
                {
                    min = r;
                    j = k;
                }
            k++;
            r = r->Next;
    }
    //Swap the Elements
    Swap(L,i,j);
    i++; // increments the index of first node
    Tmp = Tmp->Next;
}
    return L; // returns Sorted List
}

//prints the list
void
PrintList( const List L )
{
    printf("\n");

    Position P = Header( L );
    struct Record R;
    if( IsEmpty( L ) )
        printf( "Empty list\n" );
    else
    {
        //traverse through the list and print all records in nodes
        do
        {
            P = Advance( P );
            R = Retrieve( P );
            printf( "%u %s %s %s\n",R.ID,R.Name,R.city,R.Rank);
        } while( !IsLast( P, L ) );
        printf( "\n" );
    }

    printf("\n");
}
