/* Interface for quadratic probing hash table */
typedef int ElementType;

        #ifndef _HashQuad_H
        #define _HashQuad_H

        typedef unsigned int Index;
        typedef Index Position;

		struct Record;
		struct HashEntry;
		typedef struct Record Cell;
	//	typedef Cell * Block;
		typedef struct Record Cell;
		typedef struct Record *Rec;
        struct HashTbl;
        typedef struct HashTbl *HashTable;

		enum KindOfEntry { Legitimate, Empty, Deleted};

		struct Record{
			enum KindOfEntry Info;
			unsigned int ID;
			char Name[20], city[4];
			char Rank[2];
		};

        struct HashEntry
        {
            ElementType ID;
            char Name[15];
            char city[4];
            char Rank[2];
            enum KindOfEntry Info;
        };

        HashTable InitializeTable( int TableSize );
        void DestroyTable( HashTable H );
        Position Find( ElementType Key, HashTable H );
        void Insert( struct Record R, HashTable H );
        HashTable Rehash( HashTable H );
		void Delete(ElementType Key, HashTable H);
		void Print_Array(Rec R, int size);
		Rec Insert_Data(int size, Rec R, FILE *fptr);
		Rec CreateArray(int size);
		int Sort(HashTable H);
		void Print_Hash(HashTable H);
        #endif  /* _HashQuad_H */

/* END */
