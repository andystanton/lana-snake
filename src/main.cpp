#include <cmath>
#include <ctime>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include "common/Logger.h"

#include "model/entity/Pickup.h"
#include "model/entity/Snake.h"
#include "model/entity/World.h"
#include "model/foundation/Colour.h"

#include "drawing/Gameplay.h"
#include "drawing/Screens.h"

#include "drawing/Palette.h"

using namespace std;

enum GAME_STATE {
    MENU,
    PLAYING,
    PAUSED,
    DEAD,
    COMPLETE
};

static int running = 1;
static GAME_STATE state = MENU;

static Logger* mainLog;

// constants
static GLint gameSpeed = 100;

static const GLint width = 800;
static const GLint height = 600;

// game loop
static int lastUpdate = 0;
static int deadStartTime = 0;

Snake* snake;
Pickup* randomPickup;
World* world;
Screens* screens;
Palette * palette;

static void spawnPickup() {
    Vec2d* pickupCoords;
    bool uniqueCoords = false;
    while (!uniqueCoords) {
        pickupCoords = new Vec2d(abs(rand() % world->getXBound()), abs(rand() % world->getYBound()));
        uniqueCoords = !(snake->collidesWith(pickupCoords));
        if (!uniqueCoords) {
            mainLog->info("Attempted to spawn pickup under snake at " + *pickupCoords->toString());
        }
    }
    randomPickup = new Pickup(pickupCoords, palette->getRandomColour());
}


static void draw(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    switch(state) {
        case MENU: {
            screens->drawStartScreen();
            break;
        }
        case PAUSED:
        case PLAYING: {
            Gameplay::draw(randomPickup);
            Gameplay::draw(snake);
            if (state == PAUSED) {
                Gameplay::drawPause(width);
            }
            break;
        }
        case DEAD: {
            GLint count = 3 - (lastUpdate - deadStartTime) / 1000;
            screens->drawDeadScreen(count);
            break;
        }
        case COMPLETE: {
            screens->drawCompleteScreen();
            break;
        }
    }
}

void key(GLFWwindow* window, int k, int scancode, int action, int mods) {
    if(action != GLFW_PRESS ) return;
    
    switch (k) {
        case GLFW_KEY_UP:
            snake->addDirectionToQueue(Vec2d::UP);
            break;
        case GLFW_KEY_DOWN:
            snake->addDirectionToQueue(Vec2d::DOWN);
            break;
        case GLFW_KEY_LEFT:
            snake->addDirectionToQueue(Vec2d::LEFT);
            break;
        case GLFW_KEY_RIGHT:
            snake->addDirectionToQueue(Vec2d::RIGHT);
            break;
        case GLFW_KEY_SPACE:
            if (state == MENU) {
                state = PLAYING;
            } else if (state == DEAD || state == COMPLETE) {
                state = MENU;
            } else if (state == PLAYING) {
                state = PAUSED;
            } else if (state == PAUSED) {
                state = PLAYING;
            }
            break;
        case GLFW_KEY_ESCAPE:
            running = 0;
            break;
        default:
            return;
    }
}

static void resetToOrigin() {
    mainLog->info(string("Resetting to ") + *world->getOrigin()->toString());
    snake->setCoords(world->getOrigin());
    snake->resetSnake();
    snake->addDirectionToQueue(Vec2d::RIGHT);
}


static void init(int argc, char *argv[]) {
    Text::init();
    palette = Palette::getInstance();
    
    screens = new Screens(width, height);
    world = new World(width/Primitive::DEFAULT_PIXEL_SIZE, height/Primitive::DEFAULT_PIXEL_SIZE);
    snake = new Snake(world->getOrigin());

	resetToOrigin();
    spawnPickup();

    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(palette->getBgColour()->getR(), palette->getBgColour()->getG(), palette->getBgColour()->getB(), 0);
}

static int roundUp(int numToRound, int multiple) {
    if (multiple == 0) {
        return numToRound;
    }
    int remainder = numToRound % multiple;
    if (remainder == 0) {
        return numToRound;
    }
    return numToRound + multiple - remainder;
}

static bool hitPickup() {
    return randomPickup->collidesWith(snake->getCoords());
}

static bool outOfBounds() {
    return world->collidesWith(snake->getCoords());
}


static void processWorld(void) {
    GLint tick = roundUp(glfwGetTime() * 1000, 100 * (100 / gameSpeed));
    if (state == DEAD) {
        if (tick > lastUpdate) {
            lastUpdate = tick;
        }
        if (tick - deadStartTime > 3000) {
            state = MENU;
        }
    } else if (state == PLAYING) {
        if (tick > lastUpdate) {
            lastUpdate = tick;
            if (hitPickup()) {
                if (!snake->incrementLength(randomPickup->getColour())) {
                    state = COMPLETE;
                    resetToOrigin();
                }
                spawnPickup();
            } else if (outOfBounds()) {
                state = DEAD;
                resetToOrigin();
                spawnPickup();
                deadStartTime = lastUpdate;
            } else if (!snake->update()) {
                state = DEAD;
                resetToOrigin();
                spawnPickup();
                deadStartTime = lastUpdate;
            }
        }
    }
}

void reshape(GLFWwindow* window, int width, int height ) {
    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0, width, height, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW );
    glLoadIdentity();
}


int main(int argc, char *argv[]) {
    mainLog = Logger::getLogger("main");
    mainLog->log(Logger::LEVEL_DEBUG, "Logger initialised");
    
    srand((int) time(0));
    
    GLFWwindow* window;

    if(!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n" );
        exit(EXIT_FAILURE );
    }
    
    window = glfwCreateWindow(width, height, "lanaSnake", NULL, NULL);
    
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    if(!window) {
        fprintf(stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit(EXIT_FAILURE );
    }
    
    glfwMakeContextCurrent(window);
    reshape(window, width, height);
    
    init(argc, argv);
    
    glfwSetWindowSizeCallback(window, reshape);
    glfwSetKeyCallback(window, key);
    
    while(!glfwWindowShouldClose(window)) {
        draw();
        processWorld();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

