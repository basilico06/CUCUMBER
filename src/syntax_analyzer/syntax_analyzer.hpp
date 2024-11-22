#pragma once
#include "../lexer/token.hpp"
#include <deque>
#include "entity.cpp"
#include "syntax_analyzer_util.cpp"
#include "../symble_table/symble_table.cpp"
#include "../symble_table/symble_table_row/symble_table_row.hpp"
#include <cstdlib>

#ifndef syntax_analyzer_hpp
#define syntax_analyzer_hpp

/*
--------------------------------------------------------------
dichiaraioni clasi per futuro albero di sintassi
--------------------------------------------------------------
*/




class START_FILE : public Entity {
public:
    short type = syntax_analyzer::START_FILE;

    short getCategory() { return category_syntax_analyzer::_default; }
    short getType() const { return type; }

    void add(Entity *x) { return; }
    /*
    START_FILE(){
        symble_table::SYMBLE_TABLE->push_back(new symble_table_tuple());
    }
    */
};

class datatype : public Entity {
public:
    short type;

    short getCategory() { return category_syntax_analyzer::_default; }
    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    datatype(token *token) {
        this->type = syntax_analyzer::DATATYPE;
        this->TOKEN = token;
    }

    string* get_name() {
        return &this->TOKEN->text;
    }
};

class var : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    string *get_name() {
        return &this->TOKEN->text;
    }

    void add(Entity *x) { return; }

    var(token *token) {
        this->type = syntax_analyzer::VAR;
        this->TOKEN = token;
    }
};

class constant : public Entity {
public:
    short type;

    short getCategory() {
        return category_syntax_analyzer::_real;
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    constant(token *token) {
        this->type = syntax_analyzer::CONSTANT;
        this->TOKEN = token;
    }
};

class cond_operand : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    cond_operand(token *token) {
        this->type = syntax_analyzer::COND_OPERAND;
        this->TOKEN = token;
    }
};

class plus_minus : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    plus_minus(token *token) {
        this->type = syntax_analyzer::PLUS_MINUS;
        this->TOKEN = token;
    }
};

class assign_operand : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type > 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else {
            return category_syntax_analyzer::_default;
        }
    }


    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    assign_operand(token *token) {
        this->type = syntax_analyzer::ASSIGN_OPERAND;
        this->TOKEN = token;
    }
};

class int_modifier_operand : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    int_modifier_operand(token *token) {
        this->type = syntax_analyzer::INT_MODIFIER_OPERAND;
        this->TOKEN = token;
    }
};

class boolean_operand : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    boolean_operand(token *token) {
        this->type = syntax_analyzer::BOOLEAN_OPERAND;
        this->TOKEN = token;
    }
};

class boolean_var : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    boolean_var(token *token) {
        this->type = syntax_analyzer::BOOLEAN_VAR;
        this->TOKEN = token;
    }
};

class left_paren : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    left_paren(token *token) {
        this->type = syntax_analyzer::LEFT_PAREN;
        this->TOKEN = token;
    }
};

class right_paren : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    right_paren(token *token) {
        this->type = syntax_analyzer::RIGHT_PAREN;
        this->TOKEN = token;
    }
};

class left_square : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    left_square(token *token) {
        this->type = syntax_analyzer::LEFT_SQUARE;
        this->TOKEN = token;
    }
};

class right_square : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    right_square(token *token) {
        this->type = syntax_analyzer::RIGHT_SQUARE;
        this->TOKEN = token;
    }
};

class comma : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    comma(token *token) {
        this->type = syntax_analyzer::COMMA;
        this->TOKEN = token;
    }
};

class if_declaration : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    if_declaration(token *token) {
        this->type = syntax_analyzer::IF_DECLARATION;
        this->TOKEN = token;
    }
};

class for_declaration : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    for_declaration(token *token) {
        this->type = syntax_analyzer::FOR_DECLARATION;
        this->TOKEN = token;
    }
};

class while_declaration : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    while_declaration(token *token) {
        this->type = syntax_analyzer::WHILE_DECLARATION;
        this->TOKEN = token;
    }
};

class function_dec : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    function_dec(token *token) {
        this->type = syntax_analyzer::FUNCTION_DEC;
        this->TOKEN = token;
    }
};

class class_declaration : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    class_declaration(token *token) {
        this->type = syntax_analyzer::CLASS_DECLARATION;
        this->TOKEN = token;
    }
};

class return_declaration : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    return_declaration(token *token) {
        this->type = syntax_analyzer::RETURN_DECLARATION;
        this->TOKEN = token;
    }
};

class cycle_sign : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    cycle_sign(token *token) {
        this->type = syntax_analyzer::cycle_sign;
        this->TOKEN = token;
    }
};

