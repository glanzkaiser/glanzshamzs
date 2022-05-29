GLAD_PATH = /opt/hamzstlib/glanzshamzs/glanzshamzs/GLAD/build/src/glad.c

SYSTEM=Linux
 g++ shaders_uniform.cpp -Ibuild/include /opt/hamzstlib/glanzshamzs/glanzshamzs/GLAD/build/src/glad.c -lglfw -ldl
CPPFLAGS += -Ibuild/include
ifndef NDEBUG
CXXFLAGS += -g -Wall
else
CXXFLAGS += -O3
endif

# mirrored from the irrlicht example code (included in the irrlicht path: $(IRRLICHT_PATH)/examples

LIBS += -L$(GLAD_PATH) -lglfw -ldl

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
