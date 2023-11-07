#include<iostream>
#include "student.cpp"
#include "courses.cpp"

class Enrollment : private student, new_course
{
    public:
    Enrollment(student& student1, new_course& new_course1)
    {
        student1.courses.push_back(new_course1.get_course_id());
        new_course1.enrolled_students.push_back(roll_number);
    }
    ~Enrollment(){}
};

class Enroll
{
    private:
    Enroll(int student_name, int course_id)
    {
        for(int i=0; i<6; i++)
        {
            Enrollment new_student(student& student1, new_course& new_course);
        }
    }
};