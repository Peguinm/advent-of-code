
# Change the day and the part here
# to compile, just use make, without any lable
# It should compile and run
DAY := 2
PART := 1
# ================= #

FILE := day$(DAY)/day$(DAY)_part$(PART)

all: run clear

clear: $(FILE).o
	@del /Q *.o

$(FILE).o: $(FILE).cpp
	g++ -O2 $^ -c

program.exe: $(FILE).o
	g++ $(notdir $^) -o program.exe

run: program.exe
	./program.exe