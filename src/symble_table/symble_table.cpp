#pragma once




using namespace std;

#ifndef symble_table_core_cpp
#define symble_table_core_cpp


#include "symble_table_util.cpp"
#include <iostream>
#include <string>
#include <cstdint>


#include <vector>
#include "../syntax_analyzer/entity.hpp"
#include "symble_table_row/robin_hood.h"
#include "../../external_library/plf_queue.h"

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;


class NODE;









class SymbleTable_Row {
public:
    virtual ~SymbleTable_Row() = default;

    virtual ENUM_INFO get_info() { return ENUM_INFO::NONE; }
    virtual std::string* get_name() { return new std::string(); }
    virtual ENUM_TIPO_VARIABILE get_tipo() { return ENUM_TIPO_VARIABILE::NONE_VAR; }
    virtual uint32_t get_posizione() { return 0; }
    virtual void set_valore(void* valore) {}
    virtual void* get_valore() { return nullptr; }
    virtual bool get_usato() { return false; }
    virtual void set_usato(bool usato) {}
    virtual NODE* get_oggetto_puntato() { return nullptr; }
    virtual void print(string spaziatura){return;}
    virtual NODE* get_contesto() { return nullptr; }
    virtual NODE* get_contesto_var() { return nullptr; };
};

/**
 * @class NODE
 * @brief Represents a node in the symbol table hierarchy.
 *
 * This class is used to manage the symbol table entries and their hierarchical relationships.
 */
class NODE {
public:
    uint32_t lenght = 0; ///< The current position in the node.
    NODE* up_layer; ///< Pointer to the parent node in the hierarchy.
    robin_hood::unordered_node_map<std::string, SymbleTable_Row*> map; ///< Map to store symbol table rows.
    SymbleTable_Row* return_type=nullptr; ///< Return type of the node.
    /**
     * @brief Constructs a new NODE object.
     * @param up_layer Pointer to the parent node.
     */
    explicit NODE(NODE* up_layer) {
        this->up_layer = up_layer;
        this->map=robin_hood::unordered_node_map<std::string, SymbleTable_Row*>();
    }

    /**
     * @brief Gets the parent node.
     * @return Pointer to the parent node.
     */
    [[nodiscard]] NODE* get_up_layer() const {
        return up_layer;
    }

    /**
     * @brief Allocates a new position in the node.
     * @param offset The offset to add to the current position.
     * @return The previous position before allocation.
     */
    uint32_t allocate_position(const short offset) {
        const uint32_t posizione1 = this->lenght;
        this->lenght += offset;
        return posizione1;
    }

    /**
     * @brief Checks if a key exists in the node or its parent nodes.
     * @param key Pointer to the key string.
     * @return 1 if the key exists, otherwise 0.
     */
    short contains_key(const std::string* key) const {
        if (map.contains(*key)) {
            return 1;
        }
        if (up_layer != nullptr) {
            return up_layer->contains_key(key);
        }
        return 0;
    }

    /**
     * @brief Inserts a new key-value pair into the node.
     * @param key Pointer to the key string.
     * @param value Pointer to the SymbleTable_Row object.
     */
    void insert(const std::string* key, SymbleTable_Row* value) {
        if (this->map.contains(*key)) {
            std::cout << "errore" << std::endl;
            return;
        }
        map[*key] = value;
    }

    /**
     * @brief Retrieves the value associated with a key.
     * @param key Pointer to the key string.
     * @return Pointer to the SymbleTable_Row object.
     */
    SymbleTable_Row* get(const std::string* key) {
        if (map.contains(*key)) {
            return map[*key];
        }else {
            if (this->get_up_layer()==nullptr) {
                //TODO errore
                return nullptr;
            }else {
                return this->get_up_layer()->get(key);
            }
        }


    }

    /**
     * @brief Checks if a key exists in the node.
     * @param key Pointer to the key string.
     * @return True if the key exists, otherwise false.
     */
    bool contains(const std::string* key) const {
        return map.contains(*key);
    }

