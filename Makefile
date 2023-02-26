CC := g++
OFILES := obj/Node.o obj/HuffmanNode.o obj/HuffmanLeaf.o obj/Huffman.o obj/Encoder.o obj/Decoder.o obj/main.o
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