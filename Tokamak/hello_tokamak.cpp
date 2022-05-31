#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <tokamak.h>
#pragma comment(lib, "tokamak.lib")

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


// Global variables for Tokamak
neSimulator *gSim = NULL;
// The number of cubes to render in the simulation (try values between 2 and about 50)
#define CUBECOUNT 5
neRigidBody *gCubes[CUBECOUNT];
neAnimatedBody *gFloor = NULL;

// Timer variables
bool gbUseHFTimer;
INT64 gCurrentTime;
float gfTimeScale;


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// Vertex data for the cubes
// Note that the cube's dimensions are 1 unit in each axis.

strVertex gCubeVertices[] =
{
	{-0.5f,-0.5f,-0.5f,   0.0f, 0.0f,-1.0f,   0xffff0000, 0.0f, 1.0f },  //Front face
	{-0.5f, 0.5f,-0.5f,   0.0f, 0.0f,-1.0f,   0xffffffff, 0.0f, 0.0f },
	{ 0.5f, 0.5f,-0.5f,   0.0f, 0.0f,-1.0f,   0xffffffff, 1.0f, 0.0f },
	{ 0.5f, 0.5f,-0.5f,   0.0f, 0.0f,-1.0f,   0xffffffff, 1.0f, 0.0f },
	{ 0.5f,-0.5f,-0.5f,   0.0f, 0.0f,-1.0f,   0xffffffff, 1.0f, 1.0f },
	{-0.5f,-0.5f,-0.5f,   0.0f, 0.0f,-1.0f,   0xffffffff, 0.0f, 1.0f },

	{ 0.5f,-0.5f, 0.5f,   0.0f, 0.0f, 1.0f,   0xff00ff00, 0.0f, 1.0f },  //Back face
	{ 0.5f, 0.5f, 0.5f,   0.0f, 0.0f, 1.0f,   0xffffffff, 0.0f, 0.0f },
	{-0.5f, 0.5f, 0.5f,   0.0f, 0.0f, 1.0f,   0xffffffff, 1.0f, 0.0f },
	{-0.5f, 0.5f, 0.5f,   0.0f, 0.0f, 1.0f,   0xffffffff, 1.0f, 0.0f },
	{-0.5f,-0.5f, 0.5f,   0.0f, 0.0f, 1.0f,   0xffffffff, 1.0f, 1.0f },
	{ 0.5f,-0.5f, 0.5f,   0.0f, 0.0f, 1.0f,   0xffffffff, 0.0f, 1.0f },

	{-0.5f, 0.5f,-0.5f,   0.0f, 1.0f, 0.0f,   0xff0000ff, 0.0f, 1.0f },  //Top face
	{-0.5f, 0.5f, 0.5f,   0.0f, 1.0f, 0.0f,   0xffffffff, 0.0f, 0.0f },
	{ 0.5f, 0.5f, 0.5f,   0.0f, 1.0f, 0.0f,   0xffffffff, 1.0f, 0.0f },
	{ 0.5f, 0.5f, 0.5f,   0.0f, 1.0f, 0.0f,   0xffffffff, 1.0f, 0.0f },
	{ 0.5f, 0.5f,-0.5f,   0.0f, 1.0f, 0.0f,   0xffffffff, 1.0f, 1.0f },
	{-0.5f, 0.5f,-0.5f,   0.0f, 1.0f, 0.0f,   0xffffffff, 0.0f, 1.0f },

	{ 0.5f,-0.5f,-0.5f,   0.0f,-1.0f, 0.0f,   0xffffff00, 0.0f, 1.0f },  //Bottom face
	{ 0.5f,-0.5f, 0.5f,   0.0f,-1.0f, 0.0f,   0xffffffff, 0.0f, 0.0f },
	{-0.5f,-0.5f, 0.5f,   0.0f,-1.0f, 0.0f,   0xffffffff, 1.0f, 0.0f },
	{-0.5f,-0.5f, 0.5f,   0.0f,-1.0f, 0.0f,   0xffffffff, 1.0f, 0.0f },
	{-0.5f,-0.5f,-0.5f,   0.0f,-1.0f, 0.0f,   0xffffffff, 1.0f, 1.0f },
	{ 0.5f,-0.5f,-0.5f,   0.0f,-1.0f, 0.0f,   0xffffffff, 0.0f, 1.0f },

	{-0.5f,-0.5f, 0.5f,  -1.0f, 0.0f, 0.0f,   0xffff00ff, 0.0f, 1.0f },  //Left face
	{-0.5f, 0.5f, 0.5f,  -1.0f, 0.0f, 0.0f,   0xffffffff, 0.0f, 0.0f },
	{-0.5f, 0.5f,-0.5f,  -1.0f, 0.0f, 0.0f,   0xffffffff, 1.0f, 0.0f },
	{-0.5f, 0.5f,-0.5f,  -1.0f, 0.0f, 0.0f,   0xffffffff, 1.0f, 0.0f },
	{-0.5f,-0.5f,-0.5f,  -1.0f, 0.0f, 0.0f,   0xffffffff, 1.0f, 1.0f },
	{-0.5f,-0.5f, 0.5f,  -1.0f, 0.0f, 0.0f,   0xffffffff, 0.0f, 1.0f },

	{ 0.5f,-0.5f,-0.5f,   1.0f, 0.0f, 0.0f,   0xff00ffff, 0.0f, 1.0f },  //Right face
	{ 0.5f, 0.5f,-0.5f,   1.0f, 0.0f, 0.0f,   0xffffffff, 0.0f, 0.0f },
	{ 0.5f, 0.5f, 0.5f,   1.0f, 0.0f, 0.0f,   0xffffffff, 1.0f, 0.0f },
	{ 0.5f, 0.5f, 0.5f,   1.0f, 0.0f, 0.0f,   0xffffffff, 1.0f, 0.0f },
	{ 0.5f,-0.5f, 0.5f,   1.0f, 0.0f, 0.0f,   0xffffffff, 1.0f, 1.0f },
	{ 0.5f,-0.5f,-0.5f,   1.0f, 0.0f, 0.0f,   0xffffffff, 0.0f, 1.0f },

};
#define NUM_VERTICES_CUBE (sizeof(gCubeVertices)/sizeof(strVertex))

