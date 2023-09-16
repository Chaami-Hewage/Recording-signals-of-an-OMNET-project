//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Computer.h"

Define_Module(Computer);

void Computer::initialize()
{
    cMessage *information = new cMessage();
    send(information, "port$o");

    messagesRecievedSignal = registerSignal("messagesRecieved");
    delaySignal = registerSignal("delay");

    // Initialize messagesReceived to 0 in the initialize function
    messagesRecieved = 0;

}

void Computer::handleMessage(cMessage *msg)
{
    EV << "Message Received";

    // Increment the messagesRecieved count
    messagesRecieved++;
    delay= uniform(10,60);

    cMessage *answer = new cMessage();
    sendDelayed(answer,delay, "port$o");

    emit(messagesRecievedSignal, messagesRecieved);
    emit(delaySignal, delay);
}
