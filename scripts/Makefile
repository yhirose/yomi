
CXX = clang++
CXXFLAGS = -std=c++0x -stdlib=libc++ -g

LIBS = -lkytea

yomi: yomi.cpp ruby.h
	$(CXX) $(CXXFLAGS) -o yomi yomi.cpp $(LIBS)
