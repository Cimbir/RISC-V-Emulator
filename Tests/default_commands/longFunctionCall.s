# main(){
#   int i = 4;
#   int j = 5;
#   j = foo(i,j);
# }
# foo(int i, int j){
#   return i * bar(i,j);
# }
# bar(int i, int j){
#   return i + j;
# }

.text
main:

# grow stack
addi sp, sp, -8

# i = 3
li x10, 4
sw x10, 4(sp)
# j = 5
li x10, 5
sw x10, 0(sp)

# grow for args
addi sp, sp, -8
# i as arg0
lw x10, 12(sp)
sw x10, 0(sp)
# j as arg1
lw x10, 8(sp)
sw x10, 4(sp)
# foo(i,j)
call foo
# shrink for args
addi sp, sp, 8

# shrink stack
addi sp, sp, 8

mv x11, x10
li x10, 1
ecall

li x10, 10
ecall

# return at x10
foo:
# grow for ra
addi sp, sp, -4
sw ra, 0(sp)

lw x10, 4(sp) # res = arg0

# grow for args
addi sp, sp, -8
# i as arg0
lw x11, 12(sp)
sw x11, 0(sp)
# j as arg1
lw x11, 16(sp)
sw x11, 4(sp)
# foo(i,j)
call bar
# shrink for args
addi sp, sp, 8

# res = i * bar(i,j);
mul x10, x10, x11

lw ra, 0(sp)
# shrink for ra
addi sp, sp 4
ret

# return at x11
bar:
# grow for ra
addi sp, sp, -4
sw ra, 0(sp)

lw x11, 4(sp) # res = arg0
lw x12, 8(sp) # tmp = arg1
add x11, x11, x12 # res = res + tmp

lw ra, 0(sp)
# shrink for ra
addi sp, sp, 4
ret