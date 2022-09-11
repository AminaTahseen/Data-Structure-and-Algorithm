#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "tree.h"


char str[120];
FILE *fptr;

int main()
{
    LARGE_INTEGER start_time, end_time, elapsed_time, frequency;
    int length, i;
    Rec R;
    SearchTree T;
    clock_t start, end;
    double run_time;
    int mem = 0;


    if ((fptr = fopen("data_1000.txt","r")) == NULL)
    {
       printf("Error! Cant open file");
       // Program exits if the file pointer returns NULL.
       exit(1);
    }
    fgets (str, 120, fptr);
    while(1)
    {
        if(strstr(str,"$Records"))
        {
            fgets (str, 120, fptr);
            length = atoi(str); //converts the number of employees in record from string to integer
            break;
        }
   }
   printf("Number of Records = %d\n", length);

    //inserting in array
    R = CreateArray(length);
    R = Insert_Data(length, R, fptr);

    T = MakeEmptyTree(NULL);
    //inserting
    printf("Insert");
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start_time);
    for (i = 0; i < length; i++)
    {
        T = Insert(R[i], T);
        mem += sizeof( T ) + sizeof( struct TreeNode );
    }
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\t\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);

    //sorting
    printf("Sorted Traversal");
    QueryPerformanceCounter(&start_time);
    printTree(T, 0);
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);

    //find
    printf("Find");
    SearchTree element;
    i = 0;
    QueryPerformanceCounter(&start_time);
    while(i != length)
    {
        element = Find(R[i], T);
        i += 2;
    }
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\t\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);


    //delete
    printf("Delete");
    i = 1;
    QueryPerformanceCounter(&start_time);
    while(i != length + 1)
    {
        T = Delete(R[i], T);
        i += 2;
        mem -= sizeof( T ) + sizeof( struct TreeNode );
    }
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\t\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);

    free(R);
    free(T);
    fclose(fptr);

    mem = 0;

    printf("\n");
    if ((fptr = fopen("data_10000.txt","r")) == NULL)
    {
       printf("Error! Cant open file");
       // Program exits if the file pointer returns NULL.
       exit(1);
    }
    fgets (str, 120, fptr);
    while(1)
    {
        if(strstr(str,"$Records"))
        {
            fgets (str, 120, fptr);
            length = atoi(str); //converts the number of employees in record from string to integer
            break;
        }
   }
   printf("Number of Records = %d\n", length);

    //inserting in array
    R = CreateArray(length);
    R = Insert_Data(length, R, fptr);

    T = MakeEmptyTree(NULL);
    //inserting
    printf("Insert");
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start_time);
    for (i = 0; i < length; i++)
    {
        T = Insert(R[i], T);
        mem += sizeof( T ) + sizeof( struct TreeNode );
    }
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\t\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);

    //sorting
    printf("Sorted Traversal");
    QueryPerformanceCounter(&start_time);
    printTree(T, 0);
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);

    //find
    printf("Find");
    i = 0;
    QueryPerformanceCounter(&start_time);
    while(i != length)
    {
        element = Find(R[i], T);
        i += 2;
    }
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\t\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);


    //delete
    printf("Delete");
    i = 1;
    QueryPerformanceCounter(&start_time);
    while(i != length + 1)
    {
        T = Delete(R[i], T);
        i += 2;
        mem -= sizeof( T ) + sizeof( struct TreeNode );
    }
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\t\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);

    free(R);
    free(T);
    fclose(fptr);

    mem = 0;
    printf("\n");

    if ((fptr = fopen("data_100000.txt","r")) == NULL)
    {
       printf("Error! Cant open file");
       // Program exits if the file pointer returns NULL.
       exit(1);
    }
    fgets (str, 120, fptr);
    while(1)
    {
        if(strstr(str,"$Records"))
        {
            fgets (str, 120, fptr);
            length = atoi(str); //converts the number of employees in record from string to integer
            break;
        }
   }
   printf("Number of Records = %d\n", length);

    //inserting in array
    R = CreateArray(length);
    R = Insert_Data(length, R, fptr);

    T = MakeEmptyTree(NULL);
    //inserting
    printf("Insert");
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start_time);
    for (i = 0; i < length; i++)
    {
        T = Insert(R[i], T);
        mem += sizeof( T ) + sizeof( struct TreeNode );
    }
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\t\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);

    //sorting
    printf("Sorted Traversal");
    QueryPerformanceCounter(&start_time);
    printTree(T, 0);
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);

    //find
    printf("Find");
    i = 0;
    QueryPerformanceCounter(&start_time);
    while(i != length)
    {
        element = Find(R[i], T);
        i += 2;
    }
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\t\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);


    //delete
    printf("Delete");
    i = 1;
    QueryPerformanceCounter(&start_time);
    while(i != length + 1)
    {
        T = Delete(R[i], T);
        i += 2;
        mem -= sizeof( T ) + sizeof( struct TreeNode );
    }
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\t\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);

    free(R);
    free(T);
    fclose(fptr);

    mem = 0;

    printf("\n");
    if ((fptr = fopen("data_1000000.txt","r")) == NULL)
    {
       printf("Error! Cant open file");
       // Program exits if the file pointer returns NULL.
       exit(1);
    }
    fgets (str, 120, fptr);
    while(1)
    {
        if(strstr(str,"$Records"))
        {
            fgets (str, 120, fptr);
            length = atoi(str); //converts the number of employees in record from string to integer
            break;
        }
   }
   printf("Number of Records = %d\n", length);

    //inserting in array
    R = CreateArray(length);
    R = Insert_Data(length, R, fptr);

    T = MakeEmptyTree(NULL);
    //inserting
    printf("Insert");
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start_time);
    for (i = 0; i < length; i++)
    {
        T = Insert(R[i], T);
        mem += sizeof( T ) + sizeof( struct TreeNode );
    }
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\t\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);

    //sorting
    printf("Sorted Traversal");
    QueryPerformanceCounter(&start_time);
    printTree(T, 0);
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);

    //find
    printf("Find");
    i = 0;
    QueryPerformanceCounter(&start_time);
    while(i != length)
    {
        element = Find(R[i], T);
        i += 2;
    }
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\t\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);


    //delete
    printf("Delete");
    i = 1;
    QueryPerformanceCounter(&start_time);
    while(i != length + 1)
    {
        T = Delete(R[i], T);
        i += 2;
        mem -= sizeof( T ) + sizeof( struct TreeNode );
    }
    QueryPerformanceCounter(&end_time);
    elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
    run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
    printf("\t\t\tExecution Time:  %gs", run_time);
    printf("\t\tMemory Consumption: %d bytes\n", mem);

    free(R);
    free(T);
    fclose(fptr);
    return 0;
}
