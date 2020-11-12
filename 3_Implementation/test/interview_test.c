#include "src-heacder.h"
#include "unity_header.h"
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

typedef struct Applicant
{
char name[100];
long int ID;
int status;
float marks;
}Applicant;

typedef struct Criteria
{
float marks;
float selection_cutoff;
}Criteria;

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

void test_selected_students_interview()
{
Criteria c ={8,0};
Applicant app1= {"kevin",123,0,9};
Applicant app2= {"jack",246,0,7};
Applicant app3 ={"jimin",234,0,8.2};
Applicant app1icant_list[3]={app1,app2,app3};
Applicant expected_list[2] = {app1,app3};
Applicant *actual= selected_students_interview(app1icant_list,c,3);

for(int i = 0; i < 2;i++)
{
TEST_ASSERT_EQUAL_STRING_MESSAGE(expected_list[i].name,actual[i].name,"ERROR in NAME");
TEST_ASSERT_EQUAL_MESSAGE(expected_list[i].ID,actual[i].ID, "ERROR in ID");
TEST_ASSERT_EQUAL_MESSAGE(expected_list[i].status,actual[i].status, "Error in Status");
TEST_ASSERT_EQUAL_MESSAGE(expected_list[i].marks,actual[i].marks, "Error in Marks");
}
}
void test_allocate_panel()
{
  Applicant app1 = {"kevin",123,0,9};
  Applicant app2 = {"jack",246,0,7};
  Applicant app1icant_list[2]={app1,app2};
  Interviewer I1 = {"Interviewer_1",45};
  Interviewer I2 = {"Interviewer_2",89};
  Interviewer interviewer_list[2] = {I1,I2};
  Panel *panel = allocate_panel(app1icant_list,interviewer_list,2,2);

  for(int i = 0;i < 2;i++) {
    TEST_ASSERT_EQUAL_STRING(interviewer_list[i].interviewer_name,panel[i].interviewer.interviewer_name);
    TEST_ASSERT_EQUAL_STRING(app1icant_list[i].name,panel[i].applicant.name);
  }
}

void test_promoted_students()
{
Criteria c ={0,8};
Applicant app1 = {"kevin",123,0,9};
Applicant app2 = {"jack",246,0,7};
Interviewer I1 = {"Interviewer_1",45};
Interviewer I2 = {"Interviewer_2",89};
Panel panel1 = {I1, app1, 7};
Panel panel2 = {I2, app2, 9};
Panel panel_list[2] = {panel1, panel2};
Applicant expected_list[1] = {app2};
Applicant *actual= promoted_students(panel_list,c,2);

for(int i = 0;i < 1;i++) {
    TEST_ASSERT_EQUAL_STRING(expected_list[i].name,actual[i].name);
    TEST_ASSERT_EQUAL(expected_list[i].ID,actual[i].ID);
    TEST_ASSERT_EQUAL(1,actual[i].status);
    TEST_ASSERT_EQUAL(expected_list[i].marks,actual[i].marks);
}
}

int test_main(void)
{
  /* Initiate the Unity Test Framework */
  UNITY_BEGIN();
  /* Run Test functions */
  RUN_TEST(test_selected_students_interview);
  RUN_TEST(test_allocate_panel);
  RUN_TEST(test_promoted_students);
  /* Close the Unity Test Framework */
  return UNITY_END();
}
