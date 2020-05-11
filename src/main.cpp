#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    double width;           // Will contain the default window width
    double height;          // Will contain the default window height
    int wd;                 // Will contain the dimensions of the window
    int configLineNum;      // Will track place in the config file
    bool init;              // Will start the program
    string configLine;      // Used in parsing the config file

    ifstream configFile;    // A stream pointer for grabbing the config settings

    configLineNum = 0;
    init = 0;

    // Get cofiguration settings from file
    if (argc > 1)
    {
        configLine = argv[1];

        if (configLine.compare("config.txt") == 0)
        {
            configFile.open(configLine.c_str(), ios::in);
        
            while (std::getline(configFile, configLine))
            {
                switch(configLineNum)
                {
                    case 0:
                    {
                        width = stod(configLine);
                        break;
                    }
                    case 1:
                    {
                        height = stod(configLine);
                        break;
                    }
                    default:
                        break;
                }

                configLineNum++;
            }

            init = 1;
        }
    }
    else
    {
        cout << "Must provide a configuration file." << endl;
    }

    if (init)
    {
        // Initialize glut

        glutInit(&argc, argv);

        // Set the display mode
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

        // Set the initial window size
        glutInitWindowSize((int) width, (int) height);

        wd = glutCreateWindow("BreakOut");

        // Start the main loop
        glutMainLoop();
    }

    return 0;
}
