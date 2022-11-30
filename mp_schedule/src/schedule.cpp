/**
 * @file schedule.cpp
 * Exam scheduling using graph coloring
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>

#include "schedule.h"
#include "utils.h"
#include <algorithm>
#include <bits/stdc++.h>

/**
 * Given a filename to a CSV-formatted text file, create a 2D vector of strings where each row
 * in the text file is a row in the V2D and each comma-separated value is stripped of whitespace
 * and stored as its own string. 
 * 
 * Your V2D should match the exact structure of the input file -- so the first row, first column
 * in the original file should be the first row, first column of the V2D.
 *  
 * @param filename The filename of a CSV-formatted text file. 
 */
V2D file_to_V2D(const std::string & filename){
    // Your code here!
    std::vector<std::string> line_vect;
    std::vector<std::vector<std::string>> vect;
    std::string string_file = Trim(file_to_string(filename));
    int count_line = SplitString(string_file, '\n', line_vect);
    vect.resize(count_line);
    for (int i = 0; i < count_line; i++) {
        std::string word = Trim(line_vect[i]);
        SplitString(word, ',', vect[i]);
    }
    for (unsigned long i = 0; i < vect.size(); i++) {
        for (unsigned long j = 0; j < vect[i].size(); j++) {
            vect[i][j] = Trim(vect[i][j]);
        }
     }
    return vect;
}

/**
 * Given a course roster and a list of students and their courses, 
 * perform data correction and return a course roster of valid students (and only non-empty courses).
 * 
 * A 'valid student' is a student who is both in the course roster and the student's own listing contains the course
 * A course which has no students (or all students have been removed for not being valid) should be removed
 * 
 * @param cv A 2D vector of strings where each row is a course ID followed by the students in the course
 * @param student A 2D vector of strings where each row is a student ID followed by the courses they are taking
 */
V2D clean(const V2D & cv, const V2D & student){
    // YOUR CODE HERE
    std::vector<std::vector<std::string>> rows;
    for (unsigned long i = 0; i < cv.size(); i++) { // iterating courses vector
        std::vector<std::string> vect_stud;
        std::string course_name = cv[i][0];
        vect_stud.push_back(course_name); // push course name into the vector
        for (unsigned long j = 0; j < cv[i].size(); j++) {  // looking through the students from cv rows
            std::string student_name = cv[i][j]; // check if the student roster also has the same class
            unsigned long count = 0; // iterate row 0
            while (count < student.size()) {
                if (student[count][0] != student_name) { // not matched so skip
                    count++;
                    continue;
                } else { // matched
                    for (unsigned long col = 0; col < student[count].size(); col++) {
                        if (student[count][col] == course_name) { // contains course from student vector
                            vect_stud.push_back(student_name); // pushes course name into the vector
                            break;
                        }
                    }
                }
                count++;
            }
        }
        if (vect_stud.size() > 1) {
            rows.push_back(vect_stud);
        }
    }
    return rows;
}

/**
 * Given a collection of courses and a list of available times, create a valid scheduling (if possible).
 * 
 * A 'valid schedule' should assign each course to a timeslot in such a way that there are no conflicts for exams
 * In other words, two courses who share a student should not share an exam time.
 * Your solution should try to minimize the total number of timeslots but should not exceed the timeslots given.
 * 
 * The output V2D should have one row for each timeslot, even if that timeslot is not used.
 * 
 * As the problem is NP-complete, your first scheduling might not result in a valid match. Your solution should 
 * continue to attempt different schedulings until 1) a valid scheduling is found or 2) you have exhausted all possible
 * starting positions. If no match is possible, return a V2D with one row with the string '-1' as the only value. 
 * 
 * @param courses A 2D vector of strings where each row is a course ID followed by the students in the course
 * @param timeslots A vector of strings giving the total number of unique timeslots
 */
V2D schedule(const V2D &courses, const std::vector<std::string> &timeslots){
    // Your code here!
    return V2D();
}