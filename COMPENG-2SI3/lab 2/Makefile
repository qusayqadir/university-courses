CC=g++
CFLAGS=-I. -lm -g
DEPS = *.h
OBJ = objPos.o objPosArrayList.o objPosDLinkedList.o Test.o  

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Lab2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

test:	testLab2
testLab2:
	./run.sh

.PHONY: clean

clean:
	$(RM) *.o *.exe *.xml Lab2
