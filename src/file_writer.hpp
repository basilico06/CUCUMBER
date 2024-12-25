//
// Created by basil on 16/12/2024.
//
#pragma once
#ifndef FILE_WRITER_H
#define FILE_WRITER_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>




class File_Writer_ {
private:
    std::ofstream file;

public:
    // Constructor
    File_Writer_(const std::string& filename) {

        file.open(filename, std::ios::out | std::ios::trunc);
        if (!file.is_open()) {
            throw std::ios_base::failure("Failed to open the file.");
        }
    }

    // Write a single line to the file
    void writeLine(const std::string& line) {
        if (file.is_open()) {
            cout << line << endl;
            file << line << '\n';
        } else {
            throw std::ios_base::failure("File is not open for writing.");
        }
    }

    void writeLineWithTab(const std::string& line) {
        if (file.is_open()) {
            cout << line << endl;
            file <<'\t'<< line << '\n';
        } else {
            throw std::ios_base::failure("File is not open for writing.");
        }
    }

    // Write multiple lines to the file
    void writeLines(const std::vector<std::string>& lines) {
        for (const auto& line : lines) {
            writeLine(line);
        }
    }

    // Check if the file is open
    bool isOpen() const {
        return file.is_open();
    }


    void close() {
        if (file.is_open()) {
            file.close();
        }
    }
};

File_Writer_* output = new File_Writer_("output.asm");



#endif // FILE_WRITER_H

