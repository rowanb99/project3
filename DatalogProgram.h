#ifndef CS236_PROJECT_2_DATALOGPROGRAM_H
#define CS236_PROJECT_2_DATALOGPROGRAM_H
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class DatalogProgram {
public:

    //Finishes parsing by changing the vectors into a readable string for the executor
    void PrintDatalog();

    //Vector of all my schemes
    vector<string> schemesVector;

    //Vector of all my facts
    vector<string> factsVector;

    //Vector of all my rules
    vector<string> rulesVector;

    //Vector of all my queries
    vector<string> queriesVector;

    //Vector of all the strings in the domain
    vector<string> domainVector;

};


#endif //CS236_PROJECT_2_DATALOGPROGRAM_H
