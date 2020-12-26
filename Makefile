TARGET = playerTest
SOURCES = AnsiPrint Board Ship Point Player AIPlayer
TEST = playerTest

# about compiler and .obj file directory #
CXX = g++
CXXFLAGS = -g -Wall
O_DIR = O_

# some names #
SRCS = ${SOURCES:%=%.cc}
OBJS = ${SRCS:%.cc=$(O_DIR)/%.o}
TESTSRC = ${TEST:%=%.cc}
TESTOBJ = ${TESTSRC:%.cc=$(O_DIR)/%.o}

# commnad #
$(TARGET): $(O_DIR) $(OBJS) $(TESTOBJ)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJS) $(TESTOBJ)

$(O_DIR):
	mkdir $@

$(O_DIR)/%.o: %.cc
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f $(TARGET) $(OBJS) $(TESTOBJ)
	rmdir $(O_DIR)

# dependence relation #
Ship.o: Ship.h Point.h
Board.o: Board.h AnsiPrint.h Ship.h Point.h
AnsiPrint.o: AnsiPrint.h
Point.o: Point.h
Player.o: Player.h Board.h Ship.h Point.h
AIPlayer.o: AIPlayer.h Board.h Ship.h Point.h
