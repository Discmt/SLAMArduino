
#ifndef LOGGER_H
#define LOGGER_H
#include<Arduino.h>

namespace Logger {
  
  enum LogLevel {
        WARNING = 1,
        ERROR = 2,
        INFO = 3,
        DEBUG = 4,
        VERBOSE = 5
  };
  
  enum LogComponent {
	File = 0,
        GlobalGrid = 1
  };
  
  /** A container for mapping a LogComponent to a setting value */
  struct LogSetting {
        LogSetting(LogComponent component, LogLevel level) {component_ = component; level_ = level;};
        
        /** Log Component */
        LogComponent component_;
        
        /** Log Level for corresponding component */
        LogLevel level_;
  };
  
  
  extern LogSetting logSettings_[];
  extern String slamLogStack_;
  extern int slamStackCount_;
  extern int nestLevel_;
  
  /** Add a logging nest */
  void addNest();
  
  /** Remove a logging nest */
  void removeNest();
  
  /** Clear the method stack */
  void clearMethodStack(); 
  
  /** Add a method to the method stack for logging purposes. Note: Becareful when using this method, it does not do anything in the way of verying you are correctly removing methods */
  void pushMethodStack(String methodName);
  
  /** Remove the top method from the method stack */
  void popMethodStack();
  
  /** Log a message on the serial communication monitor */
  void log(LogComponent component, LogLevel level ,String title);
  
  /** Log a message on the serial communication monitor */
  void log(LogComponent component, LogLevel level, String title, String details);

  /** Constructs a header with a new line */
  String buildHeader(LogComponent component, LogLevel level,String title);
  
}

/** Container for file related methods */
namespace LogUtil {

  char * getCharArray(String s);
  

}

#endif