    void print(string spaziatura) {
        cout<<"--------------------------"<<endl;

        for (auto& x : map) {

            std::cout<< spaziatura << x.first << "   |||    " ;
            x.second->print(spaziatura);
        }

        if(return_type!=nullptr){
            std::cout<< spaziatura << "return type" << "   |||    " ;
            return_type->print(spaziatura);

        }
        cout<<"--------------------------"<<endl;
    }



};


/**
 * @class SymbleTable_Core
 * @brief Manages the core operations of the symbol table.
 *
 * This class provides methods to insert entries into the symbol table,
 * navigate between nodes, and add new nodes.
 */
class SymbleTable_Core {
public:
    NODE* root; ///< Pointer to the root node of the symbol table.
    NODE* actual_node; ///< Pointer to the current node in the symbol table.

    const string* plain_string_for_block= new string("___");

    bool check_if_present_at_global_level(const string*key) const {

        return this->root->map.contains(*key);
    }

    [[nodiscard]] SymbleTable_Row* get_at_root_level (const string*key) const {
        return this->root->map[*key];
    }

    [[nodiscard]] NODE* get_node_at_root_level (const string*key) const {
        return this->root->map[*key]->get_oggetto_puntato();
    }

    ENUM_TIPO_VARIABILE check_if_two_node_are_equal_type(const string*key1, const string*key2) const {
        auto temp_actual_node = this->actual_node;
        ENUM_TIPO_VARIABILE tipo1 = ENUM_TIPO_VARIABILE::NONE_VAR;
        ENUM_TIPO_VARIABILE tipo2 = ENUM_TIPO_VARIABILE::NONE_VAR;
        while (temp_actual_node!=nullptr) {
            if (temp_actual_node->map.contains(*key1)) {
                tipo1= temp_actual_node->map[*key1]->get_tipo();

            }
            if (temp_actual_node->map.contains(*key2)) {
                tipo2 = temp_actual_node->map[*key2]->get_tipo();

            }

            if(tipo1!=ENUM_TIPO_VARIABILE::NONE_VAR and tipo2!=ENUM_TIPO_VARIABILE::NONE_VAR){
                if(tipo1==tipo2){
                    return tipo1;
                }
            }
            temp_actual_node = temp_actual_node->up_layer;

        }
        //TODO errore tipo non corrispondente
        return ENUM_TIPO_VARIABILE::NONE_VAR;
    }

    [[nodiscard]] ENUM_TIPO_VARIABILE check_if_node_is_equal( const ENUM_TIPO_VARIABILE first,const string* key) const {
        auto temp_actual_node= this->actual_node;
        while (temp_actual_node!=nullptr) {
            if (temp_actual_node->map.contains(*key)) {
                if (temp_actual_node->map[*key]->get_tipo()==first) {
                    return first;
                }
            }
            temp_actual_node = temp_actual_node->up_layer;
        }
        //TODO errore tipo non corrispondente
        return ENUM_TIPO_VARIABILE::NONE_VAR;
    }


    //gesu cristo,chi me l ha fatto fatto fare
    // per il futuro me, ricordati di non avere ste idee di merda!!!
    // chi cazzo me l ha fatta fare
    [[nodiscard]] SymbleTable_Row* exist_propriety_of_a_class(SymbleTable_Row* object_key, string* propriety_key) const {
        cout<<"funzione di merda"<<endl;


        cout<<"ciao"<<object_key->get_name()<< endl;

        if (object_key->get_info()!=PUNTATORE) {
            // oggetto non è una classe
            cout << "ERRORE: OGGETTO NON E UNA CLASSE" << endl;
            exit(0);
        }
        cout<< "passato if 1 "<< endl;
        auto x= object_key->get_oggetto_puntato();
        if (x->map.contains(*propriety_key)) {
            return x->map[*propriety_key];
        }else {
            cout<<"non esiste una proprieta del genere in quella classe";
            exit(0);
        }

    }



