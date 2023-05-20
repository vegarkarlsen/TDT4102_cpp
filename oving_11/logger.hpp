
#pragma once
#include <iostream>
// #include <ctime>

#ifndef LOG_LEVEL
    #define LOG_LEVEL Log::Level::Debug
#endif

class Log{
    
    public:
        enum Level { Silent = 0, Error, Warning, Info, Debug};

        static std::ostream& getStream() { return std::cout; }
        static bool IsLevelActive(Level l) {return LOG_LEVEL >= l ; }
        
};



#define DEBUG(...) do {                                     \
    if (Log::IsLevelActive(Log::Debug))(                        \
        Log::getStream() << "[DEBUG] " << __VA_ARGS__   <<  "\n"         \
    ); } while (false)


#define INFO(...) do {                                      \
    if (Log::IsLevelActive(Log::Info))(                         \
        Log::getStream() << "[INFO] " << __VA_ARGS__  <<  "\n"          \
    ); } while (false)


#define WARN(...) do {                                      \
    if (Log::IsLevelActive(Log::Warning))(                      \
        Log::getStream() << "[WARNING] File: " << __FILE__ <<   \
        " line " << __LINE__ << "; "<< __VA_ARGS__  <<  "\n"            \
    ); } while (false)

#define ERROR(...) do {                                     \
    if (Log::IsLevelActive(Log::Error))(                        \
        Log::getStream() << "[ERROR] File: " << __FILE__ <<     \
        " line " << __LINE__ << "; "<< __VA_ARGS__  <<  "\n"    \
    ); } while (false)



