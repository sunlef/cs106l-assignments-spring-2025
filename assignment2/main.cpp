/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob
 * Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <algorithm>
#include <cassert>
#include <chrono>
#include <fstream>
#include <iostream>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "SUNLEF BLUE"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names
 * as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the
 * function below it) to use a `std::unordered_set` instead. If you do so, make
 * sure to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  std::set<std::string> returnSet;

  std::ifstream ifs(filename);
  std::string line;
  while (std::getline(ifs, line)) {
    returnSet.insert(line);
  }
  return returnSet;
}

std::string findInitials(std::string const &s) {
  auto p = s.find_first_of(' ');
  assert(p + 1 < int(s.size()));
  std::string returnString;
  returnString += s[0];
  returnString += s[p + 1];
  return returnString;
}
/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as
 * this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */

std::queue<const std::string *> find_matches(std::string name,
                                             std::set<std::string> &students) {
  std::queue<const std::string *> returnQueue;
  std::string const hereInitial = findInitials(name);
  for (auto const &s : students) {
    if (findInitials(s) == hereInitial) {
      returnQueue.push(&s);
    }
  }
  return returnQueue;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true
 * match!
 *
 * You can implement this function however you'd like, but try to do something a
 * bit more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string *> &matches) {
  if (matches.empty()) {
    return "NO MATCHES FOUND.";
  }

  std::vector<const std::string *> x;
  while (!matches.empty()) {
    x.push_back(matches.front());
    matches.pop();
  }

  auto rng =
      std::mt19937(std::chrono::steady_clock::now().time_since_epoch().count());
  std::shuffle(x.begin(), x.end(), rng);
  return *x[0];
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
