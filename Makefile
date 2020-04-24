##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC_NO_TEST			=	src/main.c

SRC_TEST			=	src/lem_in.c						\
						src/room.c							\
						src/ant.c							\
						src/generate_anthill.c				\
						src/generation/add_room.c			\
						src/generation/add_tunnel.c			\
						src/generation/set_nb_ants.c		\
						src/generation/error_check.c		\
						src/generation/find_room_by.c		\
						src/print_anthill.c					\
						src/pathfinding/pathfinding.c		\
						src/pathfinding/keep_track.c		\
						src/pathfinding/valid_room.c		\
						src/pathfinding/select_rooms.c		\
						src/pathfinding/move_ants.c			\
						src/pathfinding/heuritmics.c

SRC					=	$(SRC_NO_TEST) $(SRC_TEST)

CFLAGS				=	-Wall -Wextra

CPPFLAGS			=	-I./include/

override LDFLAGS	+=	-L./lib

override LDLIBS		+=	-lmy

OBJ					=	$(SRC:.c=.o)

NAME				=	lem_in

all:	$(NAME)

$(NAME):	CFLAGS += -O2
$(NAME):	$(LDLIBS) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

-lmy:
	$(MAKE) -s -C ./lib/my

tests_run:	CFLAGS += --coverage
tests_run:	LDLIBS += -lcriterion
tests_run:	$(LDLIBS)
	@find -name "*.gc*" -delete
	$(CC) -o unit_tests $(SRC_TEST) tests/*.c $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	-./unit_tests
	$(RM) unit_tests test*.gc*
	mkdir -p coverage
	mv *.gc* coverage/

debug:	CFLAGS += -g
debug:	$(LDLIBS)
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(LDLIBS) $(CFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) unit_tests *.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all -lmy tests_run debug clean fclean re
