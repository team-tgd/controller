We're using Open Source Frameworks wherever possible in order to speed up and ease development of the controller. Why reinvent the wheel right? Just pick stable frameworks with good documentation. 

Starting with open Home Automation Bus (openHAB) is an open source, technology agnostic home automation platform which runs as the center of your smart home! errr Garden\GrowOp with a little imagination. - docs.openhab.org

Since its already designed for home automation we can integrate this with technologies such as Phillips Hue, anything ZWave like a door lock, smoke detector, ect.

Or we can create a 'binding' in openHAB which talks to an Mosquitto a MQTT Broker. MQTT is a machine-to-machine (M2M)/"Internet of Things" connectivity protocol. It was designed as an extremely lightweight publish/subscribe messaging transport. It is useful for connections with remote locations where a small code footprint is required and/or network bandwidth is at a premium. mqtt.org

Mosquitto is the MQTT messaging broker (server) that resides on the RasberryPi running openHAB. - mosquitto.org
This interface enables us to send data from anywhere to anywhere. Look at how this tech works for the next bit. It's a very unsexy part of the solution but really what enables this vision. 

Node-RED is a flow-based programming tool, original developed by IBM’s Emerging Technology Services team and now a part of the JS Foundation.
This is how i was able to go from not knowing how to code at all to having a working controller in less than a week including learning Arduino. 

Flow-based Programming - Invented by J. Paul Morrison in the 1970s, flow-based programming is a way of describing an application’s behavior as a network of black-boxes, or “nodes” as they are called in Node-RED. Each node has a well-defined purpose; it is given some data, it does something with that data and then it passes that data on. The network is responsible for the flow of data between the nodes.

It is a model that lends itself very well to a visual representation and makes it more accessible to a wider range of users. If someone can break down a problem into discrete steps they can look at a flow and get a sense of what it is doing; without having to understand the individual lines of code within each node.

But you're still going to have to learn a little bit of code and this is why I suggest you spend the majority of you learning time on learning the ins and outs of Node-RED since its doing most of the heavy lifting for us.  - nodered.org/docs/

And finally that brings us to the hardware level for which i picked the beloved Arduino platform. Learning how to code enough to make this work was the most time extensive, about 2 sleepless days for me before I had all the sensors sending data to MQTT. If you know Arduino its a great advantage but I'll be providing sketches on GitHub that you can modify and compile in the Arduino IDE.  However I've done all the heavy lifting here. Proceed only if you dare - arduino.cc

/thegrowingdude




