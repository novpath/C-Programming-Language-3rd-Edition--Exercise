#ifndef __LIST_HEAD__
#define __LIST_HEAD__

#include<stdio.h>
#include<string.h>
#define MaxSize 50


struct student{
	int num;
	char name[10];
	int computer, english, math;
	float average;
};

void average(struct student s[]);
void sort(struct student s[]);
void new_student(struct student students[]);
void output_student(struct student students[]);
void modify(struct student *p);
void search_student(struct student students[], int num); 

#endif
