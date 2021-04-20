#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct calendar{
    char* name_job;
    int day;
    int month;
    int hours;
    struct calendar *pnext;
} Cal;

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

void split(char *line, char *name_job, int *day, int *month, int *hours)
{
    char s[5][1000];
    int cnt = 0, j = 0;
    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] == ' ' || line[i] == '\0')
        {
            s[cnt][j] = '\0';
            cnt++;
            j = 0;
        }
        else
        {
            s[cnt][j] = line[i];
            j++;
        }
    }
    char *name;
    strcpy(name_job, s[0]);
    puts(name_job);
    *day = atoi(s[1]);
    *month = atoi(s[2]);
    *hours = atoi(s[3]);
}

// input data for add_entry
void input() {}
// create a instant calendar
Cal *create_calendar(char *name_job, int day, int month, int hours)
{
    Cal *calendar = (Cal *)malloc(sizeof(Cal));
    strcpy(calendar->name_job, name_job);

    calendar->day = day;
    calendar->month = month;
    calendar->hours = hours;
    return calendar;
}
// add entry to Schedule
void add_entry(Schedule *Sche1, Cal *cal1) {}
// delete a entry which user take input
Schedule * delete_entry(Schedule *Sche1,int day, int month, int hours)
{
    if (check_datetime(day, month, hours) == 1)
    {
        Schedule * current = Sche1;
        if(Sche1 == NULL) return Sche1;

        while(current->ptail!=NULL){
            if(current->ptail->day == day && current->ptail->month == month && current->ptail->hours == hours){
                current = current ->ptail;
                current->phead == NULL;
                break;
            }
        } 
    return Sche1;
    }
    else return Sche1;
}
// replace calendar current
void load_calendar() {}
// print calendar current to console
void output_calendar(Schedule* Sche1)
{
    if (Sche1 == NULL)
        return;
    Schedule *p = Sche1;
    while (p->ptail != NULL)
    {
        printf("%s ", p->ptail);
    }
}
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
void run()
{
    char choose;
    int check = 0;
    do
    {   
        switch (choose)
        {
        case 'A':
            add_entry();
            break;
        case 'D':
            delete_entry();
            break;
        case 'L':
            output_calendar();
            break;
        case 'W':
            save_calendar();
            break;
        case 'O':
            load_calendar();
            break;
        case 'Q':
            check =1;
            exit;
            break;
        default:
            check=1;
            break;
        }
    } while (check ==0);
}

int main(){
    init(&Sche1);
    
    return 0;
}