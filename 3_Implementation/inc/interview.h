/**
* @file interview.h
*
*/

#ifndef INTERVIEW_H_INCLUDED
#define INTERVIEW_H_INCLUDED

typedef struct Applicant
{
char name[100];
long int ID;
int status;
float marks;
}Applicant;

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
/**
*  sets the criteria marks for selection given by the recruiter
* @param[in] marks_CGPA (for initial screening of candidates)
* @param[in] selection_cutoff  (interview marks set by the recruiter)
* @return marks
*/
Criteria set_criteria(float marks, float selection_cutoff);
/**
*  screening  the applicants for interview  based on marks_CGPA and returns the selected applicant list
* @param[in] list of applicants
* @param[in] criteria for selecting applicants
* @param[in] number of applicants
* @return list of selected applicants for interview
*/
Applicant* selected_students_interview(Applicant* applicant_array, Criteria criteria, int n);
/**
*  selecting  the applicants after interview process  based on interview marks and returns the final selected applicants
* @param[in] list of applicants
* @param[in] criteria for selecting applicants
* @param[in] number of applicants
* @return final list of selected applicants
*/
Applicant* promoted_students(Panel* panel_array ,Criteria criteria, int n);
/**
*  allocating  the panels for interview process based on number of interviewers
* @param[in] list of applicants
* @param[in] list of interviewers (with ID and Name)
* @param[in] number of applicants
* @param[in] number of interviewers
* @return list of panels for conducting interview
*/
Panel* allocate_panel(Applicant* applicant_array, Interviewer* interviewer_array, int n, int m);

#endif /* #ifndef __INTERVIEW_H__ */
