
#pragma once
#include <iostream>


class Log
{
    
public:

    enum Level { Warning, Error, Info };

    static std::ostream& GetStream() { return std::cout; }
    static bool IsLevelActive() { return true; }
};


#ifdef LOG
#define LOG_ERROR(M)   do { if (true)   (Log::GetStream() <<"[ERROR]: " << M << "\n"); } while (false)
#define LOG_INFO(M)    do { if (true)    (Log::GetStream() << "[INFO]: " << M << "\n"); } while (false)
#define LOG_WARNING(M) do { if (Log::IsLevelActive(Log::Warning)) (Log::GetStream() << "[WARNING]: " << M << "\n"); } while (false)
#else
#define LOG_ERROR(M)
#define LOG_INFO(M)
#define LOG_WARNING(M)
#endif