class else_declaration : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    else_declaration(token *token) {
        this->type = syntax_analyzer::ELSE_DECLARATION;
        this->TOKEN = token;
    }
};

class dot : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    dot(token *token) {
        this->type = syntax_analyzer::DOT;
        this->TOKEN = token;
    }
};

class semicolon : public Entity {
public:
    short type;

    short getCategory() {
        return category_syntax_analyzer::_default;
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    semicolon(token *token) {
        this->type = syntax_analyzer::SEMICOLON;
        this->TOKEN = token;
    }
};

class right_curly : public Entity {
public:
    short type;

    short getCategory() { return category_syntax_analyzer::_default; }
    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    right_curly(token *token) {
        this->type = syntax_analyzer::RIGHT_CURLY;
        this->TOKEN = token;
    }
};

class left_curly : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    left_curly(token *token) {
        this->type = syntax_analyzer::LEFT_CURLY;
        this->TOKEN = token;
    }
};

class mul_div : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    mul_div(token *token) {
        this->type = syntax_analyzer::MUL_DIV;
        this->TOKEN = token;
    }
};

class poww : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    poww(token *token) {
        this->type = syntax_analyzer::POW;
        this->TOKEN = token;
    }
};

class mod : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    mod(token *token) {
        this->type = syntax_analyzer::MOD;
        this->TOKEN = token;
    }
};

/*
//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////layer 2//////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
*/

class array_declaration : public Entity {
public:
    short type;

    short getCategory() { return category_syntax_analyzer::_allocation; }
    short getType() const { return type; }
    Entity *DATATYPE;
    Entity *IDENTIFIER;

    void add(Entity *x) { return; }

    array_declaration(Entity *datatype, Entity *identifier) {
        this->type = syntax_analyzer::ARRAY_DEC;
        this->DATATYPE = datatype;
        this->IDENTIFIER = identifier;
    }
};

class array_dec : public Entity {
public:
    short type;

    short getCategory() { return category_syntax_analyzer::_default; }
    short getType() const { return type; }
    token *TOKEN;

    void add(Entity *x) { return; }

    array_dec(token *token) {
        this->type = syntax_analyzer::ARRAY_DEC;
        this->TOKEN = token;
    }
};

class array_position : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }

    Entity *POSITION;

    void add(Entity *x) { return; }

    array_position(Entity *position) {
        this->POSITION = position;
        this->type = syntax_analyzer::ARRAY_POSITION;
    }
};

class simple_condition : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    Entity *left;
    Entity *center;
    Entity *right;

    void add(Entity *x) { return; }

    simple_condition(Entity *token1, Entity *token2, Entity *token3) {
        this->left = token1;
        this->center = token2;
        this->right = token3;
        this->type = syntax_analyzer::SIMPLE_CONDITION;
    }
};

class object_allocation: public Entity{
private:
    void add_to_symble_table(NODE* classdefiniction) const {
        if(CORE_SYMBLETABLE->actual_node->map.contains(*this->right->get_name())) {
            //TODO variabile gia presente nel indirizzo attuale
            return;
        }

        CORE_SYMBLETABLE->insert_at_actual_node(
            this->right->get_name(),
            new SymbleTable_Row_Puntatore(
                this->right->get_name(),
                classdefiniction,
                CORE_SYMBLETABLE->actual_node->allocate_position(8)
                )
            );
        //TODO FUNZIONE COMPLETA SISTEMARE IL TUTTUO

    }
public:
    short type{};
    Entity *left;
    Entity *right;

    short getCategory() {return category_syntax_analyzer::_allocation;}

    [[nodiscard]] short getType() const override { return type; }

    void add(Entity *x) { return; }

    object_allocation(Entity* left, Entity* right, NODE* classdefiniction) {
        this->left=left;
        this->right=right;
        this->add_to_symble_table(classdefiniction);
    }


};

class allocation : public Entity {
private:

void add_to_symble_table() {
    if(CORE_SYMBLETABLE->actual_node->map.contains(*this->right->get_name())) {
        //TODO variabile gia presente nel symble_table attuale
        return;
    }
    ENUM_TIPO_VARIABILE tipo_variabile = get_tipo_variabile_from_string(*this->left->get_name());
    CORE_SYMBLETABLE->insert_at_actual_node(
        this->right->get_name(),
        new SymbleTable_Row_Variabile(
            this->right->get_name(),
            tipo_variabile,
            CORE_SYMBLETABLE->actual_node->allocate_position(get_size_from_tipo_variabile(tipo_variabile))
            ));

}


public:
    short type;

    short getCategory() {
        return category_syntax_analyzer::_allocation;
    }

    short getType() const { return type; }
    Entity *left;
    Entity *right;

    void add(Entity *x) { return; }