// Vertex data for the floor (change FLOORSIZE for larger/smaller floor area)
#define FLOORSIZE 30
strVertex gFloorVertices[] =
{
	{-(FLOORSIZE/2), 0, -(FLOORSIZE/2),   0.0f, 1.0f, -0.0f,   0xffff0000, 0.0f, 1.0f },  //Top face
	{-(FLOORSIZE/2), 0,  (FLOORSIZE/2),   0.0f, 1.0f, -0.0f,   0xffffffff, 0.0f, 0.0f },
	{ (FLOORSIZE/2), 0,  (FLOORSIZE/2),   0.0f, 1.0f, -0.0f,   0xffffffff, 1.0f, 0.0f },
	{ (FLOORSIZE/2), 0,  (FLOORSIZE/2),   0.0f, 1.0f, -0.0f,   0xffffffff, 1.0f, 0.0f },
	{ (FLOORSIZE/2), 0, -(FLOORSIZE/2),   0.0f, 1.0f, -0.0f,   0xffffffff, 1.0f, 1.0f },
	{-(FLOORSIZE/2), 0, -(FLOORSIZE/2),   0.0f, 1.0f, -0.0f,   0xffffffff, 0.0f, 1.0f },
};
#define NUM_VERTICES_FLOOR (sizeof(gFloorVertices)/sizeof(strVertex))


int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


