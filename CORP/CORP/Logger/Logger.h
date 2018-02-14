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
	void log(const std::string& message);

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
	void logHelper(const std::string& message);

private:
//Default Constructor
	Logger();
// ? virtual ?
	virtual ~Logger();

	Logger(const Logger&);
	Logger& operator=(const Logger&);
};

#endif // !_LOGGER_GUARD