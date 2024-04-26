#ifndef __parse__
#define __parse__

#include "Build.h"

class ParseFile{
public:
    ParseFile();
    // Get runnable object by parsing and analysing the given ASM file
    Build getBuild(string fileName);

private:
    // Lines where pc should start when jumping to labels
    map<string,int> labelLocations;
    // String representation of the lines that will be analysed
    vector<string> displayLines;

    // Executable ASM lines
    vector<ExecLine> lineInformation;

    // Analyse labels from file
    void readLabels(string fileName);
    // Analyse the entire file to convert to executable lines(after analysing labels)
    void readFile(string fileName);

    // Display string representation of executable lines
    void printLines();
};

#endif