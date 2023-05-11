#pragma once

#include <string>
#include <iostream>

#include <windows.h>

#include "common.h"
#include "base_sink.h"


namespace SyrenLogger {

	class ConsoleColourSink : public BaseSink
	{
		// sink that writes messages to the console in the colour assigned to the logging level (colours can only be set on object creation)
	private:
		Colour trace_colour; // colour of the trace logging level
		Colour debug_colour; // colour of the debug logging level
		Colour info_colour; // colour of the info logging level
		Colour warning_colour; // colour of the warning logging level
		Colour error_colour; // colour of the error logging level
		Colour fatal_colour; // colour of the fatal logging level

	public:
		ConsoleColourSink(const char* uniqueid) : BaseSink(uniqueid) {
			// constructor used to set default colours
			trace_colour = Colour::GREEN;
			debug_colour = Colour::CYAN;
			info_colour = Colour::WHITE;
			warning_colour = Colour::BLUE;
			error_colour = Colour::YELLOW;
			fatal_colour = Colour::RED;
		}

		virtual void set_colour(Colour colour, LogLevel level) {
			switch (level) {
			case LogLevel::LTRACE:
				trace_colour = colour;
				break;
			case LogLevel::LDEBUG:
				debug_colour = colour;
				break;
			case LogLevel::LINFO:
				info_colour = colour;
				break;
			case LogLevel::LWARNING:
				warning_colour = colour;
				break;
			case LogLevel::LERROR:
				error_colour = colour;
				break;
			case LogLevel::LFATAL:
				fatal_colour = colour;
				break;
			}
		}

	private:
		ConsoleColourSink& operator=(ConsoleColourSink other) {}

		virtual void log(std::string message, LogLevel level)
		{
			// changes console colour based on logging level, prints message to console, then switches colour back to default colour
			switch (level) {
			case LogLevel::LTRACE:
				change_colour(trace_colour);
				break;
			case LogLevel::LDEBUG:
				change_colour(debug_colour);
				break;
			case LogLevel::LINFO:
				change_colour(info_colour);
				break;
			case LogLevel::LWARNING:
				change_colour(warning_colour);
				break;
			case LogLevel::LERROR:
				change_colour(error_colour);
				break;
			case LogLevel::LFATAL:
				change_colour(fatal_colour);
				break;
			}

			message = message + "\n";
			printf(message.c_str());
			change_colour(Colour::DEFAULT);
		}

		void change_colour(Colour colour) {
			// changes colour of console output based on operating system (does not chnage colour if the operating system is unknown)
			switch (operating_system) {
			case OperatingSystem::Windows:
				change_colour_windows(colour);
				break;
			case OperatingSystem::Linux:
				change_colour_linux(colour);
				break;
			case OperatingSystem::Unknown:
				break;
			}

		}

		void change_colour_windows(Colour colour) {
			// windows operating system specific console colour change using a windows handle to the console
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			switch (colour) {
			case Colour::WHITE:
				SetConsoleTextAttribute(hConsole, 15);
				break;
			case Colour::CYAN:
				SetConsoleTextAttribute(hConsole, 11);
				break;
			case Colour::GREEN:
				SetConsoleTextAttribute(hConsole, 10);
				break;
			case Colour::BLUE:
				SetConsoleTextAttribute(hConsole, 9);
				break;
			case Colour::YELLOW:
				SetConsoleTextAttribute(hConsole, 14);
				break;
			case Colour::RED:
				SetConsoleTextAttribute(hConsole, 12);
				break;
			case Colour::DEFAULT:
				SetConsoleTextAttribute(hConsole, 7);
				break;
			}
		}

		void change_colour_linux(Colour colour) {
			// linux operating system specific colour change (to be implemented)
			switch (colour) {
			case Colour::WHITE:
				break;
			case Colour::CYAN:
				break;
			case Colour::GREEN:
				break;
			case Colour::BLUE:
				break;
			case Colour::YELLOW:
				break;
			case Colour::RED:
				break;
			case Colour::DEFAULT:
				break;
			}
		}

	};

};