// Initialise the Tokamak physics engine.
// Here's where the interesting stuff starts.
bool InitPhysics(void)
{
	neGeometry *geom;	// Pointer to a Geometry object which we'll use to define the shape/size of each cube
	neV3 boxSize1;		// A variable to store the length, width and height of the cube
	neV3 gravity;		// A vector to store the direction and intensity of gravity
	neV3 pos;			// The position of a cube
	f32 mass;			// The mass of our cubes
	neSimulatorSizeInfo sizeInfo;	// SizeInfo stores data about how many objects we are going to model
	int i;

	// Create and initialise the simulator
	// Tell the simulator how many rigid bodies we have
	sizeInfo.rigidBodiesCount = CUBECOUNT;
	// Tell the simulator how many animated bodies we have
	sizeInfo.animatedBodiesCount = 1;
	// Tell the simulator how many bodies we have in total
	s32 totalBody = sizeInfo.rigidBodiesCount + sizeInfo.animatedBodiesCount;
	sizeInfo.geometriesCount = totalBody;
	// The overlapped pairs count defines how many bodies it is possible to be in collision
	// at a single time. The SDK states this should be calculated as:
	//   bodies * (bodies-1) / 2
	// So we'll take its word for it. :-)
	sizeInfo.overlappedPairsCount = totalBody * (totalBody - 1) / 2;
	// We're not using any of these so set them all to zero
	sizeInfo.rigidParticleCount = 0;
	sizeInfo.constraintsCount = 0;
	sizeInfo.terrainNodesStartCount = 0;

	// Set the gravity. Try changing this to see the effect on the objects
	gravity.Set(0.0f, -10.0f, 0.0f);

	// Ready to go, create the simulator object
	gSim = neSimulator::CreateSimulator(sizeInfo, NULL, &gravity);

	// Now we need to add some other elements to the physics engine, namely
	// the cubes and the floor.

	// Create rigid bodies for the cubes
	for (i=0; i<CUBECOUNT; i++)
	{
		// Create a rigid body
		gCubes[i] = gSim->CreateRigidBody();
		// Add geometry to the body and set it to be a box of dimensions 1, 1, 1
		geom = gCubes[i]->AddGeometry();
		boxSize1.Set(1.0f, 1.0f, 1.0f);
		geom->SetBoxSize(boxSize1[0], boxSize1[1], boxSize1[2]);
		// Update the bounding info of the object -- must always call this
		// after changing a body's geometry.
		gCubes[i]->UpdateBoundingInfo();

		// Set other properties of the object (mass, position, etc.)
		mass = 1.0f;
		gCubes[i]->SetInertiaTensor(neBoxInertiaTensor(boxSize1[0], boxSize1[1], boxSize1[2], mass));
		gCubes[i]->SetMass(mass);
		// Vary the position so the cubes don't all exactly stack on top of each other
		// (makes for a more interesting simulation)
		pos.Set((float)(rand()%10) / 100, 4.0f + i*2.0f, (float)(rand()%10) / 100);
		gCubes[i]->SetPos(pos);
	}

	// Create an animated body for the floor
	gFloor = gSim->CreateAnimatedBody();
	// Add geometry to the floor and set it to be a box with size as defined by the FLOORSIZE constant
	geom = gFloor->AddGeometry();
	boxSize1.Set(FLOORSIZE, 0.2f, FLOORSIZE);
	geom->SetBoxSize(boxSize1[0],boxSize1[1],boxSize1[2]);
	gFloor->UpdateBoundingInfo();
	// Set the position of the box within the simulator
	pos.Set(0.0f, -3.0f, 0.0f);
	gFloor->SetPos(pos);

	// All done
	return true;
}


void KillPhysics(void)
{
	if (gSim)
	{
		// Destroy the simulator.
		// Note that this will release all related resources that we've allocated.
		neSimulator::DestroySimulator(gSim);
		gSim = NULL;
	}
}



// Initialise a timer for use in our application.
// Wherever possible use a Performance timer as this
// gives the best accuracy.
// If this isn't available, fall back to the multimedia timer.
// In each case, note the number of "ticks" per second so that
// we can divide the elapsed time by this value to determine
// how much real time has actually passed.
// For more information on using these timers, see the articles at
// www.mvps.org/directx
bool InitTimer(void)
{
	INT64 TimerFrequency;

	// Can we use the high performance timer?
	if (QueryPerformanceFrequency( (LARGE_INTEGER*)&TimerFrequency))
	{
		// High performance timer available, let's get ready to use it
		gfTimeScale = 1.0f / TimerFrequency;
		QueryPerformanceCounter((LARGE_INTEGER *) &gCurrentTime);
		gbUseHFTimer = true;
		return true;
	}
	else
	{
		// No high precision timer to be seen, let's use the Windows multimedia timer instead
		gfTimeScale = 0.001f;
		gCurrentTime = timeGetTime();
		gbUseHFTimer = false;
		return true;
	}

	// No timer available at all (should never happen)
	return false;
}


// Use the timer we previously initialised to determine
// how much time (in seconds, or a fraction thereof) has
// passed since this function was last called.
float GetElapsedTime()
{
	INT64 newTime;
	float fElapsed;

	if (gbUseHFTimer) 
	{
		QueryPerformanceCounter((LARGE_INTEGER *) &newTime);
	}
	else 
	{
		newTime=timeGetTime();
	}

	// Scale accordingly
	fElapsed = (float)((newTime - gCurrentTime) * gfTimeScale);

	// Save the new time value for the next time we're called
	gCurrentTime = newTime;

	return fElapsed;
}
