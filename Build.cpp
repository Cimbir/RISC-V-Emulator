#include "Build.h"

Build::Build(vector<ExecLine> lines){
    programLines = lines;
    registers = new int[RegisterAmount];
    memory = new char[ProgramMemorySize];
    isFree = new bool[HeapStart];
    for(int i = 0; i < HeapStart; i++) isFree[i] = true;
    pc = 0;

    registers[zero] = 0;
    registers[sp] = StackStart;
}
void Build::Run(){
    for(; pc < programLines.size(); pc++){
        ExecuteLine(programLines[pc]);
    }
}

void Build::ExecuteLine(ExecLine line){
    if(line.instructionNumber == _add) ADD(line.args);
    else if(line.instructionNumber == _addi) ADDI(line.args);
    else if(line.instructionNumber == _sub) SUB(line.args);
    else if(line.instructionNumber == _subi) SUBI(line.args);
    else if(line.instructionNumber == _mul) MUL(line.args);
    else if(line.instructionNumber == _muli) MULI(line.args);
    else if(line.instructionNumber == _div) DIV(line.args);
    else if(line.instructionNumber == _divi) DIVI(line.args);
    else if(line.instructionNumber == _blt) BLT(line.args);
    else if(line.instructionNumber == _ble) BLE(line.args);
    else if(line.instructionNumber == _beq) BEQ(line.args);
    else if(line.instructionNumber == _bne) BNE(line.args);
    else if(line.instructionNumber == _bgt) BGT(line.args);
    else if(line.instructionNumber == _bge) BGE(line.args);
    else if(line.instructionNumber == _j) J(line.args);
    else if(line.instructionNumber == _call) CALL(line.args);
    else if(line.instructionNumber == _lb) LB(line.args);
    else if(line.instructionNumber == _lh) LH(line.args);
    else if(line.instructionNumber == _lw) LW(line.args);
    else if(line.instructionNumber == _sb) SB(line.args);
    else if(line.instructionNumber == _sh) SH(line.args);
    else if(line.instructionNumber == _sw) SW(line.args);
    else if(line.instructionNumber == _jal) JAL(line.args);
    else if(line.instructionNumber == _jr) JR(line.args);
    else if(line.instructionNumber == _jalr) JALR(line.args);
    else if(line.instructionNumber == _ret) RET(line.args);
    else if(line.instructionNumber == _mv) MV(line.args);
    else if(line.instructionNumber == _li) LI(line.args);
    else if(line.instructionNumber == _neg) NEG(line.args);
    else if(line.instructionNumber == _slli) SLLI(line.args);
    else if(line.instructionNumber == _srli) SRLI(line.args);
    else if(line.instructionNumber == _or) OR(line.args);
    else if(line.instructionNumber == _and) AND(line.args);
    else if(line.instructionNumber == _xor) XOR(line.args);
    else if(line.instructionNumber == _not) NOT(line.args);
    else if(line.instructionNumber == _ecall) ECALL(line.args);

    else if(line.instructionNumber == _printf) PRINTF(line.args);
    else if(line.instructionNumber == _memcmp) MEMCMP(line.args);
    else if(line.instructionNumber == _memcpy) MEMCPY(line.args);
    else if(line.instructionNumber == _memmove) MEMMOVE(line.args);
    else if(line.instructionNumber == _memset) MEMSET(line.args);
    else if(line.instructionNumber == _strlen) STRLEN(line.args);

    else if(line.instructionNumber == _malloc) MALLOC(line.args);
    else if(line.instructionNumber == _realloc) REALLOC(line.args);
    else if(line.instructionNumber == _free) FREE(line.args);
}

