##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	src/main.cpp						\
		src/dynamicFile.cpp					\
		src/Error/Error.cpp					\
		src/LoadLib/LoadLib.cpp				\
		src/Core/Core.cpp					\
		src/Graphic/ADisplayModule.cpp		\

OBJ	=	$(SRC:.cpp=.o)

###############################################################################

NAME	=	arcade

CXXFLAGS	=	-Wall -Wextra -std=c++17

CPPFLAGS	=	-iquote./src/

CXX	=	g++

#MAIN RULES
all: core games graphicals

.PHONY: core
core:	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) -ldl -lncurses

################################################################################

#GAME RULES

.PHONY: games
games:
	mkdir -p lib 
	make -C ./src/Game

.PHONY: graphicals
graphicals:
	mkdir -p lib
	make -C ./src/Graphic

################################################################################

#CLEAN RULES
clean: 	doc-clean
	$(RM) $(OBJ) *.gcda *.gcno
	make clean -C ./src/Graphic
	make clean -C ./src/Game

fclean:	clean
	$(RM) $(NAME) unit_tests
	make fclean -C ./src/Graphic
	make fclean -C ./src/Game

re:		fclean all
re:
	make re -C src/Graphic
	make re -C src/Game

debug:	CPPFLAGS += -g3 -ggdb
debug:	re
	make debug -C ./src/Graphic
	make debug -C ./src/Game

.PHONY: all fclean re clean debug

DOC_DIR 	=	./Documentation

.PHONY: doc
doc:
	doxygen $(DOC_DIR)/Doxyfile

# Generate PDF documentation
.PHONY: doc_pdf
doc-pdf:	doc
	make -C $(DOC_DIR)/latex/
	cp $(DOC_DIR)/latex/refman.pdf $(DOC_DIR)

# Launch doxygen in firefox browser
.PHONY: doc-firefox
doc-firefox:	doc
	firefox $(DOC_DIR)/html/index.html

.PHONY: doc-clean
doc-clean:
	$(RM) -r $(DOC_DIR)/html/
	$(RM) -r $(DOC_DIR)/latex/
	$(RM) $(DOC_DIR)/refman.pdf
