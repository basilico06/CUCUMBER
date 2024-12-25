//
// Created by basil on 18/11/2024.
//



#ifndef symble_table_util_hpp
#define symble_table_util_hpp

enum ENUM_INFO {
    NONE,
    VARIABILE,
    CLASSE,
    PUNTATORE,
    FUNZIONE,
    BLOCCO,
    ARRAY
};


/**
*   @attention aggiunta compatibilita con i TOKEN
*/
enum ENUM_TIPO_VARIABILE {
    NONE_VAR,  // Renamed to avoid conflict
    INT=Parser::INTLIT,
    FLOAT=Parser::FLOATLIT,
    BOOLEAN=Parser::BOOLLIT,
    STRING=Parser::STRINGLIT,
    PTR=Parser::CLASS,

};

#endif // symble_table_util_hpp