void Build::ADD(vector<int>& args){
    registers[args[0]] = registers[args[1]] + registers[args[2]];
}
void Build::ADDI(vector<int>& args){
    registers[args[0]] = registers[args[1]] + args[2];
}
void Build::SUB(vector<int>& args){
    registers[args[0]] = registers[args[1]] - registers[args[2]];
}
void Build::SUBI(vector<int>& args){
    registers[args[0]] = registers[args[1]] - args[2];
}
void Build::MUL(vector<int>& args){
    registers[args[0]] = registers[args[1]] * registers[args[2]];
}
void Build::MULI(vector<int>& args){
    registers[args[0]] = registers[args[1]] * args[2];
}
void Build::DIV(vector<int>& args){
    registers[args[0]] = registers[args[1]] / registers[args[2]];
}
void Build::DIVI(vector<int>& args){
    registers[args[0]] = registers[args[1]] / args[2];
}
void Build::BLT(vector<int>& args){
    if(registers[args[0]] < registers[args[1]]) pc = args[2]-1;
}
void Build::BLE(vector<int>& args){
    if(registers[args[0]] <= registers[args[1]]) pc = args[2]-1;
}
void Build::BEQ(vector<int>& args){
    if(registers[args[0]] == registers[args[1]]) pc = args[2]-1;
}
void Build::BNE(vector<int>& args){
    if(registers[args[0]] != registers[args[1]]) pc = args[2]-1;
}
void Build::BGT(vector<int>& args){
    if(registers[args[0]] > registers[args[1]]) pc = args[2]-1;
}
void Build::BGE(vector<int>& args){
    if(registers[args[0]] >= registers[args[1]]) pc = args[2]-1;
}
void Build::J(vector<int>& args){
    pc = args[0]-1;
}
void Build::CALL(vector<int>& args){
    registers[ra] = pc;
    pc = args[0]-1;
}
void Build::LB(vector<int>& args){
    registers[args[0]] = *(char*)(memory + args[1] + registers[args[2]]);
}
void Build::LH(vector<int>& args){
    registers[args[0]] = *(short*)(memory + args[1] + registers[args[2]]);
}
void Build::LW(vector<int>& args){
    registers[args[0]] = *(int*)(memory + args[1] + registers[args[2]]);
}
void Build::SB(vector<int>& args){
    *(char*)(memory + args[1] + registers[args[2]]) = registers[args[0]];
}
void Build::SH(vector<int>& args){
    *(short*)(memory + args[1] + registers[args[2]]) = registers[args[0]];
}
void Build::SW(vector<int>& args){
    *(int*)(memory + args[1] + registers[args[2]]) = registers[args[0]]; 
}
void Build::JAL(vector<int>& args){
    registers[ra] = pc;
    pc = args[0]-1;
}
void Build::JR(vector<int>& args){
    pc = registers[args[0]]-1;
}
void Build::JALR(vector<int>& args){
    registers[ra] = pc;
    pc = registers[args[0]]-1;
}
void Build::RET(vector<int>& args){
    pc = registers[ra];
}
void Build::MV(vector<int>& args){
    registers[args[0]] = registers[args[1]];
}
void Build::LI(vector<int>& args){
    registers[args[0]] = args[1];
}
void Build::NEG(vector<int>& args){
    registers[args[0]] = 0 - registers[args[1]];
}
void Build::SLLI(vector<int>& args){
    registers[args[0]] = registers[args[1]] << args[2];
}
void Build::SRLI(vector<int>& args){
    registers[args[0]] = registers[args[1]] >> args[2];
}
void Build::OR(vector<int>& args){
    registers[args[0]] = registers[args[1]] | registers[args[2]];
}
void Build::AND(vector<int>& args){
    registers[args[0]] = registers[args[1]] & registers[args[2]];
}
void Build::XOR(vector<int>& args){
    registers[args[0]] = registers[args[1]] ^ registers[args[2]];
}
void Build::NOT(vector<int>& args){
    registers[args[0]] = registers[args[1]] ^ -1;
}
void Build::ECALL(vector<int>& args){
    int displayFormat = registers[10];
    int displayInfo = registers[11];
    if(displayFormat == 1){
        cout << displayInfo;
    }else if(displayFormat == 10){
        pc = programLines.size();
    }else if(displayFormat == 11){
        cout << (char)displayInfo;
    }
}

