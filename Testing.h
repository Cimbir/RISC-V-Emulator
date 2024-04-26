#ifndef __testing__
#define __testing__

#include "ParseFile.h"

class Testing{
public:
    Testing(ParseFile parf);
    bool TestDefault(string filename);
    void TestAll();

private:
    ParseFile pf;
    string getAnswer(string command);
};

#endif