IRRLICHT_PATH = /opt/hamzstlib/Physics/irrlicht-1.8.5/

SYSTEM=Linux

CPPFLAGS += -I$(IRRLICHT_PATH)/include
ifndef NDEBUG
CXXFLAGS += -g -Wall
else
CXXFLAGS += -O3
endif

# mirrored from the irrlicht example code (included in the irrlicht path: $(IRRLICHT_PATH)/examples

LIBS += -lGL -lXxf86vm  -lX11 -L$(IRRLICHT_PATH)/lib/$(SYSTEM) -lIrrlicht

TARGET = experimental

SOURCES += $(TARGET).cpp
# if more cpp files are created, add them here
#SOURCES +=  something1.cpp something2.cpp  something3.cpp


all: $(TARGET)

$(TARGET):
	g++ $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET).o
	rm -f $(TARGET)
