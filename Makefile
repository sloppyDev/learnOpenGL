COMP = g++
FLAGS = -Wall
INCLUDES = -I./vendor/glfw-3.3.7_64/include -I./vendor/glew-2.1.0/include -I./vendor/stb -I./include/graphics -I./include/math
LFLAGS = -L./vendor/glfw-3.3.7_64/lib-mingw-w64 -L./vendor/glew-2.1.0/lib/Release/x64
LIBS = -lglfw3 -lglew32s -lopengl32 -lgdi32
SRCS = $(wildcard ./src/*.cpp) $(wildcard ./src/graphics/*.cpp) $(wildcard ./src/math/*.cpp)
OBJS = $(patsubst %.cpp,%.o,$(subst ./src/, ./build/obj/, $(wildcard $(SRCS))))

$(info $(SRCS))
TARGET = ./build/learnOpenGL

.PHONY: clean

all: $(TARGET)
	@echo Joe\'s Dumb-Ass FIFTEENTH attempt at learning openGL has compiled!

$(TARGET): $(OBJS)
	$(COMP) $(FLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS)

build/obj/%.o:src/%.cpp
	$(COMP) $(FLAGS) $(INCLUDES) -c $< -o $@

build/obj/graphics/%.o:src/graphics/%.cpp
	$(COMP) $(FLAGS) $(INCLUDES) -c $< -o $@

build/obj/math/%.o:src/math/%.cpp
	$(COMP) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET) 
