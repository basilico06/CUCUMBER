//
// Created by basil on 18/11/2024.
//
#include <deque>
#include <string>
#include "syntax_analyzer_util.cpp"
#include "../symble_table/symble_table_util.cpp"
using namespace std;

#ifndef entity_hpp
#define entity_hpp

/**
 * @class Entity
 * @brief Represents a generic entity in the syntax analyzer.
 *
 * This class serves as a base class for various types of entities in the syntax analyzer.
 * It provides virtual methods for type, name, category, and deque management.
 */
class Entity {
public:
    /**
     * @brief Gets the type of the entity.
     * @return The type of the entity.
     */
    virtual short getType() const { return this->type; }

    short type; ///< The type of the entity.

    /**
     * @brief Gets the name of the entity.
     * @return The name of the entity.
     */
    virtual std::string * get_name() { return nullptr; }

    /**
     * @brief Virtual destructor.
     */
    virtual ~Entity() = default;

    /**
     * @brief Gets the category of the entity based on its type.
     * @return The category of the entity.
     */
    virtual short getCategory() {
        if (this->getType() > 800 && this->getType() < 1000) {
            return category_syntax_analyzer::_allocation;
        } else if (this->type >= 500 && this->type < 525) {
            return category_syntax_analyzer::_real;
        } else if (this->type >= 451 && this->type < 455) {
            return category_syntax_analyzer::_math_symbol;
        } else {
            return category_syntax_analyzer::_default;
        }
    }

    /**
     * @brief Gets a deque of entities.
     * @return A pointer to a deque of entities.
     */
    virtual deque<Entity*>* get_deque() { return new deque<Entity*>(); }

    /**
     * @brief Adds an entity to the current entity.
     * @param x Pointer to the entity to be added.
     */
    virtual void add(Entity *x) { return; }

    /**
     * @brief Adds an entity to a deque of entities.
     * @param second Pointer to the deque of entities.
     * @param operand Pointer to the entity to be added.
     */
    virtual void add(deque<Entity*>* second, Entity* operand) { return; }

    /**
     * @brief Adds an entity to another entity.
     * @param second Pointer to the second entity.
     * @param operand Pointer to the entity to be added.
     */
    virtual void add(Entity* second, Entity* operand) { return; }

    virtual ENUM_TIPO_VARIABILE get_tipo_operazione() { return ENUM_TIPO_VARIABILE::NONE_VAR;} ///< The type of the variable.
};

#endif // entity_hpp