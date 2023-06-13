##
## EPITECH PROJECT, 2022
## make file
## File description:
## make file
##

SRC	=	src/main.c						\
		src/my_rpg.c					\
		src/system/get_usr_input.c		\
    src/system/getenv.c				\
		src/system/get_mouse_pos.c		\
		src/handle_movement.c			\
		src/draw_map.c					\
		src/camera_movement.c			\
		src/display_framerate.c			\
		src/init_rpg_values.c			\
		src/init_rpg_visuals.c			\
		src/ray_cast/draw_ray_cast.c	\
		src/ray_cast/utils_ray_cast.c	\
		src/ray_cast/get_hit_point.c	\
		src/init_entity.c				\
		src/init_other_rpg_vars.c \
		src/metal_pipe_handler.c \
		src/animate_entities.c			\
		src/load.c							\
		src/menu/draw_all_buttons.c			\
		src/menu/draw_button.c 				\
		src/menu/init_all_buttons.c 		\
		src/menu/init_button.c 				\
		src/menu/is_clicked.c 				\
		src/menu/is_hover.c 				\
		src/menu/main_menu.c 				\
		src/menu/settings_menu.c 			\
		src/menu/pause_menu.c 				\
		src/menu/assign_keybind.c			\
		src/reinit_rpg_values.c				\
		src/menu/update_all_buttons.c 		\
		src/menu/update_button.c 			\
		src/particle.c 						\
		src/hit_entity.c					\
		src/ray_cast/cot.c					\
		src/system/inventory.c 				\
		src/system/saves/fetch_save.c		\
		src/system/saves/save.c				\
		src/system/saves/getvalue.c			\
		src/system/saves/setvalue.c			\
		src/system/saves/delvalue.c			\
		src/system/saves/freesave.c			\
		src/system/saves/writesave.c \
		src/switch_level.c \
		src/freemem.c \
		src/shrek_movement.c \
		src/pathfinding.c \
		src/dialogs/create_dialogs.c \
		src/dialogs/display_dialogs.c \
		src/dialogs/init_dialogs.c \
		src/menu/level_selector.c \
		src/menu/end_screen.c \
		src/dialogs/free_dialogs.c	\
		src/utils.c	\
		src/handle_queu.c

TESTS_SRC = ./tests/tests_rpg.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS += -Wall -Wextra -Wshadow -Wimplicit

LDFLAGS += -L./lib -lmy -lm -lcsfml-graphics -lcsfml-audio \
-lcsfml-window -lcsfml-system

CPPFLAGS += -I./include

DEBUGFLAGS = -ggdb3 -fsanitize=address

all:	$(NAME)
PHONY	+= all

lib:
	make -C lib
PHONY += lib

$(NAME):	$(OBJ) lib
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

debug: lib
	gcc -o $(NAME) $(SRC) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS) $(DEBUGFLAGS)
PHONY += debug

clean:
	rm -f $(OBJ)
	make -C lib clean
	find -name "*.gc*" -delete
PHONY	+= clean

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests
	make -C lib fclean

PHONY	+= fclean

re:	fclean all
PHONY	+= re

run: $(OBJ) lib all
	./$(NAME)

compile_tests: lib
	gcc -o unit_tests $(filter-out src/main.c, $(SRC)) \
	$(TESTS_SRC) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS) --coverage -lcriterion
PHONY += compile_tests

tests_run: compile_tests
	./unit_tests
PHONY	+= tests_run

test: tests_run
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY:	$(PHONY)
