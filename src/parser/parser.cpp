#include "../lexer/lexer.hpp"
#include "../syntax_analyzer/syntax_analyzer_util.cpp"
#include <deque>
#include "../symble_table/symble_table.cpp"

void print(string x) {
    cout << x << endl;
}


list<Entity *>::iterator safe_next(list<Entity *>::iterator it, list<Entity *> &buffer, size_t steps = 1) {
    auto result = it;
    for (size_t i = 0; i < steps; i++) {
        if (result == buffer.end()) {
            throw std::runtime_error("Iterator out of bounds");
        }
        result = std::next(result);
    }
    return result;
}

void parse_2_entity(list<Entity *>::iterator start, list<Entity *> *BUFFER) {
    if (std::distance(start, BUFFER->end()) < 3) {
        throw std::runtime_error("Not enough elements for parse_2_entity");
    }

    auto first = *safe_next(start, *BUFFER);
    auto second = *safe_next(start, *BUFFER, 2);

    if (first->getType() == syntax_analyzer::VAR and second->getType() == syntax_analyzer::REAL_PARAMETHER_LIST) {
        Entity *entity = new function_call(first, second);
        BUFFER->pop_back();
        BUFFER->pop_back();
        BUFFER->push_back(entity);
        goto end_parser_2;
    }

    if (first->getType()==syntax_analyzer::VAR and second->getType()==syntax_analyzer::VAR) {
        if(CORE_SYMBLETABLE->check_if_present_at_global_level(first->get_name())){
            if (const auto x= CORE_SYMBLETABLE->get_at_root_level(first->get_name()); x->get_info()==ENUM_INFO::CLASSE) {
                Entity *entity = new object_allocation(first, second, x->get_oggetto_puntato());
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->push_back(entity);
            }

        }
        //todo implementare errore : classe non presente al toplayer
    }



    if (first->getType() == syntax_analyzer::DATATYPE and second->getType() == syntax_analyzer::VAR) {
        Entity *entity = new allocation(first, second);
        BUFFER->pop_back();
        BUFFER->pop_back();
        BUFFER->push_back(entity);
        goto end_parser_2;
    }

    if (first->getType() == syntax_analyzer::VAR and second->getType() == syntax_analyzer::INT_MODIFIER_OPERAND) {
        Entity *entity = new int_modifier(first, second);
        BUFFER->pop_back();
        BUFFER->pop_back();
        BUFFER->push_back(entity);
        goto end_parser_2;
    }
    //TO-DO:
    //implementing more thing with 2 entity


end_parser_2:
    return;
}


void print_entity_debug(Entity *entity, const std::string &prefix = "") {
    if (!entity) {
        std::cout << prefix << "NULL ENTITY" << std::endl;
        return;
    }
    try {
        std::cout << prefix << "Type: " << entity->getType()
                << " Category: " << entity->getCategory() << std::endl;
    } catch (...) {
        std::cout << prefix << "INVALID ENTITY - Exception on access" << std::endl;
    }
}

