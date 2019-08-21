#include <Utils.h>
#include <Calculator.h>

ESP8266WebServer server(80);

const char *ssid = "RedeMarcelo2.4";
const char *password = "me+youfor3ver2.4";

void handleAdd()
{ //Handler for the body path

    if (!server.hasArg("a") || !server.hasArg("b"))
    {
        server.send(200, "text/plain", "Missing/Incorrect arguments");
        return;
    }

    String inputA = server.arg("a");
    String inputB = server.arg("b");

    if(!Utils::IsNumber(inputA) || !Utils::IsNumber(inputB))
    {
        server.send(200, "text/plain", "Parameters must be numbers");
        return;
    }
    
    double a = atof(inputA.c_str());
    double b = atof(inputB.c_str());

    double res = Calculator::add(a,b);

    String message;
    message = "{\n";
    message += "\t\"Result\": ";
    message += res;
    message += "\n}";

    server.send(200, "text/plain", message);
    Serial.println(inputA + " + " + inputB + " = " + res );
}

void handleSubtract()
{ //Handler for the body path

    if (!server.hasArg("a") || !server.hasArg("b"))
    {
        server.send(200, "text/plain", "Missing/Incorrect arguments");
        return;
    }

    String inputA = server.arg("a");
    String inputB = server.arg("b");

    if(!Utils::IsNumber(inputA) || !Utils::IsNumber(inputB))
    {
        server.send(200, "text/plain", "Parameters must be numbers");
        return;
    }
    
    double a = atof(inputA.c_str());
    double b = atof(inputB.c_str());

    double res = Calculator::sub(a,b);

    String message;
    message = "{\n";
    message += "\t\"Result\": ";
    message += res;
    message += "\n}";

    server.send(200, "text/plain", message);
    Serial.println(inputA + " - " + inputB + " = " + res );
}

void handleMultiply()
{ //Handler for the body path

    if (!server.hasArg("a") || !server.hasArg("b"))
    {
        server.send(200, "text/plain", "Missing/Incorrect arguments");
        return;
    }

    String inputA = server.arg("a");
    String inputB = server.arg("b");

    if(!Utils::IsNumber(inputA) || !Utils::IsNumber(inputB))
    {
        server.send(200, "text/plain", "Parameters must be numbers");
        return;
    }
    
    double a = atof(inputA.c_str());
    double b = atof(inputB.c_str());

    double res = Calculator::mul(a,b);

    String message;
    message = "{\n";
    message += "\t\"Result\": ";
    message += res;
    message += "\n}";

    server.send(200, "text/plain", message);
    Serial.println(inputA + " * " + inputB + " = " + res );
}

void handleDivide()
{ //Handler for the body path

    if (!server.hasArg("a") || !server.hasArg("b"))
    {
        server.send(200, "text/plain", "Missing/Incorrect arguments");
        return;
    }

    String inputA = server.arg("a");
    String inputB = server.arg("b");

    if(!Utils::IsNumber(inputA) || !Utils::IsNumber(inputB))
    {
        server.send(200, "text/plain", "Parameters must be numbers");
        return;
    }
    
    double a = atof(inputA.c_str());
    double b = atof(inputB.c_str());

    if(!b)
    {
        server.send(200, "text/plain", "Parameter b cannot be zero");
        return;
    }

    double res = Calculator::div(a,b);

    String message;
    message = "{\n";
    message += "\t\"Result\": ";
    message += res;
    message += "\n}";

    server.send(200, "text/plain", message);

    Serial.println(inputA + " / " + inputB + " = " + res );
}

void setup()
{
    Serial.begin(115200);
    WiFi.begin(ssid, password); //Connect to the WiFi network

    delay(1000);
    Serial.println("Waiting to connect");
    while (WiFi.status() != WL_CONNECTED)
    { //Wait for connection
        delay(1000);
        Serial.print(".");
    }
    Serial.println();

    Serial.print("IP address: ");
    Serial.println(WiFi.localIP()); //Print the local IP

    server.on("/add", handleAdd);
    server.on("/subtract", handleSubtract);
    server.on("/multiply", handleMultiply);
    server.on("/divide", handleDivide);
    
    server.begin(); //Start the server
    Serial.println("Server listening");
}

void loop()
{
    server.handleClient(); //Handling of incoming requests
}