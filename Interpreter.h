#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "DatalogProgram.h"
#include "DataBase.h"


class Interpreter {
private:
    DataLogProgram* program;
    DataBase* database;

public:
    Interpreter(DataLogProgram* program) {
        this->program = program;
        DataBase* database = new DataBase;
        this->database = database;
    }
    void InterpretSchemes();
    void InterpretFacts();
    Relation* evaluatePredicate(Predicate& p);
    void InterpretQueries();
};


#endif //INTERPRETER_H
