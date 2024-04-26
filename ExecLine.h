#ifndef __execLine__
#define __execLine__

#include "Constants.h"

class ExecLine{
public:
    int instructionNumber;
    vector<int> args;

    ExecLine(string line, map<string,int>& labelLocations);
private:
};

#endif