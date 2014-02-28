//
//  Logger.cpp
//  snake
//
//  Created by Andy Stanton on 27/05/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#include "Logger.h"

map<string, Logger> loggers;

Logger* Logger::getLogger(string name) {
    
    Logger* logger = &loggers.find(name)->second;
    if (logger == NULL) {
        logger = new Logger(name);
    }
    return logger;
}

Logger::Logger(string name) {
    this->name = name;
    logToStd = true;
    logToFile = false;
}

void Logger::info(string message) {
    log(LEVEL_INFO, message);
}

void Logger::debug(string message) {
    log(LEVEL_DEBUG, message);
}

void Logger::error(string message) {
    log(LEVEL_ERROR, message);
}

void Logger::warn(string message) {
    log(LEVEL_WARN, message);
}

void Logger::trace(string message) {
    log(LEVEL_TRACE, message);
}

void Logger::log(LOG_LEVEL level, int message) {
    stringstream stream;
    stream << message;
    log(level, stream.str());
}

void Logger::log(LOG_LEVEL level, float message) {
    stringstream stream;
    stream << message;
    log(level, stream.str());
}

void Logger::log(LOG_LEVEL level, string message) {
    if (level >= Logger::DISPLAY_LEVEL) {
        time_t t = time(0);
        struct tm* now = localtime(&t);
        stringstream timestamp;
        timestamp << "[" << setfill('0') << setw(2) << now->tm_hour << ":" << setfill('0') << setw(2) << now->tm_min << ":" << setfill('0') << setw(2) << now->tm_sec << "] ";
        
        if (logToStd) {
        cout << timestamp.str() << message << endl;
        }
        /*
        if (logToFile) {
        ofstream fileOut = ofstream("log.txt", fstream::out | fstream::app);
        fileOut << timestamp.str() << message << endl;
        fileOut.close();
        }
        */
    }
}

void Logger::configure() {
}
