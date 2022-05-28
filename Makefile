NAME =					so_long
NAME_BONUS =			${NAME}_bonus

LIBFT = 				${LIBFT_PATH}/libft.a
LIBFT_PATH = 			libraries/libft

MINILIBX =				${MINILIBX_PATH}/libmlx.a
MINILIBX_PATH =			libraries/minilibx

SOURCES_FILES =			so_long.c map_validation.c render_map.c controls.c \
						player_movement.c
OBJECTS_FILES =			${SOURCES_FILES:.c=.o}
SOURCES_PATH =			sources
OBJECTS_PATH =			objects

SOURCES =				$(addprefix ${SOURCES_PATH}/, ${SOURCES_FILES})
OBJECTS =				$(addprefix ${OBJECTS_PATH}/, ${OBJECTS_FILES})
HEADER =				${SOURCES_PATH}/so_long.h

SOURCES_FILES_BONUS =	so_long_bonus.c map_validation_bonus.c \
						render_map_bonus.c controls_bonus.c \
						player_movement_bonus.c init_images_bonus.c
OBJECTS_FILES_BONUS =	${SOURCES_FILES_BONUS:.c=.o}
SOURCES_PATH_BONUS =	${SOURCES_PATH}_bonus

SOURCES_BONUS =			$(addprefix ${SOURCES_PATH_BONUS}/, ${SOURCES_FILES_BONUS})
OBJECTS_BONUS =			$(addprefix ${OBJECTS_PATH}/, ${OBJECTS_FILES_BONUS})
HEADER_BONUS =			${SOURCES_PATH_BONUS}/so_long_bonus.h

REMOVE =				rm -rf
CC =					cc -g3 -Wall -Wextra -Werror
MLXFLAGS =				-lXext -lX11

all:					${NAME}

bonus:					${NAME_BONUS}

${NAME}:				${OBJECTS_PATH} ${OBJECTS} ${LIBFT} ${MINILIBX}
						${CC} ${OBJECTS} ${LIBFT} ${MINILIBX} ${MLXFLAGS} \
						-o ${NAME}

${NAME_BONUS}:			${OBJECTS_PATH} ${OBJECTS_BONUS} ${LIBFT} ${MINILIBX}
						${CC} ${OBJECTS_BONUS} ${LIBFT} ${MINILIBX} ${MLXFLAGS} \
						-o ${NAME_BONUS}

${OBJECTS_PATH}:
						mkdir -p $@

${OBJECTS_PATH}/%.o:	${SOURCES_PATH}/%.c ${HEADER} Makefile | ${OBJECTS_PATH}
						${CC} -c $< -o $@

${OBJECTS_PATH}/%.o:	${SOURCES_PATH_BONUS}/%.c ${HEADER_BONUS} Makefile | ${OBJECTS_PATH}
						${CC} -c $< -o $@

${LIBFT}:
						${MAKE} -C ${LIBFT_PATH} bonus

${MINILIBX}:
						${MAKE} -C ${MINILIBX_PATH}

run:					bonus
						./so_long_bonus maps/monsters.ber

vg:						bonus
						valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
						./so_long_bonus maps/monsters.ber

test:					all
						./tests/test.sh

clean:
						$(MAKE) -C $(LIBFT_PATH) clean
						$(MAKE) -C $(MINILIBX_PATH) clean
						${REMOVE} ${OBJECTS_PATH}

fclean:					clean
						$(MAKE) -C $(LIBFT_PATH) fclean
						${REMOVE} ${NAME} ${NAME_BONUS}

re:						fclean all

.PHONY:					all clean fclean re run vg
