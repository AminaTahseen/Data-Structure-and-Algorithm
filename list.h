		#ifndef _List_H
        #define _List_H
        struct Record;
        typedef struct Record *Rec;
        //element type of linked list would be array structure
        typedef struct Record ElementType;

        struct Node;
        typedef struct Node *PtrToNode;
        typedef PtrToNode List;
        typedef PtrToNode Position;

        enum KindOfEntry { Legitimate, Empty, Deleted};

        struct Record{
            enum KindOfEntry Info;
            unsigned int ID;
            char Name[20], city[4];
            char Rank[2];
        };

        struct Node
        {
            ElementType Element;
            Position    Next;
        };

        List MakeEmpty( List L );
        int IsEmpty( List L );
        int IsLast( Position P, List L );
        Position Find( ElementType X, List L );
        void Delete( ElementType X, List L );
        Position FindPrevious( ElementType X, List L );
        void Insert( ElementType X, List L, Position P );
        void DeleteList( List L );
        Position Header( List L );
        Position First( List L );
        Position Advance( Position P );
        ElementType Retrieve( Position P );
        Position GoToIndex(List L, int n);
		List Swap(List L, int n1, int n2);
		List Sort(List L);

        Rec CreateArray(int size);
        Rec Insert_Data(int size, Rec R, FILE *fptr);

        #endif
