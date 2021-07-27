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
OBJPATH = bin/release/


###### FILES USED 

# object files
OBJ = $(OBJPATH)main.o
# header file dependencies
DEPS = 


# COMMANDS 


default : run


run : $(RTARGET)
	$^

$(RTARGET) : $(OBJ)
	$(COMPILER) $^ -o $@ $(CFLAGS) $(LIBS)

clean : 
	rm $(OBJPATH)*.exe $(OBJPATH)*.o

# impilcit rule: compile .cpp files but don't link
$(OBJPATH)%.o : $(SRCPATH)%.cpp $(DEPS) 
	g++ $< -c -o $@