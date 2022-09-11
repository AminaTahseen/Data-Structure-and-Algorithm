#include <stdio.h>
#include <stdlib.h>
#include "hashquad.h"
#include <time.h>
#include <Windows.h>
#include <string.h>


FILE *fptr;
char str[120];
int main( )
{
	LARGE_INTEGER start_time, end_time, elapsed_time, frequency;
	HashTable H;
    Rec R;
    Position L;
	int length, len2, i;
    int mem = 0, mem_array;
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
 		length = atoi(str);  //converts the number of employees in record from string to integer
		break;}

   }

   printf("Number of Records: %d\n", length);
   H = InitializeTable(length);

   R = CreateArray(length);
   R = Insert_Data(length,R,fptr);

    printf("Insert: ");
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	len2 = length;
	for(i = 0; i < length;++i){
		Insert(R[i] ,H);
		if( i > len2 / 2 )
            {
                len2 *= 2;
                H = Rehash( H );
            }
		mem += sizeof( H ) + sizeof( struct HashEntry );
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem);

	printf("Find: ");
	QueryPerformanceCounter(&start_time);
	for(i = 0; i < length; i = i + 2){
		L = Find(R[i].ID,H);
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem);

	printf("Sorted Traversal: ");
	QueryPerformanceCounter(&start_time);
	mem_array = Sort(H);
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem + mem_array);

	printf("Delete: ");
	QueryPerformanceCounter(&start_time);
	for(i=1;i<length;i=i+2){
		Delete(R[i].ID,H);
	}

	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem);

	DestroyTable(H);//Destroying the table
	free(R);
	fclose(fptr);

	printf("\n");
	
	//data_10000
	mem=0;
	if ((fptr = fopen("data_10000.txt","r")) == NULL){
       printf("Error! opening file");

       exit(1);
   }
   fgets (str, 120, fptr);
   while(1){
   	if(strstr(str,"$Records")){
 		fgets (str, 120, fptr);
 		length = atoi(str);
		break;}		//converts the number of employees in record from string to integer

   }

   printf("Number of Records: %d\n", length);
   H = InitializeTable(length);

   R = CreateArray(length);
   R = Insert_Data(length,R,fptr);

    printf("Insert: ");
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	len2 = length;
	for(i = 0; i < length;++i){
		Insert( R[i] ,H);
		if( i > len2 / 2 )
            {
                len2 *= 2;
                H = Rehash( H );
            }
		mem += sizeof( H ) + sizeof( struct HashEntry );
	}

	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem);


	printf("Find: ");
	QueryPerformanceCounter(&start_time);
	for(i=0;i<length;i=i+2){
		L = Find(R[i].ID,H);
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem);

	printf("Sorted Traversal: ");
	QueryPerformanceCounter(&start_time);
	mem_array = Sort(H);
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem + mem_array);

	printf("Delete: ");
	for(i=1;i<length;i=i+2){
		Delete(R[i].ID, H);
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem);

	DestroyTable(H);//Destroying the table
	free(R);
	fclose(fptr);

	printf("\n");
	//data_100000
	mem=0;

	if ((fptr = fopen("data_100000.txt","r")) == NULL){
       printf("Error! opening file");

       exit(1);
   }
   fgets (str, 120, fptr);
   while(1){
   	if(strstr(str,"$Records")){
 		fgets (str, 120, fptr);
 		length = atoi(str);
		break;}		//converts the number of employees in record from string to integer

   }

   printf("Number of Records: %d\n", length);
   H = InitializeTable(length);

   R = CreateArray(length);
   R = Insert_Data(length,R,fptr);

    printf("Insert: ");
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	len2 = length;
	for(i = 0; i < length;++i){
		Insert( R[i] ,H);
		if( i > len2 / 2 )
            {
                len2 *= 2;
                H = Rehash( H );
            }
		mem += sizeof( H ) + sizeof( struct HashEntry );
	}

	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem);


	printf("Find: ");
	QueryPerformanceCounter(&start_time);
	for(i=0;i<length;i=i+2){
		L = Find(R[i].ID,H);
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem);

	printf("Sorted Traversal: ");
	QueryPerformanceCounter(&start_time);
	mem_array = Sort(H);
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem + mem_array);


	printf("Delete: ");
	QueryPerformanceCounter(&start_time);
	for(i=1;i<length;i=i+2){
		Delete(R[i].ID,H);
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem);

	DestroyTable(H);//Destroying the table
	free(R);
	fclose(fptr);

	printf("\n");
	//data_1000000
	mem = 0;

	if ((fptr = fopen("data_1000000.txt","r")) == NULL){
       printf("Error! opening file");

       exit(1);
   }
   fgets (str, 120, fptr);
   while(1){
   	if(strstr(str,"$Records")){
 		fgets (str, 120, fptr);
 		length = atoi(str);
		break;}		//converts the number of employees in record from string to integer

   }

   printf("Number of Records: %d\n", length);
   H = InitializeTable(length);

   R = CreateArray(length);
   R = Insert_Data(length,R,fptr);

    printf("Insert: ");
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	len2 = length;
	for(i = 0; i < length;++i){
		Insert( R[i] ,H);
		if( i > len2 / 2 )
            {
                len2 *= 2;
                H = Rehash( H );
            }
		mem += sizeof( H ) + sizeof( struct HashEntry );
	}

	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem);


	printf("Find: ");
	QueryPerformanceCounter(&start_time);
	for(i=0;i<length;i=i+2){
		L = Find(R[i].ID,H);
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\t\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem);


	printf("Delete: ");
	QueryPerformanceCounter(&start_time);
	for(i=1;i<length;i=i+2){
		Delete(R[i].ID,H);
	}
	QueryPerformanceCounter(&end_time);
	elapsed_time.QuadPart = end_time.QuadPart - start_time.QuadPart;
	run_time = ((double) elapsed_time.QuadPart) / frequency.QuadPart;
	printf("\t\tExecution Time:  %gs", run_time);
	printf("\tMemory Consumption: %d bytes\n", mem);

	DestroyTable(H);//Destroying the table
	free(R);
	fclose(fptr);
    return 0;
}
