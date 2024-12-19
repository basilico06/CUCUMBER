//
// Created by basil on 16/12/2024.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <string>


#ifndef FILE_WRITER_H
#define FILE_WRITER_H

class File_Writer_ {
private:
    std::ofstream file;

public:
    // Constructor
    explicit File_Writer_(const std::string& filename) {

        file.open(filename, std::ios::out | std::ios::trunc);
        if (!file.is_open()) {
            throw std::ios_base::failure("Failed to open the file.");
        }
    }

    // Destructor
    ~File_Writer_() {
        if (file.is_open()) {
            file.close();
        }
    }

    // Write a single line to the file
    void writeLine(const std::string& line) {
        if (file.is_open()) {
            file << line << '\n';
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
};

#endif // FILE_WRITER_H

