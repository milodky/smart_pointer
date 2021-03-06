TARGET := SP_Test
CC := g++
SRCS := SP_Test.cpp
HDRS := SmartPointer.h
CXXFLAGS := -std=c++11
OBJS := $(SRCS:.cpp=.o)
.SUFFIXES: .cpp .o
$(TARGET): $(OBJS)
	$(CC) -Wall -o $@ $(OBJS)

$(OBJS) : $(HDRS)

.cpp.o:
	$(CC) $(CXXFLAGS) -Wall -c $<


.PHONY: clean run
run:
	make
	./${TARGET}

clean:
	-rm *.o
	-rm ${TARGET}
