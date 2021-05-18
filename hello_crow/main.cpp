#include "crow_all.h"
#include <boost/filesystem.hpp>
#include <sstream>
#include <fstream>
using namespace std;
using namespace crow;

#define CROW_ENABLE_LOGGING
void sendFile(response &res, string filename, string contentType)
{
    ifstream index("/usr/src/cppbox/hello_crow/public/" + filename, std::ios::in);

    if (index.is_open())
    {
        ostringstream contents;
        contents << index.rdbuf();
        index.close();
        res.set_header("Content-Type", contentType);
        res.write(contents.str());
    }
    else
    {
        res.write("Not found!");
    }
    res.end();
}

void sendHtml(response &res, string filename)
{
    sendFile(res, filename + ".html", "text/html");
}

void sendImage(response &res, string filename)
{
    sendFile(res, "images/" + filename, "image/jpeg");
}

void sendScript(response &res, string filename)
{
    sendFile(res, "scripts/" + filename, "text/javascript");
}

void sendStyle(response &res, string filename)
{
    sendFile(res, "styles/" + filename, "text/css");
}

int main(int argc, char* argv[])
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([](const request &req, response &res)
    {
        sendHtml(res, "index");
    });

    CROW_ROUTE(app, "/styles/<string>")
    ([](const request &req, response &res, string filename)
    {
        sendStyle(res, filename);
    });

    CROW_ROUTE(app, "/images/<string>")
    ([](const request &req, response &res, string filename)
    {
        sendImage(res, filename);
    });

    CROW_ROUTE(app, "/scripts/<string>")
    ([](const request &req, response &res, string filename)
    {
        sendScript(res, filename);
    });

    char* port = getenv("PORT");
    uint16_t iPort = static_cast<uint16_t>(port != NULL ? stoi(port): 18080);
    cout << "PORT = " << iPort << "\n";
    
    app.loglevel(crow::LogLevel::DEBUG);
    app.port(iPort).multithreaded().run();
}