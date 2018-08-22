//
// Created by maciej on 20.08.18.
//

#ifndef PARANOID_LOGGER_HPP
#define PARANOID_LOGGER_HPP

#include <fstream>
#include <memory>
const unsigned int maxBufferSize = 1024;

enum class logging{
    logEnd,
    warning,
    debug
};

class Logger
{
public:
    Logger () = delete;
    explicit Logger (const std::string &_nameOfLoggerOwner);
    virtual ~Logger ();
    void setNameOfLoggerOwner (const std::string &nameOfLoggerOwner);
private:
    std::string _buffer;
    std::string _nameOfLoggerOwner;
    static std::unique_ptr<std::ofstream> _logFile;
    static void initLogFile();
    void clearBuffer();
    friend Logger& operator << (Logger &log, const char* strm);
    friend Logger& operator << (Logger &log, logging&& strm);
};





#endif //PARANOID_LOGGER_HPP
