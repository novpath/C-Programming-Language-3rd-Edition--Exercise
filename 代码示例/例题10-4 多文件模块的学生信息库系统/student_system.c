#include "student.h"
#include "input_output.c"
#include "aver_sort.c"
#include "modify.c"

int Count = 0;

int main(void) 
{
	struct student students[MaxSize];
	new_student(students);
	output_student(students);
	average(students);
	sort(students);
	output_student(students);
	modify(students);
	average(students);
	sort(students);
	output_student(students);
	
	return 0;
}
