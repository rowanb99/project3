#include "DatalogProgram.h"

using namespace std;

//compare any way you like, here I am using the default string comparison
bool compareFunction(std::string a, std::string b) { return a < b; }


void DatalogProgram::PrintDatalog() {
    cout << "Success!" << endl;
    cout << "Schemes(" + to_string(schemesVector.size()) + "):" << endl;
    for (auto &i: schemesVector) {
        cout << "  " << i << endl;
    }
    cout << "Facts(" + to_string(factsVector.size()) + "):" << endl;
    for (auto &i: factsVector) {
        cout << "  " << i << endl;
    }
    cout << "Rules(" + to_string(rulesVector.size()) + "):" << endl;
    for (auto &i: rulesVector) {
        cout << "  " << i << endl;
    }
    cout << "Queries(" + to_string(queriesVector.size()) + "):" << endl;
    for (auto &i: queriesVector) {
        cout << "  " << i << endl;
    }
    std::sort(domainVector.begin(), domainVector.end(), compareFunction);//sort the vector
    vector<string>::iterator it;
    it = unique(domainVector.begin(), domainVector.end());
    domainVector.resize(distance(domainVector.begin(), it));
    cout << "Domain(" + to_string(domainVector.size()) + "):" << endl;
    for (auto &i: domainVector) {
        cout << "  " << i << endl;
    }
}


