# SyrenLogger
SyrenLogger is a simple header only C++ logging library with C# style string formatting.

## Features
- Log messages to the console with the option of colouring messages by log level.
- Log messages to files, including the ability to overwrite logged messages.
- Thread-safe logging
- Extensive ability to format how numerical data is displayed
- Format logged times to match a set timezone
- C# style string formatting for including variables in the log message 

## Getting Started
The following example illustrates how to use the library
```c++
#include "logger.h"

SyrenLogger::Logger log_manager;
log_manager.create_console_sink("Application");

auto logger = log_manager.get_sink("Application");
logger->Debug("This is a debug message");
logger->Error("This error message logs the value {0}", 1)
```