void parse_3_entity(list<Entity *>::iterator start, list<Entity *> *BUFFER) {
    std::cout << "\nParse 3 Entity Debug:" << std::endl;
    std::cout << "Start iterator position: " << std::distance(BUFFER->begin(), start) << std::endl;

    // Validate iterator positions
    if (std::distance(start, BUFFER->end()) < 4) {
        throw std::runtime_error("Not enough elements for parse_3_entity");
    }

    Entity *start_entity = *start;
    Entity *first = *(std::next(start, 1));
    Entity *second = *(std::next(start, 2));
    Entity *third = *(std::next(start, 3));

    // Debug print each entity
    std::cout << "Start entity: ";
    print_entity_debug(start_entity);
    std::cout << "First entity: ";
    print_entity_debug(first);
    std::cout << "Second entity: ";
    print_entity_debug(second);
    std::cout << "Third entity: ";
    print_entity_debug(third);


    //* real_var + comma + real_var
    if (first->getCategory() == category_syntax_analyzer::_real and third->getCategory() ==
        category_syntax_analyzer::_real and second->getType() == syntax_analyzer::COMMA) {
        // ( var , var )
        Entity *ENTITY = new sequence_of_entity(first, third);
        BUFFER->pop_back();
        BUFFER->pop_back();
        BUFFER->pop_back();
        BUFFER->push_back(ENTITY);
        return;
    }

    //class + var + block
    if(first->getType()==syntax_analyzer::CLASS_DECLARATION and second->getType()==syntax_analyzer::VAR and third->getType()==syntax_analyzer::BLOCK){
        Entity *entity = new class_statment(third, second->get_name());
        BUFFER->pop_back();
        BUFFER->pop_back();
        BUFFER->pop_back();
        BUFFER->push_back(entity);
        return;
    }



    //* declaration + comma + declaration
    if (first->getCategory() == category_syntax_analyzer::_allocation and third->getCategory() ==
        category_syntax_analyzer::_allocation and second->getType() == syntax_analyzer::COMMA) {
        // ( allocation , allocation )
        Entity *ENTITY = new sequence_of_allocation(first, third);
        BUFFER->pop_back();
        BUFFER->pop_back();
        BUFFER->pop_back();
        BUFFER->push_back(ENTITY);
        return;
    }

    //* formal_list + comma + declaration
    if (first->getType() == syntax_analyzer::SEQUENCE_OF_ALLOCATION and third->getCategory() ==
        category_syntax_analyzer::_allocation and second->getType() == syntax_analyzer::COMMA) {
        first->add(third);
        BUFFER->pop_back();
        BUFFER->pop_back();
        return;
    }

    //* real_list + comma + real_var
    if (first->getType() == syntax_analyzer::SEQUENCE_OF_ENTITY and third->getCategory() ==
        category_syntax_analyzer::_real and second->getType() == syntax_analyzer::COMMA) {
        first->add(third);
        BUFFER->pop_back();
        BUFFER->pop_back();
        return;
    }

    if (first->getType() == syntax_analyzer::LEFT_PAREN and third->getType() == syntax_analyzer::RIGHT_PAREN) {
        if ((*start)->getType() == syntax_analyzer::VAR) {
            if (second->getType() == syntax_analyzer::SEQUENCE_OF_ENTITY) {
                //* VAR , ( , LIST, )
                Entity *TEMP = new real_paramether_list(second->get_deque());
                Entity *ENTITY = new function_call((*start), TEMP);
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->push_back(ENTITY);
                return;
            }

            if (second->getType() == syntax_analyzer::SEQUENCE_OF_ALLOCATION) {
                //* ( , LIST_ALLOCATION, )
                Entity *ENTITY = new formal_paramether_list(second->get_deque());
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->push_back(ENTITY);
                return;
            }

            if (second->getCategory() == category_syntax_analyzer::_real) {
                //* VAR , ( , PARM, )
                Entity *TEMP = new real_paramether_list(second);
                Entity *ENTITY = new function_call((*start), TEMP);
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->push_back(ENTITY);

                return;
            }

            if (second->getCategory() == category_syntax_analyzer::_allocation) {
                //* ( , DECLARATION, )
                Entity *ENTITY = new formal_paramether_list(second);
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->push_back(ENTITY);
                return;
            }

            // *TODO RICORDARSI DI IMPLEMENTARE GLI ERRORI SENNO SONO CAZZI
        }

        //PARENTESI IN MATEMATICA
        if (second->getType() == syntax_analyzer::MATH_EXPRESSION) {
            print("entrato");
            BUFFER->pop_back();
            BUFFER->pop_back();
            BUFFER->pop_back();
            BUFFER->push_back(second);
            return;
        }


        // FOR PARAMETHER
        if (second->getType() == syntax_analyzer::SEQUENZE_OF_ISTRUCTION and second->get_deque()->size() == 3) {
            Entity *ENTITY = new for_paramether(second->get_deque());
            BUFFER->pop_back();
            BUFFER->pop_back();
            BUFFER->pop_back();
            BUFFER->push_back(ENTITY);
            return;
        }

        // IF CONDITION
        if (second->getType() == syntax_analyzer::SIMPLE_CONDITION) {
            print("entrato nel if delle simple condition+++++++++++++");
            BUFFER->pop_back();
            BUFFER->pop_back();
            BUFFER->pop_back();
            BUFFER->push_back(second);
            for (auto x: *BUFFER) {
                cout << " ---   " << x->getType() << endl;
            }
            return;
        }

        //*TODO IMPLEMENTARE ERRORI
    }


    /*
    //*! PARTE MOLTO IMPORANTE
    //* MOTORE MATEMATICA
    //*!RICORDARSI DI IMPLEMENTARE GLI ERRORI
    */
    if (second->getCategory() == category_syntax_analyzer::_math_symbol) {
        print("entrato in mate");
        if (first->getType() == syntax_analyzer::MATH_EXPRESSION) {
            if (third->getType() == syntax_analyzer::MATH_EXPRESSION) {
                first->add(third->get_deque(), second);
                BUFFER->pop_back();
                BUFFER->pop_back();
                return;
            }
            if (third->getCategory() == category_syntax_analyzer::_real) {
                first->add(third, second);
                BUFFER->pop_back();
                BUFFER->pop_back();
                return;
            }

            //*TODO IMPLEMENTARE ERRORI
        }

        if (first->getCategory() == category_syntax_analyzer::_real) {
            if (third->getType() == syntax_analyzer::MATH_EXPRESSION) {
                print("cucu");
                third->get_deque();
                print("cucu2");
                Entity *ENTITY = new math_expression(first, second, third->get_deque());
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->push_back(ENTITY);
                print("cucu3");
                return;
            }
            if (third->getCategory() == category_syntax_analyzer::_real) {
                print("d=1");
                Entity *ENTITY = new math_expression(first, second, third);
                print("d=1");
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->pop_back();
                print("d=1");
                BUFFER->push_back(ENTITY);
                print("d=1");

                return;
            }

            //*TODO IMPLEMENTARE ERRORI
        }
        //*TODO IMPLEMENTARE ERRORI
        print("come mai non fai un cazzo?");
    }


    //ARRAY CALL
    if (first->getType() == syntax_analyzer::LEFT_SQUARE and third->getType() == syntax_analyzer::RIGHT_SQUARE) {
        if ((*start)->getType() == syntax_analyzer::VAR) {
            if (second->getType() >= 500 and second->getType() < 518) {
                Entity *temp = new array_position(second);
                Entity *ENTITY = new array_call((*start), temp);
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->push_back(ENTITY);
                return;
            }
            //*TODO IMPLEMENTARE ERRORI
        }

        //*TODO IMPLEMENTARE ERRORI
    }

    //LIST OF ISTRUCTION
    if (second->getType() == syntax_analyzer::SEMICOLON) {
        if (first->getType() == syntax_analyzer::SEQUENZE_OF_ISTRUCTION) {
            first->add(third);
            BUFFER->pop_back();
            BUFFER->pop_back();
            return;
        } else {
            Entity *ENTITY = new sequence_of_istruction(first, second);
            BUFFER->pop_back();
            BUFFER->pop_back();
            BUFFER->pop_back();
            BUFFER->push_back(ENTITY);
        }
    }

    //BLOCK
    if (first->getType() == syntax_analyzer::LEFT_CURLY) {
        if (third->getType() == syntax_analyzer::RIGHT_CURLY) {
            if (second->getType() == syntax_analyzer::SEQUENZE_OF_ISTRUCTION) {
                Entity *ENTITY = new block(second->get_deque());
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->push_back(ENTITY);
                return;
            }
            //! implementare errori
        }
        //TODO non scrivere qui dentro qui dentro è il caso in cui il 3 non sia una parentesi
    }

    //simple condition
    if (second->getType() == syntax_analyzer::COND_OPERAND) {
        if (first->getCategory() == category_syntax_analyzer::_real and third->getCategory() ==
            category_syntax_analyzer::_real) {
            Entity *ENTITY = new simple_condition(first, second, third);
            BUFFER->pop_back();
            BUFFER->pop_back();
            BUFFER->pop_back();
            BUFFER->push_back(ENTITY);
            return;
        }
    }

    //STATMENT
    if (third->getType() == syntax_analyzer::BLOCK) {
        if (first->getType() == syntax_analyzer::FOR_DECLARATION) {
            if (second->getType() == syntax_analyzer::FOR_PARAMETHER) {
                Entity *ENTITY = new for_statment(second->get_deque(), third);
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->push_back(ENTITY);
                return;
            }
            //TODO importare mancanza parametri
        }


        if (first->getType() == syntax_analyzer::IF_DECLARATION) {
            if (second->getType() == syntax_analyzer::SIMPLE_CONDITION) {
                Entity *ENTITY = new if_statment(second, third);
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->push_back(ENTITY);
                return;
            }

            //TODO implementare macanza condition
        }

        if (first->getType() == syntax_analyzer::WHILE_DECLARATION) {
            if (second->getType() == syntax_analyzer::SIMPLE_CONDITION) {
                Entity *ENTITY = new while_statment(second, third);
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->pop_back();
                BUFFER->push_back(ENTITY);
                return;
            }
        }
        //TODO implementare altri statment
    }

    if (second->getType() == syntax_analyzer::ASSIGN_OPERAND) {
        Entity *ENTITY = new assign_expression(first, second);
        BUFFER->pop_back();
        BUFFER->pop_back();
        BUFFER->pop_back();
        BUFFER->push_back(ENTITY);
        return;
    }

    cout << "errore nel parser: non presente compatibilita" << endl;
}

