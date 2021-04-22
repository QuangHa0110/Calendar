#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void init(Schedule *Sche1)
{
    Sche1->phead = Sche1->ptail = NULL;
}

Schedule Sche1;

// to check format datetime
int check_datetime(int day, int month, int hours)
{
    if (hours < 0 || hours > 23)
    {
        printf("TIME ERROR\n");
        return 0;
    }
    if (day < 0 || day > 31)
    {
        printf("DAY ERROR\n");
        return 0;
    }
    if (month < 1 || month > 12)
    {
        printf("MONTH ERROR\n");
        return 0;
    }
    else
    {
        switch (month)
        {
        case 2:
            if (day > 29)
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
            if (day > 31)
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
            if (day > 30)
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

// create a instant calendar
Cal *create_calendar(char *name_job, int day, int month, int hours)
{
    Cal *calendar = (Cal *)calloc(1, sizeof(Cal));
    calendar->name_job = (char *)malloc((strlen(name_job) + 1) * sizeof(char));
    strcpy(calendar->name_job, name_job);
    calendar->day = day;
    calendar->month = month;
    calendar->hours = hours;
    return calendar;
}
// compare two datetime
int datetime_cmp(Cal *c1, Cal *c2)
{
    if (c1->month < c2->month)
        // c1 < c2
        return -1;
    else if (c1->month > c2->month)
        // c1 > c2
        return 1;
    else if (c1->day < c2->day)
        // c1<c2
        return -1;
    else if (c1->day > c2->day)
        // c1> c2
        return 1;
    else if (c1->hours < c2->hours)
        // c1<c2
        return -1;
    else if (c1->hours > c2->hours)
        // c1> c2
        return 1;
    else
        // c1==c2
        return 0;
}
// add entry to Schedule
int add_entry(Schedule *Sche1, Cal *cal1)
{
    if (Sche1->phead == NULL)
    {
        Sche1->phead = Sche1->ptail = cal1;
        Sche1->phead->pnext = NULL;
        Sche1->ptail->pnext = NULL;
        printf("ADDED SUCCESS !!!\n");
        fflush(stdin);
        return 1;
    }
    else if (datetime_cmp(Sche1->phead, cal1) > 0)
    {
        cal1->pnext = Sche1->phead;
        Sche1->phead = cal1;

        printf("ADDED SUCCESS !!!\n");

        fflush(stdin);
        return 1;
    }
    else if (datetime_cmp(Sche1->ptail, cal1) < 0)
    {
        Sche1->ptail->pnext = cal1;
        Sche1->ptail = cal1;
        printf("ADDED SUCCESS  !!!\n");
        fflush(stdin);
        return 1;
    }
    else
    {
        Cal *k;
        Cal *g;
        for (k = Sche1->phead; k != NULL; k = k->pnext)
        {
            if (datetime_cmp(cal1, k) == 0)
            {
                printf("This schedule is existed!!!\n");
                fflush(stdin);
                return 0;
                break;
            }
            else if (datetime_cmp(cal1, k) < 0)
            {
                g->pnext = cal1;
                cal1->pnext = k;
                printf("ADDED SUCCESS !!!\n");
                fflush(stdin);
                return 1;
                break;
            }
            g = k;
        }
    }
    printf("\n");
    fflush(stdin);
    return 1;
}

// delete a entry which user take input
void delete_entry(int day, int month, int hours)
{
    if (Sche1.phead == NULL)
    {
        printf("This Schedule is empty!!!\n");
        fflush(stdin);
    }
    else
    {
        if (check_datetime(day, month, hours) == 1)
        {
            Cal *c1 = create_calendar("tmp", day, month, hours);
            if (datetime_cmp(Sche1.phead, c1) == 0)
            {
                Cal *g = Sche1.phead;
                Sche1.phead = Sche1.phead->pnext;
                free(g);
                printf("DELETE DONE !!!\n");
                fflush(stdin);
            }
            else
            {
                Cal *g = (Cal *)calloc(1, sizeof(Cal));
                Cal *k = (Cal *)calloc(1, sizeof(Cal));
                for (k = Sche1.phead; k != NULL; k = k->pnext)
                {
                    if (datetime_cmp(k, c1) == 0)
                    {
                        Cal *h = k;
                        g->pnext = h->pnext;
                        free(h);
                        printf("DELETE DONE !!!\n");
                        fflush(stdin);
                        return;
                    }
                    g = k;
                }
                printf("The datetime is not exist to delete !!!\n");
                fflush(stdin);
                free(g);
                free(k);
            }
            free(c1->name_job);
            free(c1);
        }
    }
}
// replace calendar current
void load_calendar(FILE *file_name)
{
    Sche1.phead = Sche1.ptail = NULL;

    while (getc(file_name) != EOF)
    {
        char *data = (char *)calloc(100, sizeof(char));
        int day, month, hours;

        fscanf(file_name, "%s", data);
        fscanf(file_name, "%d%d%d", &day, &month, &hours);
        fflush(stdin);
        if (day != 0)
        {
            Cal *c1 = create_calendar(data, day, month, hours);
            add_entry(&Sche1, c1);
        }
        free(data);
    }
    printf("LOAD SUCCESS\n");
    fflush(stdin);
}
// print calendar current to console
void output_calendar()
{
    if (Sche1.phead == NULL && Sche1.ptail == NULL)
    {
        printf("Empty date!!!!\n");
        fflush(stdin);
        return;
    }
    else
    {
        Cal *s1 = Sche1.phead;
        while (s1 != Sche1.ptail->pnext)
        {
            printf("%s on %d.%d at %d\n", s1->name_job, s1->day, s1->month, s1->hours);
            fflush(stdin);
            s1 = s1->pnext;
        }
        // return;
    }
}
// save a Schedule calendar to a filename
void save_calendar(FILE *file_name)
{
    Cal *s1 = Sche1.phead;
    while (s1 != NULL)
    {

        if (s1->pnext == NULL)
        {
            fprintf(file_name, " %s %d %d %d", s1->name_job, s1->day, s1->month, s1->hours);
        }
        else
        {
            fprintf(file_name, " %s %d %d %d\n", s1->name_job, s1->day, s1->month, s1->hours);
        }
        s1 = s1->pnext;
    }
    printf("SAVE SUCCESS\n");
    fflush(stdin);
}
// remove all Schedule
void removeAll()
{
    Cal *current = NULL;
    while (Sche1.phead != NULL)
    {
        current = Sche1.phead->pnext;
        free(Sche1.phead->name_job);
        free(Sche1.phead);
        Sche1.phead = current;
    }
}
// func run main
void run()
{

    char choose;

    while (1)
    {

        fflush(stdin);
        scanf("%c", &choose);
        char *name_job = (char *)calloc(1000, sizeof(char));
        int day = 0;
        int month = 0;
        int hours = 0;
        FILE *file_name;
        switch (choose)
        {
        case 'A':
            // if choose = 'A', then executes add a entry

            scanf("%s", name_job);
            scanf("%d %d %d", &month, &day, &hours);
            fflush(stdin);
            if (check_datetime(day, month, hours) == 1)
            {
                Cal *new_calendar = create_calendar(name_job, day, month, hours);
                int a = add_entry(&Sche1, new_calendar);
                if (a == 0)
                {
                    free(new_calendar->name_job);
                    free(new_calendar);
                }
            }

            break;
        case 'D':
            // if choose = 'D', then executes delete a entry with day, month, hours
            scanf("%d %d %d", &month, &month, &hours);
            fflush(stdin);
            delete_entry(day, month, hours);
            break;
        case 'L':
            // if choose ='L' print Schedule to console
            fflush(stdin);
            output_calendar();
            break;
        case 'W':
            // if choose ='W', then save schedule to <filename>
            scanf("%s", name_job);
            file_name = fopen(name_job, "w");
            save_calendar(file_name);
            fclose(file_name);
            break;
        case 'O':

            scanf("%s", name_job);
            file_name = fopen(name_job, "r");
            load_calendar(file_name);
            fclose(file_name);
            break;
        case 'Q':
            free(name_job);
            printf("GOOD BYE && SEE YOUR AGAIN!!!");
            removeAll();
            exit(1);
            break;
        }
        free(name_job);
    }
}

int main()
{
    run();

    return 0;
}
