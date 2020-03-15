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
> In the Advertising state, a device sends out packets containing useful data for others to receive and process. The packets are sent at a fixed interval defined as the Advertising Interval. There are 40RF channels in BLE, each separated by 2MHz. Three of these channels are called the Primary Advertising Channels, while the remaining 37 channels are used for Secondary Advertisements and for Data Packet transfer during a Connection.
