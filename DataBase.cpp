#include "DataBase.h"

void DataBase::AddRelation(Relation* newRelation) {
    relations.insert(pair<string, Relation*>(newRelation->GetName(), newRelation));
}

Relation* DataBase::GetRelation(string relationName) {
    return relations[relationName];
}

Relation DataBase::GetRelationCopy(string relationName) {
    return *relations[relationName];
}
