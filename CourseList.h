#pragma once
#ifndef COURSELIST_H
#define COURSELIST_H



class CourseList {
private:
    // Structure for representing a course node
    struct CourseNode {
        int courseCode;
        int creditHours;
        char grade;
        CourseNode* next;

        // Constructor for initializing the course node
        CourseNode(int cCode, int cHours, char cGrade) {
            courseCode = cCode;
            creditHours = cHours;
            grade = cGrade;
            next = nullptr;
        }
    };
    CourseNode* head;  // Pointer to the first node in the linked list

public:
    // Constructor
    CourseList();

    // Destructor
    ~CourseList();

    // Function to add a course to the list
    void addCourse(int courseCode, int creditHours, char grade);

    // Function to delete a course by course code
    void deleteCourse(int courseCode);

    // Function to delete all nodes in the list
    void deleteAllNodes();

    // Function to display the course list
    void displayCourses() const;

    //Function to check if List is empty
    bool isEmpty();
};

#endif