//
// Created by maciej on 20.08.18.
//

#ifndef PARANOID_LOGGER_HPP
#define PARANOID_LOGGER_HPP

#include <fstream>
#include <memory>


class Logger
{
public:
    Logger () = delete;
    Logger (const std::string &_nameOfLoggerOwner);
    virtual ~Logger ();
private:
    std::string _nameOfLoggerOwner;
    std::string _buffer;
    static std::unique_ptr<std::ofstream> _logFile;
    static void initLogFile();
    friend Logger& operator << (Logger &log, const char *strm);
    friend Logger& operator <<(Logger& log, Logger& strm);

};




#endif //PARANOID_LOGGER_HPP
