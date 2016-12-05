//File: char_list_driver.make
TARGET = char_list_driver
OBJS = char_list_driver.o char_list.o random.o
CFLAGS = -c 

all: $(TARGET)
<TAB> $(g++) -o $(TARGET) $(OBJS)

char_list_driver.o: char_list_driver.cpp
<TAB> g++ $(CFLAGS) char_list_driver.cpp

char_list.o: char_list.cpp char_list.h
<TAB> $(CFLAGS) char_list.cpp

clean:
<TAB> rm -rf $(TARGET) *.o *~ core* \#*\#\#*\#