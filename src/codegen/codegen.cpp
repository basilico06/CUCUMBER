//
// Created by basil on 12/12/2024.
//

#include <iostream>
#include <string>
#include <deque>
#include <list>
#include "../symble_table/symble_table.cpp"

enum REGISTER_X64 {
    RAX,
    RBX,
    RCX,
    RDX,
    RSI,
    RDI,
    RBP,
    RSP,
    RIP,
    R8,
    R9,
    R10,
    R11,
    R12,
    R13,
    R14,
    R15,
};

class llvm_register {
public:
    robin_hood::unordered_node_map< NODE*,REGISTER_X64> memory_to_register;
    robin_hood::unordered_node_map< REGISTER_X64,NODE*> register_to_memory;

    REGISTER_X64 get_register_containing_the_value(NODE* x) {
        return this->memory_to_register[x];
    }

    bool check_if_register_is_free(REGISTER_X64 x) const {
        return this->register_to_memory.contains(x);
    }

    void set_a_memory_in_register(REGISTER_X64 x, NODE* y) {
        this->register_to_memory[x]=y;
        this->memory_to_register[y]=x;
    }


};

struct data_ {
    string name;
    string type;
    string value;
};

class section {
public:
    list<data_> data_list;

    void add_data(const string name, const string type, const string value) {
        data_ temp;
        temp.name = name;
        temp.type = type;
        temp.value = value;
        this->data_list.push_back(temp);
    }

    section() {
        this->data_list = list<data_>();
    }
};


class llvm {

    void stack_adjustment(const uint32_t x) {
        this->stack_offset += x;
    }


    void stack_pop(const uint32_t x) {
        this->stack_offset += x;
    }
public:

    llvm_register register_= llvm_register();

    section bss_section= section();
    section data_section= section();


    int loop_index=0;
    int if_index=0;
    uint64_t stack_offset=0;
    vector<NODE*>* actual_node_function= new vector<NODE*>();
    uint64_t temp_offset=0;
    llvm()= default;




    uint64_t get_stack_offset_from_a_var( const string* nome) const
    {
        cout<< "----------------" <<temp_offset<<endl;
        uint64_t temp_stack_offset=0;
        auto temp_actual_node= this->actual_node_function->end();
        while (temp_actual_node!=this->actual_node_function->begin()) {
            --temp_actual_node;
            cout<< *nome    ;
            temp_actual_node.operator*()->print("-----");
            if (temp_actual_node.operator*()->contains(nome)) {
                const uint64_t ret = temp_offset+ temp_actual_node.operator*()->lenght - temp_actual_node.operator*()->map[*nome]->get_posizione()-temp_stack_offset;
                cout<< "----------------#################à" <<ret<<endl;
                return ret;
            }
            temp_stack_offset+=temp_actual_node.operator*()->lenght;
        }

        //todo errore variabile non esistenteà

        exit(0);

    }

    void stack_adjust(NODE* x) {
        this->actual_node_function -> push_back(x);
        stack_adjustment(x->lenght);
    }

    void remove_actual_node_function() {
        stack_pop(this->actual_node_function->back()->lenght);
        this->actual_node_function->pop_back();
    }

    ENUM_TIPO_VARIABILE get_tipo_variabile(string* name) {
        auto temp_actual_node = this->actual_node_function->end();
        while (temp_actual_node != this->actual_node_function->begin()) {
            --temp_actual_node;
            if (temp_actual_node.operator*()->contains(name)) {
                return temp_actual_node.operator*()->map[*name]->get_tipo();
            }
        }

        return ENUM_TIPO_VARIABILE::NONE_VAR;
        //todo errore variabile non esistente

    }

};

llvm LLVM= llvm();
