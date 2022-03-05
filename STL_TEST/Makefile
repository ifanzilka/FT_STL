CXX			= clang++

CXXFLAGS 	=  #-Wall -Wextra -Werror -std=c++98


all: start_iterator start_memory start_vector start_stack start_set

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
