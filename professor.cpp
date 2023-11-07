#include <bits/stdc++.h>
#include "courses.cpp"

class professor : private new_course
{
private:
    std::string pass = "teacher_password";

public:
    void see_students_in_my_course()
    {
        std ::string teacher_password;
        std ::cin >> teacher_password;
        if (pass == teacher_password)
        {
            std ::cout << "course name :: " << get_course_name() << " course id :: " << get_course_id() << std ::endl;
            std ::cout << "\n\tStudents in my course are:\n";
            for (int i = 0; i < enrolled_students.size(); i++)
            {
                std ::cout << enrolled_students[i] << std::endl;
            }
        }
        else
        {
            std::cout << "Enter valid password\n";
            static int retry = 3;
            retry--;
            if (retry)
                see_students_in_my_course();
            else
                std::cout << "Go Away Hacker\n";
        }
    }
};
