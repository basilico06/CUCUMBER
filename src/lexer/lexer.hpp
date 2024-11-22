#ifndef lexer_hpp
#define lexer_hpp

#include <sstream>

#include "token.hpp"  // Corrected include directive
#include "lexer_util.hpp"
#include <iostream>
#include <string>
#include <regex>
#include <list>
#include "../syntax_analyzer/syntax_analyzer.hpp"
using namespace std;

    //
    // se ne avro voglio inplemento con cuda per velocita di ellaborazione
    // 
    // O COL PARALLELISSMOOOOOOOO
    // PAOLO LILLO LORE

int line=0;
int col=0;
    


void newline() {
    line++;
    col = 0;
}

void sposta_puntatore(int x) {
    col += x;
}

bool tryParseFloat(const std::string& str, float& result) {
    std::istringstream iss(str);
    iss >> result;

    // Check if conversion failed or there are extra characters
    return !iss.fail() && iss.eof();
}

bool tryParseInt(const std::string& str, int& result) {
    std::istringstream iss(str);
    iss >> result;

    // Check if conversion failed or there are extra characters
    return !iss.fail() && iss.eof();
}



Entity* lex(string word) {
    char char0 = word[0];
    int char0int = (int)char0;
    
    if (char0 == '"') {
        token* x = new token(Parser::STRINGLIT, word, col, line, 'v');
        Entity* y= new constant(x);
        return y;
    }
    
    if (Parser::isdigit(char0int)) {
        int s;
        if (tryParseInt(word, s)) {
            token* x = new token(Parser::INTLIT, word, col, line, 'v');
            Entity* y= new constant(x);
            
            return y;
        }
        float ss;
        if (tryParseFloat(word, ss)) {
            token* x = new token(Parser::FLOATLIT, word, col, line, 'v');
            Entity* y= new constant(x);
            return y;
        }
        token* x = new token(Parser::IDENTIFIER, word, col, line, 'v');
        Entity* y= new var(x);
        
        return y;
    }
    
    if (Parser::isalpha(char0int)) {
        if (word=="array"){
            token* x = new token(Parser::ARRAY, word, col, line);
            Entity* y= new array_dec(x);
            return y; 
        }
        if (word == "int") {
            token* x = new token(Parser::INT, word, col, line);
            Entity* y= new datatype(x);
            return y;  // ()
            //---------------------------------------
        }
        if (word == "semmai") {
            token* x = new token(Parser::IF, word, col, line);
            Entity* y= new if_declaration(x);
            return y;
        }
        if (word == "float") {
            token* x = new token(Parser::FLOAT, word, col, line);
            Entity* y= new datatype(x);
            return y;
        }
        if (word == "method") {
            token* x = new token(Parser::METHOD, word, col, line);
            Entity* y= new function_dec(x);
            return y;
        }
        if (word == "for") {
            token* x = new token(Parser::FOR, word, col, line);
            Entity* y= new for_declaration(x);
            return y;
            
        }
        if (word == "false") {
            token* x = new token(Parser::FALSE, word, col, line, 'v');
            Entity* y= new boolean_var(x);
            return y;
        }
        if (word == "bool") {
            token* x = new token(Parser::BOOL, word, col, line);
            Entity* y= new datatype(x);
            return y;
        }
        if (word == "break") {
            token* x = new token(Parser::BREAK, word, col, line);
            Entity* y= new cycle_sign(x);
            return y;
        }
        if (word == "while") {
            token* x = new token(Parser::WHILE, word, col, line);
            Entity* y= new while_declaration(x);
            return y;
        }
        if (word == "string") {
            token* x = new token(Parser::STRING, word, col, line);
            Entity* y= new datatype(x);
            return y;
        }
        
        if (word == "class") {
            token* x = new token(Parser::CLASS, word, col, line);
            Entity* y= new class_declaration(x);
            return y;
        }
        if (word == "continue") {
            token* x = new token(Parser::CONTINUE, word, col, line);
            Entity* y= new cycle_sign(x);
        }
        if (word == "return") {
            token* x = new token(Parser::RETURN, word, col, line);
            Entity* y= new return_declaration(x);
            return y;
        }

        if (word == "void") {
            token* x = new token(Parser::VOID, word, col, line);
            Entity* y= new datatype(x);
            return y;
        }
        if (word == "null") {
            token* x = new token(Parser::NULLLIT, word, col, line);
            Entity* y= new constant(x);
            return y;
        }
        if (word == "true") {
            token* x = new token(Parser::TRUE, word, col, line, 'v');
            Entity* y= new boolean_var(x);
            return y;
        }
        if (word == "this") {
            token* x = new token(Parser::THIS, word, col, line);
            Entity* y= new var(x);
            return y;
        }
        
        if (word == "else") {
            token* x = new token(Parser::ELSE, word, col, line);
            Entity* y= new else_declaration(x);
            return y;
        }
        
        token* x = new token(Parser::IDENTIFIER, word, col, line, 'v');
        Entity* y= new var(x);
        
        return y;
    }
    
    if (char0int > 32 && char0int < 48) {
        if (word == "!") {
            token* x = new token(Parser::NOT, word, col, line);
            Entity* y= new boolean_operand(x);
            return y;
        }
        if (word == ".") {
            token* x = new token(Parser::DOT, word, col, line);
            Entity* y=  new dot(x);
            return y;
        }
        if (word == ",") {
            token* x = new token(Parser::COMMA, word, col, line);
            Entity* y= new comma(x);
            return y;
        }
        if (word == "%") {
            token* x = new token(Parser::MOD, word, col, line, 'm');
            Entity* y= new mod(x);
            return y;

        }
        if (word == "&&") {
            token* x = new token(Parser::AND, word, col, line );
            Entity* y= new boolean_operand(x);
            return y;
        }
        if (word == "+") {
            token* x = new token(Parser::ADD, word, col, line, 'm');
            Entity* y= new plus_minus(x);
            return y;

        }
        if (word == "++") {
            token* x = new token(Parser::INCREMENT, word, col, line, 'm');
            Entity* y= new int_modifier_operand(x);
            return y;
        }
        if (word == "-") {
            token* x = new token(Parser::MINUS, word, col, line, 'm');
            Entity* y= new plus_minus(x);
            return y;
        }
        if (word == "--") {
            token* x = new token(Parser::DECREMENT, word, col, line, 'm');
            Entity* y= new int_modifier_operand(x);
            return y;
        }
        if (word == "*") {
            token* x = new token(Parser::MULT, word, col, line, 'm');
            Entity* y= new mul_div(x);
            return y;
        }
        if (word == "/") {
            token* x = new token(Parser::DIV, word, col, line, 'm');
            Entity* y= new mul_div (x);
            return y;
        }
        if (word == "(") {
            token* x = new token(Parser::LEFTPAREN, word, col, line);
            Entity* y= new left_paren(x);
            return y;
        }
        if (word == ")") {
            token* x = new token(Parser::RIGHTPAREN, word, col, line);
            Entity* y= new right_paren(x);
            return y;
            
        }
        
        token* x = new token(Parser::IDENTIFIER, word, col, line);
        Entity* y= new var(x);
        return y;
    }
    
    if (char0int > 57 && char0int < 65) {
        if (word == ";") {
            token* x = new token(Parser::SEMICOLON, word, col, line, 't' );
            Entity* y= new semicolon(x);
            return y;
        }
        if (word == "=") {
            token* x = new token(Parser::ASSIGN, word, col, line, 'a');
            Entity* y= new assign_operand(x);
            return y;
        }
        if (word == "<") {
            token* x = new token(Parser::LESSTHAN, word, col, line, 'c');
            Entity* y= new cond_operand(x);
            return y;
        }
        if (word == ">") {
            token* x = new token(Parser::GREATERTHAN, word, col, line, 'c');
            Entity* y= new cond_operand(x);
            return y;
        }
        if (word == "<=") {
            token* x = new token(Parser::LESSTHANEQUAL, word, col, line, 'c');
            Entity* y= new cond_operand(x);
            return y;
        }
        if (word == ">=") {
            token* x = new token(Parser::GREATERTHANEQUAL, word, col, line, 'c');
            Entity* y= new cond_operand(x);
            return y;
        }
        if (word == "==") {
            token* x = new token(Parser::EQUAL, word, col, line, 'c');
            Entity* y= new cond_operand(x);
            return y;
        }

        
        if (word == "!=") {
            token* x = new token(Parser::NOTEQUAL, word, col, line, 'c');
            Entity* y= new cond_operand(x);
            return y;
        }
        token* x = new token(Parser::IDENTIFIER, word, col, line, 'v');
        Entity* y= new var(x);
        return y;
    }
    
    if (char0int > 90 && char0int < 97) {
        if (word == "[") {
            token* x = new token(Parser::LEFTSQUARE, word, col, line);
            Entity* y= new left_square(x);
        }
        if (word == "]") {
            token* x = new token(Parser::RIGHTSQUARE, word, col, line);
            Entity* y= new right_square(x);
            return y;
        }
        if (word=="^"){
            token* x = new token(Parser::POW, word, col, line);
            Entity* y= new poww(x);
            return y;
        }
        token* x = new token(Parser::IDENTIFIER, word, col, line, 'v');
        Entity* y= new var(x);
        return y;
    }
    
    if (char0int > 122 && char0int < 127) {
        if (word == "{") {
            token* x = new token(Parser::LEFTCURLY, word, col, line);
            Entity* y= new left_curly(x);
            return y;
        }
        if (word == "}") {
            token* x = new token(Parser::RIGHTCURLY, word, col, line, 't');
            Entity* y= new right_curly(x);
            return y;
        }
        token* x = new token(Parser::IDENTIFIER, word, col, line, 'v');
        Entity* y= new var(x);
        return y;
    }
    
    token* x = new token(Parser::IDENTIFIER, word, col, line, 'v');
    Entity* y= new var(x);
    return y;
}

