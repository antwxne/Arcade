##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

#SHARED

SHARED_SRC =	AGame.cpp	\
				Object/MovableObject.cpp	\
				Object/StaticObject.cpp	\
				../Graphic/Drawable.cpp

SHARED_OBJ =	$(SHARED_SRC:.cpp=.o)

#################################################################################

#NIBBLER SOURCES

NIBBLER_SRC =	Nibbler/Nibbler.cpp

NIBBLER_OBJ =	$(NIBBLER_SRC:.cpp=.o)

NIBBLER_NAME	=	arcade_nibbler.so

NIBBLER_LIB	=

#################################################################################

#PACMAN SOURCES

PACMAN_SRC =	Pacman/pacman.cpp

PACMAN_OBJ =	$(PACMAN_SRC:.cpp=.o)

PACMAN_NAME	=	arcade_pacman.so

PACMAN_LIB	=

#################################################################################

#VAR

CXX	=	g++

CPPFLAGS	=	-iquote./ -iquote..

CXXFLAGS	=	-Wall -Wextra -fPIC -std=c++17

DEST_DIRECTORY	=	../../lib

#################################################################################

#RULES

.PHONY: all
all: clean
all: nibbler pacman
all:
	mv $(NIBBLER_NAME) $(DEST_DIRECTORY)
	mv $(PACMAN_NAME) $(DEST_DIRECTORY)

#MAIN RULES

.PHONY: nibbler
nibbler: $(NIBBLER_OBJ) $(SHARED_OBJ)
	$(CXX) -o $(NIBBLER_NAME) $(NIBBLER_OBJ) $(SHARED_OBJ) $(NIBBLER_LIB) -shared

.PHONY: pacman
pacman: $(PACMAN_OBJ) $(SHARED_OBJ)
	$(CXX) -o $(PACMAN_NAME) $(PACMAN_OBJ) $(SHARED_OBJ) $(PACMAN_LIB) -shared

#CLEAN RULES

.PHONY: clean
clean:
	$(RM) $(NIBBLER_OBJ) $(PACMAN_OBJ) $(SHARED_OBJ)

.PHONY: fclean
fclean: clean
	$(RM) $(NIBBLER_NAME) $(PACMAN_NAME)

.PHONY: re
re: fclean all

#DEBUG RULE

.PHONY: debug
debug: CPPFLAGS += -g3 -ggdb
debug: re
