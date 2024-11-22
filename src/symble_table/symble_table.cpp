#include "symble_table_row/symble_table_row.hpp"



using namespace std;

#ifndef symble_table_core_cpp
#define symble_table_core_cpp
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

    void 




    /**
     * @brief Constructs a new SymbleTable_Core object.
     *
     * Initializes the root node and sets the current node to the root.
     */
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
     *@details funione di debug per la visione della symble table
     */
    void print() {
        this->root->print("    ");
    }


};

auto CORE_SYMBLETABLE = new SymbleTable_Core();



#endif // symble_table_core_cpp