COMP = g++
FLAGS = -Wall
INCLUDES = -I./vendor/glfw-3.3.7_64/include -I./vendor/glew-2.1.0/include
LFLAGS = -L./vendor/glfw-3.3.7_64/lib-mingw-w64 -L./vendor/glew-2.1.0/lib/Release/x64
LIBS = -lglfw3 -lglew32s -lopengl32 -lgdi32
SRCS = ./src/*.cpp
OBJS = $(patsubst %.cpp,%.o,$(subst ./src/, ./build/obj/, $(wildcard $(SRCS))))

TARGET = ./build/learnOpenGL

.PHONY: clean

all: $(TARGET)
	@echo Joe\'s Dumb-Ass FIFTEENTH attempt at learning openGL has compiled!

# $(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS) 
$(TARGET): $(OBJS)
	$(COMP) $(FLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS)

$(OBJS): $(SRCS)
	$(COMP) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET) 
