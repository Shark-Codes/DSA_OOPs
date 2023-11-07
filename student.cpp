#include <iostream>
#include<vector>

class student
{
    private:
        friend class Enrollment;
        static int student_count;
        int mobile_number;

        unsigned short int courses_count=0;

    protected:
        std :: vector<int> courses;
        std :: string name;
        std :: string roll_number;

        struct dob
        {
                int day   = 0;
                int month = 0; // if we see these value 0 then we can use it for error handling
                int year  = 0;
                
        }stud;

    public:
        student (void) {/*do nothing constructor*/};
        student (std::string name, std :: string roll_number, int day_dob, int month_dob, int year_dob, int mobile_number)
        {
            this->name          =name;
            this->roll_number   = roll_number;
            this->mobile_number = mobile_number;
            
            stud.day   = day_dob;
            stud.month = month_dob;
            stud.year  = year_dob;

            student_count++;
        }

        void getdata();
};

int student :: student_count = 0;


void student :: getdata()
{
    std :: cout << "---------------------------------------------"         << std :: endl;
    std :: cout << "Student Name ::              " << name                 << std :: endl;
    std :: cout << "Student Roll number ::       " << roll_number          << std :: endl;
    std :: cout << "Student Date of Birth is ::  " << stud.day << "/" <<stud.month << "/" <<stud.year<< std :: endl;
    std :: cout << "Student Mobile number is ::  " << mobile_number        << std :: endl << std :: endl;
    std :: cout << "---------------------------------------------"         << std :: endl;
}

