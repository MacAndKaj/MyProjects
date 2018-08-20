//


//
// Created by maciej on 20.08.18.

#include <Logger.hpp>
#include <ctime>

using namespace std;

unique_ptr<ofstream> Logger::_logFile = unique_ptr<ofstream>(nullptr);
Logger::Logger (const string &_nameOfLoggerOwner) : _nameOfLoggerOwner(_nameOfLoggerOwner)
{
    if (not Logger::_logFile) initLogFile();
}

void Logger::initLogFile ()
{
    auto now = time(nullptr);
    auto timeNow = localtime(&now);
    string fileName = "logs/";
    fileName += to_string(timeNow->tm_year);
    fileName += to_string(timeNow->tm_mon);
    fileName += to_string(timeNow->tm_mday);
    fileName += to_string(timeNow->tm_hour);
    fileName += to_string(timeNow->tm_min);
    fileName += ".log";
    Logger::_logFile = make_unique<ofstream>(fileName);
}

Logger::~Logger ()
{
    if (Logger::_logFile) {
        if (Logger::_logFile->is_open()) _logFile->close();
    }
}


Logger &operator<< (Logger &log, Debug& dbgStrm)
{
    if ( log._logFile->is_open() and dbgStrm._buffer.size() > 0 )
        *log._logFile << dbgStrm._buffer;
    dbgStrm._buffer.clear();
    return log;
}

Debug &operator<< (Debug &dbg, const char* strm)
{
    std::string tmp{strm};
    tmp += ' ';
    if (tmp.size()>0)
    {
        dbg._buffer.append(tmp);
    }
}