void Build::PRINTF(vector<int>& args){
    int resAddr = args[0]+registers[args[1]];
    string res = "";
    while(memory[resAddr] != 0) res += memory[resAddr++];
    cout << res;
}
void Build::MEMCMP(vector<int>& args){
    char* first = memory+args[1]+registers[args[2]];
    char* second = memory+args[3]+registers[args[4]];
    int n = registers[args[5]];
    int res = 0;
    for(int i = 0; i < n; i++){
        if(*(first+i) != *(second+i)){
            if(*(first+i)-*(second+i) > 0) res = 1;
            else res = -1;
            break;
        }
    }
    registers[args[0]] = res;
}
void Build::MEMCPY(vector<int>& args){
    char* first = memory+args[0]+registers[args[1]];
    char* second = memory+args[2]+registers[args[3]];
    int n = registers[args[4]];
    for(int i = 0; i < n; i++) first[i] = second[i];
}
void Build::MEMMOVE(vector<int>& args){
    char* first = memory+args[0]+registers[args[1]];
    char* second = memory+args[2]+registers[args[3]];
    int n = registers[args[4]];
    char* tmp = (char*)malloc(n);
    for(int i = 0; i < n; i++) tmp[i] = second[i];
    for(int i = 0; i < n; i++) first[i] = tmp[i]; 
    free(tmp);
}
void Build::MEMSET(vector<int>& args){
    char* addr = memory+args[0]+registers[args[1]];
    int elem = registers[args[2]];
    int n = registers[args[3]];
    for(int i = 0; i < n; i++) addr[i] = elem;
}
void Build::STRLEN(vector<int>& args){
    int resAddr = args[1]+registers[args[2]];
    int res = 0;
    while(memory[resAddr++] != 0) res++;
    registers[args[0]] = res;
}

void Build::MALLOC(vector<int>& args){
    int size = registers[args[1]];
    int curSize = 0;
    for(int i = HeapStart-1; i >= 0; i--){
        if(isFree[i]) curSize++;
        else curSize = 0;

        if(curSize == size){
            int resAddr = i;
            for(int j = 0; j < size; j++) isFree[i+j] = false;
            addrToSize[resAddr] = size;
            registers[args[0]] = resAddr;
            break;
        }
    }

    Error("No place found to allocate memory");
}
void Build::REALLOC(vector<int>& args){
    int resAddr = registers[args[1]];
    int oldSize = addrToSize[resAddr];
    int newSize = registers[args[2]];
    if(oldSize >= newSize){
        Error("New size can't be smaller or equal to old size");
        return;
    }

    // check if can expand where it is
    int tmpSize = oldSize;
    for(int i = resAddr+oldSize; i < HeapStart; i++){
        if(isFree[i]) tmpSize++;
        else break;

        if(tmpSize == newSize){
            for(int j = 0; j < newSize; j++) isFree[resAddr+j] = false;
            addrToSize[resAddr] = newSize;
            registers[args[0]] = resAddr;
            return;
        } 
    }

    // save memory info
    char* info = (char*)malloc(oldSize);
    for(int i = 0; i < oldSize; i++) info[i] = memory[resAddr+i]; 

    // if not, first free the current memory
    for(int i = 0; i < oldSize; i++) isFree[resAddr+i] = true;
    addrToSize.erase(resAddr);

    // then find an empty place big enough
    int curSize = 0;
    for(int i = HeapStart-1; i >= 0; i--){
        if(isFree[i]) curSize++;
        else curSize = 0;

        if(curSize == newSize){
            int resAddr = i;
            for(int j = 0; j < newSize; j++) isFree[i+j] = false;
            for(int j = 0; j < oldSize; j++) memory[resAddr+j] = info[j];
            addrToSize[resAddr] = newSize;
            registers[args[0]] = resAddr;
            free(info);
            break;
        }
    }
    free(info);

    Error("No place found to allocate memory");
}
void Build::FREE(vector<int>& args){
    int resAddr = registers[args[0]];
    if(!addrToSize.count(resAddr)){
        Error("Incorrect pointer for free()");
        return;
    }
    int size = addrToSize[resAddr];
    for(int i = 0; i < size; i++) isFree[resAddr+i] = true;
    addrToSize.erase(resAddr);
}

void Build::Error(string message){
    cout << message << endl;
    pc = programLines.size();       
}