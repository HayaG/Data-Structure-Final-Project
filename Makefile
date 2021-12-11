EXENAME = graph
OBJS = main.o graph.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

net.o : main.cpp graph.cpp facebook_graph.h
	$(CXX) $(CXXFLAGS) main.cpp graph.cpp

test: output_msg test.o graph.o
	$(LD) test.o graph.o $(LDFLAGS) -o test

test.o: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp

clean :
	-rm -f *.o .txt $(EXENAME) test
