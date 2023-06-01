#----Common-Var------------------------------------------------------------
CC				=		cc
FLAGS			=		-Wall -Wextra -Werror
RM				=		rm -rf
OBJS_DIR		=		.OBJS/
#----Server-Var------------------------------------------------------------
SRC_SERV		=		src_server/server.c src_server/utils_server.c
OBJ_SERV		=		$(addprefix $(OBJS_DIR), $(SRC_SERV:.c=.o))
HEADER_SERV		=		src_server/server.h
#----Client-Var------------------------------------------------------------
SRC_CLI			=		src_client/client.c src_client/utils_client.c
OBJ_CLI			=		$(addprefix $(OBJS_DIR), $(SRC_CLI:.c=.o))
HEADER_CLI		=		src_client/client.h

all:					Server Client

Server:					$(OBJ_SERV)
						$(CC) $(FLAGS) -I $(HEADER_SERV) $(OBJ_SERV) -o server

Client:					$(OBJ_CLI)
						$(CC) $(FLAGS) -I $(HEADER_CLI) $(OBJ_CLI) -o client

$(OBJS_DIR)%.o:			%.c Makefile | dir
						$(CC) $(FLAGS) -c $< -o $@


dir:
						@mkdir -p $(OBJS_DIR)
						@mkdir -p $(OBJS_DIR)src_server
						@mkdir -p $(OBJS_DIR)src_client

clean:
						$(RM) $(OBJS_DIR)

fclean:					clean
						$(RM) Server Client

re:						fclean all