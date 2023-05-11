#pragma once

#include <string>
#include <iostream>

#include "common.h"
#include "base_sink.h"


namespace SyrenLogger {

	class ConsoleSink : public BaseSink
		// logs data to the console 
	{
	public:
		ConsoleSink(const char* uniqueid) : BaseSink(uniqueid) {} // constructor used to set default formatter properties

	private:
		ConsoleSink& operator=(ConsoleSink other) {}

		virtual void log(std::string message, LogLevel level) {
			// prints logging message to the console 
			message = message + "\n";
			printf(message.c_str());
		}
	};

};
