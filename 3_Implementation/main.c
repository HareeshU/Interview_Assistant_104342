#include <stdio.h>
#include <stdlib.h>
int main()
{
    test_main();
    /*int number_of_applicants,temp,i,count,number_of_interviewers,j;
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
    printf("\n No candidates were selected");*/
    return 0;
}

