//
// Created by Jason Forsyth on 10/27/24.
//
#ifndef APP_H
#define APP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
bool app_init(void);

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
bool app_process_action(void);


/**
 * Dr. Forsyth's code for parsing a string...
 * @param line The string to be parsed
 * @param container A vector<string> container to hold the results
 * @return Return True if we successfully complete. False otherwise.
 */
bool splits(std::string line, std::vector<std::string>& container);


ifstream load_csv_file(string filepath);
#endif  // APP_H