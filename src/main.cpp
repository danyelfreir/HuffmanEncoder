#include <string.h>

#include <fstream>
#include <string>

#include "../include/Decoder.h"
#include "../include/Encoder.h"
#include "../include/Huffman.h"

int main(int argc, char *argv[]) {
    if (argc < 4) {
        std::cout << "Missing arguments!"
                  << "Need a compression/decompression flag (-c/-d)"
                  << "An input file and an output file"
                  << "Example: ./compressor -c myAudio.wav \
                      myAudioCompressed.cmpr"
                  << std::endl;
        return -1;
    }
    bool isCompressing = false;
    bool isDecompressing = false;
    if (strcmp(argv[1], "-c") == 0) isCompressing = true;
    if (strcmp(argv[1], "-d") == 0) isDecompressing = true;
    std::string inputFile(argv[2]);
    std::string outputFile(argv[3]);

    if (isCompressing) {
        Encoder hc(inputFile, outputFile);
        hc.encode();
    } else if (isDecompressing) {
        Decoder hd(inputFile, outputFile);
        hd.decode();
    }

    return 0;
}