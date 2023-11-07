#include <bits/stdc++.h>

class course
{
protected:
    static int course_count;
    static std:: set<std::pair<int,std::string>> all_courses;
};

class new_course : private course
{
private:
    friend class Enrollment;
    std::string course_name;
    unsigned short int course_id;
    std ::string course_password = "my_password", temp;
protected:
    std :: vector<std::string> enrolled_students;
    int get_course_id(){return course_id;}
    std :: string get_course_name() {return course_name;}
public:

    new_course(void){/*default constructor*/}
    new_course(int id, std :: string course_name)
    {
        std ::cout << "This requires authentifiaction, Enter password :: ";
        std ::cin >> temp;
        if (temp == course_password)
        {
            this->course_id = id;
            course_count++;
            
            this->course_name = course_name;

            all_courses.insert(std::make_pair(id,course_name));
        }
    }
};
