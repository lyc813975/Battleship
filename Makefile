TARGET = Game
SOURCES = AnsiPrint Board Ship Player AIPlayer Judge
TEST = Game 

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
Ship.o: Ship.h
Board.o: Board.h AnsiPrint.h Ship.h
AnsiPrint.o: AnsiPrint.h
Player.o: Player.h Board.h Ship.h
AIPlayer.o: AIPlayer.h Player.h Board.h Ship.h
Judge.o: Judge.h AIPlayer.h Player.h 
