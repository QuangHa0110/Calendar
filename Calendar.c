#include<stdio.h>
#include<string.h>
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
    Sche1=NULL;
}

// to check format datetime
int check_datetime(int day, int month, int hours){};
// to split line of input according format
void split(char *line){};
// input data for add_entry
void input(){}
// create a instant calendar
Cal *create_calendar(char* name_job, int day, int month, int hours){}
// add entry to Schedule
void add_entry(Schedule *Sche1, Cal *cal1){}
// delete a entry which user take input
void delete_entry(int day, int month, int hours){}
// print calendar current to console
void output_calendar(){}
// save a Schedule calendar to a filename
void save_calendar(FILE *file_name){}
// func run main
void run(){}

int main(){

    return 0;
}