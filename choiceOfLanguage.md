## Choice of Language

There has to be a lot of data that is moving around. An elevator system that can be efficient and also fail safe has to have some way of knowing if the elevators are doing their job. The different elevators have to send and receive information. A shared variable system will probably be hard to get right with all necessary locks. This is probably my main concern, and a good reason to choose a message passing language. 
My initial thought is that there should be a master process, a control centre which communicates with all the elevators and makes the decisions. The elevators has to run their own process of course. (If I have understood the blab setup properly). The different functions and modules are hard visualize already now. But there has to be functions for choosing which elevator should respond to each call for an elevator. There should also be functions for handling failing of network, power loss and missed messages.  
A popular message passing language is Go. Does Go have testing libraries, networking libraries, IDE support and debugging? Yes. So why not, lets Go.

