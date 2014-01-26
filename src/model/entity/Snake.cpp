#include "Snake.h"

Vec2d* Snake::BASE_DIR = new Vec2d(1, 0);
Logger* Snake::log = Logger::getLogger("Snake");

Snake::Snake(Vec2d* coords): Entity(coords) {
    resetSnake();
}

bool Snake::incrementLength(Colour* colour) {
    logState();
    segments->push_back(new Segment(segments->back()->getRelativeCoord(), colour));
    return segments->size() < MAX_LENGTH;
}

Vec2d* Snake::getDirection() {
    return this->direction;
}

void Snake::addDirectionToQueue(Vec2d* direction) {
    log->info("comparing " + *direction->toString() + " to " + *this->direction->toString());
    if (this->direction->equals(direction->getInverse())) {
        log->info("AH FUCKING HA");
    } else if (directionQueue.empty()) {
        directionQueue.push_front(direction);
    } else {
        log->info("comparing " + *direction->toString() + " to " + *directionQueue.back()->toString());
        if (!direction->equals(directionQueue.back())) {
            directionQueue.push_front(direction);
        }
    }
}

bool Snake::update() {
    if (directionQueue.empty()) {
        directionQueue.push_front(direction);
    }
    return changeDirection();
}

bool Snake::changeDirection() {
    log->trace("Changing Direction entered:");
    while(!directionQueue.empty()) {
        if (changeDirection(directionQueue.front())) {
            directionQueue.pop_back();
        } else {
            return false;
        }
    }
    return true;
}

bool Snake::changeDirection(Vec2d* direction) {
    log->trace(" - " + *direction->toString());
    
    if (live) {
        if (collidesWith(getCoords())) {
            return false;
        }
    } else {
        live = true;
    }

    getCoords()->applyOffset(direction);
    this->direction = new Vec2d(direction);

    for (int i = (int) segments->size() - 1; i>0; i--) {
        log->trace("updating element " + to_string(i) + " to " + *segments->at(i-1)->getRelativeCoord()->toString());
        segments->at(i)->setRelativeCoord(segments->at(i-1)->getRelativeCoord());
    }

    log->trace("updating element 1 to " + *direction->toString());
    segments->front()->setRelativeCoord(direction);
    return true;
}

void Snake::resetSnake() {
    palette::initColours();
    segments = new vector<Segment*>();
    direction = new Vec2d(Vec2d::RIGHT);
    directionQueue.clear();
    live = false;
    
    segments->push_back(new Segment(new Vec2d(0,0), palette::getPink()));
    for (int i=1; i<MIN_LENGTH; i++) {
        Segment* newSeg = new Segment(new Vec2d(BASE_DIR), palette::getPink());
        segments->push_back(newSeg);
    }
}

vector<Segment*>* Snake::getMesh() {
    return segments;
}

bool Snake::collidesWith(Vec2d *coords) {
    Vec2d* testCoord = new Vec2d(getCoords());
    bool collision = false;
    for (Segment* seg : *segments) {
        testCoord->applyOffset(seg->getRelativeCoord()->getInverse());
        if (testCoord->equals(coords)) {
            log->log(Logger::LOG_LEVEL::LEVEL_INFO, "you and I, collide");
            collision = true;
            break;
        }
    }
    return collision;
}

void Snake::logState() {
    log->log(Logger::LEVEL_INFO, "SNAKE STATE:");
    for (Segment* seg : *segments) {
        log->log(Logger::LEVEL_INFO, *seg->getRelativeCoord()->toString());
    }
}
