#ifdef ARDUINO
    #include <ESP8266WiFi.h>
    #include <ESP8266WebServer.h>
#else
    #include <string>
    using namespace std;
    #define String string
#endif

namespace Utils{

    bool IsNumber(const String& p_number_str)
    {
        if (!p_number_str.length())
        {
            return false;
        }

        char ch;
        for (unsigned int i=0; i<p_number_str.length(); i++)
        {
            ch = (char) p_number_str[i];
            if (!isdigit(ch))
            {
                if (ch == '.')
                {
                    continue;
                }
                return false;
            }
        }

        return true;
    }
}