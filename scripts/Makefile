
CXX = clang++
CXXFLAGS = -std=c++11 -stdlib=libc++ -g

LIBS = -lkytea

all: yomi yomisvr

yomi: yomi.cpp ruby.h
	$(CXX) $(CXXFLAGS) -o yomi yomi.cpp $(LIBS)

yomisvr: yomisvr.cpp ruby.h
	$(CXX) $(CXXFLAGS) -o yomisvr yomisvr.cpp $(LIBS)

