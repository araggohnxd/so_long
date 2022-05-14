NAME =				libft.a

SRCS =				ft_atoi.c ft_calloc.c ft_bzero.c ft_isalnum.c \
					ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
					ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
					ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
					ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
					ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c \
					ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
					ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_newlinecpy.c \
					ft_get_next_line.c ft_printf.c ft_itoa_base.c \
					ft_handler_character.c ft_handler_decimal.c \
					ft_handler_percent.c ft_handler_hex_lower.c \
					ft_handler_hex_upper.c ft_handler_pointer.c \
					ft_handler_string.c ft_handler_unsigned.c \
					ft_strjoin_free.c ft_free_split.c
OBJ_FILES =			${SRCS:.c=.o}
OBJS =				${addprefix ${OBJS_PATH}/, ${OBJ_FILES}}

BONUS_SRCS =		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
					ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
					ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJ_FILES =	${BONUS_SRCS:.c=.o}
BONUS_OBJS =		${addprefix ${OBJS_PATH}/, ${BONUS_OBJ_FILES}}

OBJS_PATH =			objects

HEAD =				libft.h
CC =				cc -Wall -Wextra -Werror
RM =				rm -rf

all:				${NAME}

${NAME}:			${OBJS_PATH} ${OBJS} ${HEAD} Makefile
					@ar -rcs ${NAME} ${OBJS}
					@echo [SUCCESS] Library creation done!

bonus:				${NAME} ${BONUS_OBJS} ${HEAD} Makefile
					@ar -rcs ${NAME} ${BONUS_OBJS}
					@echo [SUCCESS] Bonus library creation done!

${OBJS_PATH}/%.o:	%.c | ${OBJS_PATH}
					@${CC} -I . -c $< -o $@
					@echo [SUCCESS] ${@:objects/%=%} object created!

${OBJS_PATH}:
					@mkdir -p $@
					@echo [SUCCESS] Objects directory created!

clean:
					@${RM} ${OBJS_PATH}
					@echo [SUCCESS] Objects removal done!

fclean:				clean
					@${RM} ${NAME}
					@echo [SUCCESS] Library removal done!

re:					fclean all

.PHONY:				all clean fclean re bonus
