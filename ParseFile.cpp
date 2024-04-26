#include "ParseFile.h"

ParseFile::ParseFile(){

}

Build ParseFile::getBuild(string fileName){
    // reset variables for new build
    labelLocations.clear();
    displayLines.clear();
    lineInformation.clear();

    // read labels first
    readLabels(fileName);
    // analyse entire file after
    readFile(fileName);

    // return build
    return Build(lineInformation);
}

// trim code to correct format
string trim(
    const std::string& str,
    const std::string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}
string reduce(
    const std::string& str,
    const std::string& fill = " ",
    const std::string& whitespace = " \t")
{
    // trim first
    auto result = trim(str, whitespace);

    // replace sub ranges
    auto beginSpace = result.find_first_of(whitespace);
    while (beginSpace != std::string::npos)
    {
        const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
        const auto range = endSpace - beginSpace;

        result.replace(beginSpace, range, fill);

        const auto newStart = beginSpace + fill.length();
        beginSpace = result.find_first_of(whitespace, newStart);
    }

    return result;
}

void ParseFile::readLabels(string fileName){
    ifstream infile(fileName);

    string line;
    int pc = 0;
    while(getline(infile, line)){
        // clean lines
        line = reduce(line); // from whitespace
        line = line.substr(0, line.find('#')); // from comments
        if(line.size() == 0) continue;

        if(line[line.length()-1] == ':'){
            labelLocations[line.substr(0,line.size()-1)] = pc;
        }else{
            pc++;
        }
    }
}
void ParseFile::readFile(string fileName){
    ifstream infile(fileName);

    int i = 0;
    string line;
    while(getline(infile, line)){
        // clean line
        line = reduce(line); // from whitespace 
        line = line.substr(0, line.find('#')); // from comments
        if(line.size() == 0) continue;
        line = reduce(line, " ", ","); // from commas
        line = reduce(line); // after comma reduction

        // check as label or executable line
        string res = "";
        if(line[line.size()-1] == ':'){
            res = "label : " + line + " (" + to_string(labelLocations[line.substr(0,line.size()-1)]) + ")";
        }else{
            res = "exec : " + line + " (" + to_string(i) + ")";
            i++;
            lineInformation.push_back(ExecLine(line,labelLocations));
        }

        displayLines.push_back(res);
    }
}

void ParseFile::printLines(){
    for(int i = 0; i < displayLines.size(); i++){
        cout << displayLines[i] << endl;
    }
};