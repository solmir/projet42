# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alelievr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/15 15:13:38 by alelievr          #+#    #+#              #
#    Updated: 2016/02/03 17:35:36 by jromagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Sources
SRCDIR		=	src
SRC			=	main.c				\
				main_loop.c			\
				callback.c			\
				client.c			\
				connection.c		\
				skybox.c			\

#	Objects
OBJDIR		=	obj

#	Includes
INCFLAGS	=	-I include -Ilibft -Iglfw-3.1.2/include/GLFW -ISOIL/src

#	Libraries
LDFLAGS		=	-Llibft -Lglfw-3.1.2/build/src -LSOIL/lib
LDLIBS		=	-lft -lglfw3 -lsoil

#	Output
NAME		=	visualisatron

#	Compiler
CC			=	clang
CFLAGS		=	-Wall -Wextra -pedantic -Wno-deprecated
OPTFLAGS	=	-pipe -funroll-loops -Ofast
DEBUGFLAGS	=	-ggdb
CPROTECTION	=	-z execstack -fno-stack-protector

#	Framework
FRAMEWORK	=	OpenGL AppKit CoreVideo IOKit GLUT

#################
##  COLORS     ##
#################
CPREFIX		=	"\033[38;5;"
BGPREFIX	=	"\033[48;5;"
CCLEAR		=	"\033[0m"
CLINK_T		=	$(CPREFIX)"129m"
CLINK		=	$(CPREFIX)"93m"
COBJ_T		=	$(CPREFIX)"119m"
COBJ		=	$(CPREFIX)"113m"
CCLEAN_T	=	$(CPREFIX)"9m"
CCLEAN		=	$(CPREFIX)"166m"
CRUN_T		=	$(CPREFIX)"198m"
CRUN		=	$(CPREFIX)"163m"
CNORM_T		=	"226m"
CNORM_ERR	=	"196m"
CNORM_WARN	=	"202m"
CNORM_OK	=	"231m"

#################
##  AUTO       ##
#################

OBJ			=	$(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))
NORME		=	**/*.[ch]
VPATH		+=	$(dir $(addprefix $(SRCDIR)/,$(SRC)))
VFRAME		=	$(addprefix -framework ,$(FRAMEWORK))
OS			:=	$(shell uname -s)
PROSS		:=	$(shell uname -p)

disp_indent	=	for I in `seq 1 $(MAKELEVEL)`; do \
					test "$(MAKELEVEL)" '!=' '0' && printf "\t"; \
				done
color_exec	=	$(call disp_indent); \
				echo $(1)➤ $(3)$(2)"\n"$(strip $(4))$(CCLEAR);$(4)
color_exec_t=	$(call disp_indent); \
				echo $(1)➤ $(strip $(3))$(2)$(CCLEAR);$(3)

#################
##  OS/PROSS   ##
#################

ifeq ($(OS),Windows_NT)
	CFLAGS += -D WIN32
endif
ifeq "$(OS)" "Linux"
	LDLIBS += -lgnu -lm
endif
ifeq "$(OS)" "Darwin"
	CFLAGS += -D DARWIN
endif
ifeq ($(PROSS),x86_64)
	CFLAGS += -D AMD64
endif
ifneq ($(filter %86,$(PROSS)),)
	CFLAGS += -D IA32
endif
ifneq ($(filter arm%,$(PROSS)),)
	CFLAGS += -D ARM
endif

#################
##  TARGETS    ##
#################

#	First target
all: glfw_build $(NAME)

glfw-3.1.2/build/src/libglfw3.a:
	@mkdir -p glfw-3.1.2/build && cd glfw-3.1.2/build; cmake .. && make

glfw_build: glfw-3.1.2/build/src/libglfw3.a

#	Linking
$(NAME): $(OBJ)
	@$(call color_exec_t,$(CCLEAR),$(CCLEAR),\
		make -C libft)
	@$(call color_exec_t,$(CCLEAR),$(CCLEAR),\
		make -C SOIL)
	@$(call color_exec,$(CLINK_T),$(CLINK),"Link of $(NAME):",\
		$(CC) $(LDFLAGS) $(OPTFLAGS) $(DEBUGFLAGS) $(LDLIBS) $(VFRAME) -o $@ $^)

#	Objects compilation
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(call color_exec,$(COBJ_T),$(COBJ),"Object: $(notdir $@)",\
		$(CC) $(CFLAGS) $(OPTFLAGS) $(DEBUGFLAGS) $(INCFLAGS) -o $@ -c $<)

#	Removing objects
clean:
	@$(call color_exec,$(CCLEAN_T),$(CCLEAN),"Clean:",\
		$(RM) $(OBJ))
	@rm -rf $(OBJDIR)

#	Removing objects and exe
fclean: clean
	@$(call color_exec,$(CCLEAN_T),$(CCLEAN),"Fclean:",\
		$(RM) $(NAME))

#	All removing then compiling
re: fclean all

f:	all run

#	Checking norme
norme:
	@norminette $(NORME) | sed "s/Norme/[38;5;$(CNORM_T)➤ [38;5;$(CNORM_OK)Norme/g;s/Warning/[0;$(CNORM_WARN)Warning/g;s/Error/[0;$(CNORM_ERR)Error/g"

run: $(NAME)
	@echo $(CRUN_T)"➤ "$(CRUN)"./$(NAME) ${ARGS}\033[0m"
	@./$(NAME) ${ARGS}

codesize:
	@cat $(NORME) |grep -v '/\*' |wc -l

functions: $(NAME)
	@nm $(NAME) | grep U

coffee:
	@clear
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "                 ("
	@echo "	                  )      ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""       )   (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "               ("
	@echo "	                  )     ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'

.PHONY: all clean fclean re norme codesize
