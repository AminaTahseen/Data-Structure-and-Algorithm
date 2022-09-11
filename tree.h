		#ifndef _Tree_H
        #define _Tree_H
        struct Record;
        typedef struct Record *Rec;
		//element type of binary tree would be array structure
        typedef struct Record treeElementType;

        struct TreeNode;
        typedef struct TreeNode *Position;
        typedef struct TreeNode *SearchTree;

        enum KindOfEntry {Legitimate, Empty, Deleted};

        struct Record
        {
            enum KindOfEntry Info;
            unsigned int ID;
            char Name[20];
            char city[4];
            char Rank[2];
        };

        struct TreeNode
        {
            treeElementType Element;
            SearchTree  Left;
            SearchTree  Right;
        };

        Rec CreateArray(int size);
        Rec Insert_Data(int size, Rec R, FILE *fptr);
        void Print_Array(Rec R, int size);

        SearchTree MakeEmptyTree( SearchTree T );
        SearchTree Insert( treeElementType X, SearchTree T );
        void printTree( SearchTree T, char order );
        treeElementType Retrieve( Position P );
        Position Find( treeElementType X, SearchTree T );
        void printElement( SearchTree T );
        SearchTree Delete( treeElementType X, SearchTree T );

        #endif
