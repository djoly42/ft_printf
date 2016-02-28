rm ./a.out
make fclean
make aclean
gcc mainD.c libftprintf.a
./a.out # | cat -e
