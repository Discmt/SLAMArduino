 #include"Logger.h";

extern String Logger::slamLogStack = "";
extern int Logger::slamStackCount = 0;
extern int Logger::nest = 0;

void Logger::addNest() {
  nest++;
}

void Logger::removeNest() {
  if(nest > 0) {
    nest--;
  }
}

void Logger::clearMethodStack() {
  slamLogStack = "";
  slamStackCount = 0;
}

void Logger::popOffMethodStack() {
  if(slamStackCount == 1) 
  {
    clearMethodStack();
  } 
  else if(slamStackCount > 0 && slamLogStack != "") 
  {
    int i = slamLogStack.length()-1;
    char c;
    do {
        c = slamLogStack.charAt(i);
        i--;
    } while (c != '\n' && i >= 0);
  }
}

void Logger::pushMethodStack(String methodName) {
    if(methodName != "" && methodName != "\n") {
      slamLogStack+=methodName;
      slamLogStack+='\n';
      slamStackCount++;
    }
}

void Logger::log(LogComponent component, String title) {
      log(component,title,"");
}


void Logger::log(LogComponent component, String title, String details) {
    String header = buildHeader(component, title);;
    
    if(header != "") {
      Serial.print(header);
    }
    
    if(details != "") {
      Serial.println(details);
    }
    
    if(slamStackCoint > 0) {
      Serial.println(details);
    }
}

String Logger::buildHeader(LogComponent component, String title) {
        String header;
        header+="+++";
        unsigned long time = millis();
        switch(component) {
        case GlobalGrid:
              header+=" GlobalGrid ";
        case File:
              header+=" File ";
			  break;
          default:
              header+=" Default ";
			  break;
        }
        header+="+++";
	header+=' ';
	header+=':';
        header+=title;
        header+=' ';
        header+=time;
	header+='\n';
    
        return header;
}

char * LogUtil::getCharArray(String s) {
    if(s== "") return "";
    char a[s.length()];
    s.toCharArray(a,s.length());
    return a;
}
