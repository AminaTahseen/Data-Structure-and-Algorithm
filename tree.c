#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "fatal.h"
#include "tree.h"

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

//prints the ID, name, city and rank stored in the array
void Print_Array(Rec R, int size)
{
	int i;
	for(i = 0; i < size; ++i)
	{
	    //prints the information if the entry is declared legitimate
		if(R[i].Info == Legitimate)
            printf("%u %s %s %s\n", R[i].ID, R[i].Name, R[i].city, R[i].Rank);
	}
}

//returns the tree after making it empty i.e. freeing all its nodes by recursive calls
SearchTree
MakeEmptyTree( SearchTree T )
{
    if( T != NULL )
    {
        MakeEmptyTree( T->Left );
        MakeEmptyTree( T->Right );
        free( T );
    }
    return NULL;
}

//inserts an element in a tree and returns the tree
SearchTree
Insert( treeElementType X, SearchTree T )
{
    if( T == NULL )
        {
            // Create and return a one-node tree
            T = malloc( sizeof( struct TreeNode ) );
            if( T == NULL )
                FatalError( "Out of space!" );
            else
            {
                T->Element = X;
                T->Left = T->Right = NULL;
            }
        }
    //if ID of the element is less than the ID of the node then traverse on the left sub tree
    else if( X.ID < T->Element.ID )
        T->Left = Insert( X, T->Left );
    //if ID of the element is greater than the ID of the node then traverse on the right sub tree
    else if( X.ID > T->Element.ID )
      T->Right = Insert( X, T->Right );
    // Else X is in the tree already; we'll do nothing
    return T;
}

//prints an element of the binary tree
void
printElement(SearchTree T)
{
	struct Record R;
	R = Retrieve(T);
	//print line commented out because we just have to access every node in sorted traversal not print it
//	printf("%u %s %s %s\n", R.ID, R.Name, R.city, R.Rank);
}

//takes in position of node as arguement and returns the element of node which is an array structure
treeElementType
Retrieve( Position P )
{
    return P->Element;
}

//prints the binary search tree by accessing each node
void printTree(SearchTree T, char order) {
	// order < 0 means pre-order, order == 0 means in-order, order > 0 means post-order
	// This function does not insert operator precedence brackets.
	if (T != NULL) {
		if (order < 0) {
			printElement(T);
		}
		printTree(T->Left, order);
		if (order == 0) {
			printElement(T);
		}
		printTree(T->Right, order);
		if (order > 0) {
			printElement(T);
		}
	}
}

//returns the position of the node in the tree which contains the element to be found
Position
Find( treeElementType X, SearchTree T )
{
    //if tree is empty return null
    if( T == NULL )
        return NULL;
    //if ID of the element is less than the ID of the node then traverse on the left sub tree
    if( X.ID < T->Element.ID )
        return Find( X, T->Left );
    else
    //if ID of the element is greater than the ID of the node then traverse on the right sub tree
    if( X.ID > T->Element.ID )
        return Find( X, T->Right );
    else
        return T;
}

//finds the position of the node with minimum element i.e. ID by recursively calling the function on left sub tree
Position
FindMin( SearchTree T )
{
    if( T == NULL )
        return NULL;
    else
    if( T->Left == NULL )
        return T;
    else
        return FindMin( T->Left );
}

//deletes the node in the tree and returns the tree
SearchTree
Delete( treeElementType X, SearchTree T )
{
    Position TmpCell;
    if( T == NULL )
        Error( "Element not found" );
    else
    if( X.ID < T->Element.ID )  // Go left
        T->Left = Delete( X, T->Left );
    else
    if( X.ID > T->Element.ID )  // Go right
        T->Right = Delete( X, T->Right );
    else  // Found element to be deleted
    if( T->Left && T->Right )  //node with two children
    {
        // Replace with smallest in right subtree
        TmpCell = FindMin( T->Right );
        T->Element = TmpCell->Element;
        T->Right = Delete( T->Element, T->Right );
    }
    else  // One or zero children
    {
        TmpCell = T;
        if( T->Left == NULL ) // Also handles 0 children
            T = T->Right;
        else if( T->Right == NULL )
            T = T->Left;
        free( TmpCell );
    }
    return T;
}
