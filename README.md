# poa-graph-message-tp2

### Compilation and execution
The system was developed using the C++ language, Visual Studio 2017. The project uses the Windows SDK Version 10.0.17763.0 library on top of the x64 platform.

To open the system through Visual Studio, you need to open the TP2Q4.sln file.
To compile and run the system through Visual Studio, use the Play button at the top center.

The source code to analyze are:
- TP2Q4.cpp
- Presentation.h
- Presentation.cpp
- NodeManager.h
- NodeManager.cpp
- Node.h
- Node.cpp
- Graph.h
- Graph.cpp
- Distance.h
- Distance.cpp
- GameManager.h
- GameManager.cpp

To run the application without using Visual Studio, you must run the following file:
poa-graph-message-tp2\x64\Release\TP2Q4.exe; or
Executable\TP2Q4.exe

### Instructions and operation of the game

The objective of the game is to find a way to send a message. After several paths discovered, the game presents the intermediate node to which the message passed most often. This intermediate node is the champion. In the event of a tie, more than one champion node is presented.

The game has a static network of nodes (graph) through which the player can choose the starting and ending points for sending the message. This graph is presented below:

![](https://github.com/eduardoafontana/poa-graph-message-tp2/images/graph-general.png)

The values in parentheses represent the position of the node in the two-dimensional Cartesian plane X and Y. The value on the edge is the calculated Euclidean distance between the points. We place the calculated distance on the Cartesian graph to make it easier to understand. However, the X and Y values are reported in the software for each node during the construction of the graph. In this way, the system dynamically calculates the distance between the nodes.

Below are instructions for playing the game as well as a sample execution.

When starting the game, the user must indicate which is the starting node (point A) and which is the end node (point B) to send the message. The user must inform the code of the node presented in the list of nodes.

![](https://github.com/eduardoafontana/poa-graph-message-tp2/images/print-1.png)

Then the user should indicate the maximum distance value that the algorithm should use to select the path to send the message. This maximum distance value is known as the value of variable D.

![](https://github.com/eduardoafontana/poa-graph-message-tp2/images/print-2.png)

Considering the input data shown above and also the graph shown above, we will have the following output given by the system.

![](https://github.com/eduardoafontana/poa-graph-message-tp2/images/print-3.png)

This output corresponds to the path shown in the graphic below. Observe the path found in green to send the message.

![](https://github.com/eduardoafontana/poa-graph-message-tp2/images/graph-path-1.png)

At this point the user can type N and finish the game. When you do this, you will find out which node the message transmitted the most often, which is the champion node. But only one message was sent, all the nodes P2, P4, P6, P8 and P11 are linked for the number of points as shown below.

![](https://github.com/eduardoafontana/poa-graph-message-tp2/images/print-4.png)

If the user informs Y, the game continues and the user can indicate other nodes and other distances D to send messages.

