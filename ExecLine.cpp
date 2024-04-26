#include "ExecLine.h"

bool isNumeric(string number){
    char *p;
    long converted = strtol(number.c_str(), &p, 10);
    return *p ? false : true;
}
string strLower(string text){
    string res = text;
    transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
}
int getInstructionNumber(string instr){
    return instrToNum.count(instr) ? instrToNum[instr] : -1;
}
int getRegisterNumber(string r){
    if(r[0] == 'x'){
        int res = stoi(r.substr(1));
        return (res >= 0 && res < 32) ? res : -1;
    }else{
        return regToNum.count(r) ? regToNum[r] : -1;
    }
}
int getConstant(string number, map<string,int>& labelLocations){
    if(isNumeric(number)) return stoi(number);
    return labelLocations.count(number) ? labelLocations[number] : INT_MIN;
}
int getArgLayout(int instrN){
    return instrToArgs.count(instrN) ? instrToArgs[instrN] : -1;
}
pair<int,int> parseOffset(string ofs, map<string,int>& labelLocations){
    pair<int,int> res;
    res.first = getConstant(ofs.substr(0,ofs.find('(')), labelLocations);
    res.second = getRegisterNumber(ofs.substr(ofs.find('(')+1, ofs.find(')')-ofs.find('(')-1));
    return res;
}

ExecLine::ExecLine(string line, map<string,int>& labelLocations){
    string token;
    stringstream ss(line);
    queue<string> tkns;
    while(getline(ss, token, ' ')){
        tkns.push(token);
    }

    string instrStr = strLower(tkns.front());
    tkns.pop();
    instructionNumber = getInstructionNumber(instrStr);
    int argumentNumber = getArgLayout(instructionNumber);
    while(argumentNumber > 0){
        int argType = argumentNumber % 5;
        if(argType == 1){
            // registry
            args.push_back(getRegisterNumber(strLower(tkns.front())));
        }else if(argType == 2){
            // ofs(reg)
            pair<int,int> ofsPair = parseOffset(strLower(tkns.front()), labelLocations);
            args.push_back(ofsPair.first);
            args.push_back(ofsPair.second);
        }else if(argType == 3){
            // const
            args.push_back(getConstant(tkns.front(), labelLocations));
        }else if(argType == 4){
            // label
            args.push_back(labelLocations[tkns.front()]);
        }
        tkns.pop();
        argumentNumber /= 5;
    }

        // cout << line << endl;
        // cout << instructionNumber << " : ";
        // for(int j = 0; j < args.size(); j++){
        //     cout << args[j] << " | ";
        // }
        // cout << endl;
}