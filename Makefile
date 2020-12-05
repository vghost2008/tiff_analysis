CXXFLAGS = -g
all:main.o wtiff.o wbigtiff.o wabstracttiff.o
	g++ -o tiff_analysis $^
clean:
	rm *.o
