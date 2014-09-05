#pragma once
class LevelController
{
public:
	//------SINGLETON-----//
	//getInstance returns the instance of ViewController. Used to call most functions.
	//
	//getInstance is used to return the instance of ViewController. This is used to prevent multiple instances of this controller to be made. 
	//@return ViewController instance;
	static LevelController& getInstance()
	{
		static LevelController    instance;
		return instance;
	}

	//startThread, used to start the thread of the ViewController.
	//
	//startThread starts the thread the ViewController uses to draw everything.
	void LevelController::startThread();

	//run, do not call!
	//
	//run is the function that actually does everything the ViewController has to do. Do not call this, instead use startThread()!
	void LevelController::run();
	//------END OF SINGLETON------//

private:
	//------SINGLETON-----//
	LevelController() {}
	LevelController(LevelController const&); // Don't Implement.
	void operator=(LevelController const&); // Don't implement.
	//------END OF SINGLETON------//

	void LevelController::step();
};

