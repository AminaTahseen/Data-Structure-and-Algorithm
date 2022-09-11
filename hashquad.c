        #include "fatal.h"
        #include "hashquad.h"
        #include <stdlib.h>
        #include "string.h"

        #define MinTableSize (10)

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

        /* Cell *TheCells will be an array of */
        /* HashEntry cells, allocated later */
        struct HashTbl
        {
            int TableSize;
            Cell *TheCells;
        };

        /* Return next prime; assume N >= 10 */

        static int
        NextPrime( int N )
        {
            int i;

            if( N % 2 == 0 )
                N++;
            for( ; ; N += 2 )
            {
                for( i = 3; i * i <= N; i += 2 )
                    if( N % i == 0 )
                        goto ContOuter;  
                return N;
              ContOuter: ;
            }
        }

        /* Hash function for ints */
        Index
        Hash( ElementType Key, int TableSize )
        {
            return Key % TableSize;
        }


        HashTable
        InitializeTable( int TableSize )
        {
            HashTable H;
            int i;

/* 1*/      if( TableSize < MinTableSize )
            {
/* 2*/          Error( "Table size too small" );
/* 3*/          return NULL;
            }

            /* Allocate table */
/* 4*/      H = malloc( sizeof( struct HashTbl ) );
/* 5*/      if( H == NULL )
/* 6*/          FatalError( "Out of space!!!" );

/* 7*/      H->TableSize = NextPrime( TableSize );

            /* Allocate array of Cells */
/* 8*/      H->TheCells = malloc( sizeof( Cell ) * H->TableSize );
/* 9*/      if( H->TheCells == NULL )
/*10*/          FatalError( "Out of space!!!" );

/*11*/      for( i = 0; i < H->TableSize; i++ )
/*12*/          H->TheCells[ i ].Info = Empty;

/*13*/      return H;
        }


		Position Find( ElementType Key, HashTable H )
		{
		Position CurrentPos;
		int CollisionNum;

		/* 1*/ CollisionNum = 0;
		/* 2*/ CurrentPos = Hash( Key, H->TableSize );
		/* 3*/ while( H->TheCells[ CurrentPos ].Info != Empty &&
					H->TheCells[ CurrentPos ].ID != Key )
		/* Probably need strcmp!! */
		{
		/* 4*/ CurrentPos += 2 * ++CollisionNum - 1;
		/* 5*/ if( CurrentPos >= H->TableSize )
		/* 6*/ 		CurrentPos -= H->TableSize;
		}
		return CurrentPos;
		}


        void
        Insert( struct Record R, HashTable H )
        {
            Position Pos;

            Pos = Find( R.ID, H );
			//if the cell in hashtable is empty or deleted it insert the record in it
            if( H->TheCells[ Pos ].Info != Legitimate )
            {
                /* OK to insert here */
                H->TheCells[ Pos ].Info = Legitimate;
                H->TheCells[ Pos ].ID = R.ID;
                strcpy(H->TheCells[ Pos ].city, R.city);
                strcpy(H->TheCells[ Pos ].Name, R.Name);
                strcpy(H->TheCells[ Pos ].Rank, R.Rank);
            }
        }


        HashTable
        Rehash( HashTable H )
        {
            int i, OldSize;
            Cell *OldCells;

/* 1*/      OldCells = H->TheCells;
/* 2*/      OldSize  = H->TableSize;

            /* Get a new, empty table */
/* 3*/      H = InitializeTable( 2 * OldSize );

            /* Scan through old table, reinserting into new */
/* 4*/      for( i = 0; i < OldSize; i++ )
/* 5*/          if( OldCells[ i ].Info == Legitimate )
/* 6*/              Insert( OldCells[i], H );

/* 7*/      free( OldCells );

/* 8*/      return H;
        }
/* END */


        void
        DestroyTable( HashTable H )
        {
            free( H->TheCells );
            free( H );
        }

		// Delete Function
		void Delete( ElementType Key, HashTable H )
		{
		Position Pos;

		Pos = Find( Key, H ); // Finds the position of the Key in Hash Table
		if(Pos != NULL)
			H->TheCells[ Pos ].Info = Deleted; // Labels this entry as Deleted
		}


	    void Print_Hash(HashTable H)
	    {
	        int i;
	        for (i = 0; i < H->TableSize; i++)
			{
	        printf("Index %d:\t", i);
	        if( H->TheCells[i].Info == Empty)
	            printf(" Empty");
	        else if (H->TheCells[i].Info == Deleted)
	            printf(" Deleted"); // prints "Deleted" for Deleted type entry
	        else
	            printf(" %u %s %s %s", H->TheCells[i].ID, H->TheCells[i].Name, H->TheCells[i].city, H->TheCells[i].Rank);
	        printf("\n");
	        }
	    }


		#define LeftChild( i )  ( 2 * ( i ) + 1 )
        void
        PercDown( Rec A, int i, int N )
        {
            int Child;
            struct Record Tmp;

/* 1*/      for( Tmp = A[ i ]; LeftChild( i ) < N; i = Child )
            {
/* 2*/          Child = LeftChild( i );
/* 3*/          if( Child != N - 1 && A[ Child + 1 ].ID < A[ Child ].ID )
/* 4*/              Child++;
/* 5*/          if( Tmp.ID > A[ Child ].ID )
/* 6*/              A[ i ] = A[ Child ];
                else
/* 7*/              break;
            }
/* 8*/      A[ i ] = Tmp;
        }

		//heap sort for sorting the records
        void
        Heapsort( Rec A, int N )
        {
            int i;

/* 1*/      for( i = N / 2; i >= 0; i-- )  /* BuildHeap */
/* 2*/          PercDown( A, i, N );
/* 3*/      for( i = N - 1; i > 0; i-- )
            {
/* 4*/          struct Record Temp;
						  Temp =  A[i];
						  A[ i ] = A[ 0 ] ;
						  A[0]	= Temp;
/* 5*/          PercDown( A, 0, i );
            }
        }


	int
	Sort(HashTable H){
		Rec Array;
		int i, mem = 0;
		//create an array to store the records  
		Array = (Rec) malloc(H->TableSize * sizeof(struct Record));
		if(Array == NULL)
			FatalError( "Out of space!!!" );
		else{
			for(i=0;i<H->TableSize;++i){
				Array[i].Info = Empty;
				mem += sizeof( Array ) + sizeof( struct Record );
			}
		}
		//insert the records from hash table into the array
		for(i=0;i<H->TableSize;++i){
			if(H->TheCells[i].Info == Legitimate){
				Array[i] = H->TheCells[i];
				Array[i].Info = Legitimate;
			}
		}
		//sort the array
		Heapsort(Array,H->TableSize);
		/*Uncomment this line to Print the Sorted Traversal of an Array*/
	//	Print_Array(Array,H->TableSize);
		free(Array);
		return mem;
	}

