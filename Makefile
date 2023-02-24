CC := g++
OFILES := obj/Node.o obj/FSNode.o obj/FrequencySet.o obj/PQNode.o obj/PriorityQueue.o obj/HCNode.o obj/HuffmanCoding.o obj/main.o
CPPFILES := cpp/
HFILES := include/
FLAGS := -std=c++11 -I $(HFILES)
TARGET := Encoder


$(TARGET): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $@

$(OFILES) : obj/%.o : src/%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm $(OFILES) Encoder