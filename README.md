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
