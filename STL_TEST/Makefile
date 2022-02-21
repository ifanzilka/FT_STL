CXX			= clang++

CXXFLAGS 	=  #-Wall -Wextra -Werror -std=c++98


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
