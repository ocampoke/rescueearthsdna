#********************************************************************* 
#* Program name: Makefile
#* Author: Kevin Ocampo
#* Date: 6/10/2019
#* Description: Final Project - Makefile for Rescue Earth's DNA Game 
#*				program based on code from the source cited below.
#*
#**********************************************************************
#*    Title: Writing Make Files
#*    Author: Robert I. Pitts
#*    Date: 2000
#*    Availability: https://www.cs.bu.edu/teaching/cpp/writing-makefiles/
#*
#*********************************************************************/
CXX=g++
CXXFLAGS = -Wall -g -std=c++11

main: main.o inputValid.o game.o space.o house.o nuclearPlant.o  smallForest.o zoo.o policeStation.o
	$(CXX) $(CXXFLAGS) -o main main.o inputValid.o game.o space.o house.o nuclearPlant.o smallForest.o zoo.o policeStation.o
main.o: main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp

inputValid.o: inputValid.cpp inputValid.hpp
	$(CXX) $(CXXFLAGS) -c inputValid.cpp

game.o: game.cpp game.hpp
	$(CXX) $(CXXFLAGS) -c game.cpp

space.o: space.cpp space.hpp
	$(CXX) $(CXXFLAGS) -c space.cpp

house.o: house.cpp house.hpp
	$(CXX) $(CXXFLAGS) -c house.cpp

nuclearPlant.o: nuclearPlant.cpp nuclearPlant.hpp
	$(CXX) $(CXXFLAGS) -c nuclearPlant.cpp

smallForest.o: smallForest.cpp smallForest.hpp
	$(CXX) $(CXXFLAGS) -c smallForest.cpp

zoo.o: zoo.cpp zoo.hpp
	$(CXX) $(CXXFLAGS) -c zoo.cpp

policeStation.o: policeStation.cpp policeStation.hpp
	$(CXX) $(CXXFLAGS) -c policeStation.cpp

zip:
	zip FinalProject_Ocampo_Kevin.zip *.cpp *.hpp *.pdf *.docx Makefile 

clean:
	rm *.o *.zip main 
