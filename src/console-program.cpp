#include "console-program.h"

void ConsoleProgram::run(){
	Calculator _calc;
	std::string userCommand;
	std::string userInput;
	std::cout << "Calculator >>";

	while (1) {
		if (!_calc.is_empty()){
			std::getline(std::cin, userCommand);
			userInput = std::to_string(_calc.memory) + " " + userCommand;
		}
		else {
			std::getline(std::cin, userCommand);
			userInput = userCommand;
		}

		if (userCommand == std::string("exit")) {
			return;
		}

		if (userCommand == std::string("help")) {
			std::cout << "This is calculators help: enter a valid expression after Calculator> sign. \n You can continue to write an expression after obtaining an intermediate result. \n To start writing new expression push enter\ to reinitialize calculator write clear" << std::endl;
			std::cout << "Calculator >>";
			continue;
		}

		if (userCommand == std::string("clear")) {
			_calc.clear();
			std::cout << std::endl;
			std::cout << "Calculator >>";
			continue;
		}

		try {
			double result = _calc.calculate(userInput);
			std::cout << " = " << result << " ";
		}
		catch (std::runtime_error& ex) {
			std::cout << ex.what() << std::endl;
			std::cout << "Calculator >>";
		}


		continue;
	}

}