    [[nodiscard]]SymbleTable_Row* exist_propriety_of_a_class(const string* object_key, const string* propriety_key) const {
        cout<< "funzione di merda"<< endl;
        //TODO: // implementare errore se la classe non resist
        SymbleTable_Row* object = this->actual_node->get(object_key);
        cout<<"passato"<< endl;
        if (object== nullptr) {
            // oggetto non dichiarato
            cout<<"ERRORE: OGGETTO NON ESISTENTE"<<endl;
            exit(0);

        }
        cout<< "passato"<< endl;
        cout<<object->get_info()<< endl;
        cout<<*object->get_name()<< endl;
        if (object->get_info()!=ENUM_INFO::PUNTATORE) {
            // oggetto non è una classe
            cout << "ERRORE: OGGETTO NON E UNA CLASSE" << endl;
            exit(0);
        }
        cout<< "passato"<< endl;

        NODE* class_node = object->get_oggetto_puntato();
        cout<< "passato"<< endl;
        cout << *propriety_key<< endl;
        if (class_node->map.contains(*propriety_key)) {
            cout<< "passato"<< endl;
            return class_node->map[*propriety_key];
        }
        cout<< "proprietà non esistente"<< endl;
        exit(0);
        return nullptr;

    }

    [[nodiscard]] SymbleTable_Row* get_row(const string* propriety_key, SymbleTable_Row* object_key) const {
        cout<<"funzione di merda_2"<<endl;


        cout<<"ciao"<<object_key->get_name()<< endl;

        if (object_key->get_info()!=PUNTATORE) {
            // oggetto non è una classe
            cout << "ERRORE: OGGETTO NON E UNA CLASSE" << endl;
            exit(0);
        }
        cout<< "passato if 1 "<< endl;
        auto x= object_key->get_oggetto_puntato();
        if (x->map.contains(*propriety_key)) {
            return x->map[*propriety_key];
        }else {
            cout<<"non esiste una proprieta del genere in quella classe";
            exit(0);
        }

    }


    [[nodiscard]] ENUM_TIPO_VARIABILE get_tipo_variabile(const string* key) const {
        auto temp_actual_node = this->actual_node;
        cout << "key = "<< *key<< endl;

        while (temp_actual_node!=nullptr) {
            if (temp_actual_node->map.contains(*key)) {
                return temp_actual_node->map[*key]->get_tipo();
            }
            temp_actual_node = temp_actual_node->up_layer;
        }
        //TODO errore variabile non esistente

        cout<<"variabile non esistente"<< endl;
        exit(0);
    }


    SymbleTable_Core() {
        this->root = new NODE(nullptr);
        this->actual_node = this->root;
    }

    /**
     * @brief Inserts a key-value pair into the current node.
     * @param key key string.
     * @param value Pointer to the SymbleTable_Row object.
     */
    void insert_at_actual_node(const string *key, SymbleTable_Row* value) const {
        this->actual_node->insert(key, value);
    }

    /**
     * @brief Inserts a key-value pair into the root node.
     * @param key Pointer to the key string.
     * @param value Pointer to the SymbleTable_Row object.
     */
    void insert_at_root_node(const string* key, SymbleTable_Row* value) const {
        this->root->insert(key, value);
    }


    /**
     * @brief Moves to the parent node of the current node.
     * @return Pointer to the previous current node.
     */
    NODE* go_to_parent_node() {
        NODE* temp = this->actual_node;
        this->actual_node = this->actual_node->get_up_layer();
        return temp;
    }

    SymbleTable_Row* get(const string* key) const {
        return this->actual_node->get(key);
    }


    /**
     * @brief Adds a new node as a child of the current node and moves to it.
     * @return Pointer to the new current node.
     */
    NODE* add_node() {
        const auto temp = new NODE(this->actual_node);
        this->actual_node = temp;
        return temp;
    }

    /**
     *@details function di debug per la visione della symble table
     */
    void print() const{
        this->root->print("    ");
    }


};

auto CORE_SYMBLETABLE = new SymbleTable_Core();



/**
 * @class SymbleTable_Row_Variabile
 * @brief Represents a variable row in the symbol table.
 *
 * This class is used to manage variable entries in the symbol table.
 */
class SymbleTable_Row_Variabile : public SymbleTable_Row {
public:
    const ENUM_INFO info = ENUM_INFO::VARIABILE; ///< Information type for the variable row.
    NODE* contesto_var=nullptr;

