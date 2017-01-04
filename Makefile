OBJ = main.o BMScontrol.o UImanager.o BookArray.o Course.o Book.o Product.o Electronic.o Desktop.o GraphingCalc.o Laptop.o Tutor.o ScienceT.o MathT.o MusicT.o BusinessT.o

a3:	$(OBJ)
	g++ -o a3 $(OBJ)

main.o:	main.cc
	g++ -c main.cc

BMScontrol.o:	BMScontrol.cc BMScontrol.h defs.h Dlist.h Course.h
	g++ -c BMScontrol.cc

UImanager.o:	UImanager.cc UImanager.h 
	g++ -c UImanager.cc

BookArray.o:	BookArray.cc BookArray.h Book.h
	g++ -c BookArray.cc

Course.o:	Course.cc Course.h defs.h
	g++ -c Course.cc

Product.o: Product.cc Product.h
	g++ -c Product.cc

Electronic.o: Electronic.cc Electronic.h Product.h
	g++ -c Electronic.cc

GraphingCalc.o: GraphingCalc.cc GraphingCalc.h Electronic.h
	g++ -c GraphingCalc.cc

Desktop.o: Desktop.cc Desktop.h Electronic.h Product.h
	g++ -c Desktop.cc

Laptop.o: Laptop.cc Laptop.h Desktop.h
	g++ -c Laptop.cc

Book.o:	Book.cc Book.h defs.h Product.h
	g++ -c Book.cc

Tutor.o: Tutor.cc Tutor.h
	g++ -c Tutor.cc

ScienceT.o: ScienceT.cc ScienceT.h Tutor.h
	g++ -c ScienceT.cc

MathT.o: MathT.cc MathT.h Tutor.h
	g++ -c MathT.cc

MusicT.o: MusicT.cc MusicT.h Tutor.h
	g++ -c MusicT.cc

BusinessT.o: BusinessT.cc BusinessT.h Tutor.h
	g++ -c BusinessT.cc

clean:
	rm -f *.o a3

