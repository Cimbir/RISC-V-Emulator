#ifndef __build__
#define __build__

#include "ExecLine.h"

class Build{
public:
    // Initialize build object by given executable lines
    Build(vector<ExecLine> lines);

    // Run the lines
    void Run();

private:
    // Executes a single line
    void ExecuteLine(ExecLine line);

    // Executable line list
    vector<ExecLine> programLines;
    // Program memory representation
    char* memory;
    // Register representation
    int* registers;
    
    // STACK:
    // PC representation
    int pc;

    // HEAP:
    // Tracks used heap memory location
    bool* isFree;
    // Addresses returned by malloc/realloc
    map<int,int> addrToSize;

    // Basic Commands(The same as in RISC-V)
    void ADD(vector<int>& args);
    void ADDI(vector<int>& args);
    void SUB(vector<int>& args);
    void SUBI(vector<int>& args);
    void MUL(vector<int>& args);
    void MULI(vector<int>& args);
    void DIV(vector<int>& args);
    void DIVI(vector<int>& args);
    void BLT(vector<int>& args);
    void BLE(vector<int>& args);
    void BEQ(vector<int>& args);
    void BNE(vector<int>& args);
    void BGT(vector<int>& args);
    void BGE(vector<int>& args);
    void J(vector<int>& args);
    void CALL(vector<int>& args);
    void LB(vector<int>& args);
    void LH(vector<int>& args);
    void LW(vector<int>& args);
    void SB(vector<int>& args);
    void SH(vector<int>& args);
    void SW(vector<int>& args);
    void JAL(vector<int>& args);
    void JR(vector<int>& args);
    void JALR(vector<int>& args);
    void RET(vector<int>& args);
    void MV(vector<int>& args);
    void LI(vector<int>& args);
    void NEG(vector<int>& args);
    void SLLI(vector<int>& args);
    void SRLI(vector<int>& args);
    void OR(vector<int>& args);
    void AND(vector<int>& args);
    void XOR(vector<int>& args);
    void NOT(vector<int>& args);
    void ECALL(vector<int>& args);

    void PRINTF(vector<int>& args);
    void MEMCMP(vector<int>& args);
    void MEMCPY(vector<int>& args);
    void MEMMOVE(vector<int>& args);
    void MEMSET(vector<int>& args);
    void STRLEN(vector<int>& args);

    void MALLOC(vector<int>& args);
    void REALLOC(vector<int>& args);
    void FREE(vector<int>& args);

    void Error(string message);
};

#endif