    // variabili
    std::string* nome; ///< Name of the variable.
    ENUM_TIPO_VARIABILE tipo_variabile = ENUM_TIPO_VARIABILE::NONE_VAR; ///< Type of the variable.
    uint32_t posizione; ///< Position of the variable in the symbol table.
    void* valore = nullptr; ///< Value of the variable.
    bool usato = false; ///< Indicates whether the variable has been used.

    // Funzioni
    /**
     * @brief Gets the name of the variable.
     * @return Pointer to the name of the variable.
     */
    std::string* get_name() override {
        return this->nome;
    }

    /**
     * @brief Gets the information type of the variable row.
     * @return The information type of the variable row.
     */
    ENUM_INFO get_info() override {
        return this->info;
    }

    /**
     * @brief Gets the type of the variable.
     * @return The type of the variable.
     */
    ENUM_TIPO_VARIABILE get_tipo() override {
        return this->tipo_variabile;
    }

    /**
     * @brief Gets the position of the variable in the symbol table.
     * @return The position of the variable.
     */
    uint32_t get_posizione() override {
        return this->posizione;
    }

    /**
     * @brief Sets the value of the variable.
     * @param _valore Pointer to the value to be set.
     */
    void set_valore(void* _valore) override {
        this->valore = _valore;
    }

    /**
     * @brief Gets the value of the variable.
     * @return Pointer to the value of the variable.
     */
    void* get_valore() override {
        return this->valore;
    }

    /**
     * @brief Sets the usage status of the variable.
     * @param _usato Boolean indicating whether the variable has been used.
     */
    void set_usato(const bool _usato) override {
        this->usato = _usato;
    }

    /**
     * @brief Gets the usage status of the variable.
     * @return True if the variable has been used, otherwise false.
     */
    bool get_usato() override {
        return this->usato;
    }

    NODE *get_contesto_var() override {
        return contesto_var;
    }

    /**
     * @brief Constructs a new SymbleTable_Row_Variabile object.
     * @param nome The name of the variable.
     * @param tipo_variabile The type of the variable.
     * @param posizione The position of the variable in the symbol table.
     */
    SymbleTable_Row_Variabile(std::string* nome, ENUM_TIPO_VARIABILE tipo_variabile, uint32_t posizione) {
        this->nome = nome;
        this->tipo_variabile = tipo_variabile;
        this->posizione = posizione;
        contesto_var=CORE_SYMBLETABLE->actual_node;
    }

    void print(string spaziatura) {
        cout << *this->nome << " ||| " << this->info<< " ||| "<< this->get_posizione() << std::endl;
    }

    /**
     * @brief Constructs a new SymbleTable_Row_Variabile object with a value.
     * @param nome The name of the variable.
     * @param tipo_variabile The type of the variable.
     * @param posizione The position of the variable in the symbol table.
     * @param valore Pointer to the value of the variable.
     */
    SymbleTable_Row_Variabile(std::string* nome, ENUM_TIPO_VARIABILE tipo_variabile, uint32_t posizione, void* valore) {
        this->nome = nome;
        this->tipo_variabile = tipo_variabile;
        this->posizione = posizione;
        this->SymbleTable_Row_Variabile::set_valore(valore);
        this->contesto_var=CORE_SYMBLETABLE->actual_node;

    }
};

class SymbleTable_Row_Funzione : public SymbleTable_Row {
public:
    const ENUM_INFO info = ENUM_INFO::FUNZIONE;

    // variabili
    std::string* nome;

    string* paramether_type;
    ENUM_TIPO_VARIABILE return_type;
    NODE* Block;


    bool usato = false;

    // Funzioni
    std::string* get_name() override {
        return this->nome;
    }

    ENUM_INFO get_info() override {
        return this->info;
    }

    ENUM_TIPO_VARIABILE get_tipo() override {
        return this->return_type;
    }

    void set_usato(bool _usato) override {
       this->usato = _usato;
    }

    bool get_usato() override {
        return this->usato;
    }

    [[nodiscard]] static std::string* hash_nome_variabile(string* nome, string* paramether_type, ENUM_TIPO_VARIABILE return_type ) {
        auto* x= new string(*nome);
        x->append( "_");
        x->append( *paramether_type);
        return x;
    }

    NODE* get_oggetto_puntato() override {
        return this->Block;
    }

