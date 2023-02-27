#pragma once
#include <string>

const std::string test_filename("test.file");
const std::string another_filename("another_test.file");

void readFromFile();

void openClose();

void openAnotherFileSameStream();

void alreadyOpenedFile();

void closeClosedFile();

void file_basics_main();
