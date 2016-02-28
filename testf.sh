rm ./a.out
make fclean
make aclean
gcc mainf.c libftprintf.a
./a.out # | cat -e
