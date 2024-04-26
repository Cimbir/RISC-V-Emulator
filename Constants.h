#ifndef __constants__
#define __constants__

#include <bits/stdc++.h>

using namespace std;

// General
#define ll long long

// Register aliases
#define zero 0
#define ra 1
#define sp 2
#define gp 3
#define tp 4
#define t0 5
#define t1 6
#define t2 7
#define s0 8
#define s1 9
#define a0 10
#define a1 11
#define a2 12
#define a3 13
#define a4 14
#define a5 15
#define a6 16
#define a7 17
#define s2 18
#define s3 19
#define s4 20
#define s5 21
#define s6 22
#define s7 23
#define s8 24
#define s9 25
#define s10 26
#define s11 27
#define t3 28
#define t4 29
#define t5 30
#define t6 31

// Instruction numbers
#define _add 0
#define _addi 1
#define _sub 2
#define _subi 3
#define _mul 4
#define _muli 5
#define _div 6
#define _divi 7
#define _blt 8
#define _ble 9
#define _beq 10
#define _bne 11
#define _bgt 12
#define _bge 13
#define _j 14
#define _call 15
#define _lb 16
#define _lh 17
#define _lw 18
#define _sb 19
#define _sh 20
#define _sw 21
#define _jal 22
#define _jr 23
#define _jalr 24
#define _ret 25
#define _mv 26
#define _li 27
#define _neg 29
#define _slli 30
#define _srli 31
#define _or 32
#define _and 33
#define _xor 34
#define _not 35
#define _ecall 36

#define _printf 100
#define _memcmp 101
#define _memcpy 102
#define _memmove 103
#define _memset 104
#define _strlen 105

#define _malloc 200
#define _realloc 201
#define _free 202

// Arg types
#define _rrr 31
#define _rrc 81
#define _rrl 106
#define _l 4
#define _r 1
#define _ro 11
#define _none 0
#define _rr 6
#define _rc 16
#define _o 2
#define _c 3
#define _roor 186
#define _oor 37
#define _orr 32

// Program Constants
#define ProgramMemorySize 268435456
#define StackStart ((ProgramMemorySize*3)/4)
#define HeapStart (ProgramMemorySize/2)
#define RegisterAmount 32

inline map<string,int> regToNum =
{
    {"zero", zero},
    {"ra", ra},
    {"sp", sp},
    {"gp", gp},
    {"tp", tp},
    {"t0", t0},
    {"t1", t1},
    {"t2", t2},
    {"s0", s0},
    {"s1", s1},
    {"a0", a0},
    {"a1", a1},
    {"a2", a2},
    {"a3", a3},
    {"a4", a4},
    {"a5", a5},
    {"a6", a6},
    {"a7", a7},
    {"s2", s2},
    {"s3", s3},
    {"s4", s4},
    {"s5", s5},
    {"s6", s6},
    {"s7", s7},
    {"s8", s8},
    {"s9", s9},
    {"s10", s10},
    {"s11", s11},
    {"t3", t3},
    {"t4", t4},
    {"t5", t5},
    {"t6", t6}
};

inline map<string,int> instrToNum =
{
    {"add", _add},
    {"addi", _addi},
    {"sub", _sub},
    {"subi", _subi},
    {"mul", _mul},
    {"muli", _muli},
    {"div", _div},
    {"divi", _divi},
    {"blt", _blt},
    {"ble", _ble},
    {"beq", _beq},
    {"bne", _bne},
    {"bgt", _bgt},
    {"bge", _bge},
    {"j", _j},
    {"call", _call},
    {"lb", _lb},
    {"lh", _lh},
    {"lw", _lw},
    {"sb", _sb},
    {"sh", _sh},
    {"sw", _sw},
    {"jal", _jal},
    {"jr", _jr},
    {"jalr", _jalr},
    {"ret", _ret},
    {"mv", _mv},
    {"li", _li},
    {"neg", _neg},
    {"slli", _slli},
    {"srli", _srli},
    {"or", _or},
    {"and", _and},
    {"xor", _xor},
    {"not", _not},
    {"ecall", _ecall},

    {"printf", _printf},
    {"memcmp", _memcmp},
    {"memcpy", _memcpy},
    {"memmove", _memmove},
    {"memset", _memset},
    {"strlen", _strlen},

    {"malloc", _malloc},
    {"realloc", _realloc},
    {"free", _free}
};

inline map<int,int> instrToArgs = 
{
    {_add, _rrr},
    {_addi, _rrc},
    {_sub, _rrr},
    {_subi, _rrc},
    {_mul, _rrr},
    {_muli, _rrc},
    {_div, _rrr},
    {_divi, _rrc},
    {_blt, _rrl},
    {_ble, _rrl},
    {_beq, _rrl},
    {_bne, _rrl},
    {_bgt, _rrl},
    {_bge, _rrl},
    {_j, _l},
    {_call, _l},
    {_lb, _ro},
    {_lh, _ro},
    {_lw, _ro},
    {_sb, _ro},
    {_sh, _ro},
    {_sw, _ro},
    {_jal, _l},
    {_jr, _r},
    {_jalr, _r},
    {_ret, _none},
    {_mv, _rr},
    {_li, _rc},
    {_neg, _rr},
    {_slli, _rrc},
    {_srli, _rrc},
    {_or, _rrr},
    {_and, _rrr},
    {_xor, _rrr},
    {_not, _rr},
    {_ecall, _none},

    {_printf, _o},
    {_memcmp, _roor},
    {_memcpy, _oor},
    {_memmove, _oor},
    {_memset, _orr},
    {_strlen, _ro},

    {_malloc, _rr},
    {_realloc, _rrr},
    {_free, _r}
};

#endif