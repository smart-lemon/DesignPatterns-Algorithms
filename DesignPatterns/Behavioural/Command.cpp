#include "./../../Include/Common.h"

using namespace std;

#include <list>
#include <iterator>

/* 
    ######## Command pattern ########
    
    This pattern allows decoupling between the sender and the receiver 
    i.e the Sender and the reciver dont know about each other. 

    1. Command:  An interface for a Command to execute 

    2. ConcreteCommand: Defines a binding between Receiver and an Action
     → e.g TurnTvOn, TurnTvOff

    3. Client: Generates the Command object
     → e.g testCommandPattern

    4. Invoker : Decides which method should be called 
     → e.g InvokerRemoteButton
*/

// 
class ElectronicDevice {
    public:
        virtual void on()  = 0;
        virtual void off() = 0;
        virtual void changeChannelPlus() = 0;
        virtual void changeChannelMinus() = 0;
};


// Interface
class Television : public ElectronicDevice {
    int channelNumber;

    public:   
        void on(){
            cout << "TV : is ON" << endl;
            channelNumber = 0;
        }

        void off(){
            cout << "TV : is OFF" << endl;   
        }

        void changeChannelPlus(){
            cout << "TV : Channel number is " << ++channelNumber << endl;   
        }

        void changeChannelMinus(){
            cout << "TV : Channel number is " << --channelNumber << endl;   
        }
};


// Interface
class Command {
    public:
        virtual void execute() = 0;
        virtual void undo() = 0;
};  


class TurnTvOn : public Command {

    ElectronicDevice *targetDevice;
    
    public:  
        TurnTvOn(ElectronicDevice *newDevice){
        targetDevice = newDevice;
    }   

    void execute() {
        cout << "Executing Turn On Command" << endl;
        targetDevice->on();
    }
   
    void undo() {
        cout << "Undo - Turn Off" << endl;
        targetDevice->off();
    }
};

class TurnTvOff : public Command {
    
    ElectronicDevice *targetDevice;

    public:  
        TurnTvOff(ElectronicDevice *newDevice){
        targetDevice = newDevice;
    }   

    void execute() {
        cout << "Executing Turn Off Command" << endl;
        targetDevice->off();
    }

    void undo() {
        cout << "Undo - Turn On" << endl;
        targetDevice->on();
    }
};


class ChangeTheChannel : public Command {
    
    ElectronicDevice *targetDevice;

    public:  
        ChangeTheChannel(ElectronicDevice *newDevice){
        targetDevice = newDevice;
    }   

    void execute() {
        cout << "Changing the channel" << endl;
        targetDevice->changeChannelPlus();
    }

    void undo() {
        cout << "Undo - Changed channel" << endl;
        targetDevice->changeChannelMinus();
    }
};



// The Invoker
class InvokerRemoteButton {

    list <Command *> *cmdList;
    public:  
        InvokerRemoteButton(){
            cmdList = new list <Command *>;
    }

    void store(Command *cmd){
        cmdList->push_back(cmd);
    }

    void clear(){
        cmdList->clear();
    }

    void comboPress(){
        for(std::list<Command *>::iterator listIter = cmdList->begin(); 
            listIter != cmdList->end(); listIter++) {

            Command *cmd = *listIter;
            cmd->execute();
        }
     }  
    
    void press(Command *cmd){
        cmd->execute();
    }   

    void undoPress(Command *cmd){
        cmd->undo();
    }   
};  

// The client
void testCommandPattern(){

    // Create the television 
    ElectronicDevice *telly = new Television();

    // Make the list of commands
    Command *turnOn  = new TurnTvOn(telly);
    Command *turnOff = new TurnTvOff(telly);
    Command *changeChannel = new ChangeTheChannel(telly);
    
    
    // Tell the remote to execute commands
    InvokerRemoteButton *button = new InvokerRemoteButton();
    button->press(turnOn);

    button->store(changeChannel);
    button->store(changeChannel);
    button->store(changeChannel);
    
    button->comboPress();

    button->undoPress(changeChannel);
    button->undoPress(changeChannel);  
    
    button->clear();
    
    button->store(turnOff);
    button->comboPress();
}