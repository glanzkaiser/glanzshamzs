GLAD_PATH = /opt/hamzstlib/glanzshamzs/GLAD/build/src/glad.c

CPPFLAGS += -Ibuild/include
ifndef NDEBUG
CXXFLAGS += -g -Wall
else
CXXFLAGS += -O3
endif

LIBS += $(GLAD_PATH) -lglfw -ldl

TARGET = shaders_interpolation

SOURCES += $(TARGET).cpp
# if more cpp files are created, add them here
#SOURCES +=  something1.cpp something2.cpp  something3.cpp


all: $(TARGET)

$(TARGET):
	g++ $(SOURCES) $(CPPFLAGS) $(CXXFLAGS) $(LIBS)

clean:
	rm -f $(TARGET).o
	rm -f $(TARGET)
