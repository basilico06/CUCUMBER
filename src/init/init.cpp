//
// Created by basil on 24/12/2024.
// dedicato agli scoiattoli 
//

#pragma once

#include "../parser/parser.cpp"

void file_elaborator(string filename, streambuf* old_buf) {
    deque<Entity *> *res_lex = tokenize(filename.c_str());
    print_deque(res_lex);
    list<Entity *> *res_par = nullptr;
    try {
        res_par = parse(res_lex);
    } catch (const std::exception &e) {

        std::cerr << "Error xxx: " << e.what() << std::endl;
    }
    print("output:");
    print_deque(res_par);



    if(res_par->size()!=1) {
        std::cout.rdbuf(old_buf);
        cerr << "ERRORE: il programma non è stato scritto correttamente" << endl;
        exit(0);
    }

    CORE_SYMBLETABLE->print();
    try {
        res_par->front()->GET_CODE();
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << '\n';
    }


    output->close();
    return;

}

/**
 * Measure-Command { Start-Process "C:\Users\basil\OneDrive\Desktop\starfish_programming_language\programma.exe" | Out-Host }
 * comando per misuarare le prestazioni

*/
int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename> [debug]" << std::endl;
        return 1;
    }

    std::streambuf* old_buf = std::cout.rdbuf();

    if (argc < 3 || std::string(argv[2]) != "debug") {
        std::ofstream null_stream("nul"); // su Windows; usa "/dev/null" su Linux/macOS
        std::cout.rdbuf(null_stream.rdbuf()); // redireziona cout
    }

    file_elaborator(argv[1], old_buf);

    if (argc >= 3 && std::string(argv[2]) == "debug") {
        std::cout << "end phase 1" << std::endl;
    }

    system("nasm -f win64 output.asm -o output.obj");
    system("nasm -f win64 file.asm -o programma.obj");
    system("golink.exe /console /stacksize:1000000h /entry:Start kernel32.dll programma.obj output.obj");
    system("programma.exe");

    return 0;
}