    allocation(Entity *token1, Entity *token2) {
        this->left = token1;
        this->right = token2;
        this->type = syntax_analyzer::ALLOCATION;
        this->add_to_symble_table();
    }


};

class int_modifier : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }
    Entity *left;
    Entity *right;

    void add(Entity *x) { return; }

    int_modifier(Entity *token1, Entity *token2) {
        this->left = token1;
        this->right = token2;
        this->type = syntax_analyzer::INT_MODIFIER;
    }
};

class function_call : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    Entity *IDENTIFIER;
    Entity *PARAMATHER;

    const short layer = 3;
    short getType() const { return type; }

    function_call(Entity *IDENTIFIER, Entity *PARAMETHER) {
        this->IDENTIFIER = IDENTIFIER;
        this->PARAMATHER = PARAMETHER;
        this->type = syntax_analyzer::FUNCTION_CALL;
    }

    void add(Entity *x) {
        return;
    }
};

class function_declaration : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    Entity *IDENTIFIER;
    Entity *PARAMATHER;

    short getType() const { return type; }

    function_declaration(Entity *identify, Entity *paramether) {
        this->IDENTIFIER = identify;
        this->PARAMATHER = paramether;
        this->type = syntax_analyzer::FUNCTION_DECLARATION;
    }
};

/*
//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////layer 6//////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
*/

class sequence_of_entity : public Entity {
public:
    short type;
    deque<Entity *> sequenze;

    short getCategory() { return category_syntax_analyzer::_default; }
    short getType() const { return type; }
    void add(Entity *x) { this->sequenze.push_back(x); }
    deque<Entity *> *get_deque() { return &this->sequenze; }

    sequence_of_entity(Entity *left, Entity *right) {
        this->type = syntax_analyzer::SEQUENCE_OF_ENTITY;
        this->sequenze.push_back(left);
        this->sequenze.push_back(right);
    }
};

class sequence_of_allocation : public Entity {
public:
    short type;

    short getCategory() {
        return category_syntax_analyzer::_default;
    }

    deque<Entity *> sequenze;
    short getType() const { return type; }

    sequence_of_allocation(Entity *left, Entity *right) {
        this->type = syntax_analyzer::SEQUENCE_OF_ALLOCATION;
        this->sequenze.push_back(left);
        this->sequenze.push_back(right);
    }

    void add(Entity *x) {
        this->sequenze.push_back(x);
    }

    deque<Entity *> *get_deque() {
        return &this->sequenze;
    }
};

class formal_paramether_list : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    deque<Entity *> *PARAMETHER;

    short getType() const { return type; }

    formal_paramether_list(deque<Entity *> *x) {
        this->PARAMETHER = x;
        this->type = syntax_analyzer::FORMAL_PARAMETHER_LIST;
    }

    formal_paramether_list(Entity *x) {
        this->PARAMETHER = new deque<Entity *>();
        this->PARAMETHER->push_back(x);
    }
};

class real_paramether_list : public Entity {
public:
    short type;

    short getCategory() {
        return category_syntax_analyzer::_default;
    }

    deque<Entity *> *PARAMETHER;

    short getType() const { return type; }

    real_paramether_list(deque<Entity *> *x) {
        this->PARAMETHER = x;
        this->type = syntax_analyzer::REAL_PARAMETHER_LIST;
    }

    real_paramether_list(Entity *x) {
        this->PARAMETHER = new deque<Entity *>();
        this->PARAMETHER->push_back(x);
        this->type = syntax_analyzer::REAL_PARAMETHER_LIST;
    }
};

class block : public Entity {
public:
    short type = syntax_analyzer::BLOCK;
    short getCategory() { return category_syntax_analyzer::_default; }
    deque<Entity *> *SEQUENZE_OF_ISTRUCTION;
    short getType() const { return type; }


    block(deque<Entity *> *temp) {
        this->SEQUENZE_OF_ISTRUCTION = temp;

    }
};

class math_expression : public Entity {
private:

public:
    short type;

    short getCategory() {
        return category_syntax_analyzer::_real;
    }

    deque<Entity *> EXPRESSION = deque<Entity *>();
    ENUM_TIPO_VARIABILE tipo_operazione;
    short getType() const { return type; }

    math_expression(Entity *first, Entity *operand, Entity *second) {
        this->type = syntax_analyzer::MATH_EXPRESSION;
        this->EXPRESSION.push_back(first);
        this->EXPRESSION.push_back(second);
        this->EXPRESSION.push_back(operand);
        this->tipo_operazione= CORE_SYMBLETABLE->check_if_two_node_are_equal_type(first->get_name(), second->get_name());
        if(tipo_operazione==ENUM_TIPO_VARIABILE::NONE_VAR) {
            cout<<"ERRORE: TIPO NON COMPATIBILE"<<endl;
            exit(0);
        }
    }

