		#ifndef _Array_H
        #define _Array_H
        struct Record;
        typedef struct Record *Rec;

        enum KindOfEntry { Legitimate, Empty, Deleted};
        struct Record{
            enum KindOfEntry Info;
            unsigned int ID;
            char Name[20], city[4];
            char Rank[2];
        };

        Rec CreateArray(int size);
        Rec Insert_Data(int size, Rec R, FILE *fptr);
        void Sort_Record(int size, Rec R);
        void Print_Array(Rec R, int size);
        Rec Find(struct Record Data, Rec R, int size);
        void Delete(struct Record Data, Rec R, int size);
        Rec CopyArray(Rec R, int size);
        Rec Insert_Record(struct Record Data,int index, Rec Array);

        #endif
