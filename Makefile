# compiler name
COMPILER=g++
# necessary compiler flags
CFLAGS= -lpthread
# libraries used
LIBS= -lsfml-graphics -lsfml-window -lsfml-system
# release target
RTARGET= bin/release/graph.exe


###### PATH SHORTHANDS

# include path
INCPATH = src/include/
# source path
SRCPATH = src/source/
# object file path
OBJPATH = src/obj/


###### FILES USED 

# object files
OBJ = $(SRCPATH)main.cpp
# header file dependencies
DEPS = 

$(RTARGET) : $(OBJ) 
	$(COMPILER) $< -o $@

run : $(RTARGET)
	$^