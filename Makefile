COMP = g++
FLAGS = -Wall
INCLUDES = -I./include/*.h
SRCS = ./src/*.cpp
OBJS = $(patsubst %.cpp,%.o,$(subst ./src/, ./build/obj/, $(wildcard $(SRCS))))

TARGET = ./build/learnOpenGL

.PHONY: clean

all: $(TARGET)
	@echo Joe\'s Dumb-Ass FIFTEENTH attempt at learning openGL has compiled!

# $(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS) 
$(TARGET): $(OBJS)
	$(COMP) $(FLAGS) $(INCLUDES) -o $(TARGET) $(OBJS)

$(OBJS): $(SRCS)
	$(COMP) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET) 
