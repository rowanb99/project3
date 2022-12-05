#include "Interpreter.h"

void Interpreter::InterpretSchemes() {
    for (auto &&scheme : program->getSchemes()) {
        Header* header = new Header;
        vector<string> attributes;
        for (auto &&parameter : scheme->getParameters()) {
            attributes.push_back(parameter->toString());
        }
        header->setAttributeValues(attributes);
        Relation* emptyRelation = new Relation(scheme->getID(), header);
        database->AddRelation(emptyRelation);
    }
}

void Interpreter::InterpretFacts() {
    for (auto &&fact : program->getFacts()) {
        // get the corresponding table by reference from the database
        string factName = fact->getID(); // key for map
        Relation* table = new Relation;
        table = database->GetRelation(factName);
        vector<string> values;

        // turn the parameters into a tuple and add it to the corresponding relation
        for (auto &&parameter : fact->getParameters()) {
            values.push_back(parameter->toString());
        }
        Tuple tuple(values);
        table->AddTuple(tuple);
    }
    // cout << '\n' << database->testSchemesFacts(); // TESTING of Relation and Tuple structure
}

Relation* Interpreter::evaluatePredicate(Predicate& p) { // evaluates 1 query
    Relation* table = new Relation;
    Relation* newTable = new Relation; // new empty relation

    // get the relation with the same name as the query
    table = database->GetRelation(p.getID());
    map<string, int> variables; // string is the variable while int is the index

    // get the parameters and then do select, project, and rename
    vector<Parameter*> parameters = p.getParameters();
    vector<string> stringsBefore;
    vector<int> columnsToProject;
    bool wasAnywhere = false;
    bool duplicate = false;
    for (unsigned int i = 0; i < parameters.size(); i++) {
        //cout << parameters.at(i)->toString() << ", ";
        // if the parameter is a constant
        if (parameters.at(i)->toString()[0] == '\'') {
            //cout << "Parameter is a constant" << endl;
            string paramValue = parameters.at(i)->toString();
            if (!duplicate) {
                // run select1 on the relation
                newTable = table->select1(i, paramValue);
                //cout << newTable->toString();
                wasAnywhere = true;
                duplicate = true;
            }
            else {
                newTable = newTable->select1(i, paramValue);
                wasAnywhere = true;
            }
        }
        //cout << '\n' << newTable->toString();

        // if the parameter is a variable
        else  {
            //cout << "Parameter is a variable" << endl;
            int firstColumnIndex = 0;
            duplicate = false;
            for (unsigned int j = 0; j < stringsBefore.size(); j++) {
                if (parameters.at(i)->toString() == stringsBefore.at(j)) {
                    /*cout << "Duplicate" << endl;
                    cout << parameters.at(i)->toString();*/
                    duplicate = true;
                    firstColumnIndex = j;
                }
            }
            if (duplicate) {
                if (wasAnywhere) newTable = newTable->select2(firstColumnIndex, i);
                else newTable = table->select2(firstColumnIndex, i);
                wasAnywhere = true;
            }
            else {
                columnsToProject.push_back(i);
                stringsBefore.push_back(parameters.at(i)->toString());
                //cout << "Added to stringsBefore: " << stringsBefore[stringsBefore.size() - 1];
                // cout << "Column index added: " << i << '\n';
            }
        }
    }
    if (!wasAnywhere) {
        newTable->setHeader(table->GetHeader());
        newTable->setRows(table->getRows());
    }

    // with vector of the indexes at which variables were first seen, project out one column for each variable from the relation
    Relation* newTable2 = new Relation;
    //cout << newTable->toString();
    newTable2 = newTable->project(columnsToProject);

    // with vector of all variables found (no duplicates), rename the relation's header column names to the query variables
    newTable = newTable2->rename(stringsBefore);
    return newTable;
}

void Interpreter::InterpretQueries() {
    for (auto &&query : program->getQueries()) {
        cout << query->toString() << "? ";
        string queryName = query->getID();
        Relation* table = new Relation;
        table = evaluatePredicate(*query);
        if (table->isEmpty()) cout << "No\n";
        else {
            cout << "Yes(" << table->size() << ")\n";
            if (table->GetHeader()->getAttributes().size() != 0) {
                cout << table->toString(); // print out the resulting relation
            }
        }
    }
}