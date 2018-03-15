#include "console-program.h"

void ConsoleProgram::run(){
	Calculator _calc;
	std::string userInput;

	while (1){

			std::cout << "Calculator >>";
			std::getline(std::cin, userInput);

			if (userInput == std::string("exit")) {
				return;
			}

			try {
				double result = _calc.calculate(userInput);
				std::cout << "result = " << result << std::endl;
			}
			catch (std::runtime_error& ex) {
				std::cout << ex.what() << std::endl;
			}


			continue;
		}

}
