#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct calendar{
    char* name_job;
    int day;
    int month;
    int hours;
    struct calendar *pnext;
}Cal;

typedef struct schedule{
    Cal *phead,*ptail;
}Schedule;

void init(Schedule *Sche1){
    Sche1->phead= Sche1->ptail = NULL;
}

Schedule Sche1;

// to check format datetime
int check_datetime(int day, int month, int hours){
    if( hours <0 || hours >23)
        {
            printf("TIME ERROR\n");
            return 0;
        }
    if ( day < 0 || day > 31)
        {
            printf("DAY ERROR\n");
            return 0;
        }
    if( month < 1 || month >12)
        {
            printf("MONTH ERROR\n");
            return 0;
        }
    else{
        switch (month)
        {
        case 2:
            if(day >29)
                return -2;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
            if(day > 31)
            {
                printf("MONTH ERROR\n");
                return 0;
            }
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11:
        {
            if( day > 30 )
            {
                printf("MONTH ERROR\n");
                return 0;
            }
            break;
        }
        }
    }
    return 1;
};
// to split line of input according format
void split(char *line, char* name_job, int *day, int *month, int *hours){};
// input data for add_entry
void input(char opcode,char* name_job, int *day, int*month, int*hours){
    
    char * data;
    // enter data
    scanf("%c %[^\n]s", &opcode, data);
    split(data,name_job,day,month,hours);
    if(check_datetime(*day,*month,*hours) == 0)
        printf("ERROR !!! datetime is not correctly");
}
// create a instant calendar
Cal *create_calendar(char* name_job, int day, int month, int hours){}
// compare two datetime
int datetime_cmp(Cal *c1, Cal *c2){
    if(c1->month < c2->month)
        // c1 < c2
        return -1;
    else if(c1->month > c2->month)
        // c1 > c2
        return 1;
    else if(c1->day < c2->day)
            // c1<c2
            return -1;
        else if(c1->day > c2->day)
            // c1> c2
            return 1;
        else if(c1->hours < c2->hours)
            // c1<c2
            return -1;
        else if(c1->hours > c2->hours)
            // c1> c2
            return 1;
        else
            // c1==c2
            return 0;
}
// add entry to Schedule
void add_entry(Schedule *Sche1, Cal *cal1){
    if(Sche1->phead == NULL){
        Sche1->phead = Sche1->ptail = cal1;
    }
    else if( datetime_cmp(Sche1->ptail, cal1) <0 ){
        Sche1->ptail->pnext = cal1;
        Sche1->ptail = cal1;
    }
    else{
        Cal* g = (Cal*)malloc(sizeof(Cal));
        Cal *k;
        for (k = Sche1->phead; k!= NULL; k->pnext )
        {
            if(datetime_cmp(k,cal1) == 0){
                printf("ERROR !!! There is existed");
                break;
            }
            else if (datetime_cmp(cal1,k) < 0)
            {
                cal1->pnext = k;
                g->pnext = cal1;
                printf("ADDED SUCCESS !!! ");
                break;
            }
            g = k;
        }
    }
}
// delete a entry which user take input
void delete_entry(int day, int month, int hours){}
// replace calendar current by file
void load_calendar(FILE *file_name){
    Sche1.phead= Sche1.ptail = NULL;
    while(fgetc(file_name) != EOF)  {
        char *data = (char*)malloc(100*sizeof(char));
        fscanf(file_name,"%[^\n]s",data);
        Cal *c1 = (Cal*)malloc(1* sizeof(Cal));
        split(data,c1->name_job,c1->day,c1->month,c1->hours);
        add_entry(&Sche1, c1);
    }
}
// print calendar current to console
void output_calendar(){}
// save a Schedule calendar to a filename
void save_calendar(FILE *file_name){
    Cal c1 = Sche1.phead;
    while (c1.pnext != NULL)
    {
        fprintf(file_name,"%s ",c1.name_job);
        fprintf(file_name,"%d ",c1.day);
        fprintf(file_name,"%d ",c1.month);
        fprintf(file_name,"%d\n",c1.hours);
    }
    
}
// func run main
void run(){}

int main(){
    init(&Sche1);
    
    return 0;
}