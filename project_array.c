#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include <time.h>
#include <Windows.h>


char str[120];
FILE *fptr;

int main()
{
	int mem_Array = 0;
    LARGE_INTEGER start_time, end_time, elapsed_time, frequency;
    int length;
    Rec R, R2, copyR, findR;
    int i;
	clock_t start, end;
    double run_time;


   if ((fptr = fopen("data_1000.txt","r")) == NULL){
       printf("Error! opening file");

       exit(1);
   }
   fgets (str, 120, fptr);
   while(1){
   	if(strstr(str,"$Records")){
 		fgets (str, 120, fptr);
 		length=atoi(str); //converts the number of employees in record from string to integer
		break;}		

   }

    printf("Number of Records: %d\n", length);
    R = CreateArray(length);
    R = Insert_Data(length,R,fptr); //records inserted in array
    findR = CreateArray(1);         //for storing the number found in array

    R2 = CreateArray(length);
    //insert
    printf("Insert:");
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	for(i=0;i<length;++i)
    {
        R2 = Insert_Record(R[i],i, R2);
		mem_Array += sizeof( R2 ) + sizeof( struct Record );
	}

	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

    //find
	printf("Find:");
	QueryPerformanceCounter(&start_time);

	for(i=0;i<length;i=i+2)
		findR = Find(R[i],R,length);

	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

	//sort
	printf("Sort:");
	QueryPerformanceCounter(&start_time);
	Sort_Record(length,R2);
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

	copyR = CopyArray(R, length);
    for(i = 1; i < length; i++)
		mem_Array += sizeof( R ) + sizeof( struct Record );

    //delete
	printf("Delete:");
	QueryPerformanceCounter(&start_time);
	for(i = 1;i < length; i = i + 2)
    {
		Delete(R[i], copyR, length);
		mem_Array -= sizeof( R ) + sizeof( struct Record );
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

    free(R);
    fclose(fptr);

    printf("\n");

    mem_Array=0;

   if ((fptr = fopen("data_10000.txt","r")) == NULL){
       printf("Error! opening file");

       exit(1);
   }
   fgets (str, 120, fptr);
   while(1){
   	if(strstr(str,"$Records")){
 		fgets (str, 120, fptr);
 		length=atoi(str);
		break;}		//converts the number of employees in record from string to integer

   }

    printf("Number of Records: %d\n", length);
    R = CreateArray(length);
    R = Insert_Data(length,R,fptr); //records inserted in array
    findR = CreateArray(1);         //for storing the number found in array

    R2 = CreateArray(length);
    //insert
    printf("Insert:");
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	for(i=0;i<length;++i)
    {
        R2 = Insert_Record(R[i],i, R2);
		mem_Array += sizeof( R2 ) + sizeof( struct Record );
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

    //find
	printf("Find:");
	QueryPerformanceCounter(&start_time);

	for(i=0;i<length;i=i+2)
		findR = Find(R[i],R,length);

	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

	//sort
	printf("Sort:");
	QueryPerformanceCounter(&start_time);
	Sort_Record(length,R2);
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

	copyR = CopyArray(R, length);
    for(i = 1; i < length; i++)
		mem_Array += sizeof( R ) + sizeof( struct Record );

    //delete
	printf("Delete:");
	QueryPerformanceCounter(&start_time);
	for(i = 1;i < length; i = i + 2)
    {
		Delete(R[i], copyR, length);
		mem_Array -= sizeof( R ) + sizeof( struct Record );
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

    free(R);

    fclose(fptr);
    printf("\n");

    mem_Array=0;

   if ((fptr = fopen("data_100000.txt","r")) == NULL){
       printf("Error! opening file");

       exit(1);
   }
   fgets (str, 120, fptr);
   while(1){
   	if(strstr(str,"$Records")){
 		fgets (str, 120, fptr);
 		length=atoi(str);
		break;}		//converts the number of employees in record from string to integer

   }

     printf("Number of Records: %d\n", length);
    R = CreateArray(length);
    R = Insert_Data(length,R,fptr); //records inserted in array
    findR = CreateArray(1);         //for storing the number found in array

    R2 = CreateArray(length);
    //insert
    printf("Insert:");
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	for(i=0;i<length;++i)
    {
        R2 = Insert_Record(R[i],i, R2);
		mem_Array += sizeof( R2 ) + sizeof( struct Record );
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

    //find
	printf("Find:");
	QueryPerformanceCounter(&start_time);

	for(i=0;i<length;i=i+2)
		findR = Find(R[i],R,length);

	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

	//sort
	printf("Sort:");
	QueryPerformanceCounter(&start_time);
	Sort_Record(length,R2);
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

	copyR = CopyArray(R, length);
    for(i = 1; i < length; i++)
		mem_Array += sizeof( R ) + sizeof( struct Record );

    //delete
	printf("Delete:");
	QueryPerformanceCounter(&start_time);
	for(i = 1;i < length; i = i + 2)
    {
		Delete(R[i], copyR, length);
		mem_Array -= sizeof( R ) + sizeof( struct Record );
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

    free(R);
    fclose(fptr);

    printf("\n");

    mem_Array=0;

   if ((fptr = fopen("data_1000000.txt","r")) == NULL){
       printf("Error! opening file");

       exit(1);
   }
   fgets (str, 120, fptr);
   while(1){
   	if(strstr(str,"$Records")){
 		fgets (str, 120, fptr);
 		length=atoi(str);
		break;}		//converts the number of employees in record from string to integer

   }

    printf("Number of Records: %d\n", length);
    R = CreateArray(length);
    R = Insert_Data(length,R,fptr); //records inserted in array
    findR = CreateArray(1);         //for storing the number found in array

    R2 = CreateArray(length);
    //insert
    printf("Insert:");
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	for(i=0;i<length;++i)
    {
        R2 = Insert_Record(R[i],i, R2);
		mem_Array += sizeof( R2 ) + sizeof( struct Record );
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

    //find
	printf("Find:");
	QueryPerformanceCounter(&start_time);

	for(i=0;i<length;i=i+2)
		findR = Find(R[i],R,length);

	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

	//sort
	printf("Sort:");
	QueryPerformanceCounter(&start_time);
	Sort_Record(length,R2);
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

	copyR = CopyArray(R, length);
    for(i = 1; i < length; i++)
		mem_Array += sizeof( R ) + sizeof( struct Record );

    //delete
	printf("Delete:");
	QueryPerformanceCounter(&start_time);
	for(i = 1;i < length; i = i + 2)
    {
		Delete(R[i], copyR, length);
		mem_Array -= sizeof( R ) + sizeof( struct Record );
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\t\tMemory Consumption: %d bytes\n", mem_Array);

    free(R);
    fclose(fptr);
    return 0;
}
