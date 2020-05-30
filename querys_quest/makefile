CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -g
CXXFLAGS += -lncurses

SRCS = Board.cpp Boots.cpp Door.cpp Fire.cpp Free.cpp Ice.cpp inputValidation.cpp Key.cpp main.cpp Menus.cpp Player.cpp Query.cpp Space.cpp Wall.cpp Water.cpp

HEADERS = Board.hpp Boots.hpp Door.hpp Fire.hpp Free.hpp Ice.hpp inputValidation.hpp Key.hpp Menus.hpp Player.hpp Query.hpp Space.hpp Wall.hpp Water.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main

clean:
	rm main
