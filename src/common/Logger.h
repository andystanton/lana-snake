//
//  Logger.h
//  snake
//
//  Created by Andy Stanton on 27/05/2013.
//  Copyright (c) 2013 Andy Stanton. All rights reserved.
//

#ifndef __snake__Logger__
#define __snake__Logger__

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Logger {
private:
    Logger(string name);
    string name;
    bool logToStd;
    bool logToFile;
public:
    enum LOG_LEVEL {
        LEVEL_ERROR = 5,
        LEVEL_WARN  = 4,
        LEVEL_INFO  = 3,
        LEVEL_DEBUG = 2,
        LEVEL_TRACE = 1
    };
    static const LOG_LEVEL DISPLAY_LEVEL = LEVEL_INFO;
    static void configure();
    static Logger* getLogger(string name);
    void log(LOG_LEVEL level, string message);
    void log(LOG_LEVEL level, int message);
    void log(LOG_LEVEL level, float message);
    void info(string message);
    void error(string message);
    void debug(string message);
    void warn(string message);
    void trace(string message);
};

#endif /* defined(__snake__Logger__) */
