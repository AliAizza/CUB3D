src = *.c ./getnext_line/*.c
CUB3D = CUB3D
FLAGS =  -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g3
CC = cc

all : CUB3D
	
$(CUB3D): $(src)	
	@$(CC) $(FLAGS) $(src) -o CUB3D
	@tput setaf 2; echo "CUB3D IS READY"

clean :
	@rm -f CUB3D
	@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean

re: fclean all
