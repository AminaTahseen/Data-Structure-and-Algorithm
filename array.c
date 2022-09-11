#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "fatal.h"
#include "array.h"


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

//inserts record from one array to another
Rec Insert_Record(struct Record Data,int index, Rec Array){
    if(Array[index].Info == Empty || Array[index].Info == Deleted)
    {
        Array[index].ID = Data.ID;
        strcpy(Array[index].Name,Data.Name);
        strcpy(Array[index].city,Data.city);
        strcpy(Array[index].Rank,Data.Rank);
        Array[index].Info = Legitimate;
    }
    else{
        Error("Number already exists!!!");
    }
    return Array;
}

//for swapping two entries in the array 
void
Swap( struct Record *Lhs, struct Record *Rhs )
{
    struct Record Tmp = *Lhs;
    *Lhs = *Rhs;
    *Rhs = Tmp;
}


void
Qsort( Rec A, int Left, int Right )
{

    if( Left < Right )
    {
        int i, j, mid = (Right + Left) / 2;
        struct Record Pivot;
        //checking median value by comparing center, left and right values for setting pivot
        if ((A[Left].ID < A[Right].ID && A[Left].ID > A[mid].ID) || (A[Left].ID < A[mid].ID && A[Left].ID > A[Right].ID))
            Swap( &A[ Right ], &A[ Left ] );    //swaps right and left element values if left element is the median
        else if ((A[mid].ID < A[Right].ID && A[mid].ID > A[Left].ID) || (A[mid].ID > A[Right].ID && A[mid].ID < A[Left].ID))
            Swap( &A[ Right ], &A[ mid ] );     //swaps right and center element values if center element is the median

        i = Left; j = Right - 1;
        Pivot = A[ Right ];

        while (1)
        {
            while( A[ i ].ID < Pivot.ID ) {++i;}
            while( A[ j ].ID >= Pivot.ID ) {--j;}     // changed > to >=

            if( i < j )
            {
                Swap( &A[ i ], &A[ j ] );
            }
            else
                break;
        }

        Swap( &A[ Right ], &A[ i ] );      // Put pivot at appropriate place

        Qsort( A, Left, i - 1 );
        Qsort( A, i + 1, Right );
    }
}

//function for sorting the array using quicksort 
void
Sort_Record( int size, Rec R )
{
    Qsort( R, 0, size - 1 );
}

//prints the records present in the array 
void Print_Array(Rec R, int size)
{
	int i;
	for(i = 0; i < size; ++i)
    {
		if(R[i].Info == Legitimate)
            printf("%u %s %s %s\n", R[i].ID, R[i].Name, R[i].city, R[i].Rank);
	}
}

//deletes the record from array R 
void Delete(struct Record Data, Rec R, int size)
{
	int i;
	//iterate over the array 
	for(i = 0 ; i < size; i++)
    {
    	//if a record is found and its ID matches the ID of the record to be deleted, its status is changed to deleted
		if(R[i].ID == Data.ID)
			R[i].Info = Deleted;
	}
}

//finds the record in the array R 
Rec Find(struct Record Data,Rec R, int size){
	int i;
	//iterate over the array to find the record by comparing IDs of records in array 
	for(i = 0; i < size; i++){
		if(R[i].ID == Data.ID){
			return &R[i];
	}
	}
	return NULL;
}

//function for copying contents of one array to another 
Rec CopyArray(Rec R, int size)
{
    int i;
    Rec R2;
    R2 = CreateArray(size);
    //iterate through the array
    for (i = 0; i < size; i++)
    {
        R2[i] = R[i];
    }
    return R2;
}
