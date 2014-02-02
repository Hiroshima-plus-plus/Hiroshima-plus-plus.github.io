all : generate
generate : generate.cpp
	$(CXX) -std=c++11 -Wall -Wextra -Werror -o $@ $^