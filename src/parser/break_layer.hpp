#ifndef break_layer_hpp
#define break_layer_hpp
#include "../syntax_analyzer/syntax_analyzer.hpp"



class break_point_layer{
public:
    static const short parentesis=0;
    static const short layer_1=1;
    static const short layer_2=2;
    static const short layer_3=3;
    static const short layer_4=4;
    static const short layer_5=5;
    static const short layer_6=6;
    static const short layer_7=7;
    static const short layer_8=8;
    static const short layer_9=9;
    static const short file=999;
};

class break_point_type{
public:
    static const short OPERAND=1;
    static const short PARENTESIS=2;
};

class break_point_entity{
public:
    short LAYER;
    list<Entity*>::iterator REF;
    short TYPE;
    short REF_TYPE;


    break_point_entity(short type, short layer, list<Entity*>::iterator ref, short ref_type ){
        this->LAYER=layer;
        this->REF=ref;
        this->TYPE=type;
        this->REF_TYPE=ref_type;
    }
    
    short get_layer(){
        return this->LAYER;
    }

    list<Entity*>::iterator get_ref(){
        return this->REF;
    }

    short get_ref_type(){
        return this->REF_TYPE;
    }

    short get_type(){
        return this->TYPE;
    }
};



bool is_blocking_symbol(deque<Entity*>::iterator ACTUAL){
    if((*ACTUAL)->getType()<500){
        return true; 
    }else{
        return false;
    }
}



short get_layer(short ACTUAL){
    switch (ACTUAL)
    {
    case 450:
        return break_point_layer::layer_1;  
        break;
    case 451:
        return break_point_layer::layer_2;
        break;
    case 452:
    case 453:
        return break_point_layer::layer_3;
        break;
    case 454:
        return break_point_layer::layer_4;
        break;
    case 455:
        return break_point_layer::layer_5;
        break;
    case 456:
        return break_point_layer::layer_6;
        break;
    case 457:
        return break_point_layer::layer_7;
        break;
    case 458:
        return break_point_layer::layer_8;
        break;
    case 459:
        return break_point_layer::layer_9;
        break;
    default:
        return -1;
        break;
    }
}


#endif
