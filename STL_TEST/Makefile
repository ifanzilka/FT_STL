CXX			= clang++

CXXFLAGS 	= #-Wall -Wextra -Werror -std=c++98


ITERATOR 	= iterator_test

$(ITERATOR):
	$(CXX) $(CXXFLAGS) test_iterator.cpp -o $(ITERATOR)

start_iterator: $(ITERATOR)
			@./$(ITERATOR)
			@rm $(ITERATOR)

MEMORY 		= memory_test

$(MEMORY):
	$(CXX) $(CXXFLAGS) test_memory.cpp -o $(MEMORY)

start_memory: $(MEMORY)
			@./$(MEMORY)
			@rm $(MEMORY)

VECTOR		= vector_test

$(VECTOR):
	$(CXX) $(CXXFLAGS) test_vector.cpp -o $(VECTOR)

start_vector: $(VECTOR)
			@./$(VECTOR)
			@rm $(VECTOR)
