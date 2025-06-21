/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <cstddef>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "Benhao Qu"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::unordered_set<std::string> applicants;
  std::ifstream file(filename);
  std::string name;
  while (std::getline(file, name)) {
    if (!name.empty()) {
      applicants.insert(name);
    }
  }
  return applicants;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::unordered_set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> matches;
  size_t name_pos = name.find(' ');
  std::string name_initials = name.substr(0, 1) + name.substr(name_pos + 1, 1);
  for (auto & student : students) {
    size_t pos = student.find(' ');
    if (pos != std::string::npos) {
      std::string student_initials = student.substr(0, 1) + student.substr(student.find(' ') + 1, 1);
      if (name_initials == student_initials) {
        matches.push(&student);
      }
    }
  }
  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if (matches.empty()) {
    return "NO MATCHES FOUND.";
  }
  size_t count = matches.size();
  size_t index = rand() % count; // Randomly select one match
  for (size_t i = 0; i < index; ++i) {
    matches.pop(); // Pop until we reach the randomly selected index
  }
  std::string match = *matches.front(); // Get the front element
  matches.pop(); // Remove it from the queue
  return match;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