void parse_default(list<Entity *>::iterator start, list<Entity *> *BUFFER) {
}


void parser_core(list<Entity *>::iterator it_start, list<Entity *> *BUFFER) {
    int DIST = std::distance(it_start, BUFFER->end()) - 1;

    print("parser core");
    cout << "chiamata con it=" << (*it_start)->getType() << endl;
    for (auto x = it_start; x != BUFFER->end(); x = std::next(x)) {
        cout << "    " << (*x)->getType() << endl;
    }

    switch (DIST) {
        case 0:
        //gestione degli errori
        case 1:
            return;
            break;
        case 2:
            parse_2_entity(it_start, BUFFER);
            break;
        case 3:
            parse_3_entity(it_start, BUFFER);
            break;
        default:
            break;
    }
}

#include "break_layer.hpp"

void resolve_until_last_break_point(list<Entity *>::iterator finish, list<Entity *> *BUFFER,
                                    list<break_point_entity *> *BREAKPOINT) {
    parser_core(finish, BUFFER);
}

bool is_parentesis(short type) {
    return type == break_point_type::PARENTESIS;
}

void risolve_until_a_parentesis(short finish, list<break_point_entity *> *BREAK_POINT, list<Entity *> *BUFFER,
                                Entity *ACTUAL) {
    print("aaaa");
    resolve_until_last_break_point(BREAK_POINT->back()->get_ref(), BUFFER, BREAK_POINT);
    BREAK_POINT->pop_back();

    print("break point buffer:");
    for (auto x: *BREAK_POINT) {
        cout << " ---   " << x->get_ref_type() << endl;
    }

    while (BREAK_POINT->back()->get_ref_type() != finish) {
        resolve_until_last_break_point(BREAK_POINT->back()->get_ref(), BUFFER, BREAK_POINT);
        BREAK_POINT->pop_back();
    }

    resolve_until_last_break_point(BREAK_POINT->back()->get_ref(), BUFFER, BREAK_POINT);
    BUFFER->push_back(ACTUAL);
    resolve_until_last_break_point(prev(BREAK_POINT->back()->get_ref()), BUFFER, BREAK_POINT);
    BREAK_POINT->pop_back();


    for (auto x: *BREAK_POINT) {
        cout << " ---   " << x->get_ref_type() << endl;
    }

    return;
}

