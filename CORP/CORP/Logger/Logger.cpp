#include "Logger.h"
#include "stdexcept"

const std::string Logger::logTypeDebug = "DEBUG";
const std::string Logger::logTypeInfo = "INFO";
const std::string Logger::logTypeError = "ERROR";

const std::string Logger::fileName = "log.txt";
Logger* Logger::pointMainLog = nullptr;
std::mutex Logger::logMutex;

Logger& Logger::mainLog()
{ 
	static Reset cleanup;
	std::lock_guard<std::mutex> guard(logMutex);
	if (pointMainLog == nullptr)
		pointMainLog = new Logger();
	return *pointMainLog;
}

Logger::Reset::~Reset()
{
	std::lock_guard<std::mutex> guard(Logger::logMutex);
	delete Logger::pointMainLog;
	Logger::pointMainLog == nullptr;
}

Logger::~Logger()
{
	outputStream.close();
}

Logger::Logger()
{
	outputStream.open(fileName);
	if (!outputStream.good()) {
		throw std::runtime_error("Unable to initialize the log!");
	}
}

void Logger::log(const std::string& message, const std::string& logLevel)
{
	std::lock_guard<std::mutex> guard(logMutex);
	logHelper(message,logLevel);
}

void Logger::logHelper(const std::string& inMessage, const std::string& inLogLevel)
{
	outputStream << inLogLevel << ": " << inMessage << std::endl;
}