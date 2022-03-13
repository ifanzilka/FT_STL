CXX			= clang++

CXXFLAGS 	=  #-Wall -Wextra -Werror -std=c++98

F_NONE		= \033[37m
F_BOLD		= \033[1m
F_RED		= \033[31m
F_ORANGE	= \033[38m
F_YELLOW	= \033[0;33m
F_GREEN		= \033[32m
F_CYAN		= \033[36m
F_BLUE		= \033[34m 

all: start_iterator start_memory start_vector start_stack start_set start_map

ITERATOR 	= iterator_test

$(ITERATOR):
	$(CXX) $(CXXFLAGS) test_iterator.cpp -o $(ITERATOR)

start_iterator: $(ITERATOR)
			@./$(ITERATOR) || echo " "
			@rm $(ITERATOR) || echo " "

MEMORY 		= memory_test

$(MEMORY):
	$(CXX) $(CXXFLAGS) test_memory.cpp -o $(MEMORY)

start_memory: $(MEMORY)
			@./$(MEMORY) || echo " "
			@rm $(MEMORY) || echo " "

VECTOR		= vector_test

$(VECTOR):
	$(CXX) $(CXXFLAGS) test_vector.cpp -o $(VECTOR)

start_vector: $(VECTOR)
			@./$(VECTOR) || echo " "
			@rm $(VECTOR) || echo " "

STACK		= stack_test

$(STACK):
	$(CXX) $(CXXFLAGS) test_stack.cpp -o $(STACK)

start_stack: $(STACK)
			@./$(STACK) || echo " "
			@rm $(STACK) || echo " "


SET		= set_test

CPP_SET = test_set.cpp

$(SET):
	$(CXX) $(CXXFLAGS) $(CPP_SET) -o $(SET)

start_set: $(SET)
			@./$(SET) || echo " "
			@rm $(SET) || echo " "


MAP		= map_test

CPP_MAP = test_map.cpp

$(MAP):
	$(CXX) $(CXXFLAGS) $(CPP_MAP) -o $(MAP)

start_map: $(MAP)
			@./$(MAP) || echo " "
			@rm $(MAP) || echo " "

code:
	@echo " ~~~~~~~~~~~~~~~~"
	@echo "$(F_BOLD)  * Make code, *"
	@echo "$(F_BOLD)   * not war! *"
	@echo "$(F_RED)    ..10101.."
	@echo "$(F_ORANGE)  01   1   011"
	@echo "$(F_YELLOW) 10     0     00"
	@echo "$(F_GREEN) 11   .010.   11"
	@echo "$(F_CYAN) 00 .01 1 01. 10"
	@echo "$(F_BLUE) 010   1   110"
	@echo "$(F_BLUE)   11011010**$(F_NONE)"