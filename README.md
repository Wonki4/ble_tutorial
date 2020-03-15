# ble_tutorial
Based on nRF BLE Tutorial

This tutorial is based on the free BLE course ( novelbits.io )
and the nRF BLE Tutorial with nRF 52DK(https://github.com/NordicPlayground/nRF52-Bluetooth-Course)

The definition of BLE
-----
1. BLE operate in the 2.4GHz ISM band(the bandwidth of 2.4GHz ISM band is 100MHz.)
2. BLE is not an upgrade to the previouas version, Rather, It's a new technology that utilizes the Bluetooth brand but focuses on __the Internet of Things(IoT)__ applications.
3. The difference between BLE and Blue classic in terms of technical specification, implementation.
>- Bluetooth Classic : used for streaming applications such as audio _streaming and file transfers_.
>- BLE : used for seensor data, control of devices, and low-bandwidth applicatons.

>- Bluetooth Classic : not optimized for low power and has a higher data rate.
>- BLE : low power, low duty data cycles

>- Bluetooth Classic : discovery on 79RF channels
>- BLE :Operate over 40RF channels that means BLE operate on 40channels which exists in 2.4GHz ISM band

>- Bluetoothe Classic : discovery on 32 channels, leading to slower connections.
>- BLE : connectnions are much quicker ( The number of the Primary advertising channels are three )
>> The Primary advertising channels : 2.402GHz (Ch37) 2.426GHz (Ch38) 2.480GHz (Ch39)
>> The reason why these channels are on them is to avoid the interference of the radio from Wifi (Ch1, 6, 11)

TERMINOLOGY
------
- GAP (Generic Access Profile)
  + Responsible for managing connections, advertisements discovery and security features.
  
- GATT (Generic Attribute Profile)
  + A basic data model that allows devices to discover, write, and read elements.
  
- ATT (Attribute Profile)
  + Simple protocol for devices to list attributes that allow different operations such as write, read, find into etc.
  
- Profile
  + High level definition for how services can be used to enable an application or use-case.
  
- Service
  + A collection of characteristics and relationships to other services that encapsulate the behavior of part of a device.
  
- Characteristic
  + Container for a piece of user data, usually coupled with metadata decribing it
  + (Writeable, readable description.. etc)

- Write
  + A request to change the value of an attribute.
  
- Read
  + A request to obtain the value of an attribute.
  

### - Every technology has its own benefits and limitations, and BLE is no exception. It's important to know these pros and cons to be able to determine whether BLE is suitable for your specific application and use-case or not.

- Benefits of BLE
  + Lower power consumption even when compared to other technology 
  + No cost to access the official specification documents.
  + Lower cost of modules and chipsets, even when compared to other similar technologies.
  + Most importantly, __its existence in most smartphones__ in the market.
  
- Limitations of BLE
  + Data Throughput
    * The data throught of BLE is limited by the physical radio layer(PHY) data rate, which is the rate at which the radio transmits data. This rate depends on the bluetooth version used. the criteria is the version of BLE. The rate can bve 1Mbps like earlier versions from Bluetooth4.2 or 2Mbps when utilizing the high-speed feature.
    
  + Range
    * Both of Bluetooth(BLE and Bluetooth Classic) was designated for short range appications and hence its range of operation is limited.
    * BLE operates in the 2.4GHz ISM spectrum which is greatly affected by obstacles.
    * Performance and design of the antenna of the BLE device.
    * Physical enclosure of the device.
    * Device orientation.
    
  + Gataway Requirement for Internet Connectivity
    * In order to transfer data from a BLE-only device to the Internet, Another BLE device that is in connection with Internet is required.
    
The definitnions of BLE layers
-------

- The Physical Layer(PHY) refers to the physical radio used for communication and for modulating / demodulating the data.
- The Link Layer is the layer that interfaces with PHY and provides the higher levels an abstraction and a way to interact with the radio (through an intermediary level called the HCI layer which we'll discuss shortly) It's responsible for managing the state of the radio as well as the timing requirements for adhering to the BLE specificaiton.
- Direct Test Mode is to test the operation of the radio at the physical level ( Transmission power, Receiver sensitivity, etc )
- The Host Controller Interface(HCI)layer is a standard protocol defined by the Bluetooth specification that allows the Host layer to communicate with the Controller layer.
- The Logical Link Control and Adaptation Protocol(L2CAP) layer acts as a protocol multiplexing layer. It takes multiple protocols from the upper layers and places them in standard BLE packets that are passed down to the lower layers beneath it.

There are two other important layers that are GAP and GATT

GAP(Generic Access Profile)
-----
It provides a framework that defines how BLE devices interact with each other.

This includes :
- Roles of BLE devices.
- Advertisements (Broadcasting, Discovery, Advertisement parameters, Advertisement data)
- Connection establishment (Initiating connectnions, Accepting connections, Connection parameters)
- Security

The different roles of a BLE device are:
- Broadcaster : a device that _sends out Advertisements_ and _does not receive packets or allow connections from others_.
- Observer : a device that _listens to others sending out Advertising Packet_, but _does not initiate a Connection with the Advertising device_.
- Central : a device that discovers and listens to other devices that are Advertising. A Central also has the capability of connection with an Advertising device.
- Peripheral : a device that Advertises and accepts Connections from Central devices.
- (Every BLE devices can have multiple roles of above ones)

> Advertising

>> In the Advertising state, a device sends out packets containing useful data for others to receive and process. The packets are sent at a fixed interval defined as __the Advertising Interval__. There are 40RF channels in BLE, each separated by 2MHz. Three of these channels are called __the Primary Advertising Channels__, while the remaining 37 channels are used for __Secondary Advertisements__ and for Data Packet transfer during a Connection. Advertisements always start with Advertisement Packets sent on the Primary Advertising Channels. This allows Centrals to find the Advertising device ( Peripheral or Broadcaster) and parse its advertising Packets. The Central can then initiate a Connection if the Advertiser allow it (Peripheral device)

> Scanning
>> Centrals tune into three Primary advertising channels one at a time so, in order for Centrals to discover a Peripharal, the Central has to be tuned into the same channel that the Peripheral is Advertising on at that given point( one of the Primary Advertising Channel ).
>> To increase the possibility of this happening, and in order to make it happen quickly, the different advertising and scanning parameters can be adjusted.

> Connections
>> In order for two BLE devices to connect to each other, the following needs to happen:
>> - _The Peripheral needs to start Advertising_ and send out connectable __Advertisement packet__.
>> - The Central device needs to Scan for Advertisements while the Peripheral is Advertising.
>> - If the Central happens to be listening on an Advertising Channel that the Peripheral is Advertising on, then the _Central device discovers the Peripheral_ and is able to _read the Advertisement packet and all the necessary information in order to establish a Connection._
>> - The Central then sends a Connection Request packet.
>> - The Peripheral always listens for a short interval on the same Advertising Channel after it sends out the Advertising packet. because this _allows it to receive the Connection Request packet from the Central device_ which triggers the forming of the connection between the two devices.
>>> After that, the Connection is considered "Created", but not yet "Established". __A Connection is considered "Established" once the device receives a packet from its peer device__. After a Connection becomes established, the Central becomes known as the Master, and the Peripheral becomes known as Slave. The Master is responsible for managing the Connection, controlling the Connection Parameters and the timing of the different events within a Connection.
> - Connection Events
>   + A Connection Event contains _at least one packet_ sent by the Master
>   + The Slave always _sends a packet back_ to the Master
>   + If the Master does not receive a packet back from the slave, the Master will close the Connection Event
>   + The Connection Event can be _closed by either side_.
>   + The starting points of consecutive Connection Events are spaced by __a period of time called the Connection Interval__.
> - Connection Parameter
>   + The most important parameters that __define a Connection__ includes ::
>   + Connection Interval : the interval at which two connected BLE devices wake up the radio and exchange data
>   + Slave latency : this value allows the Peripheral to skip a number of consecutive Connection Events and not listen to the Central at these Connection Events without compromising the Connection.
>   + Supervision Timeout : the maximum time between two received data packets before the Connection is considered lost.

GATT (The Generic Attribute Profile)
---------

### The main reason to connect two BLE devices to each other is to transfer data between them.
### Without a Connection, it is not possible to have a bidirectional data transfer between to BLE devices.

> The Generic Attribute Profile (GATT) defines the format of the data exposed by a BLE device. It also defines the procedures needed to access the data exposed by a device.

> There are two Roles within GATT : Server and Client. The server is the device that exposes the data it controls or contains, and possibly some other aspects of its behavior that other devices may be able to control. A Client, on the other hand, is the device that interface with te server with the purpose of reading the Server's exposed data and/or controlling the Server's behavior.

> Keep in mind that a BLE device can act as the Server and a Client at the same time. Simply put, it acts as the Server for the sake of exposing its own data, and as a Client when accessing another device's data.

> - Attributes : a generic term for any type of data exposed by the server and defines the structure of this data. For example, Servies and Characterisitc are type of Attributes.
> - Services : a grouping of one or more Attributes (Some of which are Characteristics) It's meant to group together related Attributes that satisfy a specific functionality on the server. For example, the SIG-adopted Battrey Service contains one Characteristic called the Battery level
> - Characteristics : a Characteristic is alway part of a service and it __represents a piece of information/data that a Server wants to expose to a Client__ For example, the Battery Level Characteristic represents the remaining power level of a battery in a device which can be read by a Client.
> - Profiles : Profiles are much broader in definition from Servies. They are concerned with defining the behavior of both the Client and Server when it comes to Services, Characteristics and even Connections and Security requirements. Services and their specifications, on the other hand, deal with the implementation of these Services and Characteristics on the Server side only.

> - The types of operations on Characterstic
>   + Commands : Sent by the Client to the Server and do not require a Response. One example of a Command is a write command, which does not require a Response from the Server.
>   + Request : Sent by the Client to the Server and require a Response. Some example of Requests inclues : Read Requests and Write requests.
>   + Responses : Sent by the Server in response to a Request.
>   + Notifications : Sent by the Server to the Client to let the Client know that a specific Characteristic value has changed. In order for this to be triggered and sent by the Server, the Client has to enable Notifications for the Charactericstic of interest. Note that a Notification does not require a Response from the Client to acknowledge its receipt.
>   + Indications : Sent by the Server to the Client. They are very similar to Notifications but require an acknowlegement to be sent back to the Client to let the Server know that the Indication was succesfully received. Note that Notification and Indications are exposed via the Client Characteristic Configuration Descriptor(CCCD) Attribute. Writing a "1" to this Attribute value enables Notification, whereas writing a "2" enables Indications. Writing a "0" disables both Notifications and Indications.
>   + Confirmations : sent by the Client to the Server. These are the acknowledgement packets sent back to the Server to let it know that the Client received an Indication successfully.
