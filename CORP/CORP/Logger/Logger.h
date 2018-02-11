#ifndef _LOGGER_GUARD
#define _LOGGER_GUARD

#include <fstream>
#include <iostream>
#include <string>
#include <mutex>

class Logger
{

public:
	
	static Logger& mainLog();

	void log(const std::string& message, const std::string& logLevel);

	static const std::string logTypeInfo;
	static const std::string logTypeDebug;
	static const std::string logTypeError;

protected:
	static Logger* pointMainLog;
	
	friend class Reset;
	class Reset
	{
	public:
		~Reset();
	};

	static const std::string fileName;
	static std::ofstream outputStream;
	void logHelper(const std::string& message,
		const std::string& logLevel);

private:
//Default Constructor
	Logger();
// ? virtual ?
	virtual ~Logger();

	Logger(const Logger&);
	Logger& operator=(const Logger&);

	static std::mutex logMutex;
};

#endif // !_LOGGER_GUARD