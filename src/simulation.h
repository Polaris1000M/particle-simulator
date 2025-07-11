#ifndef SIMULATION_H
#define SIMULATION_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#include "physics/object.h"
#include "render/shader.h"
#include "render/camera.h"

#define MAX_OBJECTS 100

typedef struct Simulation {
  GLFWwindow* window;
  unsigned int WINDOW_HEIGHT;
  unsigned int WINDOW_WIDTH;

  float gravity;
  float lastTime; // last time render loop was called
  float timeRatio; // multiplied by amount of real time passing to produce amount of simulation time passed
  
  Shader s;
  Shader particleShader;
  Camera c;

  unsigned int n;
  Object objects[MAX_OBJECTS];
} Simulation;

// initialize the simulation
void simulationInit(Simulation* sim, unsigned int n);

// updates the positions of the objects in the simulation based on time passed
void simulationUpdate(Simulation* sim, float deltaTime);

// renders the current state of the simulation
void simulationRender(Simulation* sim);

// starts the simulation
void simulationStart(Simulation* sim);

#endif
