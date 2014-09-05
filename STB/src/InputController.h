#pragma once
class InputController
{
public:
	//------SINGLETON-----//
	//getInstance returns the instance of ViewController. Used to call most functions.
	//
	//getInstance is used to return the instance of ViewController. This is used to prevent multiple instances of this controller to be made. 
	//@return ViewController instance;
	static InputController& getInstance()
	{
		static InputController    instance;
		return instance;
	}

	//startThread, used to start the thread of the ViewController.
	//
	//startThread starts the thread the ViewController uses to draw everything.
	void InputController::startThread();

	//run, do not call!
	//
	//run is the function that actually does everything the ViewController has to do. Do not call this, instead use startThread()!
	void InputController::run();
	//------END OF SINGLETON------//

private:
	//------SINGLETON-----//
	InputController() {}
	InputController(InputController const&); // Don't Implement.
	void operator=(InputController const&); // Don't implement.
	//------END OF SINGLETON------//

	void InputController::step();
};

