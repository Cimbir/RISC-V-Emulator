# main(){
#     int arr[4];
#     arr[0] = 2;
#     arr[1] = 32;
#     arr[2] = 0;
#     arr[3] = 10;

#     auxStr aux;
#     aux.max = 0;

#     mapFn(4,arr,getMax,aux);

#     printf("%d",aux.max);

#     return 0;
# }
# typedef struct auxStr{
#     int max;
# };
# void mapFn(int n, int* arr, mapFun* map, void* aux){
#     for(int i = 0; i < n; i++){
#         map(arr[i],aux);
#     }
# }
# mapFun getMax(int elem, void* aux){
#     if(elem > (*(auxStr*)aux)->max){
#         (*(auxStr*)aux)->max = elem;
#     }
# }

.text
main:
addi sp, sp, -20

# arr[0] = 2;
li x10, 2
sw x10, 4(sp)
# arr[1] = 32;
li x10, 3
sw x10, 8(sp)
# arr[2] = 0;
li x10, 20
sw x10, 12(sp)
# arr[3] = 10;
li x10, 10
sw x10, 16(sp)

# aux.max = 0;
li x10, 0
sw x10, 0(sp)

# mapFn(4,arr,getMax,aux);
addi sp, sp, -16
li x10, 4
sw x10, 0(sp) # 4
addi x10, sp, 20
sw x10, 4(sp) # arr
li x10, getMax
sw x10, 8(sp) # getMax
addi x10, sp, 16
sw x10, 12(sp) # aux
# mapFn()
call mapFn
addi sp, sp, 16

lw x11, 0(sp)
li x10, 1
ecall

addi sp, sp, 20
li x10 10
ecall



mapFn:
addi sp, sp, -8
sw ra, 4(sp)

li x10, 0
sw x10, 0(sp) # int i = 0;

# while(i < 4)
while_head:
lw x10, 0(sp) # i
lw x11, 8(sp) # 4
bge x10, x11, while_end


lw x10, 0(sp) # i
lw x11, 12(sp) # arr ptr
slli x10, x10, 2 # i*4
add x10, x11, x10 # arr[i] ptr
lw x10, 0(x10) # x10 = arr[i]
lw x11, 20(sp) # aux ptr
lw x12, 16(sp) # getMax ptr

addi sp, sp, -8
sw x10, 0(sp) # arg1 - arr[i]
sw x11, 4(sp) # arg2 - aux ptr
# map(arr[i],aux);
jalr x12
addi sp, sp, 8

# i++
lw x10, 0(sp)
addi x10, x10, 1
sw x10, 0(sp)

j while_head

while_end:
lw ra, 4(sp)
addi sp, sp, 8
ret



getMax:
# get max number logic
addi sp, sp, -4
sw ra, 0(sp)
# if(elem > (*(auxStr*)aux)->max)
lw x10, 4(sp) # elem
lw x11, 8(sp) # aux ptr
lw x11, 0(x11) # (*(auxStr*)aux)->max
bge x11, x10, not_max

# (*(auxStr*)aux)->max = elem;
lw x10, 8(sp) # aux ptr
lw x11, 4(sp) # elem
sw x11, 0(x10) # ->max = elem;

not_max:
lw ra, 0(sp)
addi sp, sp, 4
ret