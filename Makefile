NAME =					so_long

LIBFT = 				${LIBFT_PATH}/libft.a
LIBFT_PATH = 			libraries/libft

MINILIBX =				${MINILIBX_PATH}/libmlx.a
MINILIBX_PATH =			libraries/minilibx

SOURCES_FILES =			main.c
OBJECTS_FILES =			${SOURCES_FILES:.c=.o}
SOURCES_PATH =			sources
OBJECTS_PATH =			objects

SOURCES =				$(addprefix ${SOURCES_PATH}/, ${SOURCES_FILES})
OBJECTS =				$(addprefix ${OBJECTS_PATH}/, ${OBJECTS_FILES})
HEADER =				${SOURCES_PATH}/so_long.h

REMOVE =				rm -rf
CC =					cc -Wall -Wextra -Werror
MLXFLAGS =				-lXext -lX11

all:					${NAME}

${NAME}:				${OBJECTS_PATH} ${OBJECTS} ${HEADER} ${LIBFT} ${MINILIBX} Makefile
						${CC} ${OBJECTS} ${LIBFT} ${MINILIBX} ${MLXFLAGS} -o ${NAME}

${OBJECTS_PATH}:
						mkdir $@

${OBJECTS_PATH}/%.o:	${SOURCES_PATH}/%.c | ${OBJECTS_PATH}
						${CC} -c $< -o $@

${LIBFT}:
						${MAKE} -C ${LIBFT_PATH}

${MINILIBX}:
						${MAKE} -C ${MINILIBX_PATH}

clean:
						$(MAKE) -C $(LIBFT_PATH) clean
						$(MAKE) -C $(MINILIBX_PATH) clean
						${REMOVE} ${OBJECTS_PATH}

fclean:					clean
						$(MAKE) -C $(LIBFT_PATH) fclean
						${REMOVE} ${NAME}

re:						fclean all

.PHONY:					all clean fclean re
