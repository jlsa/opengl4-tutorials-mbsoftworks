// STL
#include <iostream>

// Project
#include "010-first-great-refactoring.h"

/**
 * Application entry point function.
 * Uses MessageBox function on Windows systems to ask about fullscreen mode and console query on Unix systems.
 */
int main()
{
	const std::string& windowTitle = "010.) First Great Refactoring - Tutorial by Michal Bubnar (www.mbsoftworks.sk)";
	int majorVersion = 4;
	int minorVersion = 4;

#ifdef _WIN32
	bool showFullscreen = MessageBox(nullptr, "Would you like to run in fullscreen mode?", "Fullscreen", MB_ICONQUESTION | MB_YESNO) == IDYES;
#else
	char answer;
	std::cout << "Would you like to run in fullscreen mode? (y/n): ";
	std::cin >> answer;
	bool showFullscreen = tolower(answer) == 'y';
#endif
	
	OpenGLWindow010 window;
	if (!window.createOpenGLWindow(windowTitle, majorVersion, minorVersion, showFullscreen))
	{
		printf("Failed to create window with OpenGL context %d.%d! Shutting down...\n", majorVersion, minorVersion);
		return 1;
	}

	window.runApp();

	if (window.hasErrorOccured())
	{
		std::cout << std::endl << std::endl << "Program could not start because of the above errors! Press ENTER to quit..." << std::endl;
		std::cin.get();
		return 1;
	}

	return 0;
}