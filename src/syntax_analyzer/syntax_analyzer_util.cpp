//
// Created by basil on 18/11/2024.
//

#include <string>

#ifndef syntax_analyzer_util_hpp
#define syntax_analyzer_util_hpp


class util_syntax_analyzer{
    public:

    static const short max_id_operand=490;
    static const short max_id_parentesis=500;

    static const short first_id_allocation=800;
};

class category_syntax_analyzer{
public:
    static const short _real=1;
    static const short _allocation=2;
    static const short _default=3;
    static const short _math_symbol=4;


};


class syntax_analyzer {

    public:
        static const short DOT = 450;
        static const short POW = 451;
        static const short MUL_DIV = 452;
        static const short MOD = 453;
        static const short PLUS_MINUS = 454;
        static const short COND_OPERAND = 455;
        static const short BOOLEAN_OPERAND = 456;
        static const short COMMA = 457;
        static const short ASSIGN_OPERAND = 458;
        static const short SEMICOLON = 459;

        static const short LEFT_PAREN = 491;
        static const short RIGHT_PAREN = 492;
        static const short LEFT_SQUARE = 493;
        static const short RIGHT_SQUARE = 494;
        static const short LEFT_CURLY = 495;
        static const short RIGHT_CURLY = 496;

        static const short VAR = 514;
        static const short CONSTANT = 515;
        static const short MATH_EXPRESSION = 516;
        static const short FUNCTION_CALL = 517;
        static const short SIMPLE_CONDITION = 518;
        static const short BOOLEAN_VAR = 519;
        static const short ARRAY_CALL = 520;

        static const short DATATYPE = 526;
        static const short INT_MODIFIER_OPERAND = 527;
        static const short ARRAY_DEC = 528;
        static const short IF_DECLARATION = 529;
        static const short FOR_DECLARATION = 530;
        static const short WHILE_DECLARATION = 531;
        static const short FUNCTION_DEC = 532;
        static const short CLASS_DECLARATION = 533;
        static const short RETURN_DECLARATION = 534;
        static const short cycle_sign = 535;
        static const short ELSE_DECLARATION = 536;

        static const short ARRAY_POSITION = 605;
        static const short SEQUENCE_OF_ENTITY = 606;
        static const short ASSIGN_OPERATION = 607;
        static const short INT_MODIFIER = 608;
        static const short FUNCTION_DECLARATION = 609;
        static const short FOR_PARAMETHER=610;
        static const short FOR_STATMENT=611;
        static const short IF_STATMENT=612;
        static const short WHILE_STATMENT=613;

        static const short FORMAL_PARAMETHER_LIST = 701;
        static const short REAL_PARAMETHER_LIST = 702;
        static const short SEQUENCE_OF_ALLOCATION = 703;
        static const short SEQUENZE_OF_ISTRUCTION=704;

        static const short BLOCK = 799;

        static const short ALLOCATION = 801;
        static const short ARRAY_DECLARATION = 803;
        static const short CLASS_STATMENT=804;

        static const short START_FILE=1023;

};

#endif //syntax_analyzer_util_hpp
