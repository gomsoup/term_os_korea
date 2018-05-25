CC = g++ -std=c++11

term: config.o process.o schedule.o main.o
        $(CC) -o term config.o process.o schedule.o main.o
config.o : config.cpp
        $(CC) -c -o config.o config.cpp
process.o : process.cpp
        $(CC) -c -o process.o process.cpp
schedule.o : schedule.cpp
        $(CC) -c -o schedule.o schedule.cpp
main.o : main.cpp
        $(CC) -c -o main.o main.cpp

clean :
        rm *.o 