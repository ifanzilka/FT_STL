CXX			= clang++

CXXFLAGS 	= #-Wall -Wextra -Werror -std=c++98


ITERATOR 	= iterator_test

$(ITERATOR):
	$(CXX) $(CXXFLAGS) test_iterator.cpp -o $(ITERATOR)

start_iterator: $(ITERATOR)
			@./$(ITERATOR)
			@rm $(ITERATOR)