// Helper function to safely process the last break point


void print_deque1(list<break_point_entity *> *da_iterare) {
    for (auto *x: *da_iterare) {
        cout << x->get_layer() << endl;
    }
}

void resolve_until_is_higher_or_equal(list<break_point_entity *> *BREAK_POINT, list<Entity *> *BUFFER,
                                      short ACTUAL_LAYER) {
    auto current = BREAK_POINT->back();


    resolve_until_last_break_point(current->get_ref(), BUFFER, BREAK_POINT);

    print("actual layer: " + ACTUAL_LAYER);
    // Process remaining break points
    while (!BREAK_POINT->empty() and BREAK_POINT->size() > 1) {
        cout << "if cirtico" << endl;
        cout << (*BREAK_POINT->rbegin())->get_layer() << "    " << ACTUAL_LAYER << "     and   " << !is_parentesis(
            (*BREAK_POINT->rbegin())->get_type()) << endl;
        if ((*BREAK_POINT->rbegin())->get_layer() <= ACTUAL_LAYER and !is_parentesis(
                (*BREAK_POINT->rbegin())->get_type())) {
            print("entrato if critico 2");
            resolve_until_last_break_point(BREAK_POINT->back()->get_ref(), BUFFER, BREAK_POINT);
            BREAK_POINT->pop_back();
        } else {
            break;
        }
    }
    resolve_until_last_break_point(BREAK_POINT->back()->get_ref(), BUFFER, BREAK_POINT);
    cout << "perche cazzo sei uscito" << endl;
    for (auto x = BREAK_POINT->begin(); x != BREAK_POINT->end(); x = std::next(x)) {
        cout << "    " << (*x)->get_type() << endl;
    }
}

