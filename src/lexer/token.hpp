#ifndef token_hpp
#define token_hpp
#include "lexer_util.hpp"
#include <string>
#include <list>
#include <vector>


using namespace std;

class ast{
    public:
    virtual int is() = 0; // Metodo virtuale puro per il polimorfismo
    virtual ~ast() {} // Distruttore virtuale

    virtual string print(string p) {return "c";} // metodo virtuale per il polimorfismo
    
};



template <typename T>
class tokenList : public ast, public list<T>{
    public:
    using list<T>::list;

    int is() override {
        return 1;
    }

    string print(string t) {
        string temp=t;
        for (auto elem : *this) {
            temp += elem->print(t);
        }
        return temp;
    }

};





class util_token{
    static const short _integer=1;
    static const short _float_=2;
    static const short _string_=3;
};

  


class token: public ast {
    public:
    short category;
    
    string text;
    int line;
    int col;
    //VAL SALVATO IN VARIABILE

    int intval;
    string strval;
    float floatval;


    
    int is()override{
        return 0;

    }

    token() {}

    token(int category, string text, int col, int line) {
        this->col = col;
        this->line = line;
        this->category = category;
        this->text = text;
        
        cat();
    }

    token(int category, string text, int col, int line, char use) {
        this->col = col;
        this->line = line;
        this->category = category;
        this->text = text;
        cat();
    }



    string print(string p) {
        return this->text+",";
    }
    
    
    

    
    private:
    
    void cat(){
        switch (this->category){
        case Parser::INTLIT:
            this->intval = stoi(this->text);
            break;
        
        case Parser::FLOATLIT:
            this->floatval = stof(this->text);
            break;
        
        case Parser::STRINGLIT:
            this->strval = this->text[1, this->text.size()-2];
            break;

        
        default:
            break;
        }
    }

};












#endif // token_hpp


