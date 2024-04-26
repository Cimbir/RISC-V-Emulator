# RISC-V Emulator

## Running on tests

To be sure, always compile again before running
```sh
g++ *.h *.cpp
```

and then run
```sh
./a.out
```

To add more tests, just place them in `Tests/default_commands`. The program will first run the emulator and then compare the result with the one venus.jar returned

C standard library tests are not present, but their examples are shown in `Tests/standard_library` directory

## C standard library command descriptions

| Name | Syntax | Description |
|------|--------|-------------|
| printf | printf offset(rs) | writes out the characters from memory of given address until character is 0 |
| memcmp | memcmp rs1, offset(rs), offset(rs), rs2 | reads rs2 amount of characters from first and second addresses and writes answer in rs1. if first > second, answer is 1, if first < second, -1, otherwise 0 |
| memcpy | memcpy offset(rs), offset(rs), rs1 | copies rs1 amount of bytes from second address(src) to first address(dest). messes up if memory blocks overlap |
| memmove | memmove offset(rs), offset(rs), rs1 | moves rs1 amount of bytes from second address(src) to first address(dest). doesn't mess up if memory blocks overlap |
| memset | memset offset(rs) rs1 rs2 | sets rs2 amount of bytes at memory address to equal rs1 (least significant byte information) | 
| strlen | strlen rs1 offset(rs) | reads characters from memory address until character is 0. returns the result in rs1 |
| malloc | malloc rs1 rs2 | allocates rs2 amount of bytes of memory and returns address to rs1 |
| realloc | realloc rs1 rs2 rs3 | reallocates rs3 amount of bytes to memory block at rs2 and returns the new address to rs1 |
| free | free rs1 | frees allocated data at rs1 |