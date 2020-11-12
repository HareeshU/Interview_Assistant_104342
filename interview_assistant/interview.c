#include<stdio.h>
#include<stdlib.h>

typedef struct Applicant
{
char name[100];
long int ID;
int status;
float marks;
}Applicant;

typedef struct recruiter
{
long int ID;
}recruiter;

typedef struct Interviewer
{
long int interviewer_ID;
char interviewer_name[100];
}Interviewer;

typedef struct Panel
{
struct Interviewer interviewer;
struct Applicant applicant;
float selection_cutoff;
}Panel;

typedef struct Criteria                //given or by the recruiter
{
float marks;
float selection_cutoff;
}Criteria;


int selected_students_interview_count(Applicant* applicant_array, Criteria criteria, int n)
{
    int i;
    int count = 0;
    for(i = 0; i < n ;i++)
    {
        if((criteria.marks == 0 || applicant_array[i].marks >= criteria.marks))
        {
            count++;
        }
    }
    return count;
}

Applicant* selected_students_interview(Applicant* applicant_array, Criteria criteria, int n)
{
    int i;
    Applicant* selected_students = malloc(n*sizeof(Applicant));
    for(i = 0; i < n ;i++)
    {
        if((criteria.marks == 0 || applicant_array[i].marks >= criteria.marks))
        {
            selected_students[i] = applicant_array[i];
        }
    }
    return selected_students;
}

Criteria set_criteria(float marks, float selection_cutoff)
{
    Criteria criteria;
    criteria.marks = marks;
    criteria.selection_cutoff = selection_cutoff;
    return criteria;
}


Applicant* promoted_students(Panel* panel_array ,Criteria criteria, int n) //for screening
{
    Applicant* applicant_array = malloc(n*sizeof(Applicant));
    int i;
    for(i = 0; i < n ;i++)
    {
        if((criteria.marks == 0 || panel_array[i].applicant.marks >= criteria.marks) && ( criteria.selection_cutoff == 0 ||panel_array[i].selection_cutoff >= criteria.selection_cutoff))
        {
            applicant_array[i] = panel_array[i].applicant;
            applicant_array[i].status=1;
        }
    }
    return applicant_array;
}

int promoted_students_count(Panel* panel_array ,Criteria criteria, int n) //for screening
{
    int count = 0;
    int i;
    for(i = 0; i < n ;i++)
    {
        if((criteria.marks == 0 || panel_array[i].applicant.marks >= criteria.marks) && ( criteria.selection_cutoff == 0 ||panel_array[i].selection_cutoff >= criteria.selection_cutoff))
        {
            count++;
        }
    }
    return count;
}

Panel* allocate_panel(Applicant* applicant_array, Interviewer* interviewer_array, int n, int m)
{
    Panel* panel = malloc(n*sizeof(Panel));
    Panel* initial = panel;
    int i;
    for(i = 0; i < n; i++)
    {
        panel->interviewer = interviewer_array[i%m];
        panel->applicant = applicant_array[i];
        panel->selection_cutoff = 0;
        panel++;
    }
    return initial;
}

Panel* set_interview_marks(Panel *panel_mark,int n)
{
    Panel* initial = panel_mark;
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n Enter the marks secured by the applicant %s", panel_mark->applicant.name);
        scanf("%f",&panel_mark->selection_cutoff);
        panel_mark++;
    }
    return initial;
}

void print_candidate(Applicant* students_list, int n)
{
    for(int i = 0;i < n;i++)
    {
        printf("%ld  %s  SELECTED", students_list[i].ID, students_list[i].name);
        printf("\n");
    }
}

int main()
{
    int number_of_applicants,temp,i,count,number_of_interviewers,j;
    Applicant applicant_list[100];
    Criteria criteria;
    Panel *panel_list;
    Interviewer interviewer_list[10];
    printf(" Enter the number of students applied");
    scanf("%d",&number_of_applicants);
    temp=number_of_applicants;
    for(i=0;i<temp;i++)
    {
        printf("\n Enter the applicant name:");
        scanf("%s",applicant_list[i].name);
        printf("\n Enter the applicant ID:");
        scanf("%ld",&applicant_list[i].ID);
        printf("\n Enter the applicant marks:");
        scanf("%f",&applicant_list[i].marks);
    }
    criteria = set_criteria(8.5, 0);
    Applicant* selected_students_list = selected_students_interview(applicant_list,criteria, temp);
    count = selected_students_interview_count(applicant_list,criteria, temp);
    number_of_interviewers=2; //set by the recruiter
    for(j=0;j<number_of_interviewers;j++)
    {
        printf("\n Enter the Interviewer Name:");
        scanf("%s", interviewer_list[i].interviewer_name);
        printf("\n Enter the Interviewer ID:");
        scanf("%ld",&interviewer_list[i].interviewer_ID);
    }
    panel_list = allocate_panel(selected_students_list,interviewer_list,count,number_of_interviewers);
    Panel* panel_list_marks =set_interview_marks(panel_list,count);
    criteria = set_criteria(0,7);  //interview marks to get selected
    Applicant* final_applicants= promoted_students(panel_list_marks,criteria,count);
    int final_candidates = promoted_students_count(panel_list_marks,criteria,count);
    printf("\n*** The Final List of Selected Candidates *** \n");
    if(final_candidates!=0 && count!=0)
    print_candidate(final_applicants, final_candidates);
    else
    printf("\n No candidates were selected");
    return 0;
}
