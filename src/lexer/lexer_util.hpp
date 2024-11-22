#ifndef Parser_hpp
#define Parser_hpp
#include <list>

using namespace std;

class Parser {
    public:
    static constexpr short INT= 257;
    static constexpr short FLOAT= 258;
    static constexpr short STRING= 259;
    static constexpr short BOOL= 260;

    static constexpr short BOOLLIT= 261;

    static constexpr short INTLIT= 262;
    static constexpr short FLOATLIT= 263;
    static constexpr short STRINGLIT= 264;
    static constexpr short VOID= 304;
    static constexpr short CAPAREZZA= 305;
    static constexpr short BREAK= 265;
    static constexpr short CONTINUE= 266;
    static constexpr short IF= 267;
    static constexpr short ELSE= 268;
    static constexpr short FOR= 269;
    static constexpr short WHILE= 270;
    static constexpr short RETURN= 271;
    static constexpr short CLASS= 272;
    static constexpr short NEW= 273;
    static constexpr short THIS= 274;
    static constexpr short NULLLIT= 275;
    static constexpr short TRUE= 276;
    static constexpr short FALSE= 277;

    static constexpr short ADD= 279;
    static constexpr short MINUS= 280;
    static constexpr short MULT= 281;
    static constexpr short DIV= 282;
    static constexpr short MOD= 283;
    static constexpr short AND= 284;
    static constexpr short OR= 285;
    static constexpr short NOT= 286;
    static constexpr short EQUAL= 287;
    static constexpr short NOTEQUAL= 288;
    static constexpr short LESSTHAN= 289;
    static constexpr short GREATERTHAN= 290;
    static constexpr short LESSTHANEQUAL= 291;
    static constexpr short GREATERTHANEQUAL= 292;
    static constexpr short LEFTPAREN= 293;
    static constexpr short RIGHTPAREN= 294;
    static constexpr short LEFTSQUARE= 295;
    static constexpr short RIGHTSQUARE= 296;
    static constexpr short LEFTCURLY= 297;
    static constexpr short RIGHTCURLY= 298;
    static constexpr short DOT= 299;
    static constexpr short COMMA= 300;
    static constexpr short SEMICOLON= 301;
    static constexpr short ASSIGN= 302;
    static constexpr short IDENTIFIER= 303;
    static constexpr short MAIN= 278;
    static constexpr short FOLDER = 304;
    static constexpr short STATIC = 305;

    static constexpr short INCREMENT = 306;
    static constexpr short DECREMENT = 307;
    static constexpr short METHOD = 308;
    static constexpr short POW=309;
    static constexpr short ARRAY=310;

    


    bool static istype(short character) {
        if (character<261 || character>259) {
            return true;
        }
        return false;
    }
    
    bool static isdigit(int character) {
        if (character >= 48 && character <= 57) {
            return true;
        } else {
            return false;
        }
    }

    bool static isalpha(int character) {
        if ((character >= 65 && character <= 90) || (character >= 97 && character <= 122) || (character == 95)) {
            return true;
        } else {
            return false;
        }
    }

    bool static isalnum(int character) {
        if (isdigit(character) || isalpha(character)) {
            return true;
        } else {
            return false;
        }
    }

    bool static iswhitespace(int character) {
        if (character == 32 || character == 9 || character == 10 || character == 13) {
            return true;
        } else {
            return false;
        }
    }

    bool static issymbol(int character) {
        if ((character >= 33 && character <= 47) || (character >= 58 && character <= 64) || (character >= 91 && character <= 96 and character != 95) || (character >= 123 && character <= 126)) {
            return true;
        } else {
            return false;
        }
    }
    
    bool static isnewline(int character) {
        if (character == 10) {
            return true;
        } else {
            return false;
        }
    }

    bool static ismathequal(int character) {
        if (character == 43 || character == 61 || character == 45) {
            return true;
        } else {
            return false;
        }

    }
    
    
    };


    // parte che va a riconoscere i blocchi di codice in

    bool static isblock(int character) {
        if (character == 123 || character == 125) {
            return true;
        } else {
            return false;
        }
    }

    bool static iscomment(int character) {
        if (character == 47 && character == 47) {
            return true;
        } else {
            return false;
        }
    }







    

#endif //parser_hpp;;