    math_expression(Entity *first, Entity *operand, deque<Entity *> *second) {
        this->type = syntax_analyzer::MATH_EXPRESSION;
        this->EXPRESSION.push_back(first);
        this->EXPRESSION.insert(this->EXPRESSION.end(), second->begin(), second->end());
        this->EXPRESSION.push_back(operand);

    }


    void add(deque<Entity *> *second, Entity *operand) {
        this->EXPRESSION.insert(this->EXPRESSION.end(), second->begin(), second->end());
        this->EXPRESSION.push_back(operand);
    };

    void add(Entity *second, Entity *operand) {
        this->EXPRESSION.push_back(second);
        this->EXPRESSION.push_back(operand);
    };

    deque<Entity *> *get_deque() {
        return &this->EXPRESSION;
    }
};

class array_call : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    Entity *VAR;
    Entity *POSITION;
    short getType() const { return type; }

    array_call(Entity *var, Entity *position) {
        this->type = syntax_analyzer::ARRAY_CALL;
        this->VAR = var;
        this->POSITION = position;
    }
};

class assign_expression : public Entity {
public:
    short type;

    short getCategory() {
        if (this->getType() > 800 and this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 and this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 and this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    short getType() const { return type; }

    Entity *LEFT;
    Entity *RIGHT;

    assign_expression(Entity *left, Entity *right) {
        this->type = syntax_analyzer::ASSIGN_OPERATION;
        this->LEFT = left;
        this->RIGHT = right;
    }
};

class sequence_of_istruction : public Entity {
public:
    short type = syntax_analyzer::SEQUENZE_OF_ISTRUCTION;

    deque<Entity *> LIST_OF_ISTRUCTION = deque<Entity *>();

    short getCategory() override { return category_syntax_analyzer::_default; }
    short getType() const override { return type; }

    sequence_of_istruction(Entity *first, Entity *second) {
        this->LIST_OF_ISTRUCTION.push_back(first);
        this->LIST_OF_ISTRUCTION.push_back(second);
    }

    void add(Entity *temp) override {
        this->LIST_OF_ISTRUCTION.push_back(temp);
    }

    deque<Entity *> *get_deque() override {
        return &this->LIST_OF_ISTRUCTION;
    }
};

class for_paramether : public Entity {
public:
    short type = syntax_analyzer::FOR_PARAMETHER;
    deque<Entity *> *PARAMETHER;

    short getCategory() override { return category_syntax_analyzer::_default; }
    short getType() const override { return type; }
    deque<Entity *> *get_deque() override { return this->PARAMETHER; }

    for_paramether(deque<Entity *> *paramether) {
        this->PARAMETHER = paramether;
    }
};

class for_statment : public Entity {
public:
    short type = syntax_analyzer::FOR_STATMENT;

    Entity *ASSIGN;
    Entity *CONDITION;
    Entity *INCREMENT;
    Entity *BLOCK;

    for_statment(deque<Entity *> *paramether, Entity *block) {
        this->ASSIGN = paramether->operator[](0);
        this->CONDITION = paramether->operator[](1);
        this->INCREMENT = paramether->operator[](2);
        this->BLOCK = block;
    }

    short getCategory() { return category_syntax_analyzer::_default; }
    short getType() const { return type; }
};


class if_statment : public Entity {
public:
    short type = syntax_analyzer::IF_STATMENT;

    Entity *CONDITION;
    Entity *BLOCK;

    if_statment(Entity *condition, Entity *Block) {
        this->BLOCK = Block;
        this->CONDITION = condition;
    }

    short getCategory() { return category_syntax_analyzer::_default; }
    short getType() const { return type; }
};


class while_statment : public Entity {
public:
    short type = syntax_analyzer::WHILE_STATMENT;

    Entity *CONDITION;
    Entity *BLOCK;

    while_statment(Entity *condition, Entity *Block) {
        this->BLOCK = Block;
        this->CONDITION = condition;
    }

    short getCategory() { return category_syntax_analyzer::_default; }
    short getType() const { return type; }
};


class class_statment : public Entity {
private:
    void add_to_symble_table() const {
        auto temp= CORE_SYMBLETABLE->go_to_parent_node();
        CORE_SYMBLETABLE->insert_at_root_node(
            this->name,
            new SymbleTable_Row_Classe(
                this->BLOCK->get_name()
                , temp
                )
            );

    }
public:
    short type = syntax_analyzer::CLASS_STATMENT;

    string* name;
    Entity *BLOCK;

    explicit class_statment(Entity *Block,string* name) {
        this->BLOCK = Block;
        this->name=name;

        this->add_to_symble_table();

    }

    short getCategory() override { return category_syntax_analyzer::_default; }
    short getType() const override { return type; }

};



//////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

#endif