#include <fcntl.h>

#include <iostream>
#include <vector>
#include <stack>

#include <stddef.h> // For size_t

#ifdef _WIN64
typedef __int64 ssize_t; // 64-bit on x64 systems
#else
typedef long ssize_t;    // 32-bit on x86 systems
#endif




#include <fcntl.h>    // For O_RDONLY, O_WRONLY, etc.
#include <io.h>       // For _open and _close





#include <thread> // Per std::this_thread::sleep_for
#include <chrono> // Per std::chrono::seconds

deque<Entity*>* tokenize(const char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return nullptr;
    }
    
    
    bool in_string = false;
    deque<Entity*>* tokens = new deque<Entity*>();



    int before=0;
    int actual=0;
    int buffer_len=0;
    char c;
    string buffer="";
    ssize_t bytes_read;


    // Read one character at a time until we hit EOF (bytes_read == 0)

    while ((bytes_read =_read(fd, &c, 1)) > 0) {
        
        int char0int = (int)c;
        if (c=='"') {

            if (in_string==false) {
                in_string = true;
                if (buffer_len > 0) {
                    tokens->push_back(lex(buffer));
                    buffer = "";
                    buffer_len = 0;
                    
                }
                goto checkpont;
            }

            if (in_string==true) {
                in_string = false;
                if (buffer_len > 0) {
                    buffer += c;
                    tokens->push_back(lex(buffer));
                    buffer = "";
                    buffer_len = 0;
                    continue;
                    
                }

                

            }
        }
        if (in_string==true) {
            buffer += c;
            buffer_len++;
            continue;
        }
        checkpont:
        if (Parser::iswhitespace(c)) {
            if (buffer_len > 0) {
                tokens->push_back(lex(buffer));
                buffer = "";
                buffer_len = 0;
                before = 0;
            }
            continue;
        }
        
        if (bytes_read ==0) {
            if (buffer_len > 0) {
                
                tokens->push_back(lex(buffer));
                buffer = "";
                buffer_len = 0;
                before = 0;
            }
            break;
        }
        
        if (buffer_len > 0) {
            if (before == 1) {
                if (!Parser::isalnum(char0int)) {
                    tokens->push_back(lex(buffer));
                    buffer = "";
                    buffer_len = 0;
                    before = 0;
                    goto checkpont;
                }else{
                    buffer+=c;
                    buffer_len++;
                }

            }
            if (before == 2) {
                if (!Parser::isdigit(char0int) && char0int != 46) {
                    tokens->push_back(lex(buffer));
                    buffer = "";
                    buffer_len = 0;
                    before = 0;
                    goto checkpont;
                }else{
                    buffer+=c;
                    buffer_len++;
                }
            }
            if (before == 3) {
                if (!Parser::issymbol(char0int) || !Parser::ismathequal(char0int)) {
                    tokens->push_back(lex(buffer));
                    buffer = "";
                    buffer_len = 0;
                    before = 0;
                    goto checkpont;
                }else{
                    buffer+=c;
                    buffer_len++;
                }
            }

        }else{
            buffer+=c;
            buffer_len++;
            
            if (Parser::isalpha(char0int)) {
                before=1;
            }
            if (Parser::isdigit(char0int)) {
                before=2;
            }
            if (Parser::issymbol(char0int)) {
                before=3;
            }

        }

    }

    if(!buffer.empty()){
        tokens->push_back(lex(buffer));
    }

    // Read until EOF

    if (bytes_read == -1) {
        perror("Error reading file");
    }

    // Close the file descriptor
    _close(fd);    

    return tokens;
}

