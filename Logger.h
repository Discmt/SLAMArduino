
#ifndef LOGGER_H
#define LOGGER_H
#include<Arduino.h>

namespace Logger {
  enum LogComponent {
	File = 1,
        GlobalGrid = 2
  };
  
  extern String slamLogStack;
  extern int slamStackCount;
  extern int nest;
  
  /** Add a logging nest */
  void addNest();
  
  /** Remove a logging nest */
  void removeNest();
  
  /** Clear the method stack */
  void clearMethodStack(); 
  
  /** Add a method to the method stack for logging purposes. Note: Becareful when using this method, it does not do anything in the way of verying you are correctly removing methods */
  void pushMethodStack(String methodName);
  
  /** Remove the top method from the method stack */
  void popOffMethodStack();
  
  /** Log a message on the serial communication monitor */
  void log(LogComponent component, String title);
  
  /** Log a message on the serial communication monitor */
  void log(LogComponent component, String title, String details);

  /** Constructs a header with a new line */
  String buildHeader(LogComponent component, String title);
  
}

/** Container for file related methods */
namespace LogUtil {

  char * getCharArray(String s);
  

}

#endif
