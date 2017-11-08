#include "./../../Include/CommonInc.h"

using namespace std;

#include <list>
#include <iterator>

// Interface
class ElectronicDevice {
    public:
        virtual void on()  = 0;
        virtual void off() = 0;
        virtual void changeChannel() = 0;
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

        void changeChannel(){
            cout << "TV : Channel number is " << ++channelNumber << endl;   
        }
};


// Interface
class Command {
    public:
        virtual void execute() = 0;
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
};


class ChangeTheChannel : public Command {
    
    ElectronicDevice *targetDevice;

    public:  
        ChangeTheChannel(ElectronicDevice *newDevice){
        targetDevice = newDevice;
    }   

    void execute() {
        cout << "Changing the channel" << endl;
        targetDevice->changeChannel();
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
    button->store(turnOff);
    
    button->comboPress();
    button->clear();
}