#endif





/*
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    const char* filename ="c:/Users/basil/OneDrive/Desktop/c++/test.txt";
    list<Entity*>* tokens = tokenize(filename);
    
    
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    

    std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
    for (auto x : *tokens){
        cout<<x->getType()<< endl;
    }
    return 0;


}
*/




/*
        int char0int = (int)c;
        
        
        if (c=='"') {

            if (in_string==false) {
                in_string = true;
                if (buffer_len > 0) {
                    tokens.push_back(lex(buffer));
                    buffer = "";
                    buffer_len = 0;
                    
                }
                goto checkpont;
            }

            if (in_string==true) {
                in_string = false;
                if (buffer_len > 0) {
                    buffer += c;
                    tokens.push_back(lex(buffer));
                    buffer = "";
                    buffer_len = 0;
                    continue;
                    
                }

                

            }
        }
        if (in_string==true) {
            buffer += c;
            buffer_len++;
            continue;
        }
        checkpont:
        if (Parser::iswhitespace(c)) {
            if (buffer_len > 0) {
                tokens.push_back(lex(buffer));
                buffer = "";
                buffer_len = 0;
                before = 0;
            }
            continue;
        }
        
        if (bytes_read ==0) {
            if (buffer_len > 0) {
                cout << "Buffer: " << buffer << endl;
                tokens.push_back(lex(buffer));
                buffer = "";
                buffer_len = 0;
                before = 0;
            }
            break;
        }
        
        if (buffer_len > 0) {
            if (before == 1) {
                if (!Parser::isalnum(char0int)) {
                    tokens.push_back(lex(buffer));
                    buffer = "";
                    buffer_len = 0;
                    before = 0;
                    goto checkpont;
                }else{
                    buffer+=c;
                    buffer_len++;
                }

            }
            if (before == 2) {
                if (!Parser::isdigit(char0int) && char0int != 46) {
                    tokens.push_back(lex(buffer));
                    buffer = "";
                    buffer_len = 0;
                    before = 0;
                    goto checkpont;
                }else{
                    buffer+=c;
                    buffer_len++;
                }
            }
            if (before == 3) {
                if (!Parser::issymbol(char0int) || !Parser::ismathequal(char0int)) {
                    tokens.push_back(lex(buffer));
                    buffer = "";
                    buffer_len = 0;
                    before = 0;
                    goto checkpont;
                }else{
                    buffer+=c;
                    buffer_len++;
                }
            }

        }else{
            buffer+=c;
            buffer_len++;
            
            if (Parser::isalpha(char0int)) {
                before=1;
            }
            if (Parser::isdigit(char0int)) {
                before=2;
            }
            if (Parser::issymbol(char0int)) {
                before=3;
            }

        }
        */




