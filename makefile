vpath %.cpp ./src/
vpath %.hpp ./includes/
vpath %.o ./build/

objects = main.o parser.o fileio.o utils.o type.o request.o
compile_args = -O3 -g -Wall -c

http : $(objects)
	mkdir -p ./build
	g++ -o main ./build/*.o -lcurl

type.o : type.hpp
	g++ $(compile_args) -o ./build/type.o ./src/type.cpp

utils.o : utils.hpp
	g++ $(compile_args) -o ./build/utils.o ./src/utils.cpp 

request.o : request.hpp
	g++ $(compile_args) -o ./build/request.o ./src/request.cpp 

parser.o : parser.hpp
	g++ $(compile_args) -o ./build/parser.o ./src/parser.cpp

fileio.o : fileio.hpp
	g++ $(compile_args) -o ./build/fileio.o ./src/fileio.cpp

main.o : main.cpp
	g++ $(compile_args) -o ./build/main.o ./src/main.cpp

.PHONY : clean static
static : $(objects)
	mkdir -p ./build
	g++ -static -pthread -o main ./build/*.o /usr/local/lib/libcurl.a -lz

clean :
	-rm ./build/*.o main