CXX         = g++
#LIBARYFLAGS = -lncurses
#-lpthread
CXXFLAGS    = -std=c++1y -Wall -Wextra -Wparentheses $(LIBARYFLAGS)
#SOURCES     = $(wildcard *.cpp)
HPPS        = $(wildcard *.hpp)
#OBJECTS    = $(SOURCES:.cpp=.o)
OBJECTS     = $(HPPS:.hpp=.o)
EXEC        = asted

all: $(EXEC) clean tags

$(EXEC): $(OBJECTS) exec.o
	-$(CXX) $(CXXFLAGS) -o $(EXEC) exec.o $(OBJECTS)

%.o: %.cpp
	-$(CXX) $(CXXFLAGS) -c $< -o $@

check-syntax: csyntax

csyntax:
	$(CXX) $(CXXFLAGS) -c ${CHK_SOURCES} -o /dev/null
# -S-fsyntax-only

tags:
	rm -f TAGS
	ls|grep "pp$$"|xargs etags -a

clean:
	rm -f $(OBJECTS) $(EXEC).o

cleanwarn:
	rm -f warnings.log
