
SRCS		= src/files.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c\
			src/lists.c\

OBJS		= ${SRCS:.c=.o}


#MFLAGS		= -L . -lmlx -framework OpenGL -framework AppKit

CFLAGS		=  -Wall -Werror -Wextra

NAME		= files

HEADER		= includes/files.h

RM			= rm -f


GC 			= gcc

#all:		${NAME}	${LIBMLX}


all:		${NAME}	

${NAME}:	${OBJS} ${HEADER}
			#${MAKE} -C ./so_long_mandatory/minilibx all
			#cp ./so_long_mandatory/minilibx/libmlx.a .
			${GC} ${CFLAGS} ${OBJS} -o  ${NAME}  


clean:		
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME} ${NAME_B}

re:			fclean all

re_bonus:	fclean bonus




