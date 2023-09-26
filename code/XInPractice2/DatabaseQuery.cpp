
#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

/// @brief stores student information
class student {
    public:
        string firstName;
        string lastName;
        int year;
        string major;

        student(string firstName, string lastName, int year, string major): firstName(firstName), lastName(lastName), year(year), major(major) {

        }
};

/// @brief Returns true if word meets criteria
///     ie. if they are the same, or the criteria is an empty string.
/// @param word - the string from the student
/// @param criteria - the string the student should be equal to.
/// @return True if criteria is an empty string or word and criteria are the same, false otherwise
static bool wordMeetsCriteria(string word, string criteria) {
    if(criteria == "")
        return true;
    
    if(word == criteria)
        return true;

    return false;
}

/// @brief Checks the students full name to ensure it meets the query criteria
/// @param s - student
/// @param firstName - firstname from query
/// @param lastName - last name from query
/// @return True if student has the correct name for meeting the criteria, false otherwise
static bool studentHasCorrectFullName(student s, string firstName, string lastName) {
    return wordMeetsCriteria(s.firstName, firstName) && wordMeetsCriteria(s.lastName, lastName);
}

/// @brief Checks the student year to ensure it meets criteria. If year is 0, then this criteria is always true.
/// @param s - student
/// @param year - year criteria from the query
/// @return - true if the student meets the criteria, false otherwise
static bool studentHasCorrectYear(student s, int year) {
    if(year == 0)
        return true;
    
    if(s.year == year)
        return true;
    
    return false;
}

/// @brief Checks all the query criteria to see if student meets the query requirments.
/// @param s - student
/// @param firstName - first name from query. If empty string this criteria is neglected.
/// @param lastName - last name from query. If empty string this criteria is neglected.
/// @param year - year in school from query. If 0 this criteria is neglected.
/// @param major - major from query. If empty string this criteria is neglected.
/// @return - True if student meets input criteria, false otherwise.
static bool studentMeetsCrieteria(student s, string firstName, string lastName, int year, string major) {
    return studentHasCorrectFullName(s, firstName, lastName) && studentHasCorrectYear(s, year) && wordMeetsCriteria(s.major, major);
}

/// @brief Gets a list of students who meet the input criteria
/// @param allStudents - list of students to check
/// @param firstName - first name from query. If empty string this criteria is neglected.
/// @param lastName - last name from query. If empty string this criteria is neglected.
/// @param year - year in school from query. If 0 this criteria is neglected.
/// @param major - major from query. If empty string this criteria is neglected.
/// @return A list of all students who meet the query criteria.
static vector<student> QueryStudents(vector<student> allStudents, 
                                     string firstName, string lastName, int year, string major) {

    vector<student> queryStudents { };

    for(student s: allStudents) {
        if(studentMeetsCrieteria(s, firstName, lastName, year, major))
            queryStudents.push_back(s);
    }

    return queryStudents;
}

/// @brief Prints this students information.
/// @param s 
static void printStudent(student s) {
    cout << s.firstName << " " << s.lastName << " " << s.year << " " << s.major << endl;
}

int main() {
    vector<student> students { };
    students.push_back(student{"a","a",1,"CS"});
    students.push_back(student{"a","b",1,"CS"});
    students.push_back(student{"b","a",1,"CS"});
    students.push_back(student{"b","b",1,"CS"});
    students.push_back(student{"b","c",1,"CS"});
    students.push_back(student{"c","a",1,"CS"});
    students.push_back(student{"c","b",1,"CS"});
    students.push_back(student{"c","c",1,"CS"});
    students.push_back(student{"c","d",1,"CS"});
    students.push_back(student{"d","d",1,"CS"});


    for(student s: QueryStudents(students, "", "b", 0, ""))
        printStudent(s);

    return 0;
}