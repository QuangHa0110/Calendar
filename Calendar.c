#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct calendar
{
    char *name_job;
    int day;
    int month;
    int hours;
    struct calendar *pnext;
} Cal;

typedef struct schedule
{
    Cal *phead, *ptail;
} Schedule;
Schedule *Sche1;
void init(Schedule *Sche1)
{
    Sche1 = NULL;
}

// to check format datetime
int check_datetime(int day, int month, int hours){};
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
void delete_entry(int day, int month, int hours)
{
    if (check_datetime(day, month, hours) == 1)
    {
        Schedule * current = 
    }
}
// replace calendar current
void load_calendar() {}
// print calendar current to console
void output_calendar()
{
    if (Sche1 == NULL)
        return;
    Schedule *p = Sche1;
    while (p->phead != NULL)
    {
        printf("%s ")
    }
}
// save a Schedule calendar to a filename
void save_calendar(FILE *file_name) {}
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

int main()
{
    char *name_job = (char *)malloc(1000 * sizeof(char));

    return 0;
}