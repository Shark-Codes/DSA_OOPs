#include <bits/stdc++.h>

class student
{
private:
    friend class Enrollment;
    static int student_count;
    int mobile_number;

    unsigned short int courses_count = 0;

protected:
    std ::vector<int> courses;
    std ::string name;
    std ::string roll_number;

    struct dob
    {
        int day = 0;
        int month = 0; // if we see these value 0 then we can use it for error handling
        int year = 0;

    } stud;

public:
    student(void){/*do nothing constructor*/};
    student(std::string name, std ::string roll_number, int day_dob, int month_dob, int year_dob, int mobile_number)
    {
        this->name = name;
        this->roll_number = roll_number;
        this->mobile_number = mobile_number;

        stud.day = day_dob;
        stud.month = month_dob;
        stud.year = year_dob;

        student_count++;
    }

    void getdata();
};

int student ::student_count = 0;

void student ::getdata()
{
    std ::cout << "---------------------------------------------" << std ::endl;
    std ::cout << "Student Name ::              " << name << std ::endl;
    std ::cout << "Student Roll number ::       " << roll_number << std ::endl;
    std ::cout << "Student Date of Birth is ::  " << stud.day << "/" << stud.month << "/" << stud.year << std ::endl;
    std ::cout << "Student Mobile number is ::  " << mobile_number << std ::endl
               << std ::endl;
    std::cout << "Total = " << student_count << "\n";
    std ::cout << "---------------------------------------------" << std ::endl;
}

class course
{
protected:
    static int course_count;
    static std::set<std::pair<int, std::string>> all_courses;
};

class new_course : private course
{
private:
    friend class Enrollment;
    friend class professor;
    std::string course_name;
    int course_id;
    std ::string course_password = "m", temp;

protected:
    int get_course_id() { return course_id; }
    std ::string get_course_name() { return course_name; }
    std ::vector<std::string> enrolled_students;

public:
    new_course(void)
    { /*default constructor*/
    }
    new_course(int id, std ::string course_name)
    {
        std ::cout << "This requires authentifiaction, Enter password :: ";
        std ::cin >> temp;
        if (temp == course_password)
        {
            this->course_id = id;
            course_count++;

            this->course_name = course_name;
            // Initialize the enrolled_students vector here
            enrolled_students = std::vector<std::string>();
            all_courses.insert(std::make_pair(id, course_name));
        }
        else
        {
            std ::cout << "wrong password\n";
            return;
        }
    }
    void get_course_data()
    {
        std::cout << course_name << "\n";
        std::cout << course_id << "\n";
        std::cout << course_count << "\n";
    }
};

int course ::course_count = 0;
std::set<std::pair<int, std::string>> course::all_courses;

// class Enrollment : private student, new_course
// {
//     public:
//     Enrollment(student& student1, new_course& new_course1)
//     {
//         student1.courses.push_back(new_course1.get_course_id());
//         new_course1.enrolled_students.push_back(roll_number);
//     }
//     ~Enrollment(){}
// };

class Enrollment : private student, new_course
{
public:
    Enrollment(student &student1, new_course &new_course1) : student(student1), new_course(new_course1)
    {
        student1.courses.push_back(new_course1.get_course_id());
        new_course1.enrolled_students.push_back(student1.roll_number);
    }
    ~Enrollment() {}
};

class Enroll
{
public:
    Enroll(student &student1, new_course &n)
    {
        // Correctly enroll the student in the course
        Enrollment new_student(student1, n);
    }
};

class professor : private new_course
{

public:
    void see_students_in_my_course(new_course &t)
    {
            std ::cout << "course name :: " << t.get_course_name() << std::endl;
            std ::cout << "course id :: " << t.get_course_id() << std ::endl;
            std ::cout << "\n\tStudents in my course are:\n";
            for (int i = 0; i < t.enrolled_students.size(); i++)
            {
                std ::cout << t.enrolled_students[i] << std::endl;
            }std::cout<<"\n\n";
    }
};

// int main()
// {
//     student s("john", "1858", 11, 6, 1980, 988887); // Create a student object
//     s.getdata();

//     new_course maths(1, "maths");
//     maths.get_course_data();

//     Enroll E(s, maths);
//     professor p;

//     // Pass the "maths" course object to the professor's method
//     p.see_students_in_my_course(maths);

//     return 0;
// }

    int main()
    {
        // Create 6 students
        student student1("John", "1858", 11, 6, 1980, 988887);
        student student2("Alice", "1859", 12, 7, 1981, 988888);
        student student3("Bob", "1860", 10, 8, 1982, 988889);
        student student4("Eve", "1861", 9, 9, 1983, 988890);
        student student5("Charlie", "1862", 8, 10, 1984, 988891);
        student student6("Grace", "1863", 7, 11, 1985, 988892);

        // Create 6 different courses
        new_course course1(1, "Maths");
        new_course course2(2, "Physics");
        new_course course3(3, "Chemistry");
        new_course course4(4, "Biology");
        new_course course5(5, "History");
        new_course course6(6, "Literature");

        // Make students take different numbers of courses
        Enroll enroll1(student1, course1);
        Enroll enroll2(student2, course1);
        Enroll enroll3(student3, course2);
        Enroll enroll4(student4, course3);
        Enroll enroll5(student5, course2);
        Enroll enroll6(student6, course4);

        professor p[6];
        p[0].see_students_in_my_course(course1);
        p[2].see_students_in_my_course(course2);
        p[3].see_students_in_my_course(course3);
        p[4].see_students_in_my_course(course4);
        p[5].see_students_in_my_course(course5);

        return 0;
    }