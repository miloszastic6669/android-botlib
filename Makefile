CXX = g++
CXXFLAGS = -w -std=c++20 -O2

INCLUDE_PATH = -I./include -I/usr/local/include/opencv4
LIBRARY_PATH = -L./lib -L/usr/local/lib

LIBS = -llua -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_videoio\
       -ldl -lm -lpthread -lrt -lX11 -ljpeg -lpng -ltiff -lz -lwebp \
       -ldl -lpthread 

SRC = $(wildcard src/*.cpp)
OUT = bot

all: $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDE_PATH) $(SRC) -o $(OUT) $(LIBRARY_PATH) $(LIBS)

clean:
	rm -f $(OUT)
