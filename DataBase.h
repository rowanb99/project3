#ifndef DATABASE_H
#define DATABASE_H
#include "Relation.h"
#include "Header.h"
#include "Tuple.h"
#include <map>
#include <string>
#include <sstream>

class DataBase {
private:
    map<string, Relation*> relations;
    // string is ID of predicate
    // Relation is just the container
    // header is the parameters of the scheme
    // tuples are the parameters of the facts
public:
    DataBase() {};
    void AddRelation(Relation* newRelation);
    Relation* GetRelation(string relationName); // TODO does this allow pass by reference???
    Relation GetRelationCopy(string relationName);
    string testSchemesFacts() { // TESTING of Relation and Tuple structure
        stringstream s;
        for (auto& item : relations) {
            s << "Relation name: " << item.first << "\nTable: \n" << item.second->toString();
        }
        return s.str();
    }
};

#endif //DATABASE_H