// Add this helper function to validate break points
bool is_valid_break_point(break_point_entity *bp) {
    return bp != nullptr && bp->get_ref() != list<Entity *>::iterator();
}

void resolve_previus_block(list<Entity *> *BUFFER, list<break_point_entity *> *BREAK_POINT) {
    resolve_until_last_break_point(BREAK_POINT->back()->get_ref(), BUFFER, BREAK_POINT);
    BREAK_POINT->pop_back();

    parser_core(BREAK_POINT->back()->get_ref(), BUFFER);
    return;
}

void print_deque(list<Entity *> *da_iterare) {
    for (Entity *x: *da_iterare) {
        cout << x->getType() << endl;
    }
}

void print_deque(deque<Entity *> *da_iterare) {
    for (Entity *x: *da_iterare) {
        cout << x->getType() << endl;
    }
}


/*
list<Entity*>* parse(deque<Entity*>* LIST_OF_RAW_TOKEN){

    list<Entity*>* BUFFER= new list<Entity*>();

    list<break_point_entity*> BREAK_POINT= list<break_point_entity*>();

    list<list<break_point_entity*>::iterator>* OPEN_PARENTESIS= new list<list<break_point_entity*>::iterator>();

    for(deque<Entity*>::iterator ACTUAL = LIST_OF_RAW_TOKEN->begin(); ACTUAL!=LIST_OF_RAW_TOKEN->end(); ACTUAL=std::next(ACTUAL) )
    {
        cout<<"actual:"<< (*ACTUAL)->getType()<< endl;

        print_deque(BUFFER);

        if((*ACTUAL)->getType()<util_syntax_analyzer::max_id_parentesis){
            if((*ACTUAL)->getType()>util_syntax_analyzer::max_id_operand){
                if((*ACTUAL)->getType()==syntax_analyzer::LEFT_CURLY or (*ACTUAL)->getType()==syntax_analyzer::LEFT_SQUARE or (*ACTUAL)->getType()==syntax_analyzer::LEFT_PAREN){
                    // parentesi di apertura
                    parser_core(BREAK_POINT.back()->get_ref(), BUFFER);
                    BUFFER->push_back((*ACTUAL));
                    BREAK_POINT.push_back(new break_point_entity(break_point_type::PARENTESIS, break_point_layer::parentesis ,std::prev(BUFFER->end()), (*ACTUAL)->getType() ));
                    OPEN_PARENTESIS->push_back(std::prev(BREAK_POINT.end()));

                }
                else
                {
                    if((*ACTUAL)->getType()-1==(*OPEN_PARENTESIS->back())->get_ref_type()){
                        risolve_until_a_parentesis((*OPEN_PARENTESIS->back())->get_ref(), &BREAK_POINT, BUFFER );
                        BREAK_POINT.pop_back();
                        OPEN_PARENTESIS->pop_back();
                        BUFFER->push_back((*ACTUAL));
                        parser_core(prev(BREAK_POINT.back()->get_ref()), BUFFER);
                    }
                    else
                    {
                       //TODO IMPLEMENTARE ERRORE CHIUSA PARENTESU SBAGLIATA
                    }
                }
            }else{
                // è un operand
                cout<< "entrato nel operando"<< endl;

                short LAYER= get_layer((*ACTUAL)->getType());
                if(!BREAK_POINT.empty()){
                    if(!is_parentesis(BREAK_POINT.back()->get_type())){
                        if(LAYER<BREAK_POINT.back()->get_layer()){
                            resolve_until_last_break_point(BREAK_POINT.back()->get_ref(), BUFFER);

                            BREAK_POINT.push_back(new break_point_entity(break_point_type::OPERAND, LAYER ,std::prev(BUFFER->end()), (*ACTUAL)->getType() ));
                        }
                        if(LAYER==BREAK_POINT.back()->get_layer()){
                            resolve_previus_block(BUFFER, &BREAK_POINT);
                            BUFFER->push_back((*ACTUAL));
                            BREAK_POINT.push_back(new break_point_entity(break_point_type::OPERAND, LAYER ,std::prev(BUFFER->end()), (*ACTUAL)->getType() ));

                        }
                        if(LAYER>BREAK_POINT.back()->get_layer()){
                            cout<< "entrato siccome minore"<< endl;
                            resolve_until_is_higher_or_equal(&BREAK_POINT, BUFFER, LAYER);
                            BUFFER->push_back((*ACTUAL));
                            BREAK_POINT.push_back(new break_point_entity(break_point_type::OPERAND, LAYER ,std::prev(BUFFER->end()), (*ACTUAL)->getType() ));
                        }
                    }else{
                        // ce una parentesi prima
                        BUFFER->push_back((*ACTUAL));
                        BREAK_POINT.push_back(new break_point_entity(break_point_type::OPERAND, LAYER ,std::prev(BUFFER->end()), (*ACTUAL)->getType() ));

                    }
                }else{
                    BUFFER->push_back((*ACTUAL));
                    BREAK_POINT.push_back(new break_point_entity(break_point_type::OPERAND, LAYER ,std::prev(BUFFER->end()), (*ACTUAL)->getType() ));
                }

            }

            for (break_point_entity* x: BREAK_POINT){
                print("    " + (*x->get_ref())->getType());
            }

        }else{
            // è una semplice entita
            BUFFER->push_back((*ACTUAL));
        }
        LIST_OF_RAW_TOKEN->pop_back();

    }
    return BUFFER;
}



// Helper functions for parse()
void handle_parenthesis(list<Entity*>::iterator& it,
                       list<Entity*>* BUFFER,
                       list<break_point_entity*>& BREAK_POINT,
                       list<list<break_point_entity*>::iterator>* OPEN_PARENTESIS) {
    Entity* current = *it;

    if (current->getType() == syntax_analyzer::LEFT_CURLY ||
        current->getType() == syntax_analyzer::LEFT_SQUARE ||
        current->getType() == syntax_analyzer::LEFT_PAREN) {

        if (!BREAK_POINT.empty()) {
            parser_core(BREAK_POINT.back()->get_ref(), BUFFER);
        }

        auto break_point = new break_point_entity(
            break_point_type::PARENTESIS,
            break_point_layer::parentesis,
            it,
            current->getType()
        );

        BREAK_POINT.push_back(break_point);
        OPEN_PARENTESIS->push_back(std::prev(BREAK_POINT.end()));
    }

    it = std::next(it);
}

void handle_operand(list<Entity*>::iterator& it,
                   list<Entity*>* BUFFER,
                   list<break_point_entity*>& BREAK_POINT) {
    Entity* current = *it;
    short LAYER = get_layer(current->getType());

    if (!BREAK_POINT.empty()) {
        auto& last_break = BREAK_POINT.back();

        if (!is_parentesis(last_break->get_type())) {
            if (LAYER < last_break->get_layer()) {
                resolve_until_last_break_point(last_break->get_ref(), BUFFER, &BREAK_POINT);
            } else if (LAYER == last_break->get_layer()) {
                resolve_previus_block(BUFFER, &BREAK_POINT);
            } else {
                resolve_until_is_higher_or_equal(&BREAK_POINT, BUFFER, LAYER);
            }
        }
    }

    BREAK_POINT.push_back(new break_point_entity(
        break_point_type::OPERAND,
        LAYER,
        it,
        current->getType()
    ));

    it = std::next(it);
}
*/

