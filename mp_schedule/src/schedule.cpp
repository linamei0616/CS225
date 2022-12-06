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

    Graph graph = Graph(courses.size());

    // make adj list
    std::unordered_map<std::string, std::vector<std::string>> adjList;
    unsigned long num_courses = courses.size();
    for (unsigned long x = 0; x < num_courses; x++) {
        for (unsigned long j=1; j < courses[x].size(); j++) {
            std::string student_name = courses[x][j];
            for (unsigned long k = 0; k < num_courses; k++) {
                if (courses[x][0] == courses[k][0]) {
                    continue;
                }
                if (std::count(courses[k].begin(),courses[k].end(),student_name)) {
                    // add to adj matrix
                    graph.addEdge(courses[k][0],courses[x][0]);
                }
            }
        }
    }

    // testing adjList
        for (auto adjs : graph.adj) {
            std::cout << adjs.first << " : ";
            for(auto it = adjs.second.begin(); it != adjs.second.end(); it++) { 
                std::cout << *it + " ";
                }
            std::cout << std::endl;
        }

    std::unordered_map<std::string, int> map = graph.greedyColoring(); // course, color
    std::vector<std::vector<std::string>> output;

    std::cout << graph.max_colors << std::endl;
    std::cout << int(timeslots.size()) << std::endl;

    if (graph.max_colors > graph.V+1 || graph.max_colors >= int(timeslots.size())) {
        std::vector<std::string> empty(1, "-1");
        output.push_back(empty);
    // printing output
        std::cout << "empty vect" << std::endl;
        return output;
    }

    // see if every course has a color
        for (auto elem : map) {
            std::cout << "course : " << elem.first << "has color : " << elem.second << std::endl;
        }

    for (unsigned long i = 0; i < timeslots.size(); i++) {
        std::vector<std::string> row;
        row.push_back(timeslots[i]);
        for (auto elem : map) {
            if (elem.second == int(i)) {
                row.push_back(elem.first);
            }
        }
        output.push_back(row);
    } 

    // printing output
    for (unsigned long i = 0; i < output.size(); i++) {
        for (unsigned long j = 0; j < output[i].size(); j++) {
            std::cout << output[i][j] + " ";
        }
        std::cout << std::endl;
    }

    return output;
}

void Graph::addEdge(std::string v, std::string w) {
    if (!(std::count(adj[v].begin(),adj[v].end(), w)))  {// element not found, add
        adj[v].push_back(w);
    }
    if (!(std::count(adj[w].begin(),adj[w].end(), v)))  {
        adj[w].push_back(v);
    }
}
std::unordered_map<std::string, int> Graph::greedyColoring(std::string starting) {
    std::unordered_map<std::string, int> color;

    for (auto elem : adj) {
        color.insert({elem.first, -1});
    }
    color[starting] = 0;

    std::vector<bool> avalible(V+1, false);
    for (auto courses : adj) {
        for (auto adj_courses : courses.second) {
            if (color[adj_courses] != -1) {
                avalible[color[adj_courses]] = true; // the color cr is assigned to one of its adjacent vertices
            }
        }
        // find first avalible color
        int cr;
        for (cr = 0; cr < V; cr++) {
            if (avalible[cr] == false) {
                break;
            }
        }
        color[courses.first] = cr;

        for (auto adj_courses : courses.second) {
            if (color[adj_courses] != -1) {
                avalible[color[adj_courses]] = false; // the color cr is assigned to one of its adjacent vertices
            }
        }
    }

    // find max color
    for (auto elems : color) {
        if (elems.second > max_colors) {
            max_colors = elems.second;
        }
    }
    return color;
}\
Graph::Graph(int V) {
    this->V = V; 
}