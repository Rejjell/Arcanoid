CC=g++
MOC=moc-qt4
CFLAGS=-Wall
SOURCES=main.cpp \
		mainwindow.cpp \
		Ball.cpp \
		Block.cpp \
		GameField.cpp \
		mainwidget.cpp \
		collision.cpp debug/moc_mainwindow.cpp \
		debug/moc_mainwidget.cpp
MOC_HEADERS=mainwindow.h \
			gamefield.h \
			ball.h \
			block.h \
			mainwidget.h \
			constants.h \
			collision.h
EXECUTABLE=Arcanoid
INCDIRS=-I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtWidgets
LIBS=-lQtCore -lQtGui -lQtWidgets

# Change postfixes
MOC_SOURCES=$(MOC_HEADERS:.h=.moc.cpp)
OBJECTS=$(SOURCES:.cpp=.o) $(MOC_SOURCES:.cpp=.o)


all: $(EXECUTABLE)
	@echo Done!

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ $(LIBS) -o $@

# Generate object files, rule to change postfix
%.o: %.cc
	$(CC) $(CFLAGS) $(INCDIRS) -c $< -o $@

# Generate cc from h via Qt's Meta Object Compiler, rule to change postfix
%.moc.cc: %.h
	$(MOC) $(INCDIRS) $< -o $@

.PHONY: tags clean

clean:
	rm *.o

# Generate ctags file for all included files (autocomplete and jump to source)
tags:
	gcc -M $(INCDIRS) $(SOURCES) | \
	sed -e 's/[\\ ]/\n/g' | \
	sed -e '/^$$/d' -e '/\.o:[ \t]*$$/d' | \
	ctags -L - --c++-kinds=+p --fields=+iaS --extra=+q