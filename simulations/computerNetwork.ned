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

package _205009e_tute03.simulations;
import _205009e_tute03.Computer;

network ComputerNetwork
{
    parameters:
        @statistic[totalMessagesRecieved](source = messagesRecieved; record = count);
        @statistic[totalDelay](source = delay; record = vector);
    submodules:
        computer_A: Computer;
        computer_B: Computer;
    connections:
        computer_A.port <--> computer_B.port;
}