list<Entity *> *parse(deque<Entity *> *LIST_OF_RAW_TOKEN) {
    list<Entity *> *BUFFER = new list<Entity *>();

    list<break_point_entity *> BREAK_POINT = list<break_point_entity *>();

    list<short> *OPEN_PARENTESIS = new list<short>();
    BUFFER->push_back(new START_FILE());
    BREAK_POINT.push_back(new break_point_entity(break_point_type::OPERAND, break_point_layer::file,
                                                 std::prev(BUFFER->end()), syntax_analyzer::START_FILE));

    for (deque<Entity *>::iterator ACTUAL = LIST_OF_RAW_TOKEN->begin(); ACTUAL != LIST_OF_RAW_TOKEN->end();
         ACTUAL = std::next(ACTUAL)) {
        cout << "actual:" << (*ACTUAL)->getType() << endl;

        for (auto x = BREAK_POINT.begin(); x != BREAK_POINT.end(); x = std::next(x)) {
            cout << "   ::: " << (*x)->get_ref_type() << endl;
        }
        /*
        if((*ACTUAL)->getType()==syntax_analyzer::LEFT_CURLY){
            symble_table_tuple* x = new symble_table_tuple();
            symble_table::SYMBLE_TABLE->push_back(x);
        }
        */

        if ((*ACTUAL)->getType() == syntax_analyzer::FUNCTION_DEC or (*ACTUAL)->getType() == syntax_analyzer::CLASS_DECLARATION) {
            CORE_SYMBLETABLE->add_node();
        }


        if ((*ACTUAL)->getType() < 500) {
            if ((*ACTUAL)->getType() > 490) {
                if ((*ACTUAL)->getType() == syntax_analyzer::LEFT_CURLY or (*ACTUAL)->getType() ==
                    syntax_analyzer::LEFT_SQUARE or (*ACTUAL)->getType() == syntax_analyzer::LEFT_PAREN) {
                    // parentesi di apertura
                    parser_core(BREAK_POINT.back()->get_ref(), BUFFER);
                    BUFFER->push_back((*ACTUAL));
                    BREAK_POINT.push_back(new break_point_entity(break_point_type::PARENTESIS,
                                                                 break_point_layer::parentesis,
                                                                 std::prev(BUFFER->end()), (*ACTUAL)->getType()));
                    OPEN_PARENTESIS->push_back((*prev(BREAK_POINT.end()))->get_ref_type());
                    cout << (*prev(BREAK_POINT.end()))->get_ref_type() << "<>>>>><><<>>>><<" << endl;


                } else {
                    if ((*ACTUAL)->getType() - 1 == OPEN_PARENTESIS->back()) {
                        cout << "reftype:" << OPEN_PARENTESIS->back() << endl;
                        risolve_until_a_parentesis(OPEN_PARENTESIS->back(), &BREAK_POINT, BUFFER, *ACTUAL);
                        OPEN_PARENTESIS->pop_back();

                        print("break point buffer:");
                        for (auto x: BREAK_POINT) {
                            cout << " ---   " << x->get_ref_type() << endl;
                        }
                    } else {
                        print("come mai arrivi qui?");
                        cout << "1:" << (*ACTUAL)->getType() - 1 << "      2:" << OPEN_PARENTESIS->back() << endl;
                    }
                }
            } else {
                // è un operand
                cout << "entrato nel operando" << endl;

                short LAYER = get_layer((*ACTUAL)->getType());
                if (!BREAK_POINT.empty()) {
                    auto last_break = BREAK_POINT.back();
                    cout << !is_parentesis(BREAK_POINT.back()->get_type()) << " operndo è preceduto da una parentesi?"
                            << endl;
                    if (!is_parentesis(BREAK_POINT.back()->get_type())) {
                        if (LAYER < last_break->get_layer()) {
                            resolve_until_last_break_point(last_break->get_ref(), BUFFER, &BREAK_POINT);
                        } else {
                            cout << "layer piu alto" << endl;
                            resolve_until_is_higher_or_equal(&BREAK_POINT, BUFFER, LAYER);
                        }
                    } else {
                        resolve_until_last_break_point(last_break->get_ref(), BUFFER, &BREAK_POINT);
                    }

                    cout << "BUFFER=" << endl;
                }
                BUFFER->push_back((*ACTUAL));
                BREAK_POINT.push_back(new break_point_entity(break_point_type::OPERAND, LAYER, std::prev(BUFFER->end()),
                                                             (*ACTUAL)->getType()));
            }

            for (auto x = BUFFER->begin(); x != BUFFER->end(); x = std::next(x)) {
                cout << "    " << (*x)->getType() << endl;
            }
        } else {
            // è una semplice entita
            cout << "semplice entita" << endl;
            BUFFER->push_back((*ACTUAL));
        }
        cout << "-----------------------------------------------" << endl;
        cout << "break-point size:" << BREAK_POINT.size() << endl;
    }
    print_deque(BUFFER);
    print("break point:");

    return BUFFER;
}

int main() {
    const char *filename = R"(C:\Users\basil\OneDrive\Desktop\starfish_programming_language\test\test.txt)";
    deque<Entity *> *res_lex = tokenize(filename);
    print_deque(res_lex);
    list<Entity *> *res_par = nullptr;
    try {
        res_par = parse(res_lex);
    } catch (const std::exception &e) {
        std::cerr << "Error xxx: " << e.what() << std::endl;
    }
    print("output:");
    print_deque(res_par);

    CORE_SYMBLETABLE->print();
    return 0;
}