    SymbleTable_Row_Funzione(std::string* nome, string* paramether, ENUM_TIPO_VARIABILE return_type, NODE* block) {
        this->nome = nome;
        this->paramether_type = paramether;
        this->return_type = return_type;
        this->Block=block;
    }

    void print(string s) override{
        cout << *this->nome << " ||| " << return_type<< " ||| " << paramether_type << std::endl;
        this->Block->print(s+"    ");
    }
};

class SymbleTable_Row_Puntatore : public SymbleTable_Row {
public:
    NODE* contesto_var=nullptr;
    const ENUM_INFO info = ENUM_INFO::PUNTATORE;


    // variabili
    std::string* nome;
    NODE* oggetto_puntato;
    uint32_t posizione;
    bool usato = false;

    // Funzioni
    ENUM_INFO get_info() override {
        return this->info;
    }

    ENUM_TIPO_VARIABILE get_tipo() override {
        return ENUM_TIPO_VARIABILE::PTR;
    }

    std::string* get_name() override {
        return this->nome;
    }

    NODE* get_oggetto_puntato() override {
        return this->oggetto_puntato;
    }

    uint32_t get_posizione() override {
        return this->posizione;
    }

    void set_usato(bool _usato) override {
        this->usato = _usato;
    }

    bool get_usato() override {
        return this->usato;
    }

    NODE *get_contesto_var() override {
        return contesto_var;
    }

    SymbleTable_Row_Puntatore(std::string* nome, NODE* oggetto_puntato, uint32_t posizione) {
        this->nome = nome;
        this->oggetto_puntato = oggetto_puntato;
        this->posizione = posizione;
        this->contesto_var=CORE_SYMBLETABLE->actual_node;
    }

    void print(string spaziatura ) {
        cout << *this->nome << " ||| " << this->info<< " ||| "<< this->get_posizione() << std::endl;
    }
};

/**
 * @class SymbleTable_Row_Classe
 * @brief Represents a class row in the symbol table.
 *
 * This class is used to manage class entries in the symbol table.
 */
class SymbleTable_Row_Classe : public SymbleTable_Row {
public:

    const ENUM_INFO info = ENUM_INFO::CLASSE; ///< Information type for the class row.

    std::string* nome; ///< Name of the class.
    NODE* table; ///< Pointer to the symbol table node associated with the class.

    /**
     * @brief Gets the information type of the class row.
     * @return The information type of the class row.
     */
    ENUM_INFO get_info() override {
        return this->info;
    }

    NODE* get_oggetto_puntato() override {
        return this->table;
    }


    /**
     * @brief Gets the name of the class.
     * @return Pointer to the name of the class.
     */
    std::string* get_name() override {
        return this->nome;
    }

    /**
     * @brief Constructs a new SymbleTable_Row_Classe object.
     * @param nome The name of the class.
     * @param table Pointer to the symbol table node associated with the class.
     */
    SymbleTable_Row_Classe( std::string* nome, NODE* table) {
        this->nome = nome;
        this->table = table;
    }

    void print(string spaziatura) {
        std::cout << "nome: " << nome << endl;
        table->print(spaziatura+ "    ");

    }


};


/** @class SymbleTable_Row_Blocco
 * @brief Represents a block row in the symbol table.
 *
 * This class is used to manage block entries in the symbol table.
 */
class SymbleTable_Row_Blocco : public SymbleTable_Row {
public:

    const ENUM_INFO info = ENUM_INFO::BLOCCO; ///< Information type for the block row.

    NODE* contesto; ///< Context of the block.
    NODE* table; ///< Pointer to the symbol table node associated with the block.

    /**
     * @brief Gets the information type of the block row.
     * @return The information type of the block row.
     */
    ENUM_INFO get_info() override {
        return this->info;
    }

    /**
     * @brief Gets the symbol table node associated with the block.
     * @return Pointer to the symbol table node.
     */
    NODE* get_oggetto_puntato() override {
        return this->table;
    }

    /**
     * @brief Gets the name of the block.
     * @return Pointer to the name of the block.
     */
    std::string* get_name() override {
        return new std::string("___");
    }

    /**
     * @brief Gets the context of the block.
     * @return Pointer to the context node.
     */
    NODE* get_contesto() override {
        return this->contesto;
    }

