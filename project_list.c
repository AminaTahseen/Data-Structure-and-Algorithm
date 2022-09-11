#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <time.h>
#include <Windows.h>
char str[120];
FILE *fptr;

int main()
{
   int length;
   Rec R;

   if ((fptr = fopen("data_1000.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   fgets (str, 120, fptr);
   while(1){
   	if(strstr(str,"$Records")){
 		fgets (str, 120, fptr);
 		length=atoi(str);
		break;}		//converts the number of employees in record from string to integer

   }

   printf("Number of records = %d\n", length);
   R = CreateArray(length);
   R = Insert_Data(length,R,fptr);
// Insert
printf("Insert: ");
    LARGE_INTEGER start_time, end_time, elapsed_time, frequency;
    double run_time;
    List L;
    Position P;
    int i;
    int mem = 0;
    QueryPerformanceFrequency(&frequency);

    L = MakeEmpty( NULL );
    P = Header( L );
    QueryPerformanceCounter(&start_time);
    for( i = 0; i < length; i++ )
    {
        Insert( R[i], L, P );
        P = Advance( P );
        mem+=sizeof(L)+(sizeof( struct Node ));
    }

    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\tExecution Time: %gs", run_time);
    printf("\tMemory consumption: %d bytes", mem);

    // Find
    printf("\nFind: ");
    {
       QueryPerformanceCounter(&start_time);
       for( i = 0; i < length; i++ )
        {
            if((i%2)==0)
            {
                Find( R[i], L );
            }
        }
        QueryPerformanceCounter(&end_time);
        elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
        run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
        printf("\t\t\tExecution Time: %gs", run_time);
        printf("\tMemory consumption: %d bytes", mem);
    }

    //Sort
     printf("\nSorted Traversal: ");
     {
         QueryPerformanceCounter(&start_time);
         L = Sort(L);
         QueryPerformanceCounter(&end_time);
         elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
         run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
         printf("\tExecution Time: %gs", run_time);
         printf("\tMemory consumption: %d bytes", mem);
     }

    //Delete
    printf("\nDelete: ");
    {
        QueryPerformanceCounter(&start_time);
        for( i = 0; i < length; i++ )
        {
            if((i%2)==1)
            {
                Delete( R[i], L );
                mem -= sizeof( L ) + (sizeof( struct Node ));
            }
        }
        QueryPerformanceCounter(&end_time);
        elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
        run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
        printf("\t\tExecution Time: %gs", run_time);
        printf("\tMemory consumption: %d bytes", mem);
    }

   free(R);
   fclose(fptr);

   printf("\n\n");
   mem = 0;

   if ((fptr = fopen("data_10000.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   fgets (str, 120, fptr);
   while(1){
   	if(strstr(str,"$Records")){
 		fgets (str, 120, fptr);
 		length=atoi(str);
		break;}		//converts the number of employees in record from string to integer

   }

   printf("Number of records = %d\n", length);
   R = CreateArray(length);
   R = Insert_Data(length,R,fptr);
// Insert
printf("Insert: ");

    L = MakeEmpty( NULL );
    P = Header( L );
    QueryPerformanceCounter(&start_time);
    for( i = 0; i < length; i++ )
    {
        Insert( R[i], L, P );
        P = Advance( P );
        mem+=sizeof(L)+(sizeof( struct Node ));
    }

    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\tExecution Time: %gs", run_time);
    printf("\tMemory consumption: %d bytes", mem);

    // Find
    printf("\nFind: ");
    {
       QueryPerformanceCounter(&start_time);
       for( i = 0; i < length; i++ )
        {
            if((i%2)==0)
            {
                Find( R[i], L );
            }
        }
        QueryPerformanceCounter(&end_time);
        elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
        run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
        printf("\t\t\tExecution Time: %gs", run_time);
        printf("\tMemory consumption: %d bytes", mem);
    }

    //Sort
     printf("\nSorted Traversal: ");
     {
         QueryPerformanceCounter(&start_time);
         L = Sort(L);
         QueryPerformanceCounter(&end_time);
         elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
         run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
         printf("\tExecution Time: %gs", run_time);
         printf("\tMemory consumption: %d bytes", mem);
     }

    //Delete
    printf("\nDelete: ");
    {
        QueryPerformanceCounter(&start_time);
        for( i = 0; i < length; i++ )
        {
            if((i%2)==1)
            {
                Delete( R[i], L );
                mem -= sizeof( L ) + (sizeof( struct Node ));
            }
        }
        QueryPerformanceCounter(&end_time);
        elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
        run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
        printf("\t\tExecution Time: %gs", run_time);
        printf("\tMemory consumption: %d bytes", mem);
    }

   free(R);
   fclose(fptr);
   printf("\n\n");
   mem = 0;

   if ((fptr = fopen("data_100000.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   fgets (str, 120, fptr);
   while(1){
   	if(strstr(str,"$Records")){
 		fgets (str, 120, fptr);
 		length=atoi(str);
		break;}		//converts the number of employees in record from string to integer

   }

   printf("Number of records = %d\n", length);
   R = CreateArray(length);
   R = Insert_Data(length,R,fptr);
// Insert
printf("Insert: ");

    L = MakeEmpty( NULL );
    P = Header( L );
    QueryPerformanceCounter(&start_time);
    for( i = 0; i < length; i++ )
    {
        Insert( R[i], L, P );
        P = Advance( P );
        mem+=sizeof(L)+(sizeof( struct Node ));
    }

    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\tExecution Time: %gs", run_time);
    printf("\tMemory consumption: %d bytes", mem);

    // Find
    printf("\nFind: ");
    {
       QueryPerformanceCounter(&start_time);
       for( i = 0; i < length; i++ )
        {
            if((i%2)==0)
            {
                Find( R[i], L );
            }
        }
        QueryPerformanceCounter(&end_time);
        elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
        run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
        printf("\t\t\tExecution Time: %gs", run_time);
        printf("\tMemory consumption: %d bytes", mem);
    }

    //Sort
     printf("\nSorted Traversal: ");
     {
         QueryPerformanceCounter(&start_time);
         L = Sort(L);
         QueryPerformanceCounter(&end_time);
         elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
         run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
         printf("\tExecution Time: %gs", run_time);
         printf("\tMemory consumption: %d bytes", mem);
     }

    //Delete
    printf("\nDelete: ");
    {
        QueryPerformanceCounter(&start_time);
        for( i = 0; i < length; i++ )
        {
            if((i%2)==1)
            {
                Delete( R[i], L );
                mem -= sizeof( L ) + (sizeof( struct Node ));
            }
        }
        QueryPerformanceCounter(&end_time);
        elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
        run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
        printf("\t\tExecution Time: %gs", run_time);
        printf("\tMemory consumption: %d bytes", mem);
    }

   free(R);
   fclose(fptr);

   printf("\n\n");
   mem = 0;

   if ((fptr = fopen("data_1000000.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   fgets (str, 120, fptr);
   while(1){
   	if(strstr(str,"$Records")){
 		fgets (str, 120, fptr);
 		length=atoi(str);
		break;}		//converts the number of employees in record from string to integer

   }

   printf("Number of records = %d\n", length);
   R = CreateArray(length);
   R = Insert_Data(length,R,fptr);
// Insert
printf("Insert: ");

    L = MakeEmpty( NULL );
    P = Header( L );
    QueryPerformanceCounter(&start_time);
    for( i = 0; i < length; i++ )
    {
        Insert( R[i], L, P );
        P = Advance( P );
        mem+=sizeof(L)+(sizeof( struct Node ));
    }

    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\tExecution Time: %gs", run_time);
    printf("\tMemory consumption: %d bytes", mem);

    // Find
    printf("\nFind: ");
    {
       QueryPerformanceCounter(&start_time);
       for( i = 0; i < length; i++ )
        {
            if((i%2)==0)
            {
                Find( R[i], L );
            }
        }
        QueryPerformanceCounter(&end_time);
        elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
        run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
        printf("\t\t\tExecution Time: %gs", run_time);
        printf("\tMemory consumption: %d bytes", mem);
    }

//    //Sort
//     printf("\nSorted Traversal: ");
//     {
//         QueryPerformanceCounter(&start_time);
//         L = Sort(L);
//         QueryPerformanceCounter(&end_time);
//         elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
//         run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
//         printf("\tExecution Time: %gs", run_time);
//         printf("\tMemory consumption: %d bytes", mem);
//     }

    //Delete
    printf("\nDelete: ");
    {
        QueryPerformanceCounter(&start_time);
        for( i = 0; i < length; i++ )
        {
            if((i%2)==1)
            {
                Delete( R[i], L );
                mem -= sizeof( L ) + (sizeof( struct Node ));
            }
        }
        QueryPerformanceCounter(&end_time);
        elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
        run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
        printf("\t\tExecution Time: %gs", run_time);
        printf("\tMemory consumption: %d bytes", mem);
    }

   free(R);
   fclose(fptr);
   return 0;
}
