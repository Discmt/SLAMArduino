 #include"Logger.h";

extern String Logger::slamLogStack_ = "";
extern int Logger::slamStackCount_ = 0;
extern int Logger::nestLevel_ = 0;
extern Logger::LogSetting Logger::logSettings_[] = {
                                           LogSetting(File, VERBOSE),
                                           LogSetting(GlobalGrid, VERBOSE),
										   LogSetting(Logging, WARNING)
                                            };

void Logger::addNest() {
  nestLevel_++;
}

void Logger::removeNest() {
  if(nestLevel_ > 0) {
    nestLevel_--;
  }
}

void Logger::clearMethodStack() {
  slamLogStack_ = "";
  slamStackCount_ = 0;
}

void Logger::popMethodStack() {
  if(slamStackCount_ == 1) 
  {
    clearMethodStack();
  } 
  else if(slamStackCount_ > 0 && slamLogStack_ != "") 
  {
    int i = slamLogStack_.length()-1;
    char c;
    do {
        c = slamLogStack_.charAt(i);
        i--;
    } while (c != '\n' && i >= 0);
  }
}

void Logger::pushMethodStack(String methodName) {
    if(methodName != "" && methodName != "\n") {
      slamLogStack_+=methodName;
      slamLogStack_+='\n';
      slamStackCount_++;
    }
}

void Logger::log(LogComponent component, LogLevel level, String title) {
      log(component,level,title,"");
}


void Logger::log(LogComponent component, LogLevel level,String title, String details) {
    
    if(logSettings_[component].level_ >= level) {
        String header = buildHeader(component,level,title);;
        
        if(header != "") {
          Serial.print(header);
        }
        
		Serial.print("\n");

        if(details != "") {
          Serial.println(details);
        } else {	
		}
        
        if(slamStackCount_ > 0 && logSettings_[component].level_ > 3) {
          Serial.println("Method Stack: ");
          Serial.println(slamLogStack_);
          Serial.print("\n");
        }
		slowDown();
    }
}

void Logger::log(LogComponent component, LogLevel level,String title, String details[], int numberOfDetails) {
    if(logSettings_[component].level_ >= level) {
        String header = buildHeader(component,level,title);;
        
        if(header != "") {
          Serial.print(header);
        }
        
        for(int i = 0; i < numberOfDetails; i++) {
		  Serial.println(details[i]);
		}
        
        if(slamStackCount_ > 0 && logSettings_[component].level_ > 3) {
          Serial.println("Method Stack: ");
          Serial.println(slamLogStack_);
          Serial.print("\n");
        }
    }
	slowDown();
}

String Logger::buildHeader(LogComponent component, LogLevel level, String title) {
        String header;
        header+="+++";
        unsigned long time = millis();
        switch(component) {
        case GlobalGrid:
              header+=" GlobalGrid ";
        case File:
              header+=" File ";
			  break;
		case Logging:
			  header+=" Logging ";
			  break;
          default:
              header+=" Default ";
			  break;
        }
        header+="+++";
	header+=':';
        header+=' ';
        header+=level;
        header+=' ';
        header+=title;
        header+=' ';
        header+=time;
	header+='\n';
    
        return header;
}

void Logger::slowDown() {
	if(!Settings::Settings::SLOW_DOWN) return;
	Logger::log(Logger::Logging, Logger::DEBUG, "Slow down called");
	unsigned long time = millis();
	unsigned long diff = 0;
	do {
		diff=(millis()-time);
	} while (diff < 5000);
}

char * LogUtil::getCharArray(String s, int size) {
    if(s== "") return "";
    char a[size+1];
    s.toCharArray(a,size-1);
    return a;
}
