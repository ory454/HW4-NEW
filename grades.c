#include <stdio.h>
#include <stdlib.h>
#include "grades.h"
#include "linked-list.h"
#include <string.h>
typedef struct grades{
 struct list * students_list;
};

typedef course{
    char* name;
    int grade;
} *Course;

int course_clone(void* element,void ** output){
    if(element==NULL||output==NULL){
        return 1;
    }
    Course source_course =(Course)element;
    Course new_course=(Course)malloc(sizeof(struct course));
    if(new_course==NULL){
        return 1;
    }
    new_course->grade=source_course->grade;
    new course->name= (char *)malloc(strlen(source_course->name)+1);
    if(new_course->name==NULL){
        free(new_course);
        return 1;
    }
    strlen(new_course->name,source_course->name);
    *output=(void*)new_course;
    return 0;
}

void course_destroy(void* element){
    if(element==NULL) return;
    Course c=(Course)element;
    free(c->name);
    free(c);
}




/*defining studnt ADT. clone func and destroy func*/
typedef struct student{
    int id;
    char* name;
    struct list* courses_list;
}*Student;

int course_clone(void* element, void **output){
    struct sourc
}

int student_clone(void* element ,void **output){
    if(element==NULL||output==NULL) return 1;
    student source_student= (Student)element;
    student new_student=(Student)malloc(sizeof(student));
    if(new_student==NULL) return 1;
    new_student->id=source_student->id;
    new_student->name=(*char)malloc(strlen(source_student->name)+1);
    if(new_student->name==NULL){
        free(new_student);
        return 1;
    }
    strcpy(new_student->name,source_student->name);

    new_student->courses_list=list_init(course_clone,course_destroy);
    if(new_student->courses_list==NULL){
        free(new_student->name);
        free(new_student);
        return 1;
    } 



}
struct grades* grades_init(){
    grades* temp= (struct grades*)malloc(sizeof(grades));
    if(!temp) return NULL;
    temp->students_list=list_init()
}