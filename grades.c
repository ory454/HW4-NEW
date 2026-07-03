#include <stdio.h>
#include <stdlib.h>
#include "grades.h"
#include "linked-list.h"
#include <string.h>

typedef struct grades {
    struct list *students_list;
};

typedef struct course {
    char *name;
    int grade;
} *Course;

int course_clone(void *element, void **output) {
    if (element == NULL || output == NULL) {
        return 1;
    }
    Course source_course = (Course)element;
    Course new_course = (Course)malloc(sizeof(struct course));
    if (new_course == NULL) {
        return 1;
    }
    new_course->grade = source_course->grade;
    new_course->name = (char *)malloc(strlen(source_course->name) + 1);
    if (new_course->name == NULL) {
        free(new_course);
        return 1;
    }
    strcpy(new_course->name, source_course->name);
    *output = (void *)new_course;
    return 0;
}

void course_destroy(void *element) {
    if (element == NULL) return;
    Course c = (Course)element;
    free(c->name);
    free(c);
}

typedef struct student {
    int id;
    char *name;
    struct list *courses_list;
} *Student;

int student_clone(void *element, void **output) {
    if (element == NULL || output == NULL) return 1;
    Student source_student = (Student)element;
    Student new_student = (Student)malloc(sizeof(struct student));
    if (new_student == NULL) return 1;
    new_student->id = source_student->id;
    new_student->name = (char *)malloc(strlen(source_student->name) + 1);
    if (new_student->name == NULL) {
        free(new_student);
        return 1;
    }
    strcpy(new_student->name, source_student->name);
    new_student->courses_list = list_init(course_clone, course_destroy);
    if (new_student->courses_list == NULL) {
        free(new_student->name);
        free(new_student);
        return 1;
    }
    *output = new_student;
    return 0;
}

void student_destroy(void *element) {
    if (element == NULL) return;
    Student s = (Student)element;
    if (s->name != NULL) {
        free(s->name);
    }
    if (s->courses_list != NULL) {
        list_destroy(s->courses_list);
    }
    free(s);
}

struct grades *grades_init() {
    struct grades *temp = (struct grades *)malloc(sizeof(struct grades));
    if (!temp) return NULL;
    temp->students_list = list_init(student_clone, student_destroy);
    if (temp->students_list == NULL) {
        free(temp);
        return NULL;
    }
    return temp;
}

void grades_destroy(struct grades *grades) {
    if (grades == NULL) return;
    list_destroy(grades->students_list);
    free(grades);
}

/* TODO: grades_add_student
 * - Return 1 if grades==NULL or name==NULL.
 * - Iterate students_list to check no student with the same id already exists;
 *   return 1 if duplicate found.
 * - Allocate a new Student: malloc(sizeof(struct student)), copy name with
 *   malloc+strcpy, set id, init courses_list with list_init(course_clone,
 *   course_destroy). Return 1 on any allocation failure (free partials).
 * - Push the new student onto students_list with list_push_back (or equivalent).
 * - Return 0 on success. */
int grades_add_student(struct grades *grades, const char *name, int id) {
    /* TODO: implement */
	if(!grades||!name)
		return 1;
	for(int i=0;i<list_size(grades->students_list);i++){
		string iterator_id= (Student)list_get(grades->students_list))->id;
		if (iterator_id==id){
			return 1;
	}
	Student s= malloc(sizeof(Student));
	strcopy(s->name,name);
	s->id=id;
	list_push_front( grades->students_list, s);
	return 0;
}

/* TODO: grades_add_grade
 * - Return 1 if grades==NULL or name==NULL.
 * - Return 1 if grade is not in [0, 100].
 * - Iterate students_list to find the student with the given id; return 1 if
 *   not found.
 * - Iterate that student's courses_list to check no course with the same name
 *   exists; return 1 if duplicate found.
 * - Allocate a new Course: malloc(sizeof(struct course)), copy name with
 *   malloc+strcpy, set grade. Return 1 on any allocation failure (free partials).
 * - Push the new course onto the student's courses_list.
 * - Return 0 on success. */
int grades_add_grade(struct grades *grades, const char *name, int id,
                     int grade) {
	if(grades)
}
    /* TODO: implement */
    return 1;
}

/* TODO: grades_calc_avg
 * - Set *out=NULL and return -1 if grades==NULL or out==NULL.
 * - Iterate students_list to find the student with the given id; return -1 if
 *   not found (with *out=NULL).
 * - Set *out to a heap-allocated copy of the student's name (caller frees);
 *   return -1 if malloc fails.
 * - If the student has no courses, return 0.0.
 * - Otherwise iterate courses_list, sum all grades, divide by count, return
 *   the average as a float. */
float grades_calc_avg(struct grades *grades, int id, char **out) {
    /* TODO: implement */
    if (out) *out = NULL;
    return -1;
}

/* TODO: grades_print_student
 * - Return 1 if grades==NULL.
 * - Iterate students_list to find the student with the given id; return 1 if
 *   not found.
 * - Print: "NAME ID: " then for each course print "COURSE_NAME GRADE, "
 *   then a newline. Format matches: "Alice 123: Math 95, English 80,\n"
 *   (trailing comma before newline is acceptable per spec).
 * - Return 0 on success. */
int grades_print_student(struct grades *grades, int id) {
    /* TODO: implement */
    return 1;
}

/* TODO: grades_print_all
 * - Return 1 if grades==NULL.
 * - Iterate students_list in insertion order and call grades_print_student for
 *   each student's id.
 * - Return 0 on success. */
int grades_print_all(struct grades *grades) {
    /* TODO: implement */
    return 1;
}