    /**
     * @brief Constructs a new SymbleTable_Row_Blocco object.
     * @param contesto Pointer to the context node.
     * @param table Pointer to the symbol table node associated with the block.
     */
    SymbleTable_Row_Blocco(NODE* contesto, NODE* table) {
        this->contesto = contesto;
        this->table = table;
    }

    /**
     * @brief Prints the block row information.
     * @param spaziatura Indentation for printing.
     */
    void print(std::string spaziatura) {
        std::cout << "nome: " << "___" << std::endl;
        table->print(spaziatura + "    ");
    }
};

class SymbleTable_Row_Array : public SymbleTable_Row {
public:
    const ENUM_INFO info = ENUM_INFO::ARRAY;
    NODE* contesto_var=nullptr;
    ENUM_TIPO_VARIABILE tipo= ENUM_TIPO_VARIABILE::NONE_VAR;

    std::string* nome;
    uint32_t posizione;
    bool usato = false;

    ENUM_INFO get_info() override {
        return this->info;
    }

    std::string* get_name() override {
        return this->nome;
    }

    uint32_t get_posizione() override {
        return this->posizione;
    }

    void set_usato(bool _usato) override {
        this->usato = _usato;
    }

    bool get_usato() override {
        return this->usato;
    }

    ENUM_TIPO_VARIABILE get_tipo() override {
        return this->tipo;
    }

    NODE *get_contesto_var() override {
        return contesto_var;
    }

    SymbleTable_Row_Array(string* name, uint32_t posizione, ENUM_TIPO_VARIABILE tipo) {
        this->nome=name;
        this->posizione=posizione;
        this->tipo=tipo;
        contesto_var=CORE_SYMBLETABLE->actual_node;
    }


};

inline ENUM_TIPO_VARIABILE get_tipo_variabile_from_string(const string ciao) {
    if (ciao == "int") {
        return ENUM_TIPO_VARIABILE::INT;
    } else if (ciao == "float") {
        return ENUM_TIPO_VARIABILE::FLOAT;
    } else if (ciao == "bool") {
        return ENUM_TIPO_VARIABILE::BOOLEAN;
    } else if (ciao == "string") {
        return ENUM_TIPO_VARIABILE::STRING;

    } else {
        return ENUM_TIPO_VARIABILE::PTR;
    }
}

inline short get_size_from_tipo_variabile(ENUM_TIPO_VARIABILE tipo) {
    switch(tipo) {
        case ENUM_TIPO_VARIABILE::INT:
        case ENUM_TIPO_VARIABILE::FLOAT:
            return 4;
            break;
        case ENUM_TIPO_VARIABILE::BOOLEAN:
            return 1;
            break;
        case ENUM_TIPO_VARIABILE::PTR:
            return 8;
            break;
        case ENUM_TIPO_VARIABILE::STRING:
            return 8;
            break;
        default:
            return 0;
            break;
    }
}

inline string* get_register_from_size(short size) {
    switch(size) {
        case 1:
            return new string("AL");
            break;
        case 4:
            return new string("EAX");
            break;
        case 8:
            return new string("RAX");
            break;
        default:
            cout << "grandezza var sbagliata : "<< size << endl;
            exit(0);
            break;
    }
}

inline string* get_alloc_from_size(short x) {
    switch(x) {
        case 1:
            return new string("BYTE");
            break;
        case 4:
            return new string("DWORD");
            break;
        case 8:
            return new string("QWORD");
            break;
        default:
            cout<< "grandezza var sbagliata : "<< x << endl;
            exit(0);
    }

}

inline string* get_condition_from_string(short x) {
    switch (x) {
        case Parser::EQUAL:
            return new string("je");
        case Parser::NOTEQUAL:
            return new string("jne");
        case Parser::LESSTHAN:
            return new string("jl");
        case Parser::GREATERTHAN:
            return new string("jg");
        case Parser::LESSTHANEQUAL:
            return new string("jle");
        case Parser::GREATERTHANEQUAL:
            return new string("jge");
        default:
            cout << "errore condizione non esistente" << endl;
            exit(0);
    }
}




#endif // symble_table_core_cpp