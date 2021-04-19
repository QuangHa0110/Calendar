#include<stdio.h>
#include<string.h>
typedef struct calendar{
    char* name_job;
<<<<<<< HEAD
    char* day;
    char* month;
    char* hours;
}calendar;
void splitString(char* line){}
void add_entry(calendar calendar){}
void 
=======
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

>>>>>>> 23d4cf2ed88df174fbce4ba3f4a901a51467b334
int main(){

    return 0;
}