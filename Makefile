DEFINES       = -DUNICODE -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_NEEDS_QMAIN
CFLAGS        = -pipe -fno-keep-inline-dllexport -g -Wall -Wextra $(DEFINES)

SOURCES       = main.cpp \
		mainwindow.cpp \
		Ball.cpp \
		Block.cpp \
		GameField.cpp \
		mainwidget.cpp \
		collision.cpp debug/moc_mainwindow.cpp \
		debug/moc_mainwidget.cpp
OBJECTS       = debug/main.o \
		debug/mainwindow.o \
		debug/Ball.o \
		debug/Block.o \
		debug/GameField.o \
		debug/mainwidget.o \
		debug/collision.o \
		debug/moc_mainwindow.o \
		debug/moc_mainwidget.o

DIST          =  mainwindow.h \
		gamefield.h \
		ball.h \
		block.h \
		mainwidget.h \
		constants.h \
		collision.h main.cpp \
		mainwindow.cpp \
		Ball.cpp \
		Block.cpp \
		GameField.cpp \
		mainwidget.cpp \
		collision.cpp
#DESTDIR        = debug/ #avoid trailing-slash linebreak
TARGET         = Arcanoid.exe
#DESTDIR_TARGET = debug/Arcanoid.exe

%.o: %.cc
      g++ -o $@ $<