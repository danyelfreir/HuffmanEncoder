Encoder: *.o
	g++ -std=c++11 obj/*.o -o Encoder

*.o: src/*.cpp include/*.h
	g++ -std=c++11 -c src/*.cpp
	mv *.o obj/

clean:
	rm obj/*.o